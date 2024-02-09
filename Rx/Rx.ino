#include <VirtualWire.h>

int IN1 = 11;  //right
int IN2 = 3;   //right
int IN3 = 6;   //left
int IN4 = 5;   //left
// int lwdPin = 2;
// int trigPin = 8;
// int echoPin = 9;
// long duration;
// int distance;

int speedH = 120;
int speedT = 0;
int speedL = 0;

void setup() {
  Serial.begin(9600);
  vw_set_rx_pin(12);
  vw_setup(2000);
  // pinMode(lwdPin,OUTPUT);
// Serial.println("workig");

  // pinMode(trigPin, OUTPUT); 
  // pinMode(echoPin, INPUT); 

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  // pinMode(2, OUTPUT);
  vw_rx_start();
}

void loop() {

  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  // Serial.println("char(buf[0])");
  // digitalWrite(2, HIGH);
  // digitalWrite(IN1, HIGH);
  // digitalWrite(IN2, LOW);
  // digitalWrite(IN3, speedL);
  // digitalWrite(IN4, speedH);
  // digitalWrite(trigPin, LOW);
  // delayMicroseconds(2);
  // // Sets the trigPin on HIGH state for 10 micro seconds
  // digitalWrite(trigPin, HIGH);
  // delayMicroseconds(10);
  // digitalWrite(trigPin, LOW);
  // // Reads the echoPin, returns the sound wave travel time in microseconds
  // duration = pulseIn(echoPin, HIGH);
  // // Calculating the distance
  // distance = duration * 0.034 / 2;
  
  // if(distance < 15) {stop(); return;}

    if(vw_get_message(buf, &buflen)){
      Serial.println(char(buf[0]));
      if (buf[0] == 'f'){
        // Serial.println("forward");
        forward();
        // analogWrite(lwdPin,speedH);
      }
      else if (buf[0] == 'b'){
          reverse();
      }
      else if (buf[0] == 'r'){
        right();
      }
      else if (buf[0] == 'l'){
        left();
      }else if (buf[0] == 's'){
        stop();
      }
      // else{
      //   // Serial.println("stop");
      //   // analogWrite(lwdPin,speedL);
      //   // stop();
      // }


  delay(200);

    }
}

void forward() {
  analogWrite(IN1, speedL);
  analogWrite(IN2, speedH);
  analogWrite(IN3, speedL);
  analogWrite(IN4, speedH);
  // Serial.println("frrward");
}
void reverse() {
  analogWrite(IN1, speedH);
  analogWrite(IN2, speedL);
  analogWrite(IN3, speedH);
  analogWrite(IN4, speedL);
}

void right() {
  analogWrite(IN1, speedH);
  analogWrite(IN2, speedL);
  analogWrite(IN3, speedL);
  analogWrite(IN4, speedH);
}
void left() {
  analogWrite(IN1, speedL);
  analogWrite(IN2, speedH);
  analogWrite(IN3, speedH);
  analogWrite(IN4, speedL);
}
void stop() {
  analogWrite(IN1, speedL);
  analogWrite(IN2, speedL);
  analogWrite(IN3, speedL);
  analogWrite(IN4, speedL);
  Serial.println("stop");
}
