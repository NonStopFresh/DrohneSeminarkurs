int MotorControl1=0; 

void Motorcontroller(float gradX, float gradY){
  Serial.println(gradX);
  if(gradX<0){
    MotorControl1=MotorControl1+10;
    MotorX1.write(MotorControl1);

  }
  else if(gradX>0){
    MotorControl1=MotorControl1-10;

  }
  if(gradY<0){

  }
  else if(gradX>0){
    
  }
  
}