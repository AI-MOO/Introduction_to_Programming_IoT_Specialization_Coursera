const int led=5; // variable which stores pin number

void setup() 
{
  pinMode(led, OUTPUT);  //configures pin 3 as OUTPUT
  digitalWrite(led,0);
}

void loop() 
{
   int sensor_value = analogRead(A0);
  if (sensor_value < 200 )// the point at which the state of LEDs change 
    { 
      digitalWrite(led, LOW);  //sets LEDs ON
    }
  else
    {
      digitalWrite(led, HIGH);  //Sets LEDs OFF
    }
delay(500);
}
