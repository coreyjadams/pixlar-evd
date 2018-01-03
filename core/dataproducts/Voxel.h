/**
 * \file Voxel.h
 *
 * \ingroup core_DataFormat
 *
 * \brief Class def header for a class pixevd::Voxel
 *
 * @author kazuhiro
 */

/** \addtogroup core_DataFormat

    @{*/
#ifndef LARCV_VOXEL_H
#define LARCV_VOXEL_H

#include "DataFormatTypes.h"
namespace pixevd {

  /**
     \class Voxel
     @brief 3D voxel definition element class consisting of ID and stored value
  */
  class Voxel {

  public:

    /// Default constructor
    Voxel(VoxelID_t id = kINVALID_VOXELID, float value = kINVALID_FLOAT);
    /// Default destructor
    ~Voxel() {}

    /// ID getter
    inline VoxelID_t id() const { return _id; }
    /// Value getter
    inline float  value() const { return _value; }

    /// Value setter
    inline void set(VoxelID_t id, float value) { _id = id; _value = value; }

    //
    // uniry operators
    //
    inline Voxel& operator += (float value)
    { _value += value; return (*this); }
    inline Voxel& operator -= (float value)
    { _value -= value; return (*this); }
    inline Voxel& operator *= (float factor)
    { _value *= factor; return (*this); }
    inline Voxel& operator /= (float factor)
    { _value /= factor; return (*this); }

    //
    // binary operators
    //
    inline bool operator == (const Voxel& rhs) const
    { return (_id == rhs._id); }
    inline bool operator <  (const Voxel& rhs) const
    {
      if ( _id < rhs._id) return true;
      if ( _id > rhs._id) return false;
      return false;
    }
    inline bool operator <= (const Voxel& rhs) const
    { return  ((*this) == rhs || (*this) < rhs); }
    inline bool operator >  (const Voxel& rhs) const
    { return !((*this) <= rhs); }
    inline bool operator >= (const Voxel& rhs) const
    { return !((*this) <  rhs); }

    inline bool operator == (const float& rhs) const
    { return _value == rhs; }
    inline bool operator <  (const float& rhs) const
    { return _value <  rhs; }
    inline bool operator <= (const float& rhs) const
    { return _value <= rhs; }
    inline bool operator >  (const float& rhs) const
    { return _value >  rhs; }
    inline bool operator >= (const float& rhs) const
    { return _value >= rhs; }

  private:
    VoxelID_t _id; ///< voxel id
    float  _value; ///< Pixel Value
  };

  static const pixevd::Voxel kINVALID_VOXEL(kINVALID_VOXELID,0.);

  /**
     \class VoxelSet
     @brief Container of multiple voxels consisting of ordered sparse vector and meta data
   */
  class VoxelSet {
  public:
    /// Default ctor
    VoxelSet() {}
    /// Default dtor
    virtual ~VoxelSet() {}

    //
    // Read-access
    //
    /// InstanceID_t getter
    inline InstanceID_t id() const { return _id; }
    /// Access as a raw vector
    inline const std::vector<pixevd::Voxel>& as_vector() const { return _voxel_v; }
    /// Returns a const reference to a voxel with specified id. if not present, invalid voxel is returned.
    const Voxel& find(VoxelID_t id) const;
    /// Sum of contained voxel values
    inline float sum() const { float res=0.; for(auto const& vox : _voxel_v) res+=vox.value(); return res;}
    /// Mean of contained voxel values
    inline float mean() const { return (_voxel_v.empty() ? 0. : sum() / (float)(_voxel_v.size())); }

    //
    // Write-access
    //    
    /// Clear everything
    inline virtual void clear_data() { _voxel_v.clear(); }
    /// Add a new voxel. If another voxel instance w/ same VoxelID exists, value is added
    void add(const Voxel& vox);
    /// Set a voxel. If another voxel instance w/ same VoxelID exists, value is set
    void insert(const Voxel& vox);
    /// Emplace a new voxel. Same logic as VoxelSet::add but consumes removable reference.
    void emplace(Voxel&& vox, const bool add);
    /// Emplace a new voxel from id & value
    inline void emplace(VoxelID_t id, float value, const bool add) 
    { emplace(Voxel(id,value),add); }
    /// InstanceID_t setter
    inline void id(const InstanceID_t id) { _id = id; }

    //
    // Uniry operations
    //
    inline VoxelSet& operator += (float value)
    { for(auto& vox : _voxel_v) vox += value; return (*this); }
    inline VoxelSet& operator -= (float value)
    { for(auto& vox : _voxel_v) vox -= value; return (*this); }
    inline VoxelSet& operator *= (float factor)
    { for(auto& vox : _voxel_v) vox *= factor; return (*this); }
    inline VoxelSet& operator /= (float factor)
    { for(auto& vox : _voxel_v) vox /= factor; return (*this); }

  private:
    /// Instance ID
    InstanceID_t _id;
    /// Ordered sparse vector of voxels
    std::vector<pixevd::Voxel> _voxel_v;
  };

  /**
     \class VoxelSetArray
     @brief Container of multiple VoxelSet (i.e. container w/ InstanceID_t & VoxelSet pairs)
  */
  class VoxelSetArray {
  public:
    /// Default ctor
    VoxelSetArray() {}
    /// Default dtor
    virtual ~VoxelSetArray() {}

    //
    // Read-access
    //
    /// Get # of VoxelSet
    inline size_t size() const { return _voxel_vv.size(); }
    /// Access specific VoxelSet
    const pixevd::VoxelSet& voxel_set(InstanceID_t id) const;
    /// Access all VoxelSet as a vector
    inline const std::vector<pixevd::VoxelSet>& as_vector() const
    { return _voxel_vv; }

    //
    // Write-access
    //
    /// Clear everything
    inline void clear_data() { _voxel_vv.clear(); }
    /// Resize voxel array
    inline void resize(const size_t num)
    { _voxel_vv.resize(num); for(size_t i=0; i<num; ++i) _voxel_vv[i].id(i); }
    /// Access non-const reference of a specific VoxelSet 
    pixevd::VoxelSet& writeable_voxel_set(const InstanceID_t id);
    /// Move an arrray of VoxelSet. Each element's InstanceID_t gets updated
    void emplace(std::vector<pixevd::VoxelSet>&& voxel_vv);
    /// Set an array of VoxelSet. Each element's InstanceID_t gets updated
    void insert(const std::vector<pixevd::VoxelSet>& voxel_vv);
    /// Move a VoxelSet into a collection. The InstanceID_t is respected.
    void emplace(pixevd::VoxelSet&& voxel_v);
    /// Set a VoxelSet into a collection. The InstanceID_t is respected.
    void insert(const pixevd::VoxelSet& voxel_v);
    /// Mover
    void move(pixevd::VoxelSetArray&& orig)
    { _voxel_vv = std::move(orig._voxel_vv); }

  private:
    std::vector<pixevd::VoxelSet> _voxel_vv;
  };

}

#endif
/** @} */ // end of doxygen group

