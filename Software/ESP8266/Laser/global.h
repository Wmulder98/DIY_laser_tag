
//Baudrate for serial over usb
#define BAUDRATE  115200

//Wifi settings
#define ssid        "laser_game"
#define password    "laserTag"

//MQTT setting 
#define mqtt_broker "192.168.1.10"
#define mqtt_port   1883

//Topic to subscribe to
#define newPlayer   "general/newPlayer"
#define gameTime    "general/gameTime"
#define gameStarted "general/gameStarted"

#define RECEIVER_PIN 5 // define the IR receiver pin D1 on node MCU