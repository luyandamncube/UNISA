%{ 
    Try sourcing this file. So in the  cmed line: 
    1. octave
    2. source('003_fn_area_vol.m')
    3. [Area,Vol] = fn_cal_area_vol(2)
%}

function [A,V] = fn_cal_area_vol(r)
    % r is the radius of a sphere
    % A is the surface area of a sphere
    % V is the volume of a sphere
    
    A = 4*pi*r^2;
    V = 4/3*pi*r^3;
end