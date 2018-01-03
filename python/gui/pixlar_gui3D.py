from gui3D import gui3D
from pyqtgraph.Qt import QtGui, QtCore
from ROOT import pixevd

# override the gui to give the lariat display special features:
class pixlar_gui3D(gui3D):
  """special lariat gui"""
  def __init__(self,manager):
    super(pixlar_gui3D, self).__init__()
    self.connect_manager(manager)
    self._watcher = None
    self._stopFlag = None
    self._running = False
    # self.update()

  # override the initUI function to change things:
  def initUI(self):
    super(pixlar_gui3D,self).initUI()

    # Change the name of the labels for lariat:
    self._subrunLabel.setText("Spill: 0")      


  # override the update function for lariat:
  def update(self):
    # set the text boxes correctly:
    eventLabel = "Ev: " + str(self._event_manager.event())
    self._eventLabel.setText(eventLabel)
    runLabel = "Run: " + str(self._event_manager.run())
    self._runLabel.setText(runLabel)
    spillLabel = "Spill: "  + str(self._event_manager.spill())
    self._subrunLabel.setText(spillLabel)
    self._view_manager.drawVoxels(self._event_manager.io())
    # Also update the lariat text boxes, just in case:
    if self._event_manager.io().isRunning():
      self._spillUpdatePauseButton.setText("PAUSE")
      self._spillUpdateLabel.setText("Spill update ON")
    else:
      self._spillUpdatePauseButton.setText("START")
      self._spillUpdateLabel.setText("Spill update OFF")    
    if self._event_manager.io().isCycling():
      self._eventUpdatePauseButton.setText("PAUSE")
      self._autoRunLabel.setText("Event update ON")
    else:
      self._eventUpdatePauseButton.setText("START")
      self._autoRunLabel.setText("Event update OFF")


  def quit(self): 
    if self._event_manager.io().isRunning():
      self._event_manager.io().stopSpillRun()
    if self._event_manager.io().isCycling():
      self._event_manager.io().stopCycle()
    QtCore.QCoreApplication.instance().quit()


  # This function sets up the eastern widget
  def getEastLayout(self):
    # This function just makes a dummy eastern layout to use.
    label1 = QtGui.QLabel("Lariat DQM")
    label2 = QtGui.QLabel("Online Monitor")

    font = label1.font()
    font.setBold(True)
    label1.setFont(font)
    label2.setFont(font)
    # This label tells the user that the event switching is on
    self._autoRunLabel = QtGui.QLabel("Event Update OFF")
    # This label is showing the delay between event updates
    self._eventUpdateDelayLabel = QtGui.QLabel("Delay (s):")
    self._eventUpdateDelayEntry = QtGui.QLineEdit("1")
    self._eventUpdateDelayEntry.setMaximumWidth(35)
    self._eventUpdatePauseButton = QtGui.QPushButton("START")
    self._eventUpdatePauseButton.clicked.connect(self.eventUpdateButtonHandler)

    self._spillUpdateLabel = QtGui.QLabel("Spill Update OFF")
    self._spillUpdatePauseButton = QtGui.QPushButton("START")
    self._spillUpdatePauseButton.clicked.connect(self.spillUpdateButtonHandler)

    self._eastWidget = QtGui.QWidget()
    # This is the total layout
    self._eastLayout = QtGui.QVBoxLayout()
    # add the information sections:
    self._eastLayout.addWidget(label1)
    self._eastLayout.addWidget(label2)
    self._eastLayout.addStretch(1)
    # Add the auto event switch stuff:
    self._eastLayout.addWidget(self._autoRunLabel)
    autoDelayLayout = QtGui.QHBoxLayout()
    autoDelayLayout.addWidget(self._eventUpdateDelayLabel)
    autoDelayLayout.addWidget(self._eventUpdateDelayEntry)
    # add it to the widget:
    self._eastLayout.addLayout(autoDelayLayout)
    self._eastLayout.addWidget(self._eventUpdatePauseButton)
    self._eastLayout.addStretch(1)

    # Add the controls for spill update:
    self._eastLayout.addWidget(self._spillUpdateLabel)
    self._eastLayout.addWidget(self._spillUpdatePauseButton)
    self._eastLayout.addStretch(1)

    self._eastWidget.setLayout(self._eastLayout)
    self._eastWidget.setMaximumWidth(150)
    self._eastWidget.setMinimumWidth(100)
    return self._eastWidget

  def spillUpdateButtonHandler(self):
    if self._event_manager.io().isRunning():
      self._event_manager.io().stopSpillRun()
      self._spillUpdatePauseButton.setText("START")
      self._spillUpdateLabel.setText("Spill Update OFF")
    else:
      self._event_manager.io().startSpillRun()
      if self._event_manager.io().isRunning():
        self._spillUpdatePauseButton.setText("PAUSE")
        self._spillUpdateLabel.setText("Spill Update ON")

  def eventUpdateButtonHandler(self):
    if self._event_manager.io().isCycling():
      self._event_manager.io().stopCycle()
      self._eventUpdatePauseButton.setText("START")
      self._autoRunLabel.setText("Event Update OFF")
    else:
      try:
        delay = float(self._eventUpdateDelayEntry.text())
      except Exception, e:
        delay = 1.0
      if delay < 0.1:
        delay = 0.1
      self._eventUpdatePauseButton.setText("PAUSE")
      self._event_manager.io().startCycle(delay)
      self._autoRunLabel.setText("Event Update ON")

def sigintHandler(*args):
    """Handler for the SIGINT signal."""
    sys.stderr.write('\r')
    sys.exit()