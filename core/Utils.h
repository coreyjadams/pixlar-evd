/**
 * \file Utils.h
 *
 * \ingroup LArUtil
 *
 * \brief Class def header for a class Utils
 *
 * @author cadams + david caratelli
 */

/** \addtogroup LArUtil

    @{*/
#ifndef PIXLAR_EVD_UTILS_H
#define PIXLAR_EVD_UTILS_H

#include <climits>
#include <iostream>
#include <limits>
#include <vector>

#include "Point.h"

#include "sparse_vector.h"

namespace evd {

/// Utility: maximum value for double
const double kDOUBLE_MAX = std::numeric_limits<double>::max();

/// Utility: minimum value for double
const double kDOUBLE_MIN = std::numeric_limits<double>::min();

/// Utility: maximum value for int
const int kINT_MAX = std::numeric_limits<int>::max();

/// Utility: maximum value for unsigned int
const unsigned int kUINT_MAX = std::numeric_limits<unsigned int>::max();

/// Utility: maximum value for size_t
const size_t kSIZE_MAX = std::numeric_limits<size_t>::max();

class Utils {
 private:
  /**
   * @brief Constructor
   * @details Constructor is private.  To access this class, get a pointer using
   * the Utils::GetME() function
   */
  Utils() {}

  /// Default destructor
  ~Utils() {}

  // Pointer to sole instance of this object
  static Utils* _me;

 public:
  /**
   * @brief Singleton Getter
   * @details Returns a pointer to the sole instance of this class
   * @return Pointer to Utils
   */
  static const Utils* GetME() {
    if (!_me) {
      _me = new Utils;
    }
    return _me;
  }

  const ordered_sparse_waveform& suppressed_waveform(
      const std::vector<float>& input_waveform, float threshold);
};
}

#endif