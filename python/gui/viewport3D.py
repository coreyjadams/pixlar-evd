
try:
    import pyqtgraph.opengl as gl
except:
    print "Error, must have open gl to use this viewer."
    exit(-1)

from pyqtgraph.Qt import QtGui, QtCore
import pyqtgraph as pg
import numpy
import math

from ROOT import pixevd

class viewport3D(gl.GLViewWidget):

    quitRequested = QtCore.pyqtSignal()
    keyPressSignal = QtCore.pyqtSignal(QtGui.QKeyEvent)
    viewChanged = QtCore.pyqtSignal()


    def __init__(self):
        super(viewport3D, self).__init__()
        # add a view box, which is a widget that allows an image to be shown
        # add an image item which handles drawing (and refreshing) the image
        self.setBackgroundColor((0,0,0,255))

        self._background_items = []

        self.drawDetector()
        # self.pan(0,0,self._geometry.length())
        self.show()

    def drawDetector(self):

        self.setCenter((0,0,0))
    
        for _item in self._background_items:
            self.removeItem(_item)
            self._background_items = []
    
        # Draw a set of lines to define the active volume coordinates:
        pts = numpy.array([[ 0 , 0, 0], [ 1 , 0, 0],
                           [ 1 , 1, 0], [ 0 , 1, 0],
                           [ 0 , 0, 0], [ 0 , 0, 1],
                           [ 1 , 0, 1], [ 1 , 1, 1],
                           [ 0 , 1, 1], [ 0 , 0, 1],
                           [ 1 , 0, 1], [ 1 , 0, 0],
                           [ 1 , 1, 0], [ 1 , 1, 1],
                           [ 0 , 1, 1], [ 0 , 1, 0]],
                           dtype=float)

        pts[:,0] *= pixevd.GeoService.GetME().max_x() - pixevd.GeoService.GetME().min_x()
        pts[:,1] *= pixevd.GeoService.GetME().max_y() - pixevd.GeoService.GetME().min_y()
        pts[:,2] *= pixevd.GeoService.GetME().max_z() - pixevd.GeoService.GetME().min_z()

        det_outline = gl.GLLinePlotItem(pos=pts,color=(1.0,1.0,1.0,1.0), width=3)
        self.addItem(det_outline)

    
        self._background_items.append(det_outline)
    
        # # Move the center of the camera to the center of the view:
        self.pan(0.5*(pixevd.GeoService.GetME().max_x() + pixevd.GeoService.GetME().min_x()),
                 0.5*(pixevd.GeoService.GetME().max_y() + pixevd.GeoService.GetME().min_y()),
                 0.5*(pixevd.GeoService.GetME().max_z() + pixevd.GeoService.GetME().min_z()))


        # Draw the array of pads?
        n_pads = 240

        _pad_pts = numpy.ndarray((n_pads, 3))
        for i in xrange(n_pads):
            _pad_pts[i,0] = 0
            _pad_pts[i,1] = pixevd.GeoService.GetME().pad_center(i).y
            _pad_pts[i,2] = pixevd.GeoService.GetME().pad_center(i).x
        
        padPointsCollection = gl.GLScatterPlotItem(pos=_pad_pts,
                                                   size=1,
                                                   color=[0,0,1.0,1.0], 
                                                   pxMode=False)
        self.addItem(padPointsCollection)


    def setCenter(self, center):
        if len(center) != 3:
            return
        cVec = QtGui.QVector3D(center[0],center[1],center[2])
        self.opts['center'] = cVec
        self.update()




    def worldCenter(self):
        return self.opts['center']

  # def drawBox(self, xmin, ymin, zmin, xmax, ymax, zmax):

  #   # Draw lines from each corner to the
  #   # 3 corners it connects with
  #   self.drawLine((xmin,ymin,zmin),(xmin,ymax,zmin))
  #   self.drawLine((xmin,ymin,zmin),(xmax,ymin,zmin))
  #   self.drawLine((xmax,ymin,zmin),(xmax,ymax,zmin))
  #   self.drawLine((xmin,ymax,zmin),(xmax,ymax,zmin))

  #   self.drawLine((xmin,ymin,zmax),(xmin,ymax,zmax))
  #   self.drawLine((xmin,ymin,zmax),(xmax,ymin,zmax))
  #   self.drawLine((xmax,ymin,zmax),(xmax,ymax,zmax))
  #   self.drawLine((xmin,ymax,zmax),(xmax,ymax,zmax))

  #   self.drawLine((xmin,ymin,zmin),(xmin,ymin,zmax))
  #   self.drawLine((xmax,ymax,zmin),(xmax,ymax,zmax))
  #   self.drawLine((xmin,ymax,zmin),(xmin,ymax,zmax))
  #   self.drawLine((xmax,ymin,zmin),(xmax,ymin,zmax))


    def getAzimuth(self):
        return self.opts['azimuth']


    def getElevation(self):
        return self.opts['elevation']

    def setCameraPos(self,pos):
        # calling set camera with pos doesn't actually do anything.  Convert spherical coordinates:
        if pos is not None:
            # Convert to relative coordinates to always leave the world center as the center point
            worldCenter = self.opts['center']
            # Check the type:
            if type(worldCenter) is QtGui.QVector3D:
                X = pos[0] - worldCenter.x()
                Y = pos[1] - worldCenter.y()
                Z = pos[2] - worldCenter.z()
            else:
                X = pos[0] - worldCenter[0]
                Y = pos[1] - worldCenter[1]
                Z = pos[2] - worldCenter[2]

            distance = X**2 + Y**2 + Z**2
            distance = math.sqrt(distance)
            if X != 0:
                azimuth = math.atan2(Y,X)
            else:
                azimuth = math.pi
                if Y < 0:
                    azimuth = -1 * azimuth
            if distance != 0:
                elevation = math.asin(Z / distance)
            else:
                elevation = math.copysign(Z)
            azimuth *= 180./math.pi
            elevation *= 180./math.pi
            self.setCameraPosition(distance=distance,elevation=elevation,azimuth=azimuth)
            self.viewChanged.emit()

    def keyPressEvent(self,e):
        if e.key() == QtCore.Qt.Key_C:
            # print "C was pressed"
            if e.modifiers() and QtCore.Qt.ControlModifier :
                self.quitRequested.emit()
                return
        elif e.modifiers():
            if QtCore.Qt.ShiftModifier :
                if e.key() == QtCore.Qt.Key_Up:
                    # This is supposed to pan upwards in the view
                    self.pan(0,20,0,True)
                if e.key() == QtCore.Qt.Key_Down:
                    self.pan(0,-20,0,True)
                if e.key() == QtCore.Qt.Key_Left:
                    self.pan(20,0,0,True)
                if e.key() == QtCore.Qt.Key_Right:
                    self.pan(-20,0,0,True)
        else:
            super(viewport3D,self).keyPressEvent(e)
       

        # Pass this signal to the main gui, too
        self.keyPressSignal.emit(e)

    def orbit(self, azim, elev):
        super(viewport3D, self).orbit(azim, elev)
        self.viewChanged.emit()

    def pan(self, dx, dy, dz, relative=False):
        super(viewport3D, self).pan(dx, dy, dz, relative)
        self.viewChanged.emit()

    def wheelEvent(self, ev):
        super(viewport3D, self).wheelEvent(ev)
        self.viewChanged.emit()

  
