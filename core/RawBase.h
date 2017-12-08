/**
 * \file RawBase.h
 *
 * \ingroup RawViewer
 *
 * \brief Class def header for a class RawBase
 *
 * @author cadams
 */

/** \addtogroup RawViewer

    @{*/
#ifndef PIXLAR_RAWBASE_H
#define PIXLAR_RAWBASE_H

#include <iostream>
#include <vector>

struct _object;
typedef _object PyObject;

#include "GeoService.h"
#include "Utils.h"
#include "sparse_vector.h"

#ifndef __CINT__
#include "Python.h"
#include "numpy/arrayobject.h"
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#endif

namespace evd {

/**
   \class RawBase
   This is the base class for drawing raw wire information.
   It contains the data and the methods to get the data
 */
class RawBase {
 public:
  /// Default constructor
  RawBase();

  /// Default destructor
  virtual ~RawBase();

  // This function sets the input target
  // for pixlar, this can be used to set the file
  void set_input(std::string s) { producer = s; }

  // This class has two outputs.
  // First, a user can get the plane data as a vector of float
  // Which means the user may have to know how to convert that back into
  // a 2D array
  // Alternatively, and because this is meant to be used as python,
  // you can get the numpy array of the plane of data, which is 2D

  // You are responsible for setting the dimensions of the planes too
  // There is no requirement they are uniform, but you should make sure to
  // initialize
  // them properly with the following functions:
  void set_x_dimension(unsigned int x_dim, unsigned int plane);
  void set_y_dimension(unsigned int y_dim, unsigned int plane);
  void set_pedestal(float pedestal, unsigned int plane);

  bool file_exists(std::string s);

  // Function to get the array of data
  PyObject* as_array(unsigned int p);

  // Function to get the data by plane:
  const std::vector<float>& get_data(unsigned int p) const;

  const std::vector<float> get_channel_data(unsigned int p, unsigned int ch) const;

  const std::vector<ordered_sparse_waveform> get_sparse_data(
      unsigned int p, float threshold) const;

 protected:
  // sets up the _plane data object
  void init_data_holder();

  const evd::GeoService* _geoService;
  const evd::Utils* _utils;

  // This section holds the images for the data (wire, raw digit, etc)
  std::vector<std::vector<float> > _data_array;

  // these two objects hold the dimensions of the data:
  std::vector<unsigned int> _x_dimensions;
  std::vector<unsigned int> _y_dimensions;

  std::vector<float> _pedestals;

  std::string producer;
};
}  // evd

#endif
/** @} */  // end of doxygen group
