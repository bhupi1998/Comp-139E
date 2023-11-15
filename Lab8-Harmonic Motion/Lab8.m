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
%%
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
hold off;
figure
%%
%%
% subplots
title("Time-Domain Response of Damped Systems");

for index=1:4
    [displacement, time, damping] = harmonicMotion(mass,springConstant,dampRatios(index)*2*sqrt(mass*springConstant),initDispl,InitV,timeFinal,pointTime);
    S1(index)=subplot(4,1,index);
    plot(time,displacement);
    ylabel(S1,damping);
    xlabel(S1,"Time (s)");
end
%{
[displacement, time, damping] = harmonicMotion(mass,springConstant,dampRatios(2)*2*sqrt(mass*springConstant),initDispl,InitV,timeFinal,pointTime);
S2=subplot(4,1,2);
plot(time,displacement);
ylabel(S2,damping);
xlabel(S2,"Time (s)");

[displacement, time, damping] = harmonicMotion(mass,springConstant,dampRatios(3)*2*sqrt(mass*springConstant),initDispl,InitV,timeFinal,pointTime);
S3=subplot(4,1,3);
plot(time,displacement);
ylabel(S3,damping);
xlabel(S3,"Time (s)");

[displacement, time, damping] = harmonicMotion(mass,springConstant,dampRatios(4)*2*sqrt(mass*springConstant),initDispl,InitV,timeFinal,pointTime);
S4=subplot(4,1,4);
plot(time,displacement);
ylabel(S4,damping);
xlabel(S4,"Time (s)");

linkaxes([S1,S2,S3,S4],"x");
%}
sgtitle("Time-Domain Response of Damped Systems")
%%