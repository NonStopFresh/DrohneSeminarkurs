int MotorControl1=0; 
int generalThrot;
void Motorcontroller(float gradX, float gradY){
  analogRead(pot);
  Serial.print("analogRead(pot)");
  Serial.print(analogRead(pot));
  generalThrot = map(analogRead(pot), 0, 1023, 100,250);
  analogWrite(MotorX1,generalThrot );
  
  if(gradX>0){
    Serial.print("MotorControl1 ");
    Serial.println(MotorControl1);
    MotorControl1=MotorControl1+1;
    delay(100);
   

  }
  else if(gradX<0){
    MotorControl1=MotorControl1-1;
    
  }
  else if(gradY<0){

  }
  else if(gradY>0){
    
  }
  
}