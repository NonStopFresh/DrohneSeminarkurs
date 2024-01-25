float X0Acceleromin, X90Acceleromax, gradX, gradY, Y0Acceleromin, Y90Acceleromax, AcceleroZ;
int mehrmal = 0;
void accReadings(){
  Wire.beginTransmission(MPU);
  Wire.write(59);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,6,true);//frägt nach 6 registern also von 59 nach 73 weil 59 und 60 ACC X sind 60,61 AccY usw..
  
  AccX=Wire.read()<<8|Wire.read();
  AccY=Wire.read()<<8|Wire.read();
  AccZ=Wire.read()<<8|Wire.read();
  Wire.endTransmission(true);
  ProcessAccX=AccX/ACCData;
  ProcessAccY=AccY/ACCData;
  ProcessAccZ=AccZ/ACCData;
  //Serial.print("AccX = "); Serial.print(ProcessAccX);
  //Serial.print(" || AccY = "); Serial.print(ProcessAccY);
  //Serial.print(" || AccZ = "); Serial.print(ProcessAccZ);
  //Serial.print("|| GES"); Serial.println(abs(ProcessAccZ) + abs(ProcessAccY)+abs(ProcessAccX));

  
  if(mehrmal < 400 ){
    digitalWrite(ledBlau, LOW);
    mehrmal++;
    Serial.println(mehrmal);
    accelerometerKalkulieren(ProcessAccX, ProcessAccY);
    AcceleroZ=ProcessAccZ;
  }
  else{
   
    //if (X0Acceleromin <= -1.4 || X90Acceleromax >= 1.4||Y0Acceleromin <= -1.4 || Y90Acceleromax >= 1.4){
    //exit(0);
    //}
    digitalWrite(ledBlau, HIGH);
    gradX=map(ProcessAccX*100, (X0Acceleromin*100)-5,(X90Acceleromax*100)-5,-90,90);
    gradY=map(ProcessAccY*100, (Y0Acceleromin*100)-5,(Y90Acceleromax*100)-5,-90,90);
    Serial.print("  acceleroY  ");
    Serial.print(gradY);
    Serial.print("  acceleroX  ");
    Serial.println(gradX);
    Motorcontroller(gradX, gradY);
  }
  
}

void accelerometerKalkulieren(float ProcessAccX, float ProcessAccY ){
  
   if(ProcessAccY>Y90Acceleromax){
      Y90Acceleromax=ProcessAccY;  
   }else if (ProcessAccY<Y0Acceleromin){
    Y0Acceleromin=ProcessAccY;
  }
    
    
    if(ProcessAccX>X90Acceleromax){
      X90Acceleromax=ProcessAccX;  
   }else if (ProcessAccX<X0Acceleromin){
    X0Acceleromin=ProcessAccX;
  }
  

  
}