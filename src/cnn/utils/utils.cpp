#include "utils.h"
#include "shape.h"

namespace cnn::utils
    {

        int get_top_padding(shape3d_t const& input_shape,
                            shape3d_t const& filter_shape,
                            size_t stride)
        {
            int padding{ 0 };

            if (input_shape.y() % stride == 0)
            {
                padding = filter_shape.y() - stride;
            }
            else
            {
                padding = filter_shape.y() - (input_shape.y() % stride);
            }

            if (padding < 0) { padding = 0; }

            return padding / 2;
        }

        int get_left_passing(shape3d_t const& input_shape,
                             shape3d_t const& filter_shape,
                             size_t stride)
        {
            int padding{ 0 };

            if (input_shape.x() % stride == 0)
            {
                padding = filter_shape.x() - stride;
            }
            else
            {
                padding = filter_shape.x() - (input_shape.x() % stride);
            }

            if (padding < 0) { padding = 0; }

            return padding / 2;
        }
    }