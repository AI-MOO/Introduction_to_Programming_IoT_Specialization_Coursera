void setup() {
  // put your setup code here, to run once:

pinMode (13,OUTPUT);
Serial.begin(9600);

}

void loop() {
 
if(Serial.available() > 0)

{ char x = Serial.read();


    if (x == '1') {
          digitalWrite(13, HIGH);
      
                  }
 
  else if (x == '0')  {
      digitalWrite(13,LOW);
      
      }
  }

 }
