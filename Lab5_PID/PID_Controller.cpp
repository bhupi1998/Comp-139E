/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "PID_Controller.hpp"


// Implementation of controlStep()
double PID_Controller::controlStep (const double plantOutput, double setpoint) {
    double error = setpoint - plantOutput;
    q = (0.9*q)+ (0.1*error);
    double response = setpoint + kc * (error+((1/ti)*(q))-((td)*(plantOutput- prevy)));
    prevy = plantOutput; // updating previous y value
    return response;
}
