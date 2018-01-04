# Import the class that manages the view windows
from viewport3D import viewport3D
from pyqtgraph.Qt import QtCore, QtGui
import pyqtgraph.opengl as gl
import pyqtgraph as pg
import numpy

colorMap = {'ticks': [(1, (151, 30, 22, 125)),
                      (0.791, (0, 181, 226, 125)),
                      (0.645, (76, 140, 43, 125)),
                      (0.47, (0, 206, 24, 125)),
                      (0.33333, (254, 209, 65, 125)),
                      (0, (255, 255, 255, 255))],
            'mode': 'rgb'}

box_template = numpy.array([[ 0 , 0, 0],
                            [ 1 , 0, 0],
                            [ 1 , 1, 0],
                            [ 0 , 1, 0],
                            [ 0 , 0, 1],
                            [ 1 , 0, 1],
                            [ 1 , 1, 1],
                            [ 0 , 1, 1]],
                            dtype=float)


faces_template = numpy.array([[0, 1, 2],
                              [0, 2, 3],
                              [0, 1, 4],
                              [1, 5, 4],
                              [1, 2, 5],
                              [2, 5, 6],
                              [2, 3, 6],
                              [3, 6, 7],
                              [0, 3, 7],
                              [0, 4, 7],
                              [4, 5, 7],
                              [5, 6, 7]])

class view_manager3D(QtCore.QObject):
    """This class manages a collection of viewports"""

    refreshColors = QtCore.pyqtSignal()

    def __init__(self):
        super(view_manager3D, self).__init__()
        self._view = viewport3D()


        # Define some color collections:

        self._cmap = pg.GradientWidget(orientation='right')
        self._cmap.restoreState(colorMap)
        self._cmap.sigGradientChanged.connect(self.gradientChangeFinished)
        # self._cmap.sigGradientChangeFinished.connect(self.gradientChangeFinished)
        self._cmap.resize(1, 1)

        self.refreshColors.connect(self.redraw)

        self._lookupTable = self._cmap.getLookupTable(255, alpha=0.75)

        # These boxes control the levels.
        self._upperLevel = QtGui.QLineEdit()
        self._lowerLevel = QtGui.QLineEdit()

        self._upperLevel.returnPressed.connect(self.colorsChanged)
        self._lowerLevel.returnPressed.connect(self.colorsChanged)

        self._lowerLevel.setText(str(0.0))
        self._upperLevel.setText(str(2.0))

        # Fix the maximum width of the widgets:
        self._upperLevel.setMaximumWidth(35)
        self._cmap.setMaximumWidth(25)
        self._lowerLevel.setMaximumWidth(35)

        self._voxelset = None

        self._layout = QtGui.QHBoxLayout()
        self._layout.addWidget(self._view)

        colors = QtGui.QVBoxLayout()
        colors.addWidget(self._upperLevel)
        colors.addWidget(self._cmap)
        colors.addWidget(self._lowerLevel)

        self._layout.addLayout(colors)



        self._gl_voxel_mesh = None

    def gradientChangeFinished(self):
        self._lookupTable = self._cmap.getLookupTable(255, alpha=0.75)
        self.refreshColors.emit()


    def getLookupTable(self):
        return self._lookupTable*(1./255)


    def colorsChanged(self):
        self.refreshColors.emit() 



    def getLayout(self):
        return self._layout


    def setRangeToMax(self):
        pass

    def getView(self):
        return self._view

    def getLevels(self):
        _max = float(self._upperLevel.text())
        _min = float(self._lowerLevel.text())
        return (_min, _max)

    def setCameraPosition(self, pos=None, distance=None, elevation=None, azimuth=None):
        if pos is not None:
            self._view.setCameraPos(pos)
        else:
            self._view.setCameraPosition(distance=distance,elevation=elevation,azimuth=azimuth)

    def setCenter(self, center=None):
        if center is not None:
            self._view.setCenter(center)

    def pan(self, dx, dy, dz, relative=False):
        pass

    def update(self):
        self._view.update()

    def restoreDefaults(self):
        # print "restoreDefaults called but not implemented"
        self._view.setCameraPos((22.5, 125, -60))

    def drawVoxels(self, io_manager):
        self._voxelset = io_manager.getVoxels(coarse=True)
        self.redraw()


