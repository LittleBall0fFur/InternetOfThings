#include <_HashMap.h>


#include "networkdevice.h"

NetworkDevice device;
int nightValue = 100;

void getDayOrNight(){
  String c = "";
  if(analogRead(A1) <= nightValue){
    c = String("RET;getValue;") + "nightTime";
  } else {
    c = String("RET;getValue;") + "dayTime";
  }
}

void getValue(){
  String c;
  if(((analogRead(A0) * 500) / 1023) >= 40) {
    c = String("RET;getValue;") + String(255) + String(",") + String(0) + String(",") + String(0);
  }
  if(((analogRead(A0) * 500) / 1023) >= 38 && ((analogRead(A0) * 500) / 1023) < 40) {
    c = String("RET;getValue;") + String(255) + String(",") + String(25) + String(",") + String(0);
  }
  if(((analogRead(A0) * 500) / 1023) >= 36 && ((analogRead(A0) * 500) / 1023) < 38) {
    c = String("RET;getValue;") + String(255) + String(",") + String(50) + String(",") + String(0);
  }
  if(((analogRead(A0) * 500) / 1023) >= 34 && ((analogRead(A0) * 500) / 1023) < 36) {
    c = String("RET;getValue;") + String(255) + String(",") + String(100) + String(",") + String(0);
  }
  if(((analogRead(A0) * 500) / 1023) >= 32 && ((analogRead(A0) * 500) / 1023) < 34) {
    c = String("RET;getValue;") + String(255) + String(",") + String(125) + String(",") + String(0);
  }
  if(((analogRead(A0) * 500) / 1023) >= 30 && ((analogRead(A0) * 500) / 1023) < 32) {
    c = String("RET;getValue;") + String(255) + String(",") + String(150) + String(",") + String(0);
  }
  if(((analogRead(A0) * 500) / 1023) >= 28 && ((analogRead(A0) * 500) / 1023) < 30) {
    c = String("RET;getValue;") + String(255) + String(",") + String(175) + String(",") + String(0);
  }
  if(((analogRead(A0) * 500) / 1023) >= 26 && ((analogRead(A0) * 500) / 1023) < 28) {
    c = String("RET;getValue;") + String(255) + String(",") + String(200) + String(",") + String(0);
  }
  if(((analogRead(A0) * 500) / 1023) >= 24 && ((analogRead(A0) * 500) / 1023) < 26) {
    c = String("RET;getValue;") + String(255) + String(",") + String(225) + String(",") + String(0);
  }
  if(((analogRead(A0) * 500) / 1023) >= 22 && ((analogRead(A0) * 500) / 1023) < 24) {
    c = String("RET;getValue;") + String(255) + String(",") + String(255) + String(",") + String(0);
  }
  if(((analogRead(A0) * 500) / 1023) >= 20 && ((analogRead(A0) * 500) / 1023) < 22) {
    c = String("RET;getValue;") + String(200) + String(",") + String(255) + String(",") + String(0);
  }
  if(((analogRead(A0) * 500) / 1023) >= 18 && ((analogRead(A0) * 500) / 1023) < 20) {
    c = String("RET;getValue;") + String(150) + String(",") + String(255) + String(",") + String(0);
  }
  if(((analogRead(A0) * 500) / 1023) >= 16 && ((analogRead(A0) * 500) / 1023) < 18) {
    c = String("RET;getValue;") + String(100) + String(",") + String(255) + String(",") + String(0);
  }
  if(((analogRead(A0) * 500) / 1023) >= 14 && ((analogRead(A0) * 500) / 1023) < 16) {
    c = String("RET;getValue;") + String(50) + String(",") + String(255) + String(",") + String(0);
  }
  if(((analogRead(A0) * 500) / 1023) >= 12 && ((analogRead(A0) * 500) / 1023) < 14) {
    c = String("RET;getValue;") + String(0) + String(",") + String(255) + String(",") + String(0);
  }
  if(((analogRead(A0) * 500) / 1023) >= 10 && ((analogRead(A0) * 500) / 1023) < 12) {
    c = String("RET;getValue;") + String(0) + String(",") + String(255) + String(",") + String(100);
  }
  if(((analogRead(A0) * 500) / 1023) >= 8 && ((analogRead(A0) * 500) / 1023) < 10) {
    c = String("RET;getValue;") + String(0) + String(",") + String(255) + String(",") + String(150);
  }
  if(((analogRead(A0) * 500) / 1023) >= 6 && ((analogRead(A0) * 500) / 1023) < 8) {
    c = String("RET;getValue;") + String(0) + String(",") + String(255) + String(",") + String(200);
  }
  if(((analogRead(A0) * 500) / 1023) >= 4 && ((analogRead(A0) * 500) / 1023) < 6) {
    c = String("RET;getValue;") + String(0) + String(",") + String(255) + String(",") + String(255);
  }
  if(((analogRead(A0) * 500) / 1023) >= 2 && ((analogRead(A0) * 500) / 1023) < 4) {
    c = String("RET;getValue;") + String(0) + String(",") + String(200) + String(",") + String(255);
  }
  if(((analogRead(A0) * 500) / 1023) >= 0 && ((analogRead(A0) * 500) / 1023) < 2) {
    c = String("RET;getValue;") + String(0) + String(",") + String(150) + String(",") + String(255);
  }
  if(((analogRead(A0) * 500) / 1023) <= -2 && ((analogRead(A0) * 500) / 1023) < 0) {
    c = String("RET;getValue;") + String(0) + String(",") + String(100) + String(",") + String(255);
  }
  if(((analogRead(A0) * 500) / 1023) <= -4 && ((analogRead(A0) * 500) / 1023) < -2) {
    c = String("RET;getValue;") + String(0) + String(",") + String(50) + String(",") + String(255);
  }
  if(((analogRead(A0) * 500) / 1023) <= -6 && ((analogRead(A0) * 500) / 1023) < -4) {
    c = String("RET;getValue;") + String(0) + String(",") + String(0) + String(",") + String(255);
  }
   if(((analogRead(A0) * 500) / 1023) <= -8 && ((analogRead(A0) * 500) / 1023) < -6) {
    c = String("RET;getValue;") + String(50) + String(",") + String(0) + String(",") + String(255);
  }
   if(((analogRead(A0) * 500) / 1023) <= -10 && ((analogRead(A0) * 500) / 1023) < -8) {
    c = String("RET;getValue;") + String(100) + String(",") + String(0) + String(",") + String(255);
  }
   if(((analogRead(A0) * 500) / 1023) <= -12 && ((analogRead(A0) * 500) / 1023) < -10) {
    c = String("RET;getValue;") + String(125) + String(",") + String(0) + String(",") + String(255);
  }
   if(((analogRead(A0) * 500) / 1023) <= -14 && ((analogRead(A0) * 500) / 1023) < -12) {
    c = String("RET;getValue;") + String(150) + String(",") + String(0) + String(",") + String(255);
  }
   if(((analogRead(A0) * 500) / 1023) <= -16 && ((analogRead(A0) * 500) / 1023) < -14) {
    c = String("RET;getValue;") + String(175) + String(",") + String(0) + String(",") + String(255);
  }
   if(((analogRead(A0) * 500) / 1023) <= -18 && ((analogRead(A0) * 500) / 1023) < -16) {
    c = String("RET;getValue;") + String(200) + String(",") + String(0) + String(",") + String(255);
  }
   if(((analogRead(A0) * 500) / 1023) <= -20 && ((analogRead(A0) * 500) / 1023) < -18) {
    c = String("RET;getValue;") + String(255) + String(",") + String(0) + String(",") + String(255);
  }
  device.SendMessageToServer(c);
}

String n = "TempratureDevice";
String desc = "This device returns a temprature.";

void setup() {
  pinMode(A0,INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
  
  device.RegisterCommand("REGRET", "getValue", &getValue, "1"); // TODO: int = 0, float = 1, bool = 2, string = 3
  device.RegisterCommand("REGRET", "getDayOrNight", &getDayOrNight ,"3"); // TODO: int = 0, float = 1, bool = 2, string = 3
  bool done = done = device.Init("AABBCCDD11223344", n, desc);
  while (!done)
  {
    done = device.Init("AABBCCDD11223344", n, desc);
  }
}

void loop() {
  if (!client.connected()) {
    bool done = device.Init("AABBCCDD11223344", n, desc);
    while (!done)
    {
      done = device.Init("AABBCCDD11223344", n, desc);
    }
  }
  device.HandleCommand();
  Serial.println((analogRead(A0) * 500) / 1023);
  Serial.println(analogRead(A1));
  delay(1000);
}
