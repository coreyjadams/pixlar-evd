import numpy
from ROOT import pixevd

class voxel_maker(object):
    """docstring for voxel_maker"""
    def __init__(self):
        super(voxel_maker, self).__init__()
        self.geom = pixevd.GeoService.GetME()
        # Initialize a static meta
        self.coarse_meta = pixevd.Voxel3DMeta()
        self.coarse_meta.set(0., -18., 0., 47.1, 18., 72., 157, 15, 16)
        self.fine_meta = pixevd.Voxel3DMeta()
        self.fine_meta.set(0., -18., 0., 47.1, 18., 72., 157, 120, 240)


    def get_coarse_voxels(self, pads, pad_hit_threshold, pad_hit_separation):
        # Loop through the pads and get the coarse voxels
        pad_peaks = self.detect_peaks(pads.flatten(), 
            mph=pad_hit_threshold, mpd=pad_hit_separation, valley=True)
        pad_channels, pad_times = numpy.unravel_index(pad_peaks, pads.shape)


        voxel_set = pixevd.SparseTensor3D()
        voxel_set.meta(self.coarse_meta)

        if len(pad_channels) == 0:
            return voxel_set


        # Loop over the pad hits and add them to the voxels:
        for channel, time in zip(pad_channels, pad_times):
            xy = self.geom.pad_center(channel)
            voxel_set.emplace(0.02*time, xy.y, xy.x, -pads[channel][time])

        return voxel_set

    def get_fine_voxels(self, pads, pixels, pad_hit_threshold, pad_hit_separation,
                        pixel_hit_threshold, pixel_hit_separation, match_distance):

        '''
        Create a set of matched voxels
        '''
        # Find the peaks:
        pixel_peaks = self.detect_peaks(pixels.flatten(), 
            mph=pixel_hit_threshold, mpd=pixel_hit_separation)
        pad_peaks = self.detect_peaks(pads.flatten(), 
            mph=pad_hit_threshold, mpd=pad_hit_separation, valley=True)

        # Map back to channel/time:
        pixel_channels, pixel_times = numpy.unravel_index(pixel_peaks, pixels.shape)
        pad_channels, pad_times = numpy.unravel_index(pad_peaks, pads.shape)

        # Make a set of matches:
        time_diff = numpy.zeros((len(pixel_times), len(pad_times)))
        time_diff += pad_times[numpy.newaxis,:]
        time_diff -= pixel_times[:,numpy.newaxis]
        pixel_match_indexes, pad_match_indexes = numpy.where(abs(time_diff) <= match_distance)

        voxel_set = pixevd.SparseTensor3D()
        voxel_set.meta(self.fine_meta)


        # Put them into a voxelset:
        for (pixel_match_index, pad_match_index) in zip(pixel_match_indexes, pad_match_indexes):
            pixel_channel = pixel_channels[pixel_match_index]
            pixel_time = pixel_times[pixel_match_index]    
            pad_channel = pad_channels[pad_match_index]   
            if self.geom.compatible(pixel_channel, pad_channel):
                xy = self.geom.xy(pixel_channel, pad_channel)
                voxel_set.emplace(0.02*pixel_time, xy.y, xy.x, pixels[pixel_channel][pixel_time])
            
        return voxel_set

        pass

    # This code is from http://nbviewer.jupyter.org/github/demotu/BMC/blob/master/notebooks/DetectPeaks.ipynb
    def detect_peaks(self, x, mph=None, mpd=1, threshold=0, edge='rising',
                     kpsh=False, valley=False, show=False, ax=None):

        """Detect peaks in data based on their amplitude and other features.

        Parameters
        ----------
        x : 1D array_like
            data.
        mph : {None, number}, optional (default = None)
            detect peaks that are greater than minimum peak height.
        mpd : positive integer, optional (default = 1)
            detect peaks that are at least separated by minimum peak distance (in
            number of data).
        threshold : positive number, optional (default = 0)
            detect peaks (valleys) that are greater (smaller) than `threshold`
            in relation to their immediate neighbors.
        edge : {None, 'rising', 'falling', 'both'}, optional (default = 'rising')
            for a flat peak, keep only the rising edge ('rising'), only the
            falling edge ('falling'), both edges ('both'), or don't detect a
            flat peak (None).
        kpsh : bool, optional (default = False)
            keep peaks with same height even if they are closer than `mpd`.
        valley : bool, optional (default = False)
            if True (1), detect valleys (local minima) instead of peaks.
        show : bool, optional (default = False)
            if True (1), plot data in matplotlib figure.
        ax : a matplotlib.axes.Axes instance, optional (default = None).

        Returns
        -------
        ind : 1D array_like
            indeces of the peaks in `x`.

        Notes
        -----
        The detection of valleys instead of peaks is performed internally by simply
        negating the data: `ind_valleys = detect_peaks(-x)`
        
        The function can handle NaN's 

        See this IPython Notebook [1]_.

        References
        ----------
        .. [1] http://nbviewer.ipython.org/github/demotu/BMC/blob/master/notebooks/DetectPeaks.ipynb

        Examples
        --------
        >>> from detect_peaks import detect_peaks
        >>> x = numpy.random.randn(100)
        >>> x[60:81] = numpy.nan
        >>> # detect all peaks and plot data
        >>> ind = detect_peaks(x, show=True)
        >>> print(ind)

        >>> x = numpy.sin(2*numpy.pi*5*numpy.linspace(0, 1, 200)) + numpy.random.randn(200)/5
        >>> # set minimum peak height = 0 and minimum peak distance = 20
        >>> detect_peaks(x, mph=0, mpd=20, show=True)

        >>> x = [0, 1, 0, 2, 0, 3, 0, 2, 0, 1, 0]
        >>> # set minimum peak distance = 2
        >>> detect_peaks(x, mpd=2, show=True)

        >>> x = numpy.sin(2*numpy.pi*5*numpy.linspace(0, 1, 200)) + numpy.random.randn(200)/5
        >>> # detection of valleys instead of peaks
        >>> detect_peaks(x, mph=0, mpd=20, valley=True, show=True)

        >>> x = [0, 1, 1, 0, 1, 1, 0]
        >>> # detect both edges
        >>> detect_peaks(x, edge='both', show=True)

        >>> x = [-2, 1, -2, 2, 1, 1, 3, 0]
        >>> # set threshold = 2
        >>> detect_peaks(x, threshold = 2, show=True)
        """

        x = numpy.atleast_1d(x).astype('float64')
        if x.size < 3:
            return numpy.array([], dtype=int)
        if valley:
            x = -x
        # find indices of all peaks
        dx = x[1:] - x[:-1]
        # handle NaN's
        indnan = numpy.where(numpy.isnan(x))[0]
        if indnan.size:
            x[indnan] = numpy.inf
            dx[numpy.where(numpy.isnan(dx))[0]] = numpy.inf
        ine, ire, ife = numpy.array([[], [], []], dtype=int)
        if not edge:
            ine = numpy.where((numpy.hstack((dx, 0)) < 0) & (numpy.hstack((0, dx)) > 0))[0]
        else:
            if edge.lower() in ['rising', 'both']:
                ire = numpy.where((numpy.hstack((dx, 0)) <= 0) & (numpy.hstack((0, dx)) > 0))[0]
            if edge.lower() in ['falling', 'both']:
                ife = numpy.where((numpy.hstack((dx, 0)) < 0) & (numpy.hstack((0, dx)) >= 0))[0]
        ind = numpy.unique(numpy.hstack((ine, ire, ife)))
        # handle NaN's
        if ind.size and indnan.size:
            # NaN's and values close to NaN's cannot be peaks
            ind = ind[numpy.in1d(ind, numpy.unique(numpy.hstack((indnan, indnan-1, indnan+1))), invert=True)]
        # first and last values of x cannot be peaks
        if ind.size and ind[0] == 0:
            ind = ind[1:]
        if ind.size and ind[-1] == x.size-1:
            ind = ind[:-1]
        # remove peaks < minimum peak height
        if ind.size and mph is not None:
            ind = ind[x[ind] >= mph]
        # remove peaks - neighbors < threshold
        if ind.size and threshold > 0:
            dx = numpy.min(numpy.vstack([x[ind]-x[ind-1], x[ind]-x[ind+1]]), axis=0)
            ind = numpy.delete(ind, numpy.where(dx < threshold)[0])
        # detect small peaks closer than minimum peak distance
        if ind.size and mpd > 1:
            ind = ind[numpy.argsort(x[ind])][::-1]  # sort ind by peak height
            idel = numpy.zeros(ind.size, dtype=bool)
            for i in range(ind.size):
                if not idel[i]:
                    # keep peaks with the same height if kpsh is True
                    idel = idel | (ind >= ind[i] - mpd) & (ind <= ind[i] + mpd) \
                        & (x[ind[i]] > x[ind] if kpsh else True)
                    idel[i] = 0  # Keep current peak
            # remove the small peaks and sort back the indices by their occurrence
            ind = numpy.sort(ind[~idel])

     
        return ind