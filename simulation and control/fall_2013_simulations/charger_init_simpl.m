%System Parameters
sys_Ts = 5e-6;          % system sample time
switch_Ts = 5e-5;       % microcontroller sample time
ac_volt = 169;          % AC peak voltage
dc_volt = 250;          % DC Link Voltage
Lin = 1.0e-3;             % AC/DC input inductance
ESRLin = 0.1;           % AC/DC input inductance equivalent series resistance 
Cdc = 2e-3;             % DC link Capacitance
ESRCd = 70e-3;          % DC link Capacitnace equivalent series resistance
ESLCd = 0.1e-9;          % DC link Capacitance equivalent series inductance

Ldcdc = 1.4e-3;         % DC/DC output filter inductance
ESRLdcdc = 0.1;      % DC/DC output filter inductance equivalent series resistance
Cbatt = 1e-3;           % DC/DC output filter capacitance
ESRCb = 30e-3;          % DC/DC output filter capacitance equivalent series resistance
ESLCb = 0.1e-9;          % DC/DC output filter capacitance equivalent series inductance

pre_charge_r = 6;      %precharg resistance

Rbatt = 0.10;           % ideal battery terminal resistance
voc = 105;               % open circuit voltage of battery
w = 2*pi*60;            
Vs = ac_volt/sqrt(2);

%Active and Reactive Power Control Parameters
P = 1.92e3;
Q = 0;

%DC/DC CV and CC references
dcdc_cv_ref = voc + 3;
dcdc_cc_ref = 20;

%Power Control Turn on Times
acdc_on_time = 0;
dcdc_on = 0.4;
active_power_on = 0.4;
reactive_power_on = 1.5;

% AC/DC Converter Ramp up Parameters
Vdcmin = ac_volt + 10;
pre_charge_ramp = (dc_volt - Vdcmin)/(acdc_ramp_end_time - acdc_on_time);
ramp = (dc_volt - Vdcmin)/(acdc_ramp_end_time);

%PI Controller PI Control Value
pi_vdc_ki = 2;
pi_vdc_kp = 0.5;
pi_iac_ki = 20;
pi_iac_kp = 1;


%DQ Controller PI Control Values
dq_vdc_ki = 3.7;
dq_vdc_kp = 0.37;
dq_id_ki = 200;
dq_id_kp = 20;
dq_iq_ki = 100;
dq_iq_kp = 8;

%PR Controller PI Control Values
pr_vdc_ki = 4;
pr_vdc_kp = 0.5;
pr_pr_ki =0;% 0.010;
pr_pr_kp = 0.001;
pr_iac_kp = 2;

%DC/DC Controller PI Control Values
dcdc_iki = 1;
dcdc_ikp = 0.001;
dcdc_vki = 1; 
dcdc_vkp = 0.01;

%Power Controller PI Control Values
dqQ_ki = 15;
dqQ_kp = 0.07;
piQ_ki = 0.15;
piQ_kp = 0.01;
P_ki = 0.08;
P_kp = 0.001;


% This script initializes the state space model for the
% discrete 3rd order low pass filter

% user selected parameters
fn = 60;
fo = 200;
zeta = 0.707; % must be between 0 and 1
Ts = 5e-5;

% initialization
wn = 2*pi*60;
wo = 2*pi*fo;
phasem = atan(-2*zeta*wo*wn/(wo^2 - wn^2));
a = (1 + sin(-phasem))/(1 - sin(-phasem));
T = 1/(wn*sqrt(a));

% calculate magnitude (so that it may be inverted to provide unity gain
mag = wo^2/((wo^2 - wn^2)^2 + 4*(zeta*wn*wo)^2);
mag = mag*sqrt((wo^2 - wn^2)^2 + 4*(zeta*wn*wo)^2);
K = 1/mag;

% prepare transfer function variables
n3 = 0;
n2 = 0;
n1 = a*T*wo^2;
n0 = wo^2;
d3 = T;
d2 = 1 + 2*T*zeta*wo;
d1 = wo^2*T + 2*zeta*wo;
d0 = wo^2;

% create transfer function
numc = K*[n3 n2 n1 n0];
denc = sqrt(a)*[d3 d2 d1 d0];
filter = tf(numc,denc);

% convert continuous model to discrete
[Ac,Bc,Cc,Dc] = tf2ss(numc , denc);
nstates = size(Ac,1);
invexp = inv(eye(nstates) - (Ts/2)*Ac);
Ad = invexp*(eye(nstates) + (Ts/2)*Ac);
Bd = invexp*Bc;
Cd = Cc*invexp*Ts;
Dd = Cc*invexp*Bc*(Ts/2) + Dc;




%This is the script for the first order DC pass filter

% prepare transfer function variables
dcn1 = 0;
dcn0 = 1;
dcd1 = 0.05;
dcd0 = 1;

% create transfer function
dcnumc = [dcn1 dcn0];
dcdenc = [dcd1 dcd0];

% convert continuous model to discrete
[dcAc,dcBc,dcCc,dcDc] = tf2ss(dcnumc , dcdenc);
dcnstates = size(dcAc,1);
dcinvexp = inv(eye(dcnstates) - (Ts/2)*dcAc);
dcAd = dcinvexp*(eye(dcnstates) + (Ts/2)*dcAc);
dcBd = dcinvexp*dcBc;
dcCd = dcCc*dcinvexp*Ts;
dcDd = dcCc*dcinvexp*dcBc*(Ts/2) + dcDc;