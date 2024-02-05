#include <Arduino.h>
#include <avr/interrupt.h>
//2つのデジタル信号と1つのアナログ信号を受け取りそれらを構造体に格納するプログラムを作成
typedef struct{
    int digital_in1;
    int digital_in2;
    int analog_in;
}input;

input in;
void read() {
  in.digital_in2 = digitalRead(3);
  in.analog_in = analogRead(A0);
}

ISR(INT0_vect) {
  EIMSK = 0b00000000;
  in.digital_in1 = digitalRead(2);
  EIMSK = 0b00000001;
}

void setup() {
  // put your setup code here, to run once:
  DDRD = 0b11110000;
  DDRB = 0b00111111;
  EIMSK = 0b00000001;
  Serial.begin(9600);
}
 void loop() {
  // put your main code here, to run repeatedly:
  read();
  Serial.print("digital_in1: ");
  Serial.print(in.digital_in1);
  Serial.print(" digital_in2: ");
  Serial.print(in.digital_in2);
  Serial.print(" analog_in: ");
  Serial.println(in.analog_in);
  delay(1000);
 }