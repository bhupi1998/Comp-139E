/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sphericalToRectangular.hpp
 * Author: bhupi
 *
 * Created on September 25, 2023, 9:47 a.m.
 */

#ifndef SPHERICALTORECTANGULAR_HPP
#define SPHERICALTORECTANGULAR_HPP

#include <cstdlib>
#include <iostream>
#include<math.h>

using namespace std;

typedef struct {
    double radius;
    double azimuth;
    double inclination;
}   SphericalCoords;

// sphericalToRectangular returns a unique, persistent array [x,y,z] 
double *sphericalToRectangular (double r, double azimuth, double inclination);

// Returns a SphericalCoords struct.. Be sure to declare one, put data in it, and return it!
SphericalCoords rectangularToSpherical (double x, double y, double z ); // doesn't use the z. call as rectangularToSpherical(2.0,56)
// third parameter is a default value;
#endif /* SPHERICALTORECTANGULAR_HPP */

