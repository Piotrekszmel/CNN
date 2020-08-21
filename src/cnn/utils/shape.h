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

    struct index3d_t : point3d_t<int> {
    public:
        index3d_t() = default;

        index3d_t(int x, int y, int z)
            : point3d_t(x, y, z) {}

        index3d_t(index3d_t const& other)
            : point3d_t(other.v_) {}

        index3d_t(std::array<int, 3> const& v)
            : point3d_t(v) {}

    public:
        inline index3d_t add(int x, int y, int z) const
        {
            return index3d_t(v_[0] + x, v_[1] + y, v_[2] + z);
        }

        inline index3d_t add(index3d_t const& other)
        {
            return index3d_t(v_[0] + other.v_[0], v_[1] + other.v_[1], v_[2] + other.v_[2]);
        }

        inline index3d_t inc(dim_type d, int a) const
        {
            std::array<int, 3> v(v_);
            v[(size_t)d] += a;
            return index3d_t(v);
        }

        inline index3d_t set(dim_type d, int a) const
        {
            std::array<int, 3> v(v_);
            v[(size_t)d] = a;
            return index3d_t(v);
        }
    };

    struct shape3d_t : point3d_t<int>
    {
    private :
        enum dim
        {
            X = 0,
            Y = 1,
            Z = 2
        };

    public:
        shape3d_t() = default;

        shape3d_t(int x, int y, int z)
            : point3d_t(x, y, z) {}

        shape3d_t(shape3d_t const& other)
            : point3d_t(other) {}

    public:
        inline size_t dim() const
        {
            return (v_[X] > 1 ? 1 : 0) +
                    (v_[Y] > 1 ? 1 : 0) +
                    (v_[Z] > 1 ? 1 : 0);
        }

        inline int capacity() const { return v_[X] * v_[Y] * v_[Z]; }

        inline int index(int x, int y, int z) const
        {
            return  x * v_[Z] * v_[Y] + y * v_[Z] + z;
        }

        inline int index(point3d_t<int> const& point) const
        {
            return index(point.x(), point.y(), point.z());
        }
    };

}