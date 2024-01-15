double X2, Y2;
double DriftX, DriftY, DriftZ;
double DriftXges, DriftYges, DriftZges; 
double gyroXGes, gyroYGes;
int offsetcount;
int upprbound=100;
int lowrbound=10;
int extratrim=3;
int ff;
bool allesneu = false;
float Ygyromax, Ygyromin,Xgyromax, Xgyromin, gradGyroY, gradGyroX;
int gyroReadings(){
  offsetcount++;
  Wire.beginTransmission(MPU);
  Wire.write(67);
  
  Wire.requestFrom(MPU,4,true);//frägt nach 14 registern also von 59 nach 73 weil 59 und 60 ACC X sind 60,61 AccY usw..
  Wire.endTransmission(false);
  
  GyroX=Wire.read()<<8;Wire.read();
  GyroY=Wire.read()<<8;Wire.read();
  Wire.endTransmission(true);
  
  if(!allesneu){
  ProcessGyroX=GyroX/GYROData;
  gyroXGes=gyroXGes+ProcessGyroX;

  ProcessGyroY=GyroY/GYROData;
  gyroYGes=gyroYGes+ProcessGyroY;
  
  digitalWrite(ledRot, LOW);
  digitalWrite(ledBlau, HIGH);
  }else{
    Done=true;
   ProcessGyroX=GyroX/GYROData;
   ProcessGyroY=GyroY/GYROData;
    

    digitalWrite(ledRot, HIGH);
    //gyroXGes=gyroXGes+(ProcessGyroX-DriftX);
    //gyroYGes=gyroYGes+(ProcessGyroY-DriftY);
    Serial.print("    gyroX    ");
    Serial.print(ProcessGyroX);
    Serial.print("    gyroY    ");
    Serial.print m(ProcessGyroY);
    
    
    
  }
  drift(gyroXGes,gyroYGes);

  //if(Done){
  //  if(mehrmal < 400 ){
  //  Serial.println(mehrmal);
  //  gyroKalkulieren(gyroXGes, gyroYGes);
  //}
  //else{
  //
  //  gradGyroX=map(gyroXGes, Xgyromin,Xgyromax,-90,90);
  //  gradGyroY=map(gyroYGes, Ygyromin,Ygyromax,-90,90);
  //  -
  //  Serial.print(gradGyroX);
  //  Serial.print("  gyro  ");
  //  Serial.println(gradGyroY);
  //}
  //}

  
}

void gyroKalkulieren(float ProcessGyroX, float ProcessGyroY ){
  
   if(ProcessGyroY>Ygyromax){
      Ygyromax=ProcessGyroY;  
   }else if (ProcessGyroY<Ygyromin){
    Ygyromin=ProcessGyroY;
  }
    
    
    if(ProcessGyroX>Ygyromax){
      Ygyromax=ProcessGyroX;  
   }else if (ProcessGyroX<Ygyromin){
    Ygyromin=ProcessGyroX;
  }
  

  
}

void drift(double gyroXges, double gyroYges){
  
  if(offsetcount<=upprbound && offsetcount > lowrbound){
    ff++;
    
    if(offsetcount==lowrbound+extratrim){
      DriftYges=0;
      DriftXges=0;
    }
    Serial.print("DriftY    ");
    Serial.println(DriftY);
    Serial.print("DriftX    ");
    Serial.println(DriftX);
    DriftY=gyroYGes-Y2;
    DriftX=gyroXGes-X2;
    
    Y2=gyroYGes;
    X2=gyroXGes;
    
    DriftXges=DriftXges+DriftX;
    DriftYges=DriftYges+DriftY;
    
    if(offsetcount==upprbound){
      allesneu = true;
      
  
      DriftXges=DriftXges/(upprbound-lowrbound-extratrim+1);
      DriftXges=abs(DriftXges);
      DriftYges=DriftYges/(upprbound-lowrbound-extratrim+1);
      DriftYges=abs(DriftYges);
      gyroXGes=0;
      gyroYGes=0;
      
  
      

    }
  }
}
