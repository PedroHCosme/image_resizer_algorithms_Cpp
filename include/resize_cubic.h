#ifndef RESIZE_CUBIC_H
#define RESIZE_CUBIC_H

#include "resize_image_base.h"

/**
 * @brief A class for resizing images using cubic interpolation.
 */
class resize_cubic : public resize_image_base {
public:
    /**
     * @brief Resizes the given source image to the specified new dimensions using cubic interpolation.
     * 
     * @param source The original image to be resized.
     * @param new_width The desired width of the resized image.
     * @param new_height The desired height of the resized image.
     * @return cimg_library::CImg<unsigned char> The resized image.
     */
    cimg_library::CImg<unsigned char> resize(const cimg_library::CImg<unsigned char>& source, int new_width, int new_height) const override;

protected:
    /**
     * @brief Estimates the color value at a specific position in the source image using cubic interpolation.
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
     * @brief Performs cubic interpolation on a set of four points.
     * 
     * @param p Array of four points.
     * @param x The interpolation factor (0.0 to 1.0).
     * @return float The interpolated value.
     */
    float cubic_interpolate(float p[4], float x) const;

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

#endif // RESIZE_CUBIC_H