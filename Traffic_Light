#include <Servo.h>

#define echoPin 10
#define trigPin 13

const int led_rojo = 3;
const int led_amarillo = 4;
const int led_verde = 5;

int l_delay = 1200;
int s_delay = 350;

int duration;
int distance_cm;
Servo myservo;

void setup(){
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(led_rojo, OUTPUT);
  pinMode(led_amarillo, OUTPUT);
  pinMode(led_verde, OUTPUT);
  myservo.attach(9);
}

void medir_distancia(){ // in centimeters
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance_cm = ( duration / 29 ) / 2; //global variable
  Serial.println(distance_cm);
}

void spin(){
  myservo.write(0);
  delay(s_delay);
  myservo.write(180);
  delay(s_delay);
}

void spin_slow(){
  myservo.write(0);
  delay(l_delay);
  myservo.write(180);
  delay(l_delay);
}

int x = 0; // test purposes
int y = 0;
int z = 0; 

boolean green;
boolean yellow;
boolean red;

void loop(){
  medir_distancia();
  if (distance_cm >= 75 && distance_cm < 200){
    Serial.println("GREEN");
    digitalWrite(led_verde, HIGH);
    digitalWrite(led_amarillo, LOW);
    digitalWrite(led_rojo, LOW);
    spin();
    spin();
    delay(2750);
    // the sum of the delays cannot be longer than the delay from above
    loop();
  }
  else if (distance_cm < 20){
    Serial.println("ROJO");
    digitalWrite(led_verde, LOW);
    digitalWrite(led_amarillo, LOW);
    digitalWrite(led_rojo, HIGH);
    delay(3000);
    loop();
  }
  else if (distance_cm < 75 && distance_cm >= 20){
    Serial.println("AMARILLO");
    digitalWrite(led_verde, LOW);
    digitalWrite(led_amarillo, HIGH);
    digitalWrite(led_rojo, LOW);
    spin_slow();
    delay(2000);
    loop();
    }
  }
