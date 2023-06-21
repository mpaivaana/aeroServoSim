#include <Servo.h>
//Declaração dos pinos dos botões
const int wingButtonL = 8;
const int wingButtonR = 7;
const int rudderButtonR = 2;
const int rudderButtonL = 12;
const int tailButtonUp = 13;
const int tailButtonDown = 10;

//Declaração dos pinos dos motores
const int wingR = 6;
const int wingL = 5;
const int rudder = 3;
const int tail = 9;

//Declara os objetos servos
Servo servWingR;
Servo servWingL;
Servo servRudder;
Servo servTail;

//Variavéis auxiliares de estado dos botões 
int buttonWingStateL = 0;
int buttonWingStateR = 0;
int buttonRudderStateL = 0;
int buttonRudderStateR = 0;
int buttonTailStateL = 0;
int buttonTailStateR = 0;

// Variáveis auxiliares de ângulo
int angleWingL = 90;
int angleWingR = 90;
int angleRudder = 90;
int angleTail = 90;

void setup() {
  // Associando um objeto da classe Servo a sua respectiva pinagem
  servWingR.attach(wingR);
  servWingL.attach(wingL);
  servRudder.attach(rudder);
  servTail.attach(tail);

  // Definindo o modo dos botões
  pinMode(wingButtonL, INPUT_PULLUP);
  pinMode(wingButtonR, INPUT_PULLUP);
  pinMode(rudderButtonR, INPUT_PULLUP);
  pinMode(rudderButtonL, INPUT_PULLUP);
  pinMode(tailButtonUp, INPUT_PULLUP);
  pinMode(tailButtonDown, INPUT_PULLUP);
}

void loop() {
  // Associa a pinagem dos botões à variável auxiliar de estado
  buttonWingStateL = digitalRead(wingButtonL);
  buttonWingStateR = digitalRead(wingButtonR);
  buttonRudderStateL = digitalRead(rudderButtonL);
  buttonRudderStateR = digitalRead(rudderButtonR);
  buttonTailStateL = digitalRead(tailButtonDown);
  buttonTailStateR = digitalRead(tailButtonUp);

  // Cenários Wing
  if (buttonWingStateL == LOW && buttonWingStateR == LOW) {
    angleWingL = 90;
    angleWingR = 90;
    servWingR.write(angleWingR);
    servWingL.write(angleWingL);
  }
  else if (buttonWingStateL == LOW && buttonWingStateR == HIGH) {
    while (angleWingL > 1 && angleWingR < 179) {
      angleWingL -= 30;
      angleWingR += 30;
      servWingR.write(angleWingR);
      servWingL.write(angleWingL);
      delay(5);
    }
  }
  else if (buttonWingStateL == HIGH && buttonWingStateR == LOW) {
    while (angleWingR > 1 && angleWingL < 179) {
      angleWingL += 35;
      angleWingR -= 35;
      servWingR.write(angleWingR);
      servWingL.write(angleWingL);
      delay(5);
    }
  }
  else {
    angleWingL = 90;
    angleWingR = 90;
    servWingR.write(angleWingR);
    servWingL.write(angleWingL);
  }

  // Cenários Rudder
  if (buttonRudderStateL == LOW && buttonRudderStateR == LOW) {
    angleRudder = 90;
    servRudder.write(angleRudder);
  }
  else if (buttonRudderStateL == LOW && buttonRudderStateR == HIGH) {
    while (angleRudder > 1 ) {
      angleRudder -= 30;
      servRudder.write(angleRudder);
      delay(5);
    }
  }
  else if (buttonRudderStateL == HIGH && buttonRudderStateR == LOW) {
    while (angleRudder < 179 ) {
      angleRudder += 30;
      servRudder.write(angleRudder);
      delay(5);
    }
  }
  else {
    angleRudder = 90;
    servRudder.write(angleRudder);
  }

  // Cenários Cauda
  if (buttonTailStateL == LOW && buttonTailStateR == LOW) {
    angleTail = 90;
    servTail.write(angleTail);
  }
  else if (buttonTailStateL == LOW && buttonTailStateR == HIGH) {
    while (angleTail > 1 ) {
      angleTail -= 30;
      servTail.write(angleTail);
      delay(5);
    }
  }
  else if (buttonTailStateL == HIGH && buttonTailStateR == LOW) {
    while (angleTail < 179 ) {
      angleTail += 30;
      servTail.write(angleTail);
      delay(5);
    }
  }
  else {
    angleTail = 90;
    servTail.write(angleTail);
  }

  delay(10);
}
