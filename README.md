# DIY_laser_tag
This project is an project to make our own laser tag as cheaply as posible. The project was done as a hobby project.

## Requirements
The requirements are:
- It has to cost less the 15 euros 
- There has to be a score system in a central location 
- There has to be a nice user interface that anyone can understand so no terminal apps!
- There has to be a score board that can be projected or put on a large screen 

## Communication
The communication is handeld via MQTT. The laptop has a mosquitto broker running on it and the ESP8266 has a client
running on it is this way we are able to sent messages back and forth to and fron the boards. This is needed to get a
Score system working and to be able to have it all in one place 

