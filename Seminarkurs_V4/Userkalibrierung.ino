int buttonVar=0,potVar;
short btnState = 0;
//X0Acceleromin*100
//X90Acceleromax*100
//Y0Acceleromin*100
//Y90Acceleromax*100
void Userkalibrierung(){
  digitalRead(inputBut);
  analogRead(potKalUsr);
  Serial.println(digitalRead(inputBut));
  if(digitalRead(inputBut)!=btnState){
  if (digitalRead(inputBut)==HIGH){
    
    buttonVar=buttonVar+1;
    Serial.print("#########BUTTONZÄHLER###########    ");
    
    Serial.println(buttonVar);
    if(buttonVar>=4){
      buttonVar=0;
      }
    switch(buttonVar){
      case 1:
        X0Acceleromin = X0Acceleromin +  analogRead(potKalUsr)/100;
        break;
      case 2:
        X90Acceleromax = X90Acceleromax +  analogRead(potKalUsr)/100;
        break;
      case 3:
        Y0Acceleromin = Y0Acceleromin +  analogRead(potKalUsr)/100;
        break;
      case 4:
        Y90Acceleromax = Y90Acceleromax +  analogRead(potKalUsr)/100;
        break;
    }
    }
  }
    btnState=digitalRead(potKalUsr);
}