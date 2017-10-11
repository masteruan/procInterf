 #include "Arduino.h"
 #include "SoftwareSerial.h"
 #include "DFRobotDFPlayerMini.h"

 int fog = 4;
 int button = A0;
 int relay = 3;
 boolean sign_button = true;

 SoftwareSerial mySoftwareSerial(11, 12); // RX, TX
 DFRobotDFPlayerMini myDFPlayer; 

 void setup() {
   pinMode(button, INPUT_PULLUP);
   pinMode(relay, OUTPUT);
   pinMode(fog, OUTPUT);
   digitalWrite(relay, HIGH);
   digitalWrite(fog, HIGH);
   mySoftwareSerial.begin(9600);
   //Serial.begin(115200);
   if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
     //Serial.println(F("Unable to begin:"));
     //Serial.println(F("1.Please recheck the connection!"));
     //Serial.println(F("2.Please insert the SD card!"));
     while(true);
   }
   delay(10);
//  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
//  myDFPlayer.EQ(DFPLAYER_EQ_POP);
//  myDFPlayer.EQ(DFPLAYER_EQ_ROCK);
//  myDFPlayer.EQ(DFPLAYER_EQ_JAZZ);
//  myDFPlayer.EQ(DFPLAYER_EQ_CLASSIC);
    myDFPlayer.EQ(DFPLAYER_EQ_BASS);
    myDFPlayer.enableDAC();  //Enable On-chip DAC
    myDFPlayer.volume(29);
//  myDFPlayer.play(1);
//  Serial.println("Setup OK");
   delay(2000);
}

 void loop() {
   sign_button = digitalRead(button);
   if (!sign_button) {
    sign_button = true;
    delay(300);
    sign_button = digitalRead(button);
    if (!sign_button) {
      //Serial.print("Bomb...");
      digitalWrite(fog, LOW);
      //Serial.print("Fog...");
      delay(100);
      myDFPlayer.play(1); // Boomb
      delay(50);
      digitalWrite(relay, LOW);
      //Serial.println("Open...");
      delay(40000);
      // myDFPlayer.play(1); // Electricity
      digitalWrite(fog, HIGH);
      while(true); // Stop all
    }
   }
}
