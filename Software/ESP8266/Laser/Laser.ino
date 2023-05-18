//Name of project:            DIY laser tag
//Company:                    Hobby
//Date of creation:           16-04-2023
//Date of last modification:  03-05-2023
//Creater:                    Wouter Mulder
//Proccesor:                  ESP8266
//Proccesor datasheet:
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <IRremote.h> // include the IRremote library
#include "global.h"

//Topic varables for use in other code 
char topicGeneral[30];

WiFiClient espClient;
PubSubClient client(espClient);

IRrecv receiver(RECEIVER_PIN); // create a receiver object of the IRrecv class
decode_results results; // create a results object of the decode_results class

void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUDRATE);
  WifiSetup();
  MQTTsetup();
  
  //Put the subsriptions here 
  client.subscribe(newPlayer);
  client.subscribe(gameTime);
  client.subscribe(gameStarted);

  setupIRreceive();
}

void callback(char *topic, byte *payload, unsigned int length) {
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  Serial.print("Message:");

  char messageTemp[1];

  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    messageTemp[0] = (char)payload[i];
  }

  Serial.println();
  Serial.println(" - - - - - - - - - - - -");

  if (String(topic) == newPlayer){
    Serial.println(messageTemp);\
    strcpy(topicGeneral, "player_");
    strcat(topicGeneral, messageTemp);
    strcat(topicGeneral, "/general");
    client.publish(topicGeneral, "Hello From player1");
    
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  client.loop();
  if (receiver.decode(&results)) { // decode the received signal and store it in results
    Serial.println(results.value, HEX); // print the values in the Serial Monitor
    receiver.resume(); // reset the receiver for the next code
  }

}
