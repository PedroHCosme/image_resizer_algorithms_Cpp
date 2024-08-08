#ifndef RESIZE_CUBIC_H
#define RESIZE_CUBIC_H

#include "resize_image_base.h"

class resize_cubic : public resize_image_base {
public:
    cimg_library::CImg<unsigned char> resize(const cimg_library::CImg<unsigned char>& source, int new_width, int new_height) const override;

protected:
    unsigned char estimate_color(const cimg_library::CImg<unsigned char>& source, float x, float y, int channel) const override;

private:
    float cubic_interpolate(float p[4], float x) const;
    float interpolate(float start, float end, float factor) const;
};

#endif // RESIZE_CUBIC_H
