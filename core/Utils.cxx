#ifndef PIXLAR_EVD_UTILS_CXX
#define PIXLAR_EVD_UTILS_CXX

#include "Utils.h"
namespace evd {
const ordered_sparse_waveform& Utils::suppressed_waveform(
    const std::vector<float>& input_waveform, float threshold) {
  // Loop over the input waveform, and find all continuous regions above
  // threshold.
  // If threshold is negative, do this but with opposite polarity
  size_t max_tick = input_waveform.size();
  size_t start_region_above_threshold(0);
  size_t end_region_above_threshold(0);

  ordered_sparse_waveform output;

  for (size_t i = 0; i < max_tick; i++) {
    if (input_waveform.at(i) >= threshold) {
      start_region_above_threshold = i;
      end_region_above_threshold = i + 1;
      while (end_region_above_threshold + 1 < max_tick and
             input_waveform.at(end_region_above_threshold + 1) >= threshold) {
        end_region_above_threshold++;
      }
      // Found a region above threshold, copy it to output sparse vector
      waveform _temp_wfm(
          end_region_above_threshold - start_region_above_threshold, 0);
      _temp_wfm.time = start_region_above_threshold;
      // Copy the original data to this waveform:
      for (size_t j = 0; j < _temp_wfm.size(); j++) {
        _temp_wfm.at(j) = input_waveform.at(start_region_above_threshold + j);
      }

      // Add the snippet to the output:
      output.emplace_back(std::move(_temp_wfm));

      // continue the loop but move forward the index to past the end of this
      // waveform:
      i = end_region_above_threshold;
      continue;
    }
  }
}
}
#endif