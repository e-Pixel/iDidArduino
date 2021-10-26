#define PULSADOR 10
#define echoPin 11
#define trigPin 12

const int led_rojo = 1;
const int led_verde = 13;

// Array multidimensional para mostrar los números
byte  numero[10][8] =
{
/*0*/ {0,0,0,0,0,0,0},
/*1*/ {1,0,0,1,1,1,1},
};

int duration;
int distance_cm;

// Declaracion de variables globales
float tempC; // Variable para almacenar el valor obtenido del sensor (0 a 1023)
int pinLM35 = 0; // Variable del pin de entrada del sensor (A0)

void medir_distancia(){ // in centimeters
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance_cm = ( duration / 29 ); //global variable
}

void setup() {
  // Iniciamos el monitor serie
  Serial.begin(9600);
 
  // Ponemos los pines de los segmentos en modo OUTPUT (salida)
  for (int i = 3; i < 10; i++)
  {
    pinMode(i, OUTPUT);
  }
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(led_verde, OUTPUT);
  //Establecemos la semilla fija
}
 
void loop() {
 
    // Ponemos los pines en estado correcto para mostrar el número randomNumber
    for (int e = 3; e < 8; e++)
    {
      //Serial.print(decimal);
      tempC = analogRead(pinLM35); 
      int newTemp = ((tempC * 0.48828125)/6); 
      // Serial.println(newTemp);
      if (newTemp > 40) {
        digitalWrite(e, numero[1][e]);
      }
      else { 
        digitalWrite(e, numero[0][e]);
      }
    } 
    medir_distancia();
    //Serial.println(distance_cm);
    int decimal = (distance_cm);

    Serial.println(decimal);
    if (decimal < 50) {
      digitalWrite(led_rojo, LOW);
      digitalWrite(led_verde, LOW);
    }
    if (decimal > 100){
      digitalWrite(led_rojo, LOW);
      digitalWrite(led_verde, HIGH);
    }
  }
