/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PID_Controller.hpp
 * Author: bhupi
 *
 * Created on October 9, 2023, 4:54 p.m.
 */

#ifndef PID_CONTROLLER_HPP
#define PID_CONTROLLER_HPP

#include "Controller.hpp"

class PID_Controller: public Controller{
private: //initialize as 0
    const double kc;
    const double ti ;
    const double td;
    double q=0; // current value of integral
    double prevy=0; // previous y
public:
    PID_Controller(double c, double i, double d){
        kc = c;
        ti = i;
        td = d;
    }
    double controlStep(double plantOutput, double setpoint);
};

#endif /* PID_CONTROLLER_HPP */

