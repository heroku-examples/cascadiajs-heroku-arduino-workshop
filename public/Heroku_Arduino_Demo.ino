/* 
  Sketch generated by the Arduino IoT Cloud Thing "Charmine"
  https://create.arduino.cc/cloud/things/95278635-d1bb-4e44-89f8-7db9e6a753ca 

  Arduino IoT Cloud Properties description

  The following variables are automatically generated and updated when changes are made to the Thing properties

  String button1;
  String button2;
  String button3;
  String button4;
  String button5;
  String status;
  int pendingMessage;

  Properties which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"
#include <Arduino_MKRIoTCarrier.h>
MKRIoTCarrier carrier; //Constructor of the carrier maybe we can include it on the library itself

//Set the pad sense distance for using them with or without the enclosure
bool CARRIER_CASE = false;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();
  pendingMessage = -1;
  
  carrier.begin();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(4);
  ArduinoCloud.printDebugInfo();
  
  displayMainMenu();
}

void loop() {
  ArduinoCloud.update();
  carrier.Buttons.update();
  
  if (carrier.Button1.onTouchDown()) {
    displayButton(button1, 1);
  }

  if (carrier.Button2.onTouchDown()) {
    displayButton(button2, 2);
  }
    
  if (carrier.Button3.onTouchDown()) {
    displayButton(button3, 3);
  }

  if (carrier.Button4.onTouchDown()) {
    displayButton(button4, 4);
  }
    
  if (carrier.Button5.onTouchDown()) {
    displayButton(button5, 5);
  }
}

void displayButton(String buttonText, int button) {
  pendingMessage = button;
  carrier.display.fillScreen(ST77XX_GREEN);
  carrier.display.setTextColor(ST77XX_BLACK);
  carrier.display.setTextSize(3);
  carrier.display.setCursor(0, 0);
  carrier.display.println("Sent Message");
  carrier.display.println(buttonText);
  delay(5000);
  displayMainMenu();
}

void displayAck() {
  if (pendingMessage == 0) {
    carrier.display.fillScreen(ST77XX_GREEN);
    carrier.display.setTextColor(ST77XX_BLACK);
    carrier.display.setTextSize(3);
    carrier.display.setCursor(0, 0);
    carrier.display.println("Message Acknowledged");
    carrier.Buzzer.sound(8000);
    delay(500);
    carrier.Buzzer.noSound();
    delay(4500);
    pendingMessage = -1;
    displayMainMenu();
  }
}

void displayMainMenu() {
  carrier.display.fillScreen(ST77XX_BLACK);
  carrier.display.setTextColor(ST77XX_WHITE);
  carrier.display.setTextSize(3);
  carrier.display.setCursor(0, 0);
  carrier.display.print("Status: ");
  carrier.display.println(status);
  carrier.display.print("00: ");
  carrier.display.println(button1);
  carrier.display.print("01: ");
  carrier.display.println(button2);
  carrier.display.print("02: ");
  carrier.display.println(button3);
  carrier.display.print("03: ");
  carrier.display.println(button4);
  carrier.display.print("04: ");
  carrier.display.println(button5);
}

void onButton1Change() {
  displayMainMenu();
}

void onButton2Change() {
  displayMainMenu();
}

void onButton3Change() {
  displayMainMenu();
}

void onButton4Change() {
  displayMainMenu();
}

void onButton5Change() {
  displayMainMenu();
}

void onStatusChange() {
  displayMainMenu();
}

void onPendingMessageChange() {
  displayAck();
}
