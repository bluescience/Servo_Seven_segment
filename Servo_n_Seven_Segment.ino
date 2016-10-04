int i = 0;
int outputtable[10] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 111};                                                                        
int latchPin = 8;
int clockPin = 12;
int dataPin = 11;
long previousMillis = 0;
long interval = 500;
unsigned long currentMillis;
int k = 0;
int i = 0;
int j = 0;
bool enterCheck = false;

#include <Servo.h> 
 
int servoPin = 9;
 
Servo servo;  
 



void setup() {
  Serial.begin(115200);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  servo.attach(servoPin); 
}

void loop() {
  
  enterCheck = false; 
  i = 0;
  j = 0;
  k = 0;
  Serial.println(i);
  Serial.println(j);
  Serial.println(k);
  shiftOut(dataPin, clockPin, MSBFIRST, outputtable[i]);  
  shiftOut(dataPin, clockPin, MSBFIRST, outputtable[j]);  
  shiftOut(dataPin, clockPin, MSBFIRST, outputtable[k]);  
  while(!enterCheck){
 
  if(!digitalRead(5)){
      delay (300);
      enterCheck = true;
    }
  
  if(!digitalRead(2)){
      delay (200);
      k++;
      if(k > 9) {
        k = 0;
        }
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, outputtable[i]);  
      shiftOut(dataPin, clockPin, MSBFIRST, outputtable[j]);  
      shiftOut(dataPin, clockPin, MSBFIRST, outputtable[k]);  
      digitalWrite(latchPin, HIGH);
    }
    
  if(!digitalRead(3)){
      delay (200);
      j++;
      if(j > 9) {
        j = 0;
        }
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, outputtable[i]);  
      shiftOut(dataPin, clockPin, MSBFIRST, outputtable[j]); 
      shiftOut(dataPin, clockPin, MSBFIRST, outputtable[k]);   
      digitalWrite(latchPin, HIGH);
    }
  
  if(!digitalRead(4)){
      delay (200);
      i++;
      if(i > 9) {
        i = 0;
        }
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, outputtable[i]); 
      shiftOut(dataPin, clockPin, MSBFIRST, outputtable[j]); 
      shiftOut(dataPin, clockPin, MSBFIRST, outputtable[k]);  
      digitalWrite(latchPin, HIGH); 
    }   
  }
  int angle = i * 100 + j * 10 + k;
  Serial.println(angle);
  while(angle > 180){
    angle = angle - 180;
  }
  Serial.println(angle);
  servo.write(angle);
  
  while(currentMillis - previousMillis <= interval){
        currentMillis = millis();
        }
        previousMillis = currentMillis;
  enterCheck = false; 
}
