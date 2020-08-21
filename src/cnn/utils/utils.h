#pragma once

#include <cstddef>

namespace cnn {
    struct shape3d_t;
    namespace utils {
        int get_top_padding(shape3d_t const &input_shape,
                            shape3d_t const &filter_shape,
                            size_t stride);

        int get_left_padding(shape3d_t const &input_shape,
                             shape3d_t const &filter_shape,
                             size_t stride);

    }
}