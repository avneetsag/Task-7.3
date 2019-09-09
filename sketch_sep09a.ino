
#define trig 12
#define echo 13
int alarm = 8; // Connect buzzer pin to 8
int ledPin= 6;  //Connect LEd pin to 6
int duration, distance;  

void setup() {
        Serial.begin (9600); 
        pinMode(trig, OUTPUT); 
        pinMode(echo, INPUT);
        pinMode(alarm, OUTPUT);
        pinMode(ledPin, OUTPUT);
}

void loop() 
{

    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH);
    distance = (duration/2) * 0.3;
  if (distance >= 2000 || distance <= 0) 
        {
        Serial.println("no object detected");
        digitalWrite(alarm,LOW);
        digitalWrite(ledPin,LOW);
        }
  else {
        Serial.println("object detected \n");
        Serial.print("distance= ");              
        Serial.print(distance);        
        tone(alarm,400);              
        digitalWrite(ledPin,HIGH);
  }
}
