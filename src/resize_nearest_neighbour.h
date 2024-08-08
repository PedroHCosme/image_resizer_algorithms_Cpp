#ifndef RESIZE_NEAREST_NEIGHBOUR_H
#define RESIZE_NEAREST_NEIGHBOUR_H

#include "CImg.h"

class resize_nearest_neighbour {
public:
    static cimg_library::CImg<unsigned char> resize(const cimg_library::CImg<unsigned char>& source, int new_width, int new_height);
};

#endif // RESIZE_NEAREST_NEIGHBOUR_H
