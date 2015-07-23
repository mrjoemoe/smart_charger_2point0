

% Power Plot
hold off
[ax,h1,h2] = plotyy(power_vdc_1.time, power_vdc_1.signals(1,1).values, ...
    power_vdc_1.time, power_vdc_1.signals(1,2).values);

set(ax(1),'YLim',[-500 4000]);
set(ax(2),'YLim',[-4000 1500]);
set(h1,'color','blue');
set(h2,'color','red');
set(ax(1),'YTick',[-500:500:4000]);
set(ax(2),'YTick',[-4000:500:1500]);
set(ax,{'ycolor'},{'b';'r'});

legend('Active Power (W)' , 'Reactive Power (VAR)');
xlabel('time (s)');


% Battery Plot
figure
hold off

[ax,h1,h2] = plotyy(i_v_batt_1.time, i_v_batt_1.signals(1,2).values,i_v_batt_1.time, ...
    i_v_batt_1.signals(1,3).values,'plot','plot');

set(ax(1),'YLim',[60 84]);
set(ax(2),'YLim',[-50 50]);
set(h1,'color','magenta');
set(h2,'color','black');
set(ax(1),'YTick',[60:2:84]);
set(ax(2),'YTick',[-50:10:50]);
set(ax,{'ycolor'},{'magenta';'black'});

legend('Battery Voltage (V)' , 'Battery Current (A)');
xlabel('time (s)');


%AC Plot
figure
hold off

[ax,h1,h2] = plotyy(i_v_ac_1.time([290000 : 300001]) , ... 
    i_v_ac_1.signals(1,1).values([290000 : 300001]) , ...
    i_v_ac_1.time([290000 : 300001]) , ...
    i_v_ac_1.signals(1,2).values([290000 : 300001]) , 'plot','plot');

set(ax(1),'YLim',[-200 200]);
set(ax(2),'YLim',[-60 60]);
set(ax(1),'YTick',[-200:40:200]);
set(ax(2),'YTick',[-60:10:60]);


legend('Grid Voltage (V)' , 'Input Current (A)');
xlabel('time (s)');


% DC Bus Voltage
figure 
hold off

plot(power_vdc_1.time([600000 : 620000]), ...
    power_vdc_1.signals(1,3).values([600000 : 620000]) , 'black');
ylabel('Voltage (V)');
xlabel('time (s)');





