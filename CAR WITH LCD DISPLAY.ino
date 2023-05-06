// C++ code
//
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int m1 = 4;
int m2 = 5;
int m3 = 6;
int m4 = 7;
int IR1 = 3;

char input;

void setup() {
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(IR1, INPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  Serial.begin(9600);
  lcd.begin();
}

void loop() {
  int potentiometer = analogRead(A0);
  int potent = potentiometer / 4;

  analogWrite(10, potent);
  analogWrite(11, potent);

  if (digitalRead(IR1 == HIGH)) {
    stop();
    backward();    
    delay(2000);
  } else {
    if (Serial.available()) {
      delay(100);
      lcd.clear();

      while (Serial.available()) {
        input = Serial.read();

        if (input == 'F') {
          forward();  
          lcd.print("Forward!!");
        } else if (input == 'R') {
          right();
          lcd.print("Right!!");  
        } else if (input == 'L') {
          left();  
          lcd.print("Left!!");
        } else if (input == 'G') {
          backward();  
          lcd.print("Backward!!");
        } else if (input == 'S') {
          stop();
          lcd.print("Stop!!");
        }
      }
    }
  }
}

void forward() {  
  digitalWrite(m2, HIGH);
  digitalWrite(m1, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}

void backward() {  
  digitalWrite(m2, LOW);
  digitalWrite(m1, HIGH);
  digitalWrite(m3, LOW);
  digitalWrite(m4, HIGH);
}

void left() {  
  digitalWrite(m2, LOW);
  digitalWrite(m1, HIGH);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}

void right() {  
  digitalWrite(m2, HIGH);
  digitalWrite(m1, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, HIGH);
}

void stop() {
  digitalWrite(m2, LOW);
  digitalWrite(m1, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
}
