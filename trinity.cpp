// C++ code
//
#include <Servo.h>

int potD = 0;

int potE = 0;

int led1 = 0;

int led2 = 0;

int led3 = 0;

int i = 0;

int PDsup = 0;

int PDinf = 0;

int PEsup = 0;

int PEinf = 0;

int j = 0;

int k = 0;

int ACESSO = 0;

int unnamed = 0;

int q = 0;

Servo servo_12;

int counter;

int counter2;

int counter3;

int counter4;

void setup()
{
  servo_12.attach(12, 500, 2500);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);

  servo_12.write(0);
  for (counter = 0; counter < 5; ++counter) {
    analogWrite(9, 0);
    analogWrite(10, 0);
    analogWrite(11, 0);
    delay(100); // Wait for 100 millisecond(s)
    analogWrite(9, 255);
    analogWrite(10, 255);
    analogWrite(11, 255);
    delay(100); // Wait for 100 millisecond(s)
  }
  PDsup = 131;
  PDinf = 126;
  PEsup = 68;
  PEinf = 63;
  led3 = 1;
  ACESSO = LOW;
  j = 0;
  k = 180;
}

void loop()
{
  j = j;
  k = k;
  potD = map(analogRead(A0), 0, 1023, j, k);
  potE = map(analogRead(A1), 0, 1023, j, k);
  Serial.print("potD: ");
  Serial.print(potD);
  Serial.print("  potE: ");
  Serial.println(potE);
  ACESSO = ACESSO;
  if (potD >= PDinf && potD <= PDsup) {
    digitalWrite(11, HIGH);
    led1 = led3;
  } else {
    analogWrite(11, ACESSO);
    led1 = 0;
  }
  if (potE >= PEinf && potE <= PEsup) {
    digitalWrite(9, HIGH);
    led2 = led3;
  } else {
    analogWrite(9, ACESSO);
    led2 = 0;
  }
  if (led1 == 1 && led2 == 1) {
    PEsup = 7;
    PEinf = 0;
    PDsup = 7;
    PDinf = 0;
    led3 = 2;
    digitalWrite(9, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    delay(500); // Wait for 500 millisecond(s)
    for (i = 0; i <= 255; i += 5) {
      analogWrite(10, i);
      delay(10); // Wait for 10 millisecond(s)
    }
    delay(500); // Wait for 500 millisecond(s)
    for (i = 255; i >= 0; i -= 5) {
      analogWrite(10, i);
      delay(10); // Wait for 10 millisecond(s)
    }
  }
  if (led1 == 2 && led2 == 2) {
    PEsup = 7;
    PEinf = 0;
    PDsup = 180;
    PDinf = 173;
    led3 = 3;
    for (counter2 = 0; counter2 < 5; ++counter2) {
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      delay(200); // Wait for 200 millisecond(s)
      digitalWrite(9, LOW);
      digitalWrite(11, LOW);
      delay(200); // Wait for 200 millisecond(s)
    }
    digitalWrite(10, HIGH);
  }
  if (led1 == 3 && led2 == 3) {
    for (counter3 = 0; counter3 < 10; ++counter3) {
      digitalWrite(10, HIGH);
      delay(100); // Wait for 100 millisecond(s)
      digitalWrite(10, LOW);
      delay(100); // Wait for 100 millisecond(s)
    }
    led3 = 4;
    PEsup = 160;
    PEinf = 153;
    PDsup = 30;
    PDinf = 23;
  }
  if (led1 == 4 && led2 == 4) {
    led3 = 5;
    PEsup = 93;
    PEinf = 85;
    PDsup = 7;
    PDinf = 0;
    for (counter4 = 0; counter4 < 5; ++counter4) {
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      delay(200); // Wait for 200 millisecond(s)
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
      delay(200); // Wait for 200 millisecond(s)
    }
  }
  if (led1 == 5 && led2 == 5) {
    ACESSO = HIGH;
    PEsup = 180;
    PEinf = 0;
    PDsup = 180;
    PDinf = 0;
    j = 0;
    k = 90;
    digitalWrite(10, HIGH);
    potD = map(analogRead(A0), 0, 1023, j, k);
    potE = map(analogRead(A1), 0, 1023, j, k);
    Serial.println("ABERTO/OPEN");
    Serial.println("GIRE/ TURN");
    servo_12.write(potD);
    if (potE >= 0 && potE <= 40 || potE >= 50 && potE < 90) {
      Serial.println("IT'S A TRAP!");
      servo_12.write(0);
      j = 0;
      k = 180;
      led3 = 1;
      ACESSO = LOW;
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
    }
  }
  delay(10); // Wait for 10 millisecond(s)
}