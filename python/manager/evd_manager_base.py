import ROOT
from pyqtgraph.Qt import QtCore
from .io_manager import io_manager

class evd_manager_base(QtCore.QObject):

    eventChanged = QtCore.pyqtSignal()
    drawFreshRequested = QtCore.pyqtSignal()

    """docstring for lariat_manager"""

    def __init__(self, _file=None):
        super(evd_manager_base, self).__init__()
        QtCore.QObject.__init__(self)
        self.init_manager(_file)

    def init_manager(self, _file):
        # For the larcv manager, using the IOManager to get at the data
        self._io_manager = io_manager()
        self._io_manager.eventChanged.connect(self.eventChangedEcho)

        # Drawn classes is a list of things getting drawn, as well.
        self._drawnClasses = dict()

        self._keyTable = dict()


        if _file != None:
            flist=ROOT.std.vector('std::string')()
            if type(_file) is list:
                for f in _file: flist.push_back(f)
                self._driver.override_input_file(flist)
            else:
                flist.push_back(_file)
                self._driver.override_input_file(flist)

    def eventChangedEcho(self):
        self.eventChanged.emit()

    def io(self):
        return self._io_manager

    # This function returns the list of products that can be drawn:
    def getDrawableProducts(self):
        return self._drawableItems.getDict()

    # override the run,event,subrun functions:
    def run(self):
        if self._io_manager is None:
            return 0
        return self._io_manager.run()

    def event(self):
        if self._io_manager is None:
            return 0
        return self._io_manager.event()

    def spill(self):
        if self._io_manager is None:
            return 0
        return self._io_manager.spill()


    def subrun(self):
        if self._io_manager is None:
            return 0
        return self._io_manager.subrun()

    # def internalEvent(self):
    def entry(self):
        if self._io_manager is not None:
            return self._io_manager.entry()
        else:
            return -1

    def n_entries(self):
        if self._io_manager is not None:
            return self._io_manager.n_entries()
        else:
            return 0

    # override the functions from manager as needed here
    def next(self):
        if self.entry() + 1 < self.n_entries():
            # print self._driver.event()
            self.go_to_entry(self.entry() + 1)
        else:
            print "On the last event, can't go to next."

    def prev(self):
        if self.entry != 0:
            self.go_to_entry(self.entry() - 1)
        else:
            print "On the first event, can't go to previous."

    def go_to_entry(self, entry):
        if entry >= 0 and entry < self.n_entries():
            self._io_manager.goToEvent(entry)
            # self.eventChanged.emit()
        else:
            print "Can't go to entry {}, entry is out of range.".format(entry)

    def range(self, plane):
        # To get the range, we ask for the image meta and use it:
        return self._io_manager.range(plane)

    def n_views(self):
        return self._io_manager.n_views()
