/*
  Step Motor 28BYJ-48
  Motor Forward/Reverse controlado por dos botones 'Push Button'
*/

// se definen las bobinas del Step Motor
#define IN1  8
#define IN2  9
#define IN3  10
#define IN4  11

// se definen los led indicadores para Forward o Reverse
int pinLedGreen = 3;
int pinLedRed = 6;

// se definen los botones que permitirán el sentido de giro del motor
int pinBtn1 = 7;
int pinBtn2 = 4;

// se definen los pasos para el movimiento del motor
int paso [4][4] =
{
  {1, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 1},
  {1, 0, 0, 1}
};

// se define una función para el movimiento horario del motor
void forward(){
  for (int i = 0; i < 4; i++)
    {
      digitalWrite(pinLedGreen, !digitalRead(pinLedGreen));
      digitalWrite(IN1, paso[i][3]);
      digitalWrite(IN2, paso[i][2]);
      digitalWrite(IN3, paso[i][1]);
      digitalWrite(IN4, paso[i][0]);
      delay(10);
    }
}

// se define una función para el movimiento anti-horario del motor
void reverse(){
  for (int i = 0; i < 4; i++)
    {
      digitalWrite(pinLedRed, !digitalRead(pinLedRed));
      digitalWrite(IN1, paso[i][0]);
      digitalWrite(IN2, paso[i][1]);
      digitalWrite(IN3, paso[i][2]);
      digitalWrite(IN4, paso[i][3]);
      delay(10);
    }
}

// se definen los parámetros iniciales del programa 
void setup()
{
  Serial.begin(9600);

  // bobinas como salidas
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // botones como entradas
  pinMode(pinBtn1, INPUT);
  pinMode(pinBtn2, INPUT);

  // leds indicadores como salidas
  pinMode(pinLedGreen, OUTPUT);
  pinMode(pinLedRed, OUTPUT);
  
}

// ciclo principal del programa
void loop()
{ 
  if(digitalRead(pinBtn1) == 0){
    forward();
  }

  if(digitalRead(pinBtn2) == 0){
    reverse();
  }
}
