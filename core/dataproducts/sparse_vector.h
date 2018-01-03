#ifndef PIXLAR_EVD_SPARSEVECTOR_H
#define PIXLAR_EVD_SPARSEVECTOR_H

#include <vector>
namespace pixevd {
typedef float ADC_t;
typedef size_t Time_t;

/// waveform class
class waveform : public std::vector<ADC_t> {
 public:
  waveform() : std::vector<ADC_t>() {}
  waveform(size_t num_element, ADC_t adc)
      : std::vector<ADC_t>(num_element, adc) {}
  ~waveform() {}
  /// time is the "location" of 1st index
  Time_t time;
  /// comparison operator. Only needed to make an "ordered" container
  inline bool operator<(const waveform& rhs) const { return time < rhs.time; }
};

/// very simple, un-ordered vector of waveforms
typedef std::vector<waveform> sparse_waveform;

/// ordered waveform
class ordered_sparse_waveform {
 private:
  sparse_waveform _data;

 public:
  /// accessor to a vector rep
  inline sparse_waveform& as_vector() { return _data; }
  /// accessor to a vector rep
  inline const sparse_waveform& as_vector() const { return _data; }
  /// insert method
  void push_back(const waveform& wf) {
    auto copy = wf;
    emplace_back(std::move(copy));
  }
  /// insert method
  void emplace_back(waveform&& wf) {
    // In case it's empty or greater than the last one
    if (_data.empty() || _data.back() < wf) {
      _data.emplace_back(std::move(wf));
      return;
    }
    // In case it's smaller than the first one
    if (_data.front() > wf) {
      _data.emplace_back(std::move(wf));
      for (size_t idx = 0; (idx + 1) < _data.size(); ++idx) {
        auto& element1 = _data[_data.size() - (idx + 1)];
        auto& element2 = _data[_data.size() - (idx + 2)];
        std::swap(element1, element2);
      }
      return;
    }

    // Else do log(N) search
    auto iter = std::lower_bound(_data.begin(), _data.end(), wf);

    // Cannot be the end
    if (iter == _data.end()) {
      std::cerr << "WfelSet sorting logic error!" << std::endl;
      throw std::exception();
    }

    // If found, merge
    size_t target_ctr = _data.size() - (iter - _data.begin());
    _data.emplace_back(std::move(wf));
    for (size_t idx = 0; idx < target_ctr; ++idx) {
      auto& element1 = _data[_data.size() - (idx + 1)];
      auto& element2 = _data[_data.size() - (idx + 2)];
      std::swap(element1, element2);
    }
    return;
  }
};
}

#endif