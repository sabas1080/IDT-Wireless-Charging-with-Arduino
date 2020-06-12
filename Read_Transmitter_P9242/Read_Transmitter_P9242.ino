/***************************************************************
 * Example for read register of the P9242-R
 * Authors: 
 *        Andres Sabas - @Nsabasacustico
 *        For Electronic Cats - electroniccats.com
 *        For Wurth Elektronik Mexico
 *        
 * - Arduino Nano Every
 * - Development Kit 15W Wireless Power Transfer - Wurth Elektronik
 *   https://bit.ly/wurthwireless
 * 
 *  12 Jun 2020
 * 
 * Thanks to for initial code: https://forum.arduino.cc/index.php?topic=669792.0
 * 
 * This code is beerware; if you see me (or any other collaborator 
 * member) at the local, and you've found our code helpful, 
 * please buy us a round!
 * Distributed as-is; no warranty is given.
 ******************************************************************/
#include <Wire.h>

// Address default for P9242-R 0x61 or 0x62
byte ADDRESS = 0x61;

void setup()
{
  Serial.begin(115200);
  Wire.begin();
}

void loop()
{
  Wire.beginTransmission( ADDRESS);
  Wire.write( 0x06); // MSB of Device ID Register
  Wire.write( 0xE0); // LSB of Device ID Register
  int error = Wire.endTransmission( false);  // no stop, to create a repeated start.
  if( error != 0)
    Serial.println( "Error, no device found at 0x61");

  int n = Wire.requestFrom( ADDRESS, byte(2));
  if( n != 2)
  {
    Serial.println( "requestFrom failed");
  }
  else
  {
    Serial.println(Wire.read(), HEX);
    Serial.println(Wire.read(), HEX);
  }

  delay(5000);
}
