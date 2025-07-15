#include <iostream>
#include "double3.h"
#include "color.h"
#include "ray.h"


double hit_sphere(double3& center, double radius, const Ray& r) {
    double a = dot(r.dir, r.dir);
    double b = -2.0f * dot(center - r.orig, r.dir);
    double c = dot(center - r.orig, center - r.orig) - radius * radius;

    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return -1;
    }
    return -(b + std::sqrt(discriminant)) / (2 * a);
}

Color ray_color(const Ray& r) {
    double3 unit_dir = r.dir.normalized();

    auto sphere_center = double3(0, 0, -2);
    auto sphere_radius = 0.5;
    auto t = hit_sphere(sphere_center, 1, r);
    if (t >= 0) {
        double3 normal = r.at(t) - sphere_center;
        return 0.5 * normal + 0.5 * Color(1, 1, 1);
    }

    auto a = 0.5 * (unit_dir.y + 1.0);
    return (1 - a) * Color(1, 1, 1) + a * Color(0.5, 0.7, 1.0);
}


int main() {
    auto aspect_ratio = 16.0 / 9.0;

    int image_width = 400;
    int image_height = int(image_width / aspect_ratio);
    // Make sure image_height >= 1
    image_height = image_height < 1 ? 1 : image_height;

    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(image_width) / image_height);
    auto camera_center = double3(0, 0, 0);

    auto viewport_u = double3(viewport_width, 0, 0);
    auto viewport_v = double3(0, -viewport_height, 0);

    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;

    auto viewport_upper_left = camera_center - double3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray = Ray(camera_center, pixel_center - camera_center);
            auto pixel_color = ray_color(ray);
            write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\rDone.                    \n";
    return 0;
}
