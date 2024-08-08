#include "CImg.h"
#include "resize_nearest_neighbour.h"
#include "resize_bilinear.h"
#include "resize_cubic.h"
#include <sstream>
#include <iostream>
#include <vector>    // For std::vector
#include <cstddef>   // For size_t

using namespace cimg_library;

void resize_and_save(const resize_image_base& resizer, const CImg<unsigned char>& image, float scale_factor, const std::string& method, const std::string& extension) {
    int new_width = static_cast<int>(image.width() * scale_factor);
    int new_height = static_cast<int>(image.height() * scale_factor);

    CImg<unsigned char> resized_image = resizer.resize(image, new_width, new_height);

    std::ostringstream output_filename;
    output_filename << "build/lenna_resized_" << method << "_" << scale_factor << extension;

    resized_image.save(output_filename.str().c_str());

    std::cout << "Image resized using " << method << " to " << scale_factor * 100 << "% and saved to " << output_filename.str() << std::endl;
    std::cout << "New dimensions: " << resized_image.width() << "x" << resized_image.height() << std::endl;
}

int main() {
    const std::vector<std::string> image_paths = {
        "src/lenna.png",
        "src/lenna.bmp",
        "src/lenna.jpg",
        "src/lenna.jp2"
    };

    const std::vector<std::string> extensions = {
        ".png",
        ".bmp",
        ".jpg",
        ".jp2"
    };

    resize_nearest_neighbour nearest_neighbour_resizer;
    resize_bilinear bilinear_resizer;
    resize_cubic cubic_resizer;

    float scale_factors[] = {0.5, 0.75, 1.5, 2.0};

    for (size_t i = 0; i < image_paths.size(); ++i) {
        try {
            CImg<unsigned char> image(image_paths[i].c_str());
            for (float scale_factor : scale_factors) {
                resize_and_save(nearest_neighbour_resizer, image, scale_factor, "nearest", extensions[i]);
                resize_and_save(bilinear_resizer, image, scale_factor, "bilinear", extensions[i]);
                resize_and_save(cubic_resizer, image, scale_factor, "cubic", extensions[i]);
            }
        } catch (const cimg_library::CImgIOException& e) {
            std::cerr << "Failed to open or process file: " << image_paths[i] << std::endl;
        }
    }

    return 0;
}
