
void receive() {

  if (mySwitch.available()) {
    
    int value = mySwitch.getReceivedValue();
    
    
      Serial.print("Received ");
      Serial.print( value );
  	  
      Serial.print(" / ");
      Serial.print( mySwitch.getReceivedBitlength() );
      Serial.println("bit ");
      
      value=map(value,0,1025,255,0);
      analogWrite(12,value);
    

    mySwitch.resetAvailable();
  }
}
