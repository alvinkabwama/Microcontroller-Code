void slowDown()
{
 if(analogRead(smpin) > 500)
 {
  if(smcheck == 0)
  { 
    digitalWrite(smled, HIGH);  
    Serial.print("LED ON");
    delay(300);
    smcheck = 1;
    delaytym = 1000;
  } 
  else if(smcheck == 1)
  {
    digitalWrite(smled, LOW);
    
    Serial.print("LED OFF");
    delay(300);
    smcheck = 0;
  }
  Serial.println("FINISHED");
 }
}

