#pragma once

#include <iostream>

class double3;

inline double3 operator/(const double3& v, double t);

class double3 {
public:
    double x, y, z;

    double3() : x(0), y(0), z(0) { }
    double3(double x, double y, double z) : x(x), y(y), z(z) { }

    double3 operator-() const { return double3(-x, -y, -z); }
    double3& operator+=(const double3& v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }
    double3& operator*=(double t) {
        x *= t;
        y *= t;
        z *= t;
        return *this;
    }
    double3& operator/=(double t) {
        *this *= 1 / t;
        return *this;
    }

    double length_squared() const {
        return x * x + y * y + z * z;
    }

    double length() const {
        return std::sqrt(length_squared());
    }

    double3 normalized() const {
        return *this / length();
    }
};

inline std::ostream& operator<<(std::ostream& os, const double3& v) {
    return os << v.x << ' ' << v.y << ' ' << v.z;
}

inline double3 operator+(const double3& u, const double3& v) {
    return double3(u.x + v.x, u.y + v.y, u.z + v.z);
}

inline double3 operator-(const double3& u, const double3& v) {
    return double3(u.x - v.x, u.y - v.y, u.z - v.z);
}

inline double3 operator*(const double3& u, const double3& v) {
    return double3(u.x * v.x, u.y * v.y, u.z * v.z);
}

inline double3 operator*(double t, const double3& v) {
    return double3(t * v.x, t * v.y, t * v.z);
}

inline double3 operator*(const double3& v, double t) {
    return t * v;
}

inline double3 operator/(const double3& v, double t) {
    return v * (1 / t);
}

inline double dot(const double3& u, const double3& v) {
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

inline double3 cross(const double3& u, const double3& v) {
    return double3(
        u.y * v.z - u.z * v.y,
        u.z * v.x - u.x * v.z,
        u.x * v.y - u.y * v.x
    );
}
