/**
 * \file ReadDQMFile.h
 *
 * \ingroup EventViewer
 *
 * \brief Class def header for a class ReadDQMFile
 *
 * @author cadams
 */

/** \addtogroup EventViewer

    @{*/

#ifndef PIXLAR_READDQMFILE_H
#define PIXLAR_READDQMFILE_H

#include "RawBase.h"

#include "TBranch.h"
#include "TChain.h"

#include <map>

#include "core/dataproducts/Voxel3D.h"

namespace pixevd {

class boardSet {
 public:
  // boardSet(){}
  // ~boardSet(){}

  std::vector<size_t> ttree_entries;
  std::vector<int> board_ids;
  int event_co;
};

/**
   \class ReadDQMFile
   User custom analysis class made by SHELL_USER_NAME
 */
class ReadDQMFile : public RawBase {
 public:
  /// Default constructor
  ReadDQMFile(int ticks = -1);

  /// Default destructor
  virtual ~ReadDQMFile();

  // functions that would be necessary to do this on a larlite file
  /** IMPLEMENT in ReadDQMFile.cc!
      Initialization method to be called before the analysis event loop.
  */
  void initialize();

  // Override the default behavior of this function
  void setInput(std::string s);

  void nextEvent();
  void prevEvent();
  void goToEvent(int e);

  unsigned int first_event() { return _event_set.begin()->first; }

  unsigned int run() { return _run; }
  unsigned int event_no() { return _event_no; }
  unsigned int spill() { return _spill; }
  int current_event() const { return _current_event; }
  int n_events() const { return _n_events; }

  int planeFromLariatChannel();

  SparseTensor3D getSparseTensor3D(float iou, float pixel_threshold,
                                   float induction_threshold);

  SparseTensor3D getCoarseTensor3D(float induction_threshold);

 protected:
  std::vector<TBranch *> branches;

  std::map<unsigned int, ::pixevd::boardSet> _event_set;

  std::string producer;

  TChain *c;

  int _n_events;
  // this is the event in the file (0 -> n_events)
  unsigned int _current_event;
  // this is the official event:
  unsigned int _event_no;
  int _run;
  int _spill;
  unsigned int _board_id;

  const int _n_cards = 8;
  const int _card_offset = 0;
  const int _n_channels = 64;

  std::vector<unsigned int> board_start_index;

  int _n_time_ticks;

  // Need some private worker functions to handle file i/o
  void readData();

  void prepareFile();

  int getLarsoftChannel(int &asic, int &channelOnAsic);
};
}
#endif

//**************************************************************************
//
// For Analysis framework documentation, read Manual.pdf here:
//
// http://microboone-docdb.fnal.gov:8080/cgi-bin/ShowDocument?docid=3183
//
//**************************************************************************

/** @} */  // end of doxygen group
