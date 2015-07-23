function [I] = Icap(Qs,Lc,S,Vs,Vdc)
%UNTITLED6 Summary of this function goes here
%   Detailed explanation goes here

w = 2*pi*60;
a = w*Lc.*S^.2.*Vs.^0.5;
I = sqrt(S.^2 + a.^2 - 2.*a.*Qs)/sqrt(2)/Vdc;

end

