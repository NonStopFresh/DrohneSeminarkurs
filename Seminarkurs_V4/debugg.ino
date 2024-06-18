void Debugg(){
  
  Serial.println("Degubb Motorthrot, ");
  Serial.print(MotorControlX1);
  space();
  Serial.print(MotorControlX2);
  space();
  Serial.print(MotorControlY1);
  space();
  Serial.println(MotorControlY2);
  space();
}
void space(){
  Serial.print("    ");
}

/*MotorControlX1
MotorControlX2
MotorControlY1
MotorControlY2*/