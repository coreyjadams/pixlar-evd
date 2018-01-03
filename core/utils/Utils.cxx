#ifndef PIXLAR_EVD_UTILS_CXX
#define PIXLAR_EVD_UTILS_CXX

#include "Utils.h"
namespace pixevd {

Utils* pixevd::Utils::_me = 0;

ordered_sparse_waveform Utils::suppressed_waveform(const float* input_waveform,
                                                   size_t n_ticks,
                                                   float threshold,
                                                   size_t min_length) const {
  // Loop over the input waveform, and find all continuous regions above
  // threshold.
  // If threshold is negative, do this but with opposite polarity

  size_t start_region_above_threshold(0);
  size_t end_region_above_threshold(0);

  ordered_sparse_waveform output;

  float scale = 1.0;
  if (threshold < 0) {
    scale = -1.0;
  }

  for (size_t i = 0; i < n_ticks; i++) {
    if (scale * input_waveform[i] >= scale * threshold) {
      start_region_above_threshold = i;
      end_region_above_threshold = i + 1;
      while (end_region_above_threshold + 1 < n_ticks and
             scale * input_waveform[end_region_above_threshold + 1] >=
                 scale * threshold) {
        end_region_above_threshold++;
      }
      // Check the waveform is long enough:
      if (end_region_above_threshold - start_region_above_threshold >
          min_length) {
        // Found a region above threshold, copy it to output sparse vector
        waveform _temp_wfm(
            end_region_above_threshold - start_region_above_threshold, 0);
        _temp_wfm.time = start_region_above_threshold;
        // Copy the original data to this waveform:
        for (size_t j = 0; j < _temp_wfm.size(); j++) {
          _temp_wfm.at(j) = input_waveform[start_region_above_threshold + j];
        }

        // Add the snippet to the output:
        output.emplace_back(std::move(_temp_wfm));
      }

      // continue the loop but move forward the index to past the end of this
      // waveform:
      i = end_region_above_threshold;
      continue;
    }
  }
  return output;
}

ordered_sparse_waveform Utils::suppressed_waveform(
    const std::vector<float> input_waveform, float threshold,
    size_t min_length) const {
  return suppressed_waveform(&(input_waveform[0]), input_waveform.size(),
                             threshold, min_length);
}
}
#endif