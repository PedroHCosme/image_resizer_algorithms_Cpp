#include "resize_cubic.h"
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace cimg_library;

cimg_library::CImg<unsigned char> resize_cubic::resize(const cimg_library::CImg<unsigned char>& source, int new_width, int new_height) const {
    cimg_library::CImg<unsigned char> result(new_width, new_height, 1, source.spectrum(), 0);
    float x_ratio = static_cast<float>(source.width()) / new_width;
    float y_ratio = static_cast<float>(source.height()) / new_height;

    for (int y = 0; y < new_height; ++y) {
        for (int x = 0; x < new_width; ++x) {
            for (int c = 0; c < source.spectrum(); ++c) {
                float src_x = x * x_ratio;
                float src_y = y * y_ratio;
                result(x, y, 0, c) = estimate_color(source, src_x, src_y, c);
            }
        }
    }

    return result;
}

unsigned char resize_cubic::estimate_color(const cimg_library::CImg<unsigned char>& source, float x, float y, int channel) const {
    int x1 = static_cast<int>(x);
    int y1 = static_cast<int>(y);

    // Get 4x4 neighborhood for cubic interpolation
    std::vector<unsigned char> neighborhood = get_neighborhood(source, x1, y1, 4, channel);

    float x_frac = x - x1;
    float y_frac = y - y1;

    float col[4];
    for (int i = 0; i < 4; ++i) {
        float p[4] = {
            neighborhood[i * 4 + 0],
            neighborhood[i * 4 + 1],
            neighborhood[i * 4 + 2],
            neighborhood[i * 4 + 3]
        };
        col[i] = cubic_interpolate(p, x_frac);
    }

    float result = cubic_interpolate(col, y_frac);
    std::cout << "Cubic estimate color at (" << x << ", " << y << ") in channel " << channel << std::endl;
    return std::clamp(result, 0.0f, 255.0f);
}

float resize_cubic::cubic_interpolate(float p[4], float x) const {
    return p[1] + 0.5 * x*(p[2] - p[0] + x*(2.0*p[0] - 5.0*p[1] + 4.0*p[2] - p[3] + x*(3.0*(p[1] - p[2]) + p[3] - p[0])));
}

float resize_cubic::interpolate(float start, float end, float factor) const {
    return start + factor * (end - start);
}