###########################


    def redraw(self):

        if self._voxelset is None:
            return

        if self._gl_voxel_mesh is not None:
            self.getView().removeItem(self._gl_voxel_mesh)
            self._gl_voxel_mesh = None


        verts, faces, colors = self.buildTriangleArray()


        #make a mesh item: 
        mesh = gl.GLMeshItem(vertexes=verts,
                             faces=faces,
                             faceColors=colors,
                             smooth=False)

        mesh.setGLOptions("additive")        
        if verts is not None:
            self._gl_voxel_mesh = mesh
            self.getView().addItem(self._gl_voxel_mesh)

    def buildTriangleArray(self):
        verts = None
        faces = None
        colors = None


        i = 0
        for voxel in self._voxelset.as_vector():
            # print voxel.value()

            # Don't draw this pixel if it's below the threshold:
            if voxel.value() < self.getLevels()[0]:
                continue


            this_color = self.getColor(self.getLookupTable(),
                                       self.getLevels(),
                                       voxel.value())

            if colors is None:
                colors = numpy.asarray([this_color]*12)
            else:
                colors = numpy.append(colors,
                                      numpy.asarray([this_color]*12),
                                      axis=0)

            # print "({}, {}, {})".format(_pos[0], _pos[1], _pos[2])
            this_verts = self.makeBox(voxel.id(), self._voxelset.meta())

            if faces is None:
                faces = faces_template
            else:
                faces = numpy.append(faces, 
                                     faces_template + 8*i, 
                                     axis=0)
            if verts is None:
                verts = this_verts
            else:
                verts = numpy.append(verts, 
                                     this_verts, axis=0)

            i += 1

        return verts, faces, colors

    def makeBox(self, voxel_id, meta):
        verts_box = numpy.copy(box_template)
        #Scale all the points of the box to the right voxel size:
        verts_box[:,0] *= meta.size_voxel_x()
        verts_box[:,1] *= meta.size_voxel_y()
        verts_box[:,2] *= meta.size_voxel_z()

        #Shift the points to put the center of the cube at (0,0,0)
        verts_box[:,0] -= 0.5*meta.size_voxel_x()
        verts_box[:,1] -= 0.5*meta.size_voxel_y()
        verts_box[:,2] -= 0.5*meta.size_voxel_z()
        
        #Move the points to the right coordinate in this space

        verts_box[:,0] += meta.pos_x(voxel_id) - meta.min_x()
        verts_box[:,1] += meta.pos_y(voxel_id) - meta.min_y()
        verts_box[:,2] += meta.pos_z(voxel_id) - meta.min_z()


        # color_arr = numpy.ndarray((12, 4))
        # color_arr[:] = [1,1,1,1]

        return verts_box


    def getColor(self, _lookupTable, _levels, _voxel_value ):
        _min = _levels[0]
        _max = _levels[1]

        if _voxel_value >= _max:
            # print "Max " + str(_voxel_value)
            return _lookupTable[-1]
        elif _voxel_value < _min:
            # print "Min "  + str(_voxel_value)
            return (0,0,0,0)
        else:
            index = 255*(_voxel_value - _min) / (_max - _min)
            return _lookupTable[int(index)]


    def clearDrawnObjects(self, view_manager):
        if self._gl_voxel_mesh is not None:
            view_manager.getView().removeItem(self._gl_voxel_mesh)

        self._gl_voxel_mesh = None
        self._meta = None
        self._id_summed_charge = dict()

    def refresh(self, view_manager):
        self.redraw(view_manager)