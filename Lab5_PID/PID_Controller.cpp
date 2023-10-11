/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "PID_Controller.hpp"


// Implementation of controlStep()
double pidController::controlStep (const double plantOutput, double setpoint) {
    double error = setpoint - plantOutput;
    q = q+ error;
    double response = setpoint + kc * (error+(1/ti)*(q)-(td)*(setpoint - prevy));
    prevy = setpoint; // updating previous y value
    return response;
}
