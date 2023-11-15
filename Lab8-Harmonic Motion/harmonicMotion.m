function [x,t,damping] = harmonicMotionArgumentValidation (m, k, b, x0, v0, tN, N)
% harmonicMotion
%    [x,t,damping] = harmonicMotion (m, k, b, x0, v0, tN, N)
%    computes the displacement x of a damped harmonic oscillator where
%    m  = mass
%    k  = spring constant
%    b  = damping coefficient
%    x0 = initial displacement
%    v0 = initial velocity
%    tN = final time (initial time = 0)
%    N  = number of points in time
%    x  = displacement
%    t  = time values for each x
%    damping = a string containing 'undamped', 'underdamped', 'critical', or 'overdamped'

% Dale Shpak
% November 13, 2021

arguments
    m  (1,1) {mustBePositive}
    k  (1,1) {mustBeNonnegative}
    b  (1,1) {mustBeNonnegative}
    x0 (1,1) {mustBeReal}
    v0 (1,1) {mustBeReal}
    tN (1,1) {mustBePositive}
    N  (1,1) {mustBePositive,mustBeInteger}
end
nPoints=floor(tN/N); %t increments
t = linspace(0, tN, N);
if b==0 %no damping coefficient therefore it's undamped
    damping = "Undamped";
    naturalFrequency = sqrt(k/m);
    A=x0; %0
    B=v0/naturalFrequency; %3
    % x needs to be a vector. FIGURE OUT LATER
    x = A*cos(naturalFrequency.*t)+B*sin(naturalFrequency.*t);
else %damped
    dampRatio=b/(2*sqrt(m*k));
    naturalFrequency=sqrt(k/m);
    dampedFrequency = naturalFrequency*sqrt(1+dampRatio*dampRatio);
    if dampRatio<1 %underdamped
    damping="Underdamped";
    A=x0;
    B=(dampRatio*naturalFrequency*x0+v0)/dampedFrequency;
    % x needs to be a vector. FIGURE OUT LATER
    x=exp(-dampRatio*naturalFrequency.*t).*(A*cos(dampedFrequency.*t)+B*sin(dampedFrequency.*t));
    elseif dampRatio == 1 %critically damped
    damping="Critically Damped";
    A=x0;
    B=naturalFrequency*x0+v0;
    % x needs to be a vector. FIGURE OUT LATER. t needs to be declared as
    % well
    x=exp(-naturalFrequency.*t).*(A+B.*t);
    elseif dampRatio>1 %overdamped
    damping="Overdamped";
    gamma1=naturalFrequency*(-dampRatio+sqrt(dampRatio*dampRatio-1));
    gamma2=naturalFrequency*(-dampRatio-sqrt(dampRatio*dampRatio-1));
    B=-(gamma1*x0-v0)/(gamma2-gamma1);
    A=x0-B;
    x=A*exp(gamma1*t)+B*exp(gamma2*t);
    end

end

