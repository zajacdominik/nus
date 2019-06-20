#include <stdlib.h>
#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#ifndef X_CS_PIN
#define X_CS_PIN         53
#endif

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#ifndef Y_CS_PIN
#define Y_CS_PIN         49
#endif

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#ifndef Z_CS_PIN
#define Z_CS_PIN         40
#endif

// Limit Switches
//
#define X_MIN_PIN           3
#ifndef X_MAX_PIN
  #define X_MAX_PIN         2
#endif
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19


int a = 0, b = 0;
String komunikat;
int krok1 = 0;
int krok2 = 0;
int krok3 = 0;
int kier1 = 1;
int kier2 = 1;
int kier3 = 1;

void setup() {
  Serial.begin(115200);
  pinMode(X_ENABLE_PIN, OUTPUT);
  digitalWrite(X_ENABLE_PIN, LOW);
  pinMode(Y_ENABLE_PIN, OUTPUT);
  digitalWrite(Y_ENABLE_PIN, LOW);
  pinMode(Z_ENABLE_PIN, OUTPUT);
  digitalWrite(Z_ENABLE_PIN, LOW);

  pinMode(X_DIR_PIN, OUTPUT);
  digitalWrite(X_DIR_PIN, HIGH);
  pinMode(X_STEP_PIN, OUTPUT);

  pinMode(Y_DIR_PIN, OUTPUT);
  digitalWrite(Y_DIR_PIN, HIGH);
  pinMode(Y_STEP_PIN, OUTPUT);

  pinMode(Z_DIR_PIN, OUTPUT);
  digitalWrite(Z_DIR_PIN, HIGH);
  pinMode(Z_STEP_PIN, OUTPUT);

  pinMode(X_MAX_PIN, INPUT_PULLUP);
  pinMode(Y_MAX_PIN, INPUT_PULLUP);
  pinMode(Z_MAX_PIN, INPUT_PULLUP);


  // put your setup code here, to run once:

}

void loop() {

  //  //Serial.print("a\n");
  //  // put your main code here, to run repeatedly:
  //  digitalWrite(X_STEP_PIN, LOW);
  //  digitalWrite(Y_STEP_PIN, LOW);
  //  digitalWrite(Z_STEP_PIN, LOW);
  //  delay(5);
  //
  //  digitalWrite(X_STEP_PIN, HIGH);
  //  digitalWrite(Y_STEP_PIN, HIGH);
  //  digitalWrite(Z_STEP_PIN, HIGH);
  //  delay(5);
  //
  //    a++;
  //  if(a==100)
  //  {
  //      b=!b;
  //      digitalWrite(X_DIR_PIN, b);
  //      digitalWrite(Y_DIR_PIN, b);
  //      digitalWrite(Z_DIR_PIN, b);
  //      a=0;
  //  }


  if (krok1 > 0 && digitalRead(X_MAX_PIN)<1)
  {
    digitalWrite(X_STEP_PIN, HIGH);
    krok1--;
  }

  if (krok2 > 0 && digitalRead(Y_MAX_PIN)<1)
  {
    digitalWrite(Y_STEP_PIN, HIGH);
    krok2--;
  }

  if (krok3 > 0 && digitalRead(Z_MAX_PIN)<1)
  {
    digitalWrite(Z_STEP_PIN, HIGH);
    krok3--;
  }
  delay(5);
  digitalWrite(X_STEP_PIN, LOW);
  digitalWrite(Y_STEP_PIN, LOW);
  digitalWrite(Z_STEP_PIN, LOW);
  delay(5);


  while (Serial.available() > 0)
  {
    komunikat = Serial.readStringUntil('\n');
    sscanf(komunikat.c_str(), "sil %d %d %d", &krok1, &krok2, &krok3); //ruchy silnikami: kolejno 1,2,3
    
    kier1=krok1<0;
    digitalWrite(X_DIR_PIN, kier1);
    krok1=abs(krok1);
    kier2=krok2<0;
    digitalWrite(Y_DIR_PIN, kier2);
    krok2=abs(krok2);
    kier3=krok3<0;
    digitalWrite(Z_DIR_PIN, kier3);
    krok3=abs(krok3);
    
    Serial.println(krok1);

  }

//  Serial.println(digitalRead(X_MAX_PIN));
//  Serial.println(digitalRead(Y_MAX_PIN));
//  Serial.println(digitalRead(Z_MAX_PIN));

}



