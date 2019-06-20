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
int a=0,b=0;

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

  
  // put your setup code here, to run once:

}

void loop() {
    
  //Serial.print("a\n");
  // put your main code here, to run repeatedly:
  digitalWrite(X_STEP_PIN, LOW);
  digitalWrite(Y_STEP_PIN, LOW);
  digitalWrite(Z_STEP_PIN, LOW);
  delay(5);
  
  digitalWrite(X_STEP_PIN, HIGH);
  digitalWrite(Y_STEP_PIN, HIGH);
  digitalWrite(Z_STEP_PIN, HIGH);
  delay(5);

    a++;
  if(a==100)
  {
      b=!b;
      digitalWrite(X_DIR_PIN, b);
      digitalWrite(Y_DIR_PIN, b);
      digitalWrite(Z_DIR_PIN, b);
      a=0;
  }

}
