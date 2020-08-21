#pragma once

#include <array>
#include <cassert>

namespace cnn {

#define DIM(start, end, step) (((end) - (start))/(step) + 1)

    enum struct dim_type {
        X = 0,
        Y = 1,
        Z = 2
    };

    template<typename T>
    struct point3d_t {
    public:
        point3d_t() = default;

        point3d_t(T x, T y, T z)
                : v_({x, y, z}) {}

        point3d_t(std::array<T, 3> const& v)
            : v_(v) {}

        point3d_t(point3d_t const& other)
            : v_(other.v_) {}

    public:
        T& x() { return v_[0]; }
        T& y() { return v_[1]; }
        T& z() { return v_[2]; }
        T const& x() const { return v_[0]; }
        T const& y() const { return v_[1]; }
        T const& z() const { return v_[2]; }
        std::array<T, 3>& data() { return v_; }
        std::array<T, 3> const& data() const { return v_; }

    public:
        inline T v(dim_type d) const { return v_[(size_t)d]; }

    public:
        inline bool operator==(const point3d_t& other) const
        {
            return (v_[0] == other.v_[0]) &&
                    (v_[1] == other.v_[1]) &&
                    (v_[2] == other.v_[2]);
        }

        inline bool operator!=(const point3d_t& other) const
        {
            return !this->operator==(other);
        }

    protected:
        std::array<T, 3> v_;
    };

}