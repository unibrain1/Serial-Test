/*
  Software serial multple serial test

 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.

 The circuit:
 * RX is digital pin 2 (connect to TX of other device)
 * TX is digital pin 3 (connect to RX of other device)

 Note:
 Not all pins on the Mega and Mega 2560 support change interrupts,
 so only the following can be used for RX:
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

 Not all pins on the Leonardo support change interrupts,
 so only the following can be used for RX:
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

 created back in the mists of time
 modified 25 May 2012
 by Tom Igoe
 based on Mikal Hart's example

 This example code is in the public domain.

 */

#include <Arduino.h>

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial)
  {
    ; // wait for serial port to connect. Needed for Native USB only
    // set the data rate for the SoftwareSerial port
  }
  Serial.println("Serial_Test - Visual");
  Serial.println("Hello, world?");

  Serial3.begin(115200);
  Serial3.setTimeout(5000);


  while (!Serial3)
  {
    ; // wait for serial port to connect. Needed for Native USB only
  }

  Serial3.println("list");
}


void loop() // run over and over
{
  char buff[128+1] ="";

  if (Serial3.available())
  {
    Serial3.readBytesUntil('\n', buff, 128);
    Serial.println(buff);
  }
  if (Serial.available())
  {
    Serial.readBytesUntil('\n', buff, 128);
    Serial3.println(buff);
  }
}
