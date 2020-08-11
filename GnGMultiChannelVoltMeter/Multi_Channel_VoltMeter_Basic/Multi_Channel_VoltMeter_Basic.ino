#include "GnGMultiChannelVoltMeter.h"

int tempArray[] = {A0, A1, A2, A3, A4, A5}; //Your Voltage Measuring channels

GnGMultiChannelVoltMeter *mcVoltmeterptr = new GnGMultiChannelVoltMeter(tempArray, 6); // Declaring there are six channels and what those channels are
GnGMultiChannelVoltMeter mcVoltmeter = *mcVoltmeterptr; //for ease of use below

void setup()
{
  Serial.begin(115200);
}

void loop() {
  //tempPin=5;
  for (int i = 0; i < 6; i ++)
  {
    int pin = mcVoltmeter.analogPinArray[i];
    Serial.print("A"); Serial.print(i); Serial.print(": "); Serial.println(mcVoltmeter.returnVoltage(pin)); //printing out voltage measurement of every channel
  }
  Serial.println("-------------");
  delay(1000);
}
