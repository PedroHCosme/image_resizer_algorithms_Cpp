#ifndef RESIZE_IMAGE_BASE_H
#define RESIZE_IMAGE_BASE_H

#include "CImg.h"
#include <vector>

class resize_image_base {
public:
    virtual ~resize_image_base() = default;

    virtual cimg_library::CImg<unsigned char> resize(const cimg_library::CImg<unsigned char>& source, int new_width, int new_height) const = 0;

protected:
    virtual unsigned char estimate_color(const cimg_library::CImg<unsigned char>& source, float x, float y, int channel) const = 0;

    // Utility function to clamp values to the image boundaries
    int clamp(int value, int min, int max) const {
        return std::max(min, std::min(value, max));
    }

    // Utility function to get the neighborhood of pixels of any size
    std::vector<unsigned char> get_neighborhood(const cimg_library::CImg<unsigned char>& source, int x, int y, int size, int channel) const {
        std::vector<unsigned char> neighborhood;
        int half_size = size / 2;
        for (int dy = -half_size; dy <= half_size; ++dy) {
            for (int dx = -half_size; dx <= half_size; ++dx) {
                int nx = clamp(x + dx, 0, source.width() - 1);
                int ny = clamp(y + dy, 0, source.height() - 1);
                neighborhood.push_back(source(nx, ny, 0, channel));
            }
        }
        return neighborhood;
    }
};

#endif // RESIZE_IMAGE_BASE_H
