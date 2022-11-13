#include <Servo.h>
#include "BluetoothSerial.h"

BluetoothSerial ESP_BT;
Servo sv;

int incoming;  //Incoming data from Smart Phone
int LED_1 = 26;
int LED_2 = 27;
int flag = 0;

void setup() {
  Serial.begin(115200);      //Start Serial monitor in 115200
  ESP_BT.begin("Door Kye");  //Name of your Bluetooth Signal
  Serial.println("Bluetooth Device is Ready to Pair");

  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  sv.attach(25);
}

void loop() {

  if (ESP_BT.available())  //Check if we receive anything from Bluetooth
  {
    incoming = ESP_BT.read();  //Read what we recevive
    Serial.print("Received:");
    Serial.println(incoming);
    

    if (incoming == 49) {
      sv.write(0);
      digitalWrite(LED_1, HIGH);
      digitalWrite(LED_2, LOW);
      ESP_BT.println("Open");
      incoming = NULL;
      delay(10);
    }
    if (incoming == 50) {
      sv.write(90);
      digitalWrite(LED_1, LOW);
      digitalWrite(LED_2, HIGH);
      ESP_BT.println("Close");
      incoming = NULL;
      delay(10);
    } 
  }
  delay(20);
}