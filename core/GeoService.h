/**
 * \file GeoService.h
 *
 * \ingroup LArUtil
 *
 * \brief Class def header for a class GeoService
 *
 * @author cadams + david caratelli
 */

/** \addtogroup LArUtil

    @{*/
#ifndef PIXLAR_GEOSERVICE_H
#define PIXLAR_GEOSERVICE_H

#include <iostream>
#include <climits>
#include <limits>
#include <vector>

#include "Point.h"

namespace evd {


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

    int n_channels(int p) const{return 240;}

    int n_time_ticks() const{return 3072;}

    const std::vector<std::pair<int, int> > & lariat_channels_to_pixels() const{
        return _lariat_channel_to_pixels;
    }
    const std::vector<std::vector<int> > & pixel_to_lariat_channel() const{
        return _pixel_to_lariat_channel;
    }


private:

    std::vector< std::pair<int, int> >  _lariat_channel_to_pixels;
    std::vector<std::vector<int> > _pixel_to_lariat_channel;

};

}

#endif
/** @} */ // end of doxygen group

