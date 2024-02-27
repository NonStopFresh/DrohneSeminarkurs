#include <RCSwitch.h>

int bLAST = 0;
int poThrot;
RCSwitch mySwitch = RCSwitch();
#define potThrottle A0
void setup() {
  pinMode(potThrottle,INPUT);

  mySwitch.enableTransmit(10);
  Serial.begin(9600);
}

void loop() {
  poThrot=map(analogRead(potThrottle),0,1023,0,180);
  Serial.print(poThrot);
  Serial.print("    ");
  Serial.println(analogRead(potThrottle));
  mySwitch.send(poThrot, 8);

  delay(50);
}