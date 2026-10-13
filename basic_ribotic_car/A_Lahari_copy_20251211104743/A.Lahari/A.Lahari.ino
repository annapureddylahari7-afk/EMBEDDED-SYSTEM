void setup()
{
pinMode(13,OUTPUT);
Serial.begin(2400);
}
void loop()
{
digitalWrite(13,HIGH);
Serial.println("led ON");
delay(1000);
digitalWrite(13,LOW);
Serial.println("led OFF");
delay(1000);
}
