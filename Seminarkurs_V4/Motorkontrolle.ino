int MotorControlX1=0; 
int MotorControlX2=0; 
int MotorControlY1=0; 
int MotorControlY2=0; 
int generalThrot;
void Motorcontroller(float gradX, float gradY){
 
  
  generalThrot = map(analogRead(pot), 0, 1023, 100,240); //240, da motor durch programm stärkere leistung erreichen soll|| externe inputs
  Serial.print("generalThrot  ");           
  Serial.println(generalThrot);
  analogWrite(MotorX1,generalThrot);
  analogWrite(MotorX2,generalThrot);
  analogWrite(MotorY1,generalThrot);
  analogWrite(MotorY2,generalThrot);
  /*
  if(gradX>0){
    Serial.print("MotorControl1 ");
    Serial.println(MotorControlX1);
    MotorControlX1=MotorControlX1+1;
    MotorControlX2=MotorControlX2-1;
    
   

  }
  else if(gradX<0){
    MotorControlX2=MotorControlX2+1;
    MotorControlX1=MotorControlX1-1;
    
  }
  else if(gradY>0){
    MotorControlY1=MotorControlY1+1;
    MotorControlY2=MotorControlY2-1;
  }else if(gradY<0){
    MotorControlY1=MotorControlY1-1;
    MotorControlY2=MotorControlY2+1;
    
  }else{
    Serial.println("geracde");
  }
  */
}