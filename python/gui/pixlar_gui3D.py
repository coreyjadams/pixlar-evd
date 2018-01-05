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
    self._view_manager.drawVoxels(self._event_manager.io(), self._voxel_params)
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


  def getVoxelControlLayout(self):
    '''
    Create a set of line edits and labels for matching voxels
    '''

    self._voxel_params = dict()
    self._voxel_params['pixel_threshold'] = 15
    self._voxel_params['pixel_spacing'] = 7
    self._voxel_params['pad_threshold'] = 15
    self._voxel_params['pad_spacing'] = 7
    self._voxel_params['match_spacing'] = 7
    self._voxel_params['coarse'] = True


    # master layout:
    voxel_controls = QtGui.QVBoxLayout()

    # Pad specific layout:
    pad_label = QtGui.QLabel("<b>Pad Values</b>")
    pad_label.setAlignment(QtCore.Qt.AlignCenter)
    voxel_controls.addWidget(pad_label)
    pad_threshold_layout = QtGui.QHBoxLayout()
    pad_threshold_layout.addWidget(QtGui.QLabel("Threshold:"))
    
    # Pad threshold
    self._pad_threshold_box = QtGui.QLineEdit(str(self._voxel_params['pad_threshold']))
    self._pad_threshold_box.setToolTip("Minimum signal height for pad hits")
    self._pad_threshold_box.returnPressed.connect(self.voxelValuesUpdated)
    pad_threshold_layout.addWidget(self._pad_threshold_box)
    voxel_controls.addLayout(pad_threshold_layout)

    # Pad hit spacing
    pad_spacing_layout = QtGui.QHBoxLayout()
    pad_spacing_layout.addWidget(QtGui.QLabel("Spacing:"))
    self._pad_spacing_box = QtGui.QLineEdit("7")
    self._pad_spacing_box.setToolTip("Minimum distance between pad hits")
    self._pad_spacing_box.returnPressed.connect(self.voxelValuesUpdated)
    pad_spacing_layout.addWidget(self._pad_spacing_box)
    voxel_controls.addLayout(pad_spacing_layout)

    # Pixel values
    pixel_label = QtGui.QLabel("<b>Pixel Values</b>")
    pixel_label.setAlignment(QtCore.Qt.AlignCenter)
    voxel_controls.addWidget(pixel_label)

    # Pixel Threshold
    pixel_threshold_layout = QtGui.QHBoxLayout()
    pixel_threshold_layout.addWidget(QtGui.QLabel("Threshold:"))
    self._pixel_threshold_box = QtGui.QLineEdit("15")
    self._pixel_threshold_box.setToolTip("Minimum signal height for pixel hits")
    self._pixel_threshold_box.returnPressed.connect(self.voxelValuesUpdated)
    pixel_threshold_layout.addWidget(self._pixel_threshold_box)
    voxel_controls.addLayout(pixel_threshold_layout)

    # Pixel spacing
    pixel_spacing_layout = QtGui.QHBoxLayout()
    pixel_spacing_layout.addWidget(QtGui.QLabel("Spacing:"))
    self._pixel_spacing_box = QtGui.QLineEdit("7")
    self._pixel_spacing_box.setToolTip("Minimum distance between pixel hits")
    self._pixel_spacing_box.returnPressed.connect(self.voxelValuesUpdated)
    pixel_spacing_layout.addWidget(self._pixel_spacing_box)
    voxel_controls.addLayout(pixel_spacing_layout)
    
    # Matching settings
    match_label = QtGui.QLabel("<b>Matching</b>")
    match_label.setAlignment(QtCore.Qt.AlignCenter)
    voxel_controls.addWidget(match_label)

    match_time_gap_label = QtGui.QLabel("Tick Gap:")
    gap_layout = QtGui.QHBoxLayout()
    gap_layout.addWidget(match_time_gap_label)
    self._match_spacing_box = QtGui.QLineEdit("7")
    self._match_spacing_box.setToolTip("Max tick distance between pixel/pad hits")
    self._match_spacing_box.returnPressed.connect(self.voxelValuesUpdated)
    gap_layout.addWidget(self._match_spacing_box)
    voxel_controls.addLayout(gap_layout)

    # Coarse or fine selection:
    self._viewButtonLayout = QtGui.QVBoxLayout()
    self._coarse_selection = QtGui.QRadioButton("Coarse")
    self._coarse_selection.setChecked(True)
    self._viewButtonLayout.addWidget(self._coarse_selection)
    self._fine_selection = QtGui.QRadioButton("Fine")
    self._viewButtonLayout.addWidget(self._fine_selection)

    # Connect toggling:
    self._coarse_selection.toggled.connect(self.voxelValuesUpdated)
    self._fine_selection.toggled.connect(self.voxelValuesUpdated)

    voxel_controls.addLayout(self._viewButtonLayout)

    return voxel_controls

  # This function sets up the eastern widget
  def getEastLayout(self):
    # This function just makes a dummy eastern layout to use.
    label1 = QtGui.QLabel("Pixlar DQM")
    label2 = QtGui.QLabel("3D Online Monitor")

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
    self._eastLayout.addLayout(self.getVoxelControlLayout())
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


  def voxelValuesUpdated(self):
    '''
    Update the voxel parameters:
    '''

    self._voxel_params['pixel_threshold'] = int(self._pixel_threshold_box.text())
    self._voxel_params['pixel_spacing'] = int(self._pixel_spacing_box.text())
    self._voxel_params['pad_threshold'] = int(self._pad_threshold_box.text())
    self._voxel_params['pad_spacing'] = int(self._pad_spacing_box.text())
    self._voxel_params['match_spacing'] = int(self._match_spacing_box.text())
    if self._coarse_selection.isChecked():
      self._voxel_params['coarse'] = True
    else:
      self._voxel_params['coarse'] = False


    self.update()
    pass

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