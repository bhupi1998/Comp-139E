/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "sphericalToRectangular.hpp"

// sphericalToRectangular returns a unique, persistent array [x,y,z] 
double *sphericalToRectangular(double r, double azimuth, double inclination);

// Returns a SphericalCoords struct.. Be sure to declare one, put data in it, and return it!

SphericalCoords rectangularToSpherical(double x, double y, double z = 0) {// doesn't use the z. call as rectangularToSpherical(2.0,56)
    SphericalCoords sphericalCoordinates = {};
    sphericalCoordinates.radius = sqrt(x * x + y * y + z * z);
    if (z > 0) {
        sphericalCoordinates.inclination = atan2(sqrt(x * x + y * y) / z);
    } else if (z < 0) {
        sphericalCoordinates.inclination = M_PI + atan2(sqrt(x * x + y * y) / z);
    } else if (z = 0 && x * y != 0) {
        sphericalCoordinates.inclination = M_PI;
    } else if (x == 0 && y == 0 && z == 0) {
        sphericalCoordinates.inclination = NULL;
    }
    return sphericalCoordinates;

}