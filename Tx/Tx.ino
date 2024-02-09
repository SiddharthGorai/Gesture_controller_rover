#include <VirtualWire.h>

char *data;
char *data1;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  vw_set_tx_pin(8);
  vw_setup(2000);
  pinMode(13, OUTPUT);
}

void loop() {

  if (Serial.available()) {
    data = Serial.read();
    // data = "A";
    // Serial.println(data);

    if (data == 'W') {
      // digitalWrite(13, HIGH);
      data1 = "f";
      vw_send((uint8_t *)data1, strlen(data1));
      vw_wait_tx();
    }


    if (data == 'S') {
      // digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      // Serial.println(data);
      data1 = "b";
      vw_send((uint8_t *)data1, strlen(data1));
      vw_wait_tx();
    }
    if (data == 'A') {
      // digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      // Serial.println(data);
      data1 = "l";
      vw_send((uint8_t *)data1, strlen(data1));
      vw_wait_tx();
    }
    if (data == 'D') {
      // digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      // Serial.println(data);
      data1 = "r";
      vw_send((uint8_t *)data1, strlen(data1));
      vw_wait_tx();
    }
    if (data == 'Q') {
      // digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      // Serial.println(data);
      data1 = "s";
      vw_send((uint8_t *)data1, strlen(data1));
      vw_wait_tx();
    }
    // delay(200);
  }
}