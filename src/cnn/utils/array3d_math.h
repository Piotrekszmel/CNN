#pragma once

#include <exception>
#include <cmath>

#include "array3d.h"
#include "shape.h"

namespace cnn
{
    template<typename T>
    T sigmoid(T x)
    {
        return T(1.0) / (T(1.0) + exp(-x));
    }

    template<typename T>
    T sigmoid_derivative(T x)
    {
        T sigmoid_x{ sigmoid(x) };
        return sigmoid_x * (T(1.0) - sigmoid_x);
    }

    template<typename T>
    T relu(T x)
    {
        return x < T(0.0) ? 0 : x;
    }

    template<typename T>
    array3d_t<T> sigmoid_v(const array3d_t<T>& x)
    {
        array3d_t<T> result(x);
        result.apply(sigmoid<T>);
        return result;
    }

    template<typename T>
    array3d_t<T> stable_softmax_v(const array3d_t<T>& x)
    {
        array3d_t<T> result(x);
        const int size = static_cast<int>(result.size());
        T x_max = x.max();

        T sum{ 0.0 };
        for (int i = 0; i < size; ++i)
        {
            T fi = exp(x(i) - x_max);
            result(i) = fi;
            sum+= fi;
        }

        for (int i = 0; i < size; ++i)
        {
            result(i) /= sum;
        }

        return result;
    }

    template<typename T>
    array3d_t<T> relu_v(const array3d_t<T> &x)
    {
        array3d_t<T> result(x);
        result.apply(relu<T>);
        return result;
    }








}