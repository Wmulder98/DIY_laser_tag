void setupIRreceive(){
    receiver.enableIRIn(); // enable the receiver
    receiver.blink13(true); // enable blinking of the built-in LED when an IR signal is received
}