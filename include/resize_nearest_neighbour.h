#ifndef RESIZE_NEAREST_NEIGHBOUR_H
#define RESIZE_NEAREST_NEIGHBOUR_H

#include "resize_image_base.h"

/**
 * @brief Class for resizing images using nearest neighbour interpolation.
 * 
 * This class inherits from the resize_image_base and implements the resize method
 * using nearest neighbour interpolation, which is a simple and fast resizing technique.
 */
class resize_nearest_neighbour : public resize_image_base {
public:
    /**
     * @brief Resizes the given source image to the specified new dimensions using nearest neighbour interpolation.
     * 
     * @param source The original image to be resized.
     * @param new_width The desired width of the resized image.
     * @param new_height The desired height of the resized image.
     * @return cimg_library::CImg<unsigned char> The resized image.
     */
    cimg_library::CImg<unsigned char> resize(const cimg_library::CImg<unsigned char>& source, int new_width, int new_height) const override;
};

#endif // RESIZE_NEAREST_NEIGHBOUR_H
