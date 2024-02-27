int MotorControlX1=0; 
int MotorControlX2=0; 
int MotorControlY1=0; 
int MotorControlY2=0; 
int generalThrot;

void Motorcontroller(float gradX, float gradY){
 
  
   //240, da motor durch programm stärkere leistung erreichen soll|| externe inputs
  Serial.print("generalThrot  ");           
  Serial.println(ThrotVal);
  
 
  
  motor1.write(ThrotVal);
  motor2.write(ThrotVal);
  motor3.write(ThrotVal);
  motor4.write(ThrotVal);
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