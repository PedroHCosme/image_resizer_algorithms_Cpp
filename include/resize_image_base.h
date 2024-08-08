#ifndef RESIZE_IMAGE_BASE_H
#define RESIZE_IMAGE_BASE_H

#include "CImg.h"
#include <vector>

/**
 * @brief Abstract base class for image resizing.
 * 
 * This class provides an interface for resizing images. Derived classes must implement
 * the resize method to provide specific resizing algorithms.
 */
class resize_image_base {
public:
    /**
     * @brief Virtual destructor for the base class.
     * 
     * Ensures proper cleanup of derived class objects.
     */
    virtual ~resize_image_base() = default;

    /**
     * @brief Pure virtual method to resize an image.
     * 
     * Derived classes must implement this method to resize the given source image
     * to the specified new dimensions.
     * 
     * @param source The original image to be resized.
     * @param new_width The desired width of the resized image.
     * @param new_height The desired height of the resized image.
     * @return cimg_library::CImg<unsigned char> The resized image.
     */
    virtual cimg_library::CImg<unsigned char> resize(const cimg_library::CImg<unsigned char>& source, int new_width, int new_height) const = 0;

protected:
    /**
     * @brief Pure virtual method to estimate the color of a pixel.
     * 
     * Derived classes must implement this method to estimate the color of a pixel
     * at a given position (x, y) and channel.
     * 
     * @param source The source image.
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     * @param channel The color channel.
     * @return unsigned char The estimated color value.
     */
    virtual unsigned char estimate_color(const cimg_library::CImg<unsigned char>& source, float x, float y, int channel) const = 0;

    /**
     * @brief Utility function to clamp values to the image boundaries.
     * 
     * Ensures that the value is within the specified minimum and maximum bounds.
     * 
     * @param value The value to be clamped.
     * @param min The minimum bound.
     * @param max The maximum bound.
     * @return int The clamped value.
     */
    int clamp(int value, int min, int max) const {
        return std::max(min, std::min(value, max));
    }

    /**
     * @brief Utility function to get the neighborhood of pixels of any size.
     * 
     * Retrieves a vector of pixel values from the source image around the specified
     * (x, y) coordinates, within the given neighborhood size and color channel.
     * 
     * @param source The source image.
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     * @param size The size of the neighborhood.
     * @param channel The color channel.
     * @return std::vector<unsigned char> The neighborhood pixel values.
     */
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
