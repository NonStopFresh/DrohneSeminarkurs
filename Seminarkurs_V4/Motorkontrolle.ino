int MotorControlX1=0; 
int MotorControlX2=0; 
int MotorControlY1=0; 
int MotorControlY2=0; 
int generalThrot;

void Motorcontroller(float gradX, float gradY){
 
  
   //240, da motor durch programm stärkere leistung erreichen soll|| externe inputs
  Serial.print("generalThrot  ");           
  Serial.println(ThrotVal);
  
 
  if(ThrotVal>1){
    Debugg();
  motor1.write(ThrotVal);//+MotorControlX1
  motor2.write(ThrotVal);//+MotorControlX2
  motor3.write(ThrotVal);//+MotorControlY1
  motor4.write(ThrotVal);//+MotorControlY2
  if(gradX>0){
    Serial.print("MotorControl1 ");
    Serial.println(MotorControlX1);
    if(MotorControlX1<20){
    MotorControlX1=MotorControlX1+1;
    }
    
    MotorControlX2=MotorControlX2-1;
    
   

  }
  else if(gradX<0){
    if(MotorControlX2<20){
    MotorControlX2=MotorControlX2+1;
    }
    MotorControlX1=MotorControlX1-1;
    
  }
  else if(gradY>0){
    if(MotorControlY1<20){
    MotorControlY1=MotorControlY1+1;
    }
    MotorControlY2=MotorControlY2-1;
  }else if(gradY<0){
    if(MotorControlY2<20){
    MotorControlY2=MotorControlY2+1;
    }
    MotorControlY1=MotorControlY1-1;
    
  }else{
    Serial.println("geracde");
    MotorControlX1=0;
  MotorControlX2=0;
  MotorControlY1=0;
  MotorControlY2=0;
  }
  }
  else{
  motor1.write(0);
  motor2.write(0);
  motor3.write(0);
  motor4.write(0);
  MotorControlX1=0;
  MotorControlX2=0;
  MotorControlY1=0;
  MotorControlY2=0;
  }
  
  
}