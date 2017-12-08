from pyqtgraph.Qt import QtGui, QtCore
import os
import threading

class file_watcher(QtCore.QObject,threading.Thread):
  """This file watcher class monitors a file and calls a function when it's contents change"""
  fileChanged = QtCore.pyqtSignal(str)
  def __init__(self, event,file):
    QtCore.QObject.__init__(self)
    threading.Thread.__init__(self)
    # super(file_watcher, self).__init__()
    self._stopped = event
    # keep track of the last file displayed, only send a signal when it changes
    self._prevFile=None
    self._fileToWatch = file
    # self.fileChanged = QtCore.pyqtSignal()

  def run(self):
    while not self._stopped.wait(1.5):
      # print "Thread called"
      # open the file:
      try:
        f = open(self._fileToWatch)
      except Exception, e:
        print "The file selected for watching does not exist!"
        raise e
      # At this point, the file exists.
      fileToDraw = f.readline()
      fileName, fileExtension = os.path.splitext(fileToDraw)
      fileExtension = fileExtension.rstrip()
      if fileToDraw == self._prevFile:
        # print "Not drawing because file has not changed."
        continue
      if fileExtension == ".root":
        print "Refreshing file!"
        self.fileChanged.emit(fileToDraw)
        self._prevFile = fileToDraw
      else:
        print "File has changed but does not appear to be a root file."
        self._prevFile = fileToDraw

class delayTimer(QtCore.QObject,threading.Thread):
  """docstring for funcCaller"""
  delayExpired = QtCore.pyqtSignal()
  def __init__(self, event, delay):
    QtCore.QObject.__init__(self)
    threading.Thread.__init__(self)
    self._stopped = event
    self._delay = delay
    
  def run(self):
    # print "Called run"
    while not self._stopped.wait(self._delay):
      self.delayExpired.emit()
