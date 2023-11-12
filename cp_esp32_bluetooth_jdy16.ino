#include <SoftwareSerial.h>

#define BLUETOOTH_JDY16_TX_PIN 16 // TX pin of BT JDY16
#define BLUETOOTH_JDY16_RX_PIN 17 // RX pin of BT JDY16

SoftwareSerial bt(BLUETOOTH_JDY16_TX_PIN, BLUETOOTH_JDY16_RX_PIN);

void setup() {
  Serial.begin(115200);

  Serial.println("Serial inited");
  delay(2000);

  bt.begin(9600);
  Serial.println("Bluetooth inited");

  bt.println("AT\r\n");
  updateSerial();
  Serial.println();
  bt.println("AT+VER\r\n");
  updateSerial();
}

void loop() {
  updateSerial();
}


void updateSerial()
{
  delay(500);
  while (Serial.available()) {
    //Serial.println("input data");
    bt.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(bt.available()) {
    Serial.write(bt.read());//Forward what Software Serial received to Serial Port
  }
}