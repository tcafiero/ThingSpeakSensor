% Humidity and temperature are read from a ThingSpeak channel to calculate
% dew point. The dew point is then written to another ThingSpeak
% channel.

% Channel 12397 contains data from the MathWorks Weather Station, located
% in Natick, Massachusetts. The data is collected once every minute. Field
% 3 contains humidity data and field 4 contains temperature data.

% Channel ID to read data from
readChannelID = 168044;
% Humidity Field ID
HumidityFieldID = 2;
% Temperature Field ID
TemperatureFieldID = 1;

% Channel Read API Key 
% If your channel is private, then enter the read API
% Key between the '' below: 
readAPIKey = 'MH88435QK0PEIRBV';

% To store the calculated dew point, write it to a channel other
% than the one used for reading data. To write to a channel, assign the
% write channel ID to the 'writeChannelID' variable, and the write API Key
% to the 'writeAPIKey' variable below. Find the write API Key in the right
% side pane of this page.

% TODO - Replace the [] with channel ID to write data to:
writeChannelID = 167475;
% TODO - Enter the Write API Key between the '' below:
writeAPIKey = '5XB2I9UBNJFD32Q8';

% Get latest temperature data from the MathWorks Weather Station channel.
% Learn more about the THINGSPEAKREAD function by going to the Documentation tab on
% the right side pane of this page.
[temp,time] = thingSpeakRead(readChannelID, 'Fields', TemperatureFieldID, 'NumPoints', 60);
% Get latest humidity data from the MathWorks Weather Station channel
humidity = thingSpeakRead(readChannelID, 'Fields', HumidityFieldID, 'NumPoints', 60);

% Convert temperature from Fahrenheit to Celsius

%tempC = (5/9)*(temp-32);
tempC = temp;

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
plot(time,tempC);
plot(time,dewPoint);
display(dewPoint, 'Dew point')
display(tempC, 'temp');
display(humidity, 'Humidity');
txt = jsonencode({time, temp, humidity});
display(txt, 'JSON');
display(time, 'time')
% Write the dew point value to another channel specified by the
% 'writeChannelID' variable

display(['Note: To successfully write data to another channel, ',...
    'assign the write channel ID and API Key to ''writeChannelID'' and ',...
    '''writeAPIKey'' variables above. Also uncomment the line of code ',...
    'containing ''thingSpeakWrite'' (remove ''%'' sign at the beginning of the line.)'])

% Learn more about the THINGSPEAKWRITE function by going to the Documentation tab on
% the right side pane of this page.

%thingSpeakWrite(writeChannelID, [tempC,humidity,dewPoint], 'Fields', [1,2,3], 'TimeStamps', time, 'Writekey', writeAPIKey);
