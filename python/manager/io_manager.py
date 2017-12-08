from pyqtgraph.Qt import QtCore
from ROOT import evd
import threading
from .file_watcher import file_watcher, delayTimer

class io_manager(QtCore.QObject):
  """docstring for lariat_manager"""
  eventChanged = QtCore.pyqtSignal()
  def __init__(self, file=None):
    super(io_manager, self).__init__()

    self._geom = evd.GeoService.GetME()

    # override the wire drawing process for lariat
    self._process = evd.ReadDQMFile(self._geom.n_time_ticks())
    self._process.initialize()

    self.setInputFile(file)
    self._hasFile = False

    # The lariat manager handles watching files and sending signals
    self._watcher = None
    self._stopFlag = None
    self._running = False

    # the manager also can cycle through the events in a file:
    self._cycling = False
    self._delay = 0.1

    # Lariat has special meanings to event/spill/run
    self._run = 0
    self._event = 0
    self._subrun = 0
    self._spill = 1

    self._lastProcessed = -1

  def run(self):
    return self._run

  def event(self):
    return self._event

  def entry(self):
    return self.event()

  def subrun(self):
    return self._spill

  def spill(self):
    return self._spill

  def setRun(self, run):
    self._run = run

  def setEvent(self, event):
    self._event = event

  def setSpill(self,spill):
    self._spill = spill

  def selectFile(self):
    filePath = str(QtGui.QFileDialog.getOpenFileName())
    self.parseFileName(filePath)
    print "Selected file is ", filePath

  # override the functions from manager as needed here
  def next(self):
    # print "Called next"
    # Check that this isn't the last event:
    if self._event < self._process.n_events() - 1:
      self.goToEvent(self._event + 1)
    elif self._cycling:
      self.goToEvent(1)
    else:
      print "On the last event, can't go to next."

  def prev(self):
    if self._event != 1:
      self.goToEvent(self._event - 1)
    elif self._cycling:
      self.goToEvent(self._process.n_events() -1)  
    else:
      print "On the first event, can't go to previous."

  def goToEvent(self,event):
    self.setRun(self._process.run())
    self.setEvent(event)
    self.setSpill(self._process.spill())
    self.processEvent()
    self.eventChanged.emit()


  def setInputFile(self, file):
    self._file = file
    if file == None:
      return
    else:
      file = str(file)
      print type(file)
      self._process.setInput(file)
      self._hasFile = True
      self.goToEvent(1)

  def parseFileName(self,fileName):

    if type(fileName) != str:
      self._filePath = None
      return

    if fileName.endswith(".root"):
      # this is a data file, set it to display:
      self.setInputFile(fileName)

    elif fileName.endswith(".txt"):
        # parse the txt file to get the file name
        # automatically start a run of autoupdates
        self._monitorFile = fileName
        self.startSpillRun(fileName)
    else:
        self._filePath = None

  def isRunning(self):
    return self._running

  def isCycling(self):
    return self._cycling

  def startSpillRun(self,fileName=None):
      # this function can be triggered by a button push, which implies it was stopped before;
      # In that case, refresh the thread and start over.
      # It can also be called by the parsefileName function, which implies a file is ready
      if self._watcher == None and fileName == None:
          print "ERROR: there is no file to watch, can not start a run."
          return
      self._stopFlag = threading.Event()
      self._watcher = file_watcher(self._stopFlag, self._monitorFile)
      self._watcher.fileChanged.connect(self.setInputFile)
      self._running = True
      self._watcher.start()
      

  def stopSpillRun(self):
    self._running = False
    if self._stopFlag is not None:
      self._stopFlag.set()
    return

  def startCycle(self,delay=None):
    if delay != None:
      self._delay = delay
    # set up a thread to call next event every so often
    self._cycling = True
    self._stopCycleFlag = threading.Event()
    self._cycleWatcher = delayTimer(self._stopCycleFlag,self._delay)
    self._cycleWatcher.delayExpired.connect(self.next)
    self._cycleWatcher.start()

  def stopCycle(self):
    self._cycling = False
    self._stopCycleFlag.set()

  def processEvent(self,force = False):
    if not self._hasFile:
      return
    if self._lastProcessed != self._event or force:
      self._process.goToEvent(self._event)
      self._lastProcessed = self._event

  def getPlane(self,plane):
    if self._hasFile:
      return self._process.as_array(plane)


  def hasWireData(self):
    if self._hasFile:
      return True
    else:
      return False  

  def n_views(self):
    return self._geom.n_signal_types()

  def n_entries(self):
    return self._process.n_events()