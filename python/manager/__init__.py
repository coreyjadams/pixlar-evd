from .evd_manager_base import evd_manager_base
from .evd_manager_2D import evd_manager_2D
from .evd_manager_3D import evd_manager_3D
from .io_manager import io_manager
from .voxel_maker import voxel_maker
try:
    import pyqtgraph.opengl as gl
    # from .evdmanager import evd_manager_3D
except:
    pass
