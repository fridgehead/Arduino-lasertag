#define SPEAKER  9
#define TRIGGER  3
#define LED      2


#define DATAPIN         4
#define LATCHPIN     6
#define CLOCKPIN        5


/*
Shield test sketch

For testing newly built shields
> button causes buzzer to beep
> health and shield LEDS will cycle


*/

int v = 1;
long lastChangeTime = 0;
void setup(){
  
  pinMode(SPEAKER, OUTPUT);
  pinMode(TRIGGER,INPUT);
  digitalWrite(TRIGGER, HIGH);
  
  
  pinMode( LATCHPIN, OUTPUT);
  pinMode( DATAPIN, OUTPUT);
  pinMode( CLOCKPIN, OUTPUT);
  
  digitalWrite(LATCHPIN, LOW);
  shiftOut(DATAPIN, CLOCKPIN, MSBFIRST, 255);
  shiftOut(DATAPIN, CLOCKPIN, MSBFIRST, 255);
  digitalWrite(LATCHPIN,HIGH);
}


void loop(){
  if(digitalRead(TRIGGER) == LOW){
    analogWrite(SPEAKER, 100);
   
  } else {
    analogWrite(SPEAKER, 0);
    
  }
  
  if(lastChangeTime + 500 < millis()){
    lastChangeTime = millis();
    v = v << 1;
    v = v % 0xFF;
    digitalWrite(LATCHPIN, LOW);
    shiftOut(DATAPIN, CLOCKPIN, MSBFIRST, v);
    shiftOut(DATAPIN, CLOCKPIN, MSBFIRST, v);
    digitalWrite(LATCHPIN,HIGH);
  }
  
}
