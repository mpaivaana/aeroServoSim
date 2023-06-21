#include <Servo.h>
//Declaração dos pinos dos botões
const int asaButtonL = 8;
const int asaButtonR = 7;
const int lemeButtonR = 2;
const int lemeButtonL = 12;
const int rudderButtonUp = 13;
const int rudderButtonDown = 10;

//Declaração dos pinos dos motores
const int asaR = 6;
const int asaL = 5;
const int leme = 3;
const int rudder = 9;

//Declara os objetos servos
Servo servAsaR;
Servo servAsaL;
Servo servLeme;
Servo servRudder;

//Variavéis auxiliares de estado dos botões 
int buttonAsaStateL = 0;
int buttonAsaStateR = 0;
int buttonLemeStateL = 0;
int buttonLemeStateR = 0;
int buttonRudderStateL = 0;
int buttonRudderStateR = 0;

// Variáveis auxiliares de ângulo
int angleAsaL = 90;
int angleAsaR = 90;
int angleLeme = 90;
int angleRudder = 90;

void setup() {
  // Associando um objeto da classe Servo a sua respectiva pinagem
  servAsaR.attach(asaR);
  servAsaL.attach(asaL);
  servLeme.attach(leme);
  servRudder.attach(rudder);

  // Definindo o modo dos botões
  pinMode(asaButtonL, INPUT_PULLUP);
  pinMode(asaButtonR, INPUT_PULLUP);
  pinMode(lemeButtonR, INPUT_PULLUP);
  pinMode(lemeButtonL, INPUT_PULLUP);
  pinMode(rudderButtonUp, INPUT_PULLUP);
  pinMode(rudderButtonDown, INPUT_PULLUP);
}

void loop() {
  // Associa a pinagem dos botões à variável auxiliar de estado
  buttonAsaStateL = digitalRead(asaButtonL);
  buttonAsaStateR = digitalRead(asaButtonR);
  buttonLemeStateL = digitalRead(lemeButtonL);
  buttonLemeStateR = digitalRead(lemeButtonR);
  buttonRudderStateL = digitalRead(rudderButtonDown);
  buttonRudderStateR = digitalRead(rudderButtonUp);

  // Cenários Asa
  if (buttonAsaStateL == LOW && buttonAsaStateR == LOW) {
    angleAsaL = 90;
    angleAsaR = 90;
    servAsaR.write(angleAsaR);
    servAsaL.write(angleAsaL);
  }
  else if (buttonAsaStateL == LOW && buttonAsaStateR == HIGH) {
    while (angleAsaL > 1 && angleAsaR < 179) {
      angleAsaL -= 30;
      angleAsaR += 30;
      servAsaR.write(angleAsaR);
      servAsaL.write(angleAsaL);
      delay(5);
    }
  }
  else if (buttonAsaStateL == HIGH && buttonAsaStateR == LOW) {
    while (angleAsaR > 1 && angleAsaL < 179) {
      angleAsaL += 35;
      angleAsaR -= 35;
      servAsaR.write(angleAsaR);
      servAsaL.write(angleAsaL);
      delay(5);
    }
  }
  else {
    angleAsaL = 90;
    angleAsaR = 90;
    servAsaR.write(angleAsaR);
    servAsaL.write(angleAsaL);
  }

  // Cenários Leme
  if (buttonLemeStateL == LOW && buttonLemeStateR == LOW) {
    angleLeme = 90;
    servLeme.write(angleLeme);
  }
  else if (buttonLemeStateL == LOW && buttonLemeStateR == HIGH) {
    while (angleLeme > 1 ) {
      angleLeme -= 30;
      servLeme.write(angleLeme);
      delay(5);
    }
  }
  else if (buttonLemeStateL == HIGH && buttonLemeStateR == LOW) {
    while (angleLeme < 179 ) {
      angleLeme += 30;
      servLeme.write(angleLeme);
      delay(5);
    }
  }
  else {
    angleLeme = 90;
    servLeme.write(angleLeme);
  }

  // Cenários Cauda
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

  delay(10);
}