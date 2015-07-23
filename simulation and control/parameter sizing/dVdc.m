function [C] = dVdc(Qs,Lc,S,Vs,Vdc,C)
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here

w = 2*pi*60;
a = inv(Vs*Vs);
b = (w*C.*Vdc).^-1;
dVdc = sqrt(S.^2 + (w*Lc*S.^2*a).^2 - 2*w*Lc*S.^2.*Qs*a)*b;
end

