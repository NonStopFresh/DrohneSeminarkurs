
void receive() {

  //if (mySwitch.available()) {
    
    ThrotVal = mySwitch.getReceivedValue();
    
    
      Serial.print("Received ");
      Serial.print(ThrotVal);

    mySwitch.resetAvailable();
  //}else{
    /*
    motor1.detach();
    motor2.detach();
    motor3.detach();
    motor4.detach();
  motor1.write(0);
  motor2.write(0);
  motor3.write(0);
  motor4.write(0);*/
//}
}
