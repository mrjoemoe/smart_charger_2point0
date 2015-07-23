% script to determine optimal component sizing for battery charger

% Lc: Coupling inductor
% The coupling inductor a


t = [0:4.167e-5:0.0334];






% Independant Variables
fs = 60;                    % grid frequency
S = 3.3e3;                  % apparenet power rating
Lc = 0.5e-3;                  % coupling inductor
Vs = 120;                   % source voltage RMS
Vdc_link = 350;             % dc link voltage
Vdc_rip = 20;               % dc link peak to peak ripple voltage
theta = -1;                 % power factor angle              

% Dependant Variables
ws = 2*pi*fs;               % angular frequency
Vp = sqrt(Vs);              % peak input voltage
Ic = S/Vs;                  % rms input current
rip_mag = ws*Lc*Ic*Ic;      % magnitude of ripple power component at twice grid frequency
Qs = S*sin(theta);          % reactive power rating


% Bad ass critical equations

% Power and Energy due to ripple in dc link capacitor
Prip = sqrt(S^2 + (ws*Lc*S^2/Vs^2)^2 - 2*ws*Lc*S^2*Qs/Vs^2);
beta = atan((S*sin(theta) + rip_mag*cos(2*theta))/(-S*cos(theta) + rip_mag*sin(2*theta)));
Erip = Prip/ws;



% Minimum dc link voltage calculation
Vc = sqrt(Vs^2 + (ws*Lc*S/Vs)^2 - 2*ws*Lc*Qs);
Vdc_min = sqrt(2)*Vc;

% DC Link Capacitor Value
Cdc = Erip/(Vdc_link*Vdc_rip)

% Capacitor Current Rating
Icap = sqrt(S^2 + (ws*Lc*S^2/Vs^2)^2 - 2*ws*Lc*S^2*Qs/Vs^2)/(sqrt(2)*Vdc_link);


% Plots

% Ripple Power
plot(t,Prip*cos(2*ws*t + beta));






