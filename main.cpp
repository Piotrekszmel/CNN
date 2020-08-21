#include "src/cnn/utils/shape.h"
#include <iomanip>
#include <iostream>

int main() {

    cnn::index3d_t start{ 1, 1, 1 };
    cnn::index3d_t end{ 4, 4, 4 };
    cnn::index3d_t step{ 1, 1, 1 };

    cnn::index3d_iterator it{start, end, step};

    ++it;
    ++it;
    ++it;
    ++it;
    ++it;
    ++it;
    ++it;

    return 0;
}
