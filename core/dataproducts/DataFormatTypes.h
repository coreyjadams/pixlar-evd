#ifndef __DATAFORMATTYPES_H__
#define __DATAFORMATTYPES_H__

#include "LArCVTypes.h"
#include <vector>
#include <set>
#include "pixlar_exception.h"

namespace pixevd {
  

  /// Invalid rep for vector index
  static const unsigned short kINVALID_INDEX = kINVALID_USHORT;
  /// Image index type for Image2D within EventImage2D  
  typedef unsigned short ProjectionID_t;

  /// "ID" for a set of elements
  typedef unsigned short InstanceID_t;
  /// Invalid rep for InstanceID_t
  static const unsigned short kINVALID_INSTANCEID = kINVALID_USHORT;
  /// Invalid projection id
  static const ProjectionID_t kINVALID_PROJECTIONID = kINVALID_USHORT;

  /// "ID" for Voxel3D
  typedef unsigned long long VoxelID_t;
  /// Invalid Voxel3DID_t definition
  static const VoxelID_t kINVALID_VOXELID = kINVALID_ULONGLONG;

  /// Channel status constants
  namespace chstatus {
    static const short kNOTPRESENT = -1;        ///< Channel does not exist
    static const short kNEGATIVEPEDESTAL = -2;  ///< Channel not reco-ed due to pedestal < 0
    /// Standard channel status enum stored in the database
    enum ChannelStatus_t { 
      kDISCONNECTED=0, ///< Channel is not connected
      kDEAD=1,         ///< Dead channel
      kLOWNOISE=2,     ///< Abnormally low noise channel
      kNOISY=3,        ///< Abnormally high noise channel
      kGOOD=4,         ///< Good channel
      kUNKNOWN=5       ///< Channel w/ unverified status
    };
  }

  /// Coordinate unit type
  enum DistanceUnit_t {
    kUnitUnknown, ///< undefined scale (bad!)
    kUnitCM,      ///< cm scale
    kUnitWireTime ///< wire/time in 2D image
  };



  /// "ID" 
  template <class T>
  std::string product_unique_name();

}
#endif
