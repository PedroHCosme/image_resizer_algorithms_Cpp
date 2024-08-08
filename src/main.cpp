#include "CImg.h"
#include "resize_nearest_neighbour.h"
#include <sstream>
#include <iostream>

using namespace cimg_library;

int main() {
    // Load the input image
    CImg<unsigned char> image("lenna.png");

    // Create an instance of the nearest neighbor resizer
    resize_nearest_neighbour resizer;

    // Predefined scale factors
    float scale_factors[] = {0.5, 0.75, 1.5, 2.0};

    // Loop over each scale factor and resize the image
    for (float scale_factor : scale_factors) {
        // Calculate new dimensions
        int new_width = static_cast<int>(image.width() * scale_factor);
        int new_height = static_cast<int>(image.height() * scale_factor);

        // Resize the image using nearest neighbor interpolation
        CImg<unsigned char> resized_image = resizer.resize(image, new_width, new_height);

        // Construct output filename based on scale factor
        std::ostringstream output_filename;
        output_filename << "lenna_resized_" << scale_factor << ".png";

        // Save the resized image
        resized_image.save(output_filename.str().c_str());

        std::cout << "Image resized to " << scale_factor * 100 << "% and saved to " << output_filename.str() << std::endl;
        std::cout << "New dimensions: " << resized_image.width() << "x" << resized_image.height() << std::endl;
    }

    return 0;
}
