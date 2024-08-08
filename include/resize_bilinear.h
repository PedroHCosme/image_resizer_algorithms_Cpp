#ifndef RESIZE_BILINEAR_H
#define RESIZE_BILINEAR_H

#include "resize_image_base.h"

/**
 * @class resize_bilinear
 * @brief Class for resizing images using bilinear interpolation.
 * 
 * This class inherits from the resize_image_base and implements the resize method
 * using bilinear interpolation to achieve smoother resizing results compared to
 * nearest neighbour interpolation.
 */
class resize_bilinear : public resize_image_base {
public:
    /**
     * @brief Resizes the given source image to the specified new dimensions using bilinear interpolation.
     * 
     * @param source The original image to be resized.
     * @param new_width The desired width of the resized image.
     * @param new_height The desired height of the resized image.
     * @return cimg_library::CImg<unsigned char> The resized image.
     */
    cimg_library::CImg<unsigned char> resize(const cimg_library::CImg<unsigned char>& source, int new_width, int new_height) const override;

protected:
    /**
     * @brief Estimates the color value at a specific position in the source image using bilinear interpolation.
     * 
     * @param source The original image.
     * @param x The x-coordinate of the position.
     * @param y The y-coordinate of the position.
     * @param channel The color channel to estimate.
     * @return unsigned char The estimated color value.
     */
    unsigned char estimate_color(const cimg_library::CImg<unsigned char>& source, float x, float y, int channel) const override;

private:
    /**
     * @brief Interpolates between two values.
     * 
     * @param start The starting value.
     * @param end The ending value.
     * @param factor The interpolation factor (0.0 to 1.0).
     * @return float The interpolated value.
     */
    float interpolate(float start, float end, float factor) const;
};

#endif // RESIZE_BILINEAR_H
