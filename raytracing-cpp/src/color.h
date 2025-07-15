#pragma once

#include <iostream>
#include "double3.h"

using Color = double3;

/**
 * @brief Writes a color to an output stream in PPM format
 *
 * Converts a color from normalized RGB values (0.0-1.0) to 8-bit RGB values (0-255)
 * and writes them to the specified output stream in PPM format.
 *
 * @param os The output stream to write to (e.g., std::cout)
 * @param color The color to write, represented as a double3 with RGB values in range [0.0, 1.0]
 *
 * @note The function uses a scaling factor of 255.999 to ensure proper rounding
 *       and avoid potential overflow issues when converting to integers.
 * @note Output format: "R G B\n" where R, G, B are integers in range [0, 255]
 */
void write_color(std::ostream& os, const Color& color) {
    auto r = color.x;
    auto g = color.y;
    auto b = color.z;

    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);

    os << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}
