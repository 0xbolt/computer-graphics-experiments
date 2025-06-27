#pragma once

class double3 {
public:
    double x, y, z;

    double3() : x(0), y(0), z(0) { }
    double3(double x, double y, double z) : x(x), y(y), z(z) { }

    double3 operator-() const { return double3(-x, -y, -z); }
    double3 operator+(const double3& v) const {
        return double3(x + v.x, y + v.y, z + v.z);
    }
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
};
