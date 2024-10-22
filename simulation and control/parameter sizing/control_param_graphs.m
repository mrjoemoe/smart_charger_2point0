%Vdc Min Plot

close all

L = [0.1e-3;0.05e-3;3e-3];

hold off
plot(L,sqrt(2)*Vc(3.3e3,L,3.3e3,120),'blue');
hold on
plot(L,sqrt(2)*Vc(1.65e3,L,3.3e3,120),'cyan');
plot(L,sqrt(2)*Vc(0e3,L,3.3e3,120),'red');
plot(L,sqrt(2)*Vc(-1.65e3,L,3.3e3,120),'magenta');
plot(L,sqrt(2)*Vc(-3.3e3,L,3.3e3,120),'green');
legend('Q = 3.3 kVA' , 'Q = 1.65 kVA' , 'Q = 0 kVA' , ...
'Q = -1.65 kVA' ,'Q = -3.3 kVA');
title('Vdc min vs Coupling Inductor');
xlabel('Coupling Inductor Size (H)');
ylabel('Min Vdc (V)');

%Cdc vs Vdc & dVdc (Lc = 1mH , Qs = -3.3 kVAR , S = 3.3 KVA)
Vdc = [220:1:450];

figure
hold off
plot(Vdc,Cdc(-3.3e3,1.5e-3,3e3,120,Vdc,10),'blue');
hold on
plot(Vdc,Cdc(-3.3e3,1.5e-3,3e3,120,Vdc,20),'cyan');
plot(Vdc,Cdc(-3.3e3,1.5e-3,3e3,120,Vdc,30),'red');
plot(Vdc,Cdc(-3.3e3,1.5e-3,3e3,120,Vdc,40),'magenta');
plot(Vdc,Cdc(-3.3e3,1.5e-3,3e3,120,Vdc,50),'green');
plot(Vdc,Cdc(-3.3e3,1.5e-3,3e3,120,Vdc,60),'black');
plot(Vdc,Cdc(-3.3e3,1.5e-3,3e3,120,Vdc,70),'yellow');
legend('dVdc = 10V' , 'dVdc = 20V' , 'dVdc = 30V' , ...
    'dVdc = 40V' , 'dVdc = 50V' , 'dVdc = 60V' , 'dVdc = 70V' );
title('DC Link Capacitor Size vs. DC Link Voltage');
xlabel('DC Link Voltage (V)');
ylabel('DC Link Capacitor (F)');

%Capacitor Current Vs Coupling Inductor Size for various Vdc
figure
hold off
plot(L,Icap(-3e3,L,3e3,120,250),'blue');
hold on
plot(L,Icap(-3e3,L,3e3,120,300),'cyan');
plot(L,Icap(-3e3,L,3e3,120,350),'red');
plot(L,Icap(-3e3,L,3e3,120,375),'magenta');
plot(L,Icap(-3e3,L,3e3,120,400),'green');
plot(L,Icap(-3e3,L,3e3,120,425),'black');
plot(L,Icap(-3e3,L,3e3,120,450),'yellow');
legend('Vdc = 250V' , 'Vdc = 300V' , 'Vdc = 350V' , ...
    'Vdc = 375V' , 'Vdc = 400V' , 'Vdc = 425V' , 'Vdc = 450V');
title('Capacitor Current vs. Coupling Inductor Size');
xlabel('Coupling Inductor Size (H)');
ylabel('DC Link Capacitor Current(I)');

Qvar = [-3.3e3 ; 1 ; 3.3e3];


% dVdc for various Q values
figure
hold off
plot(Qvar,dVdc(Qvar,1e-3,3e3,120,260,2e-3),'blue');
hold on
plot(Qvar,dVdc(Qvar,1e-3,3e3,120,290,2e-3),'cyan');
plot(Qvar,dVdc(Qvar,1e-3,3e3,120,320,2e-3),'red');
plot(Qvar,dVdc(Qvar,1e-3,3e3,120,350,2e-3),'magenta');
plot(Qvar,dVdc(Qvar,1e-3,3e3,120,380,2e-3),'green');
plot(Qvar,dVdc(Qvar,1e-3,3e3,120,410,2e-3),'black');
plot(Qvar,dVdc(Qvar,1e-3,3e3,120,440,2e-3),'yellow');
legend('Vdc = 260V' , 'Vdc = 290V' , 'Vdc = 320V' , ...
    'Vdc = 350V' , 'dVdc = 380V' , 'dVdc = 410V' , ...
    'dVdc = 440V');
title('DC Link Voltage Ripple vs. Reactive Power');
xlabel('Reactive Power (VARs)');
ylabel('DC Link Voltage Ripple (Vpp)');













