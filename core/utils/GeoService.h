/**
 * \file GeoService.h
 *
 * \ingroup LArUtil
 *
 * \brief Class def header for a class GeoService
 *
 * @author cadams
 */

/** \addtogroup LArUtil

    @{*/
#ifndef PIXLAR_GEOSERVICE_H
#define PIXLAR_GEOSERVICE_H

#include <iostream>
#include <climits>
#include <limits>
#include <vector>

#include "core/dataproducts/DataFormatTypes.h"
#include "core/dataproducts/Point.h"

namespace pixevd {

typedef std::pair<ProjectionID_t, int> pixel_channel;

class GeoService  {




private:

    /**
     * @brief Constructor
     * @details Constructor is private.  To access this class, get a pointer using the GeoService::GetME() function
     */
    GeoService();

    /// Default destructor
    ~GeoService() {}

    // Pointer to sole instance of this object
    static GeoService* _me;

public:

    /**
     * @brief Singleton Getter
     * @details Returns a pointer to the sole instance of this class
     * @return Pointer to GeoService
     */
    static const GeoService* GetME() {
        if (!_me) {
            _me = new GeoService;
        }
        return _me;
    }

    int n_signal_types() const{return 2;}

    int n_channels(ProjectionID_t p) const{return 240;}

    int n_time_ticks() const{return 3072;}

    ProjectionID_t signal_type(int lariat_channel){
        return _lariat_channel_to_pixels[lariat_channel].first;
    }    

    bool compatible(size_t pixel, size_t pad) const;

    Point2D xy(size_t pixel, size_t pad) const;

    Point2D pad_top_left(size_t pad) const;

    Point2D pad_center(size_t pad) const;

    Point2D pixel_relative_coordinate(size_t pixel) const;

    const std::vector<pixel_channel > & lariat_channels_to_pixels() const{
        return _lariat_channel_to_pixels;
    }
    const std::vector<std::vector<int> > & pixel_to_lariat_channel() const{
        return _pixel_to_lariat_channel;
    }

    float min_x(){return 0.;}
    float min_y(){return -18.;}
    float min_z(){return 0.;}
    float max_x(){return 47.;}
    float max_y(){return 18.;}
    float max_z(){return 72.;}

private:

    std::vector< pixel_channel >  _lariat_channel_to_pixels;
    std::vector<std::vector<int> > _pixel_to_lariat_channel;

};

}

#endif
/** @} */ // end of doxygen group

