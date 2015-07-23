function [V] = Vc(Qs,Lc,S,Vs)
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here

w = 2*pi*60;
V = sqrt(Vs*Vs + (w*Lc*S/Vs).^2 - 2*w*Lc*Qs);

end

