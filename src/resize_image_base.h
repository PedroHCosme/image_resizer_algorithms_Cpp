#ifndef RESIZE_IMAGE_BASE_H
#define RESIZE_IMAGE_BASE_H

#include "CImg.h"

class resize_image_base {
public:
    virtual ~resize_image_base() = default;
    virtual cimg_library::CImg<unsigned char> resize(const cimg_library::CImg<unsigned char>& source, int new_width, int new_height) const = 0;
};

#endif // RESIZE_IMAGE_BASE_H
