/* Finding the key codes for your remote. More info: https://www.makerguides.com */

//Install 3.3.0 of IRremote lib

#include <IRremote.h> // include the IRremote library

#define RECEIVER_PIN 5 // define the IR receiver pin
IRrecv receiver(RECEIVER_PIN); // create a receiver object of the IRrecv class
decode_results results; // create a results object of the decode_results class

void setup() {
  Serial.begin(9600); // begin serial communication with a baud rate of 9600
  receiver.enableIRIn(); // enable the receiver
  //receiver.blink13(true); // enable blinking of the built-in LED when an IR signal is received
}

void loop() {
  if (receiver.decode(&results)) { // decode the received signal and store it in results
    
    if (results.value != 0xFFFFFFFF){
      Serial.println(results.value, HEX); // print the values in the Serial Monitor
    }
    receiver.resume(); // reset the receiver for the next code
  }
}