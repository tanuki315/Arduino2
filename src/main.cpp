#include <Arduino.h>
//2つのデジタル信号と1つのアナログ信号を受け取りそれらを構造体に格納するプログラムを作成
typedef struct{
    int digital_in1;
    int digital_in2;
    int analog_in;
}input;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void read(input in) {
  in.digital_in1 = digitalRead(2);
  in.digital_in2 = digitalRead(3);
  in.analog_in = analogRead(A0);
}