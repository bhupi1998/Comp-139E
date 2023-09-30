/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "sphericalToRectangular.hpp"


// sphericalToRectangular returns a unique, persistent array [x,y,z] 

double *sphericalToRectangular(double r, double azimuth, double inclination) {
    double x = r * sin(inclination) * cos(azimuth);
    double y = r * sin(inclination) * sin(azimuth);
    double z = r * sin(inclination);
    double *cartesianArray = (double*) malloc(3 * sizeof (double));
    cartesianArray[0] = x;
    cartesianArray[1] = y;
    cartesianArray[2] = z;
    return cartesianArray;
}

// Returns a SphericalCoords struct.. Be sure to declare one, put data in it, and return it!

SphericalCoords rectangularToSpherical(double x, double y, double z) {// doesn't use the z. call as rectangularToSpherical(2.0,56)
    SphericalCoords sphericalCoordinates = {};
    sphericalCoordinates.radius = getRadius(x, y, z);
    if (z > 0) {
        sphericalCoordinates.inclination = atan(sqrt(x * x + y * y) / z);
    } else if (z < 0) {
        sphericalCoordinates.inclination = M_PI + atan(sqrt(x * x + y * y) / z);
    } else if (z = 0 && x * y != 0) {
        sphericalCoordinates.inclination = M_PI;
    } else if (x == 0 && y == 0 && z == 0) {
        sphericalCoordinates.inclination = NULL;
    }
    return sphericalCoordinates;

}