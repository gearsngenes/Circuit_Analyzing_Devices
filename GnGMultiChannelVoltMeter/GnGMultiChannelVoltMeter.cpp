

#include "GnGMultiChannelVoltMeter.h"

GnGMultiChannelVoltMeter::GnGMultiChannelVoltMeter(int pinArray[], int pinArraySize, float pmv,int vdvr)
{
  this->pinMaxVolt=pmv;
  this->  voltage_divider_ratio = vdvr;
  
  curArraySize = pinArraySize;
  for (int i = 0; i < curArraySize ; i++)
  {
    analogPinArray[i] = pinArray[i];
    pinMode (analogPinArray[i], INPUT);
  }

}
void GnGMultiChannelVoltMeter:: setMaxVoltage(float newMaxVolt)
{
  this->pinMaxVolt = newMaxVolt;
}
void GnGMultiChannelVoltMeter::set_Divider_Ratio (float newDividerRatio)
{
  this->voltage_divider_ratio = newDividerRatio;

}
float GnGMultiChannelVoltMeter:: returnVoltage(int pin)
{
  return ((analogRead(pin) * 1.0) *( pinMaxVolt) * (this->voltage_divider_ratio)/1023.0);
}