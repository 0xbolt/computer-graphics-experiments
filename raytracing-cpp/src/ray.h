#pragma once

#include "double3.h"

class Ray {
public:
    double3 orig;
    double3 dir;

    Ray() { }
    Ray(const double3& origin, const double3& direction) : orig(origin), dir(direction) { }

    double3 at(double t) const {
        return orig + t * dir;
    }
};
