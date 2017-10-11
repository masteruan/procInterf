 // Riconoscitore vocale 10 Ottobre
 // fltro input
 
 #include "Arduino.h"
 #include "SoftwareSerial.h"
 #include "DFRobotDFPlayerMini.h"

 int relay = 5;
 int verde = 7;
 int giallo = 3;
 int button = A0;
 int OK = A2;

 boolean sign_OK = true;
 boolean sign_button = true;

 SoftwareSerial mySoftwareSerial(11, 12); // RX, TX
 DFRobotDFPlayerMini myDFPlayer; 

 void setup() {
   pinMode(verde, OUTPUT);
   pinMode(giallo, OUTPUT);
   pinMode(button, INPUT_PULLUP);
   pinMode(OK, INPUT_PULLUP);
   pinMode(relay, OUTPUT);
   digitalWrite(relay, HIGH);
   mySoftwareSerial.begin(9600);
   Serial.begin(115200);
   if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
     Serial.println(F("Unable to begin:"));
     Serial.println(F("1.Please recheck the connection!"));
     Serial.println(F("2.Please insert the SD card!"));
     while(true);
   }
   
   delay(10);
   myDFPlayer.volume(30);
   //myDFPlayer.play(2);
   Serial.println("Setup OK");
   delay(2000);
}

 void loop() {
   sign_button = digitalRead(button);
   delay(50);
   if (!sign_button) {
     sign_button = true;
     delay(300);
     sign_button = digitalRead(button);
     if (!sign_button){
       delay(20);
       myDFPlayer.play(1); // Pronunciare Password
       Serial.print("Password...");
       delay(50);
       digitalWrite(giallo, HIGH);
       delay(4000);
       sign_OK = digitalRead(OK);
       if (!sign_OK) {
         sign_OK = true;
         delay(200);
         sign_OK = digitalRead(OK);
         if (!sign_OK){
           digitalWrite(giallo, LOW);
           digitalWrite(verde, HIGH);
           Serial.println("Accesso consentito...");
           myDFPlayer.play(3); // Accesso consentito
           digitalWrite(relay, LOW);
         }
        }
        else {
           digitalWrite(giallo, LOW);
           Serial.println("Accesso negato...");
           myDFPlayer.play(2); // Accesso negato
           delay(200);
           digitalWrite(verde, LOW);
         }
     }
   }
}
