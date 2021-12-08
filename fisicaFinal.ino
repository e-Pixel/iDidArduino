const int led_rojo = 2; 

void setup() {
  Serial.begin(9600);
  pinMode(led_rojo, OUTPUT);
  Serial.println("IT IS WORKING");
}

void loop() {
  digitalWrite(led_rojo, LOW);
  delay(100);
  digitalWrite(led_rojo, HIGH);
  delay(100);
}
