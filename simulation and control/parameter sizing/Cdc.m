function [C] = Cdc(Qs,Lc,S,Vs,Vdc,dVdc)
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here

w = 2*pi*60;
a = inv(Vs*Vs);
b = (w*dVdc.*Vdc).^-1;
C = sqrt(S.^2 + (w*Lc*S.^2*a).^2 - 2*w*Lc*S.^2.*Qs*a)*b;
end

