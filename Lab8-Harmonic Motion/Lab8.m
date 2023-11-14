mass=1;
springConstant=4;
dampingCoeff=1;
initDispl=2;
InitV=-2;
timeFinal=10;
pointTime=100;
dampRatios = [0,0.2,1,2];

dampeningNames= string.empty;

% overlayed
for index = 1:1:4
    [displacement, time, damping] = harmonicMotion(mass,springConstant,dampRatios(index)*2*sqrt(mass*springConstant),initDispl,InitV,timeFinal,pointTime);
    plot(time,displacement);
    title("Time-Domain Response of Damped Systems");
    xlabel("Time(s)");
    ylabel("Displacement");
    dampeningNames(index)=damping;
    hold on;
end
legend(dampeningNames(1),dampeningNames(2),dampeningNames(3),dampeningNames(4))

% subplots