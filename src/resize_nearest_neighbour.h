#ifndef RESIZE_NEAREST_NEIGHBOUR_H
#define RESIZE_NEAREST_NEIGHBOUR_H

#include "resize_image_base.h"

class resize_nearest_neighbour : public resize_image_base {
public:
    cimg_library::CImg<unsigned char> resize(const cimg_library::CImg<unsigned char>& source, int new_width, int new_height) const override;
};

#endif // RESIZE_NEAREST_NEIGHBOUR_H
