#include <Arduino.h>
//2つのデジタル信号と1つのアナログ信号を受け取りそれらを構造体に格納するプログラムを作成
typedef struct{
    int digital_in1;
    int digital_in2;
    int analog_in;
}input;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  input in;
  in.digital_in1 = digitalRead(2);
  in.digital_in2 = digitalRead(3);
  in.analog_in = analogRead(A0);
  Serial.print("digital_in1: ");
  Serial.print(in.digital_in1);
  Serial.print(" digital_in2: ");
  Serial.print(in.digital_in2);
  Serial.print(" analog_in: ");
  Serial.println(in.analog_in);
  delay(1000);
}