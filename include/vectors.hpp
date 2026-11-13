#pragma once

#include <cmath>
#include <string>
#include <format>
#include <algorithm>

template<std::floating_point T>
class three_dim_vector {
    private:

    T x_1, x_2;
    T y_1, y_2;
    T z_1, z_2;

    public:

    three_dim_vector(T x1, T x2, T y1, T y2, T z1, T z2):
        x_1(x1), x_2(x2), y_1(y1), y_2(y2), z_1(z1), z_2(z2)
    {}
        
    [[nodiscard]]
    T magnitude() const {
        return std::sqrt( delta_x()*delta_x() + delta_y()*delta_y() + delta_z()*delta_z() );
    }

    [[nodiscard]]
    T delta_x() const {return x_2 - x_1; }

    [[nodiscard]]
    T delta_y() const {return y_2 - y_1; }

    [[nodiscard]]
    T delta_z() const {return z_2 - z_1; }

    [[nodiscard]]
    std::string denote() const {
        return std::format("{{{}, {}, {}}}", delta_x(), delta_y(), delta_z());
    }

    void set_start(T x, T y, T z) {
        x_1 = x;
        y_1 = y;
        z_1 = z;
    }

    void set_end(T x, T y, T z) {
        x_2 = x;
        y_2 = y;
        z_2 = z;
    }

    void multiply(T factor) {
        set_end(x_1 + factor*delta_x(), y_1 + factor*delta_y(), z_1 + factor*delta_z());
    }
};

template<std::floating_point T>
const T scalar_product(three_dim_vector<T>& vec1, three_dim_vector<T>& vec2) {
    return vec1.delta_x()*vec2.delta_x() + vec1.delta_y()*vec2.delta_y() + vec1.delta_z() * vec2.delta_z();
}

template<std::floating_point T>
const T angle(three_dim_vector<T>& vec1, three_dim_vector<T>& vec2) {
    return std::acos(
        std::clamp(
            scalar_product(vec1, vec2) / vec1.magnitude() / vec2.magnitude(),
            static_cast<T>(-1.0),
            static_cast<T>(1.0)
        )
    );
}