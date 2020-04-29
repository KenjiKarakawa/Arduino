#include <stdlib.h>
// define números de pinos do driver no arduino
const int stepPin = 3;
const int dirPin = 4;

int Steps = 2050;
int StepsDelay = 750;

enum StepDirection {
  Clockwise = 1,
  CounterClockwise = 0
};
 
void setup () {
  Serial.begin(9600);

  // Define os dois pinos como Saídas
  pinMode (stepPin, OUTPUT);
  pinMode (dirPin, OUTPUT);
}

// faz 200 pulsos para fazer uma rotação de ciclo completo
void ExecuteStep(int steps, int stepsDelay, StepDirection stepDir){
  digitalWrite(dirPin, (int)stepDir);

  for(int x = 0; x < steps; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(stepsDelay);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(stepsDelay);
  }
}

void loop() {
  if(Serial.available())
  {
    String Value = Serial.readString();
    StepsDelay = atol(Value.c_str());
  }

  ExecuteStep(Steps, StepsDelay, StepDirection::Clockwise);
  
  delay(1000); //1 segundo de delay para inverter a direção

}
