Ts = 5e-5;

% prepare transfer function variables
n1 = 0;
n0 = 1;
d1 = 0.01;
d0 = 1;

% create transfer function
numc = [n1 n0];
denc = [d1 d0];
filter = tf(numc,denc);

% convert continuous model to discrete
[Ac,Bc,Cc,Dc] = tf2ss(numc , denc);
nstates = size(Ac,1);
invexp = inv(eye(nstates) - (Ts/2)*Ac);
Ad = invexp*(eye(nstates) + (Ts/2)*Ac);
Bd = invexp*Bc;
Cd = Cc*invexp*Ts;
Dd = Cc*invexp*Bc*(Ts/2) + Dc;