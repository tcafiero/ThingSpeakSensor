// include the aJSON library
#include <aJSON.h>
// include the JsonRPC library
#include <JsonRPCServer.h>

// {"method": "getData", "params": {"status": true} }

//const char record[]="{\"time\": [\"30-09-2019 13:58:14\",\n\"30-09-2019 13:59:10\",\n\"30-09-2019 14:00:10\",\n\"30-09-2019 14:01:09\",\n\"30-09-2019 14:02:10\",\n\"30-09-2019 14:03:10\",\n\"30-09-2019 14:04:09\",\n\"30-09-2019 14:05:09\",\n\"30-09-2019 14:06:16\",\n\"30-09-2019 14:07:10\",\n\"30-09-2019 14:08:10\",\n\"30-09-2019 14:09:10\",\n\"30-09-2019 14:10:12\",\n\"30-09-2019 14:11:09\",\n\"30-09-2019 14:12:09\",\n\"30-09-2019 14:13:18\",\n\"30-09-2019 14:14:22\",\n\"30-09-2019 14:15:10\",\n\"30-09-2019 14:16:09\",\n\"30-09-2019 14:17:11\",\n\"30-09-2019 14:18:09\",\n\"30-09-2019 14:19:09\",\n\"30-09-2019 14:20:09\",\n\"30-09-2019 14:21:11\",\n\"30-09-2019 14:22:09\",\n\"30-09-2019 14:23:09\",\n\"30-09-2019 14:24:10\",\n\"30-09-2019 14:25:09\",\n\"30-09-2019 14:26:10\",\n\"30-09-2019 14:27:10\",\n\"30-09-2019 14:28:11\",\n\"30-09-2019 14:29:09\",\n\"30-09-2019 14:30:10\",\n\"30-09-2019 14:31:09\",\n\"30-09-2019 14:32:10\",\n\"30-09-2019 14:33:09\",\n\"30-09-2019 14:34:09\",\n\"30-09-2019 14:35:10\",\n\"30-09-2019 14:36:10\",\n\"30-09-2019 14:37:11\",\n\"30-09-2019 14:38:09\",\n\"30-09-2019 14:39:09\",\n\"30-09-2019 14:40:09\",\n\"30-09-2019 14:41:09\",\n\"30-09-2019 14:42:10\",\n\"30-09-2019 14:43:20\",\n\"30-09-2019 14:44:16\",\n\"30-09-2019 14:45:12\",\n\"30-09-2019 14:46:12\",\n\"30-09-2019 14:47:12\",\n\"30-09-2019 14:48:09\",\n\"30-09-2019 14:49:12\",\n\"30-09-2019 14:49:27\",\n\"30-09-2019 14:50:13\",\n\"30-09-2019 14:50:28\",\n\"30-09-2019 14:51:10\",\n\"30-09-2019 14:52:10\",\n\"30-09-2019 14:53:09\",\n\"30-09-2019 14:54:10\",\n\"30-09-2019 14:55:10\"],\"temp\": [26.94,26.93,26.94,26.92,26.94,26.93,26.93,26.93,26.93,\n26.94,26.92,26.94,26.92,26.92,26.93,26.93,26.93,26.93,26.92,26.94,26.92,26.93,26.92,26.92,\n26.93,26.92,26.92,26.92,26.9,26.93,26.92,26.94,26.94,26.94,26.92,26.93,26.94,26.92,26.93,\n26.92,26.91,26.92,26.94,26.92,26.91,26.91,26.93,26.91,26.92,26.91,26.91,26.92,26.92,\n26.9,26.9,26.94,26.92,26.92,26.92,26.92],\"humidity\": [64.78,64.75,64.77,64.77,\n64.75,64.78,64.78,64.78,64.78,64.77,64.77,64.77,64.77,64.77,64.74,64.76,64.76,64.75,\n64.79,64.75,64.77,64.73,64.76,64.75,64.74,64.75,64.75,64.75,64.75,64.76,64.75,64.74,64.75,\n64.72,64.73,64.75,64.74,64.73,64.71,64.73,64.72,64.73,64.72,64.75,64.72,64.72,64.73,\n64.73,64.73,64.75,64.74,64.77,64.77,64.75,64.75,64.74,64.72,64.74,64.72,64.73]}";
const char record[]="{\"time\": [\"30-09-2019 13:58:14\",\"30-09-2019 13:59:10\",\"30-09-2019 14:00:10\",\"30-09-2019 14:01:09\",\"30-09-2019 14:02:10\",\"30-09-2019 14:03:10\",\"30-09-2019 14:04:09\",\"30-09-2019 14:05:09\",\"30-09-2019 14:06:16\",\"30-09-2019 14:07:10\",\"30-09-2019 14:08:10\",\"30-09-2019 14:09:10\",\"30-09-2019 14:10:12\",\"30-09-2019 14:11:09\",\"30-09-2019 14:12:09\",\"30-09-2019 14:13:18\",\"30-09-2019 14:14:22\",\"30-09-2019 14:15:10\",\"30-09-2019 14:16:09\",\"30-09-2019 14:17:11\",\"30-09-2019 14:18:09\",\"30-09-2019 14:19:09\",\"30-09-2019 14:20:09\",\"30-09-2019 14:21:11\",\"30-09-2019 14:22:09\",\"30-09-2019 14:23:09\",\"30-09-2019 14:24:10\",\"30-09-2019 14:25:09\",\"30-09-2019 14:26:10\",\"30-09-2019 14:27:10\",\"30-09-2019 14:28:11\",\"30-09-2019 14:29:09\",\"30-09-2019 14:30:10\",\"30-09-2019 14:31:09\",\"30-09-2019 14:32:10\",\"30-09-2019 14:33:09\",\"30-09-2019 14:34:09\",\"30-09-2019 14:35:10\",\"30-09-2019 14:36:10\",\"30-09-2019 14:37:11\",\"30-09-2019 14:38:09\",\"30-09-2019 14:39:09\",\"30-09-2019 14:40:09\",\"30-09-2019 14:41:09\",\"30-09-2019 14:42:10\",\"30-09-2019 14:43:20\",\"30-09-2019 14:44:16\",\"30-09-2019 14:45:12\",\"30-09-2019 14:46:12\",\"30-09-2019 14:47:12\",\"30-09-2019 14:48:09\",\"30-09-2019 14:49:12\",\"30-09-2019 14:49:27\",\"30-09-2019 14:50:13\",\"30-09-2019 14:50:28\",\"30-09-2019 14:51:10\",\"30-09-2019 14:52:10\",\"30-09-2019 14:53:09\",\"30-09-2019 14:54:10\",\"30-09-2019 14:55:10\"],\"temp\": [26.94,26.93,26.94,26.92,26.94,26.93,26.93,26.93,26.93,26.94,26.92,26.94,26.92,26.92,26.93,26.93,26.93,26.93,26.92,26.94,26.92,26.93,26.92,26.92,26.93,26.92,26.92,26.92,26.9,26.93,26.92,26.94,26.94,26.94,26.92,26.93,26.94,26.92,26.93,26.92,26.91,26.92,26.94,26.92,26.91,26.91,26.93,26.91,26.92,26.91,26.91,26.92,26.92,26.9,26.9,26.94,26.92,26.92,26.92,26.92],\"humidity\": [64.78,64.75,64.77,64.77,64.75,64.78,64.78,64.78,64.78,64.77,64.77,64.77,64.77,64.77,64.74,64.76,64.76,64.75,64.79,64.75,64.77,64.73,64.76,64.75,64.74,64.75,64.75,64.75,64.75,64.76,64.75,64.74,64.75,64.72,64.73,64.75,64.74,64.73,64.71,64.73,64.72,64.73,64.72,64.75,64.72,64.72,64.73,64.73,64.73,64.75,64.74,64.77,64.77,64.75,64.75,64.74,64.72,64.74,64.72,64.73]}";



class TargetController: public JsonRPCServer {
public:
  TargetController(Stream* stream);

  DECLARE_JSON_PROC(TargetController, init, int);
  DECLARE_JSON_PROC(TargetController, getData, void);
  

  BEGIN_JSON_REGISTRATION
    REGISTER_JSON_PROC(init, JSON_RPC_RET_TYPE_NUMERIC);
    REGISTER_JSON_PROC(getData, JSON_RPC_RET_TYPE_NONE);
  END_JSON_REGISTRATION
  

private:
  
  // on most arduino boards, pin 13 is connected to a LED
  int _led;
  
};





TargetController::TargetController(Stream* stream): JsonRPCServer(stream), _led(13) {
  // TODO Auto-generated constructor stub

}

int TargetController::init(aJsonObject* params) {

  // initialize the digital pin as an output
  pinMode(_led, OUTPUT);

  return true;
}

void TargetController::getData(aJsonObject* params)
{
  Serial.println(record);
  //Serial.println("END");
  return;
}




TargetController jsonController(&Serial);


void setup()
{
  // start up the serial interface
  Serial.begin(115200);
  Serial.println("Initializing JSON RPC server");

  /* add setup code here */

  jsonController.begin(2);
}

void loop()
{

  jsonController.process();
}