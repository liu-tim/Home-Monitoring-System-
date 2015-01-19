int i;
int minSecsBetweenEmails = 60; // 1 min
long lastSend = -minSecsBetweenEmails * 1000l;
void setup()
{
  for(i=2;i<5;i++)
   {
     pinMode(i, OUTPUT);  
   }  
 Serial.begin(9600);
}

void loop()
{
  long now = millis();
  if (analogRead(A3)>500)
  {
     for(i=2;i<5;i++)
     {
      digitalWrite(i, HIGH);  
     }   
    if (now > (lastSend + minSecsBetweenEmails * 1000l))
    {
      Serial.println("Lights Are Turned Off!");
      lastSend = now;
    }
    else
    {
      Serial.println("Email Sent...Turning On Emergency Blackout Lights");
    }
  }
  delay(500);
}
