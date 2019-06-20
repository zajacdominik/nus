%INICJALIZACJA
% Wpisac "s" w komendach by zobaczyc stan
% 
s=serial('/dev/ttyUSB0');
s.BaudRate=115200;
fopen(s);

