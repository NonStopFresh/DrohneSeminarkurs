#include <RCSwitch.h>

int bLAST = 0;

RCSwitch mySwitch = RCSwitch();
#define potThrottle A0
void setup() {
  pinMode(potThrottle,INPUT);

  mySwitch.enableTransmit(10);
  Serial.begin(9600);
}

void loop() {
  
  
  mySwitch.send(analogRead(potThrottle), 24);

  delay(50);
}