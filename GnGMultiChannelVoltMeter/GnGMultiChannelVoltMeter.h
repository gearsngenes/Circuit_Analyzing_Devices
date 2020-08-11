#ifndef GnGMultiChannelVoltMeter_h
#define GnGMultiChannelVoltMeter_h
#include "Arduino.h"

class GnGMultiChannelVoltMeter
{
  public:
    GnGMultiChannelVoltMeter(int pinArray[], int pinArraySize, float pinMaxVolt=3.30,int voltage_divider_ratio = 11.0);
  public:
    static const int max_pin_array_size = 10;
    int curArraySize;
    float pinMaxVolt;
    float voltage_divider_ratio;
    int analogPinArray[GnGMultiChannelVoltMeter::max_pin_array_size];

    const float volt_per_reading = (pinMaxVolt * 1.0) / 1023.0;

    void setMaxVoltage(float newMaxVolt);
    void set_Divider_Ratio (float newDividerRatio);
    float returnVoltage(int pin);
};


#endif