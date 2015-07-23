%This is the script for the first order DC pass filter

Ts = 1/20000;

% prepare transfer function variables
dcn1 = 0;
dcn0 = 1;
dcd1 = 1;
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