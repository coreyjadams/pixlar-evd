from pyqtgraph.Qt import QtGui, QtCore
import pyqtgraph as pg
import numpy
# Import the class that manages the view windows
from viewport import viewport


class view_manager(QtCore.QObject):
  """This class manages a collection of viewports"""
  drawHitsRequested = QtCore.pyqtSignal(int, int)


  def __init__(self):
    super(view_manager, self).__init__()
    self._nviews = 0
    self._drawerList = dict()
    self._cmapList = []

    self._selectedPlane = -1


    self._wireDrawer = pg.GraphicsLayoutWidget()
    self._wireDrawer.setBackground(None)
    self._wirePlot = self._wireDrawer.addPlot()
    # self._wirePlot.setPen((0,0,0))
    self._wirePlotItem = pg.PlotDataItem(pen=(0,0,0))
    # self._wirePlotItem.setBac
    self._wirePlot.addItem(self._wirePlotItem)
    self._wireDrawer.setMaximumHeight(200)
    self._wireDrawer.setMinimumHeight(100)
    self._wireData = None

    
  def resetEvdDrawerList(self, plane):
    self._drawerList = dict()

  def drawPlanes(self, event_manager):
    for view, obj in self._drawerList.iteritems():
      obj.setImage(event_manager.io().getPlane(view))

  def addEvdDrawer(self,plane):
    self._drawerList.update({ plane : viewport(plane)})
    self._drawerList[plane].drawWireRequested.connect(self.drawWireOnPlot)
    self._drawerList[plane].drawHitsRequested.connect(self.hitOnWireHandler)
    self._nviews += 1


  def selectPlane(self,plane):
    self._selectedPlane = plane


  def restoreDefaults(self):
    for plane, view in self._drawerList.iteritems():
      view.restoreDefaults()


  def getDrawListWidget(self):

    self._widgetList = []

    # loop through the list and add the drawing windows and their scale
    self._widget = QtGui.QWidget()
    self._layout = QtGui.QVBoxLayout()
    self._layout.setSpacing(0)
    # self._layout.setMargin(0)
    self._layout.setContentsMargins(0,0,0,0)

    self._planeWidgets = []
    for plane, view in self._drawerList.iteritems():
      widget,layout = view.getWidget()
      self._planeWidgets.append(widget)
      self._layout.addWidget(widget,0)

    self._widget.setLayout(self._layout)

    return self._widget

  def refreshDrawListWidget(self):

    # Draw all planes:
    if self._selectedPlane == -1:
      i = 0
      for widget in self._planeWidgets:
        widget.setVisible(True)
        i += 1

    else:
      i = 0
      for widget in self._planeWidgets:
        if i == self._selectedPlane:
          widget.setVisible(True)
        else:
          widget.setVisible(False)
        i += 1


  def hitOnWireHandler(self,plane,wire):
      if not self._wireDrawer.isVisible():
        return
      # Simply pass the info on to who ever is listening
      # (hint: it's the manager)
      for hit in self._plottedHits:
        self._wirePlot.removeItem(hit)
      self.drawHitsRequested.emit(plane,wire)

  def connectStatusBar(self,statusBar):
    for plane, view in self._drawerList.iteritems():
      view.connectStatusBar(statusBar)


  def setRangeToMax(self):
    for plane, view in self._drawerList.iteritems():
      view.setRangeToMax()

  def autoRange(self,event_manager):
    for view in self._drawerList:
      xRange,yRange = event_manager.getAutoRange(view.plane())
      view.autoRange(xRange,yRange)

  def lockAR(self, lockRatio):
    for plane, view in self._drawerList.iteritems():
      view.lockRatio(lockRatio)

 
  def drawWire(self,wireView):
    if wireView:
      self._layout.addWidget(self._wireDrawer)
      self._wireDrawer.setVisible(True)
    else:
      self._layout.removeWidget(self._wireDrawer)
      self._wireDrawer.setVisible(False)



  def drawWireOnPlot(self, wireData):
    # Need to draw a wire on the wire view
    # Don't bother if the view isn't active:
    if not self._wireDrawer.isVisible():
      return
    else:
      # set the display to show the wire:
      self._wireData = wireData
      self._wirePlotItem.setData(self._wireData)
      # if axisData is not None:
      #   self._wirePlotItem.setData(axisData,wireData)
      # else:

  def drawHitsOnPlot(self,hits):
    if not self._wireDrawer.isVisible():
      return
    offset = self._geometry.timeOffsetTicks(hits[0].plane())
    for i in xrange(len(hits)):
      hit = hits[i]
      xPts = numpy.linspace(hit.start_time() + offset, hit.end_time() + offset, hit.end_time() - hit.start_time() + 1)
      yPts = hit.peak_amplitude() * numpy.exp( - 0.5 * (xPts - (hit.peak_time() + offset))**2 / hit.rms()**2  )
      # self._plottedHits.append(self._wirePlot.plot(xPts,yPts))
      self._plottedHits.append(self._wirePlot.plot(xPts,yPts,pen=pg.mkPen((255,0,0,200),width=2)))

      # self._wirePlot.remove


  def plotFFT(self):
    # Take the fft of wire data and plot it in place of the wire signal
    if self._wireData is None:
      return
    fft = numpy.fft.rfft(self._wireData)
    freqs = numpy.fft.rfftfreq(len(self._wireData),0.5E-3)
    self._wirePlotItem.setData(freqs,numpy.absolute(fft))
    return

  def getViewPorts(self):
    return self._drawerList
