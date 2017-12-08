#ifndef PIXLAR_RAWBASE_CXX
#define PIXLAR_RAWBASE_CXX

#include "RawBase.h"

namespace evd {

RawBase::RawBase() {
  _geoService = evd::GeoService::GetME();
  static bool once = false;
  if (!once) {
    import_array();
    once = true;
  }
}

RawBase::~RawBase() {}

const std::vector<float> &RawBase::get_data(unsigned int p) const {
  static std::vector<float> returnNull;
  if (p >= _geoService->n_signal_types()) {
    std::cerr << "ERROR: Request for nonexistant plane " << p << std::endl;
    return returnNull;
  } else {
    try {
      return _data_array.at(p);
    } catch (...) {
      std::cerr
          << "WARNING:  REQUEST FOR PLANE FOR WHICH THERE IS NOT WIRE DATA.\n";
      return returnNull;
    }
  }
}

bool RawBase::file_exists(std::string s) {
  struct stat buffer;
  return (stat(s.c_str(), &buffer) == 0);
}

PyObject *RawBase::as_array(unsigned int p) {
  PyObject *returnNull = nullptr;
  if (p >= _geoService->n_signal_types()) {
    std::cerr << "ERROR: Request for non-existant plane " << p << std::endl;
    return returnNull;
  } else {
    try {
      // Convert the wire data to numpy arrays:
      int n_dim = 2;
      npy_intp dim_data[2];
      dim_data[0] = _x_dimensions.at(p);
      dim_data[1] = _y_dimensions.at(p);
      auto const &vec = _data_array.at(p);
      PyArrayObject *array = (PyArrayObject *)(PyArray_SimpleNewFromData(
          n_dim, dim_data, NPY_FLOAT, (char *)&(vec[0])));
      return PyArray_Return(array);
    } catch (...) {
      std::cerr << "WARNING:  REQUEST FOR PLANE FOR WHICH THERE IS NOT WIRE "
                   "DATA.\n";
      return returnNull;
    }
  }
}

const std::vector<float> RawBase::get_channel_data(unsigned int p,
                                                   unsigned int ch) const {
  std::vector<float> returnVec;
  if (p >= _geoService->n_signal_types()) {
    std::cerr << "ERROR: Request for non-existant plane " << p << std::endl;
    return returnVec;
  }
  if (ch >= _geoService->n_channels(p)) {
    std::cerr << "ERROR: Request for non-channel (" << p << "," << ch << ")"
              << std::endl;
    return returnVec;
  }
  // Copy the data from that channel from the main data:
  returnVec.resize(_y_dimensions.at(p));
  offset = ch*_y_dimensions.at(p);
  for (size_t i = 0; i < _y_dimensions.at(p); i ++){
    returnVec.at(i) = _data_array.at(p).at(offset + i);
  }
  return returnVec;
}

// const std::vector<ordered_sparse_waveform> RawBase::get_sparse_data(
//     unsigned int p, float threshold) const {
//   std::vector<ordered_sparse_waveform> output;
//   output.resize(_data_array.at(p).size());
//   for (size_t i = 0; i < _data_array.at(p).size(); i++) {
//     output.at(i) =
//         _utils->suppressed_waveform(_data_array.at(p).at(i), threshold);
//   }
// }

void RawBase::set_x_dimension(unsigned int x_dim, unsigned int plane) {
  if (_x_dimensions.size() < plane + 1) {
    _x_dimensions.resize(plane + 1);
  }
  _x_dimensions.at(plane) = x_dim;
  return;
}
void RawBase::set_y_dimension(unsigned int y_dim, unsigned int plane) {
  if (_y_dimensions.size() < plane + 1) {
    _y_dimensions.resize(plane + 1);
  }
  _y_dimensions.at(plane) = y_dim;
  return;
}

void RawBase::set_pedestal(float pedestal, unsigned int plane) {
  if (_pedestals.size() < plane + 1) {
    _pedestals.resize(plane + 1);
  }
  _pedestals.at(plane) = pedestal;
  return;
}

void RawBase::init_data_holder() {
  _data_array.resize(_x_dimensions.size());
  for (size_t i = 0; i < _x_dimensions.size(); i++) {
    _data_array.at(i).resize(_x_dimensions.at(i) * _y_dimensions.at(i));
  }
  return;
}

}  // evd

#endif
