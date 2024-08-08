#include "resize_nearest_neighbour.h"
#include <algorithm>
#include <cmath>

using namespace cimg_library;

cimg_library::CImg<unsigned char> resize_nearest_neighbour::resize(const cimg_library::CImg<unsigned char>& source, int new_width, int new_height) const {
    cimg_library::CImg<unsigned char> result(new_width, new_height, 1, source.spectrum(), 0);
    float x_ratio = static_cast<float>(source.width()) / new_width;
    float y_ratio = static_cast<float>(source.height()) / new_height;

    for (int y = 0; y < new_height; ++y) {
        for (int x = 0; x < new_width; ++x) {
            for (int c = 0; c < source.spectrum(); ++c) {
                int src_x = static_cast<int>(round(x * x_ratio));
                int src_y = static_cast<int>(round(y * y_ratio));
                src_x = std::max(0, std::min(src_x, source.width() - 1));
                src_y = std::max(0, std::min(src_y, source.height() - 1));
                result(x, y, 0, c) = source(src_x, src_y, 0, c);
            }
        }
    }

    return result;
}
