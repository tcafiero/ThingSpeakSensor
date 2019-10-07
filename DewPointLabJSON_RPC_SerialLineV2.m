try
s = serial('COM53','Baudrate', 115200, 'Terminator','LF');
s.InputBufferSize = 10000;
fopen(s)
fprintf(s,'{"method": "getData", "params": {"status": true} }')
txt = fgets(s)
disp(txt)
record=jsondecode(txt)

% Get humidity data from the record
humidity = record.humidity;

% Convert temperature from Fahrenheit to Celsius
tempC = record.temp;

% Calculate dew point

% Specify the constants for water vapor (b) and barometric (c) pressure.
b = 17.62;
c = 243.5;
% Calculate the intermediate value 'gamma'
gamma = log(humidity/100) + b*tempC ./ (c+tempC);

% Calculate dew point in Celsius
dewPoint = c*gamma ./ (b-gamma);

% Convert to dew point in Fahrenheit
dewPointF = (dewPoint*1.8) + 32;

display(record.time, 'time');
display(tempC, 'temp');
display(record.humidity, 'humidity');
display(dewPoint, 'dewPoint')
display(record.time, 'time');
plot(datetime(record.time,'InputFormat','dd-MM-yyyy HH:mm:ss'),tempC,'bo',datetime(record.time,'InputFormat','dd-MM-yyyy HH:mm:ss'),dewPoint,'r*');
%plot(datetime(record.time,'InputFormat','dd-MM-yyyy HH:mm:ss'),dewPoint);
title('Dew Point')
xlabel('temperature')
ylabel('time')
fclose(s)

catch e
    fprintf(1,'The identifier was:\n%s\n',e.identifier);
    fprintf(1,'There was an error! The message was:\n%s\n',e.message);
    fclose(s)
end
