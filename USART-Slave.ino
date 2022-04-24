int latchPin = 5;  // Latch pin of 74HC595 is connected to Digital pin 5
int clockPin = 6; // Clock pin of 74HC595 is connected to Digital pin 6
int dataPin = 4;  // Data pin of 74HC595 is connected to Digital pin 4

int slide = 12;
int btn1 = 8;
int btn2 = 9;
int btn3 = 10;

int com=0;
int val=255;
int flag=0;

void shift(){
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, val);
  digitalWrite(latchPin, HIGH);
}

void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  pinMode(btn1, OUTPUT);
  pinMode(btn2, OUTPUT);
  pinMode(btn3, OUTPUT);
  pinMode(slide, OUTPUT);
  shift();
}

void loop() {
  if(Serial1.available()){
    com = Serial1.read();
    if(com==51){
      flag=1;
    }
    else if(com==52){
      flag=2;
    }
    else if(com==53){
      flag=0;
      val=0;
      com=0;
      shift();
      digitalWrite(btn1,LOW);
      digitalWrite(btn2,LOW);
      digitalWrite(btn3,LOW);
      analogWrite(slide, com);
    }
    if(com!=51 && flag==1){
      if (com>100){
        com = com-256;
      }
      val = val+com;
      Serial.println(val);
      shift();
    }
    else if(com!=52 && flag==2){
      Serial.println(com);
      if(com==1) {
        digitalWrite(btn1,LOW);
      }
      else if(com==2) {
        digitalWrite(btn1,HIGH);
      }
      else if(com==3) {
        digitalWrite(btn2,LOW);
      }
      else if(com==4) {
        digitalWrite(btn2,HIGH);
      }
      else if(com==5) {
        digitalWrite(btn3,LOW);
      }
      else if(com==6) {
        digitalWrite(btn3,HIGH);
      }
      else {
        analogWrite(slide, com);
      }
    }
  }
}
