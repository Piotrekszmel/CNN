#include "src/cnn/utils/shape.h"
#include <iomanip>
#include <iostream>

int main() {

    cnn::shape3d_t shape{};
    std::cout << shape.x() << ' ' << shape.y() << ' ' << shape.z() << '\n';
    return 0;
}
