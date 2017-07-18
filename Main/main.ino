/*
 Main Hostel
 18 Luglio 2017
 v 1.0

OUTPUT
Porte
P1 cella uno
P2 cella due
P3 cella tre
P4 cella quattro
P5 fake
P6 porta spavento
P7 porta uscita
P8 porta ingresso

Calamite
C1 armadio cella uno
C2 polsi poltrona
C3 scatola cella tre
C4 scatola cella quattro
C5 scatola dopo fusibili in corrdoio
C6 grata

Arduino
M1 Grata

Luci
L1 neon
L2 lampeggiante

INPUT
G1 tastierino numerico cella uno
G2 interruttore cella 2 stacca polsi
G3 cavi jack per scatola cella tre
G4 deviatori tre posizioni
G5 leva apricelle
G6 fusibili corridoio
G7 detonatore
G8 scansione retina

Instructions
Send to serial
"_preparation" to close all the doors and switch on all the lights
"_startGame" to start the game
"_openAll" open all the doors
*/

// Libraries
#include "Arduino.h"

// switch
boolean start_game = false;
boolean game_started = false;

// serial
boolean stringComplete = false;
String input = ""; //String
char inChar ;

// input Variables
int games[] = {A0,A1,A2,A3,A4,A5,A6,A7};

int in_cella1 = A0;
boolean sign_cella1 = true;
boolean OK_cella1 = false;

int in_cella2 = ;
boolean sign_cella2 = false;
boolean OK_cella2 = false;

int in_cella3 = ;
boolean sign_cella3 = true;
boolean OK_cella3 = false;

int in_cella4 = ;
boolean sign_cella4 = true;
boolean OK_cella4 = false;

int in_fusibili = ;
boolean sign_fusibili = true;
boolean OK_fusibili = false;

int in_grata = ;
boolean sign_grata = true;
boolean OK_grata = false;

// out
int M1 = ; // arduino nella grata
int L1 = ; // neon
int L2 = ; // lampeggiante

// calamite
int C1 = ; //armadio cella uno
int C2 = ; //polsi poltrona
int C3 = ; //scatola cella tre
int C4 = ; //scatola cella quattro
int C5 = ; //scatola dopo fusibili in corrdoio
int C6 = ; //grata

// Porte
int P1 = ;
int P2 = ;
int P3 = ;
int P4 = ;
int P5 = ;
int P6 = ;
int P7 = ;
int P8 = ;

void setup() {
  Serial.flush();

  // OUTPUT
  for (int i = 2; i < 7; i++){
    pinMode(i, OUTPUT);
  }
  
  // INPUT
  // This input give FALSE if the input is open TRUE if the input is closed
  for (int i = 0; i < 13; i++){
      pinMode(games[i], INPUT_PULLUP);
  }

  // Start up serial connection
  Serial.begin(9600); //default 115200
  input.reserve(200);

  Serial.println("################");
  Serial.println("You are Welcome!");
}

void loop() {
  if (stringComplete) {
    //Serial.println(input);
    seriale();
    input = "";
    stringComplete = false;
  }
  game();
  //lettura();
}

void game () {
   if (start_game){

      // reset booleane
      OK_cella1 = false;
      OK_cella2 = false;
      OK_cella3 = false;
      OK_cella4 = false;
      OK_fusibili = false;
      OK_grata = false;
      
      // Close all doors
      digitalWrite(P1, HIGH);
      digitalWrite(P2, HIGH);
      digitalWrite(P3, HIGH);
      digitalWrite(P4, HIGH);
      digitalWrite(P5, HIGH);
      digitalWrite(P6, HIGH);
      digitalWrite(P7, HIGH);
      digitalWrite(P8, HIGH);
      
      // off lights
      digitalWrite(L1, LOW);
      digitalWrite(L2, LOW);
      
      start_game = false;
      game_started = true;
      Serial.println("gameStarted");
  }

  else if (game_started){
    digitalWrite(valvole, HIGH);
    sign_valvole = digitalRead(in_valvole);
    if ((!sign_valvole || H_valvole) && !OK_valvole){
    Serial.println("valvoleDone");
    digitalWrite(danger, HIGH); // switch off "DANGER"
    digitalWrite(motore, HIGH); // switch on motor
    digitalWrite(M1, LOW); // open the door
    OK_valvole = true;
    }
    delay(10);
    if(OK_valvole){
    sign_generatore = digitalRead(in_generatore);
    }
    if ((!sign_generatore || H_generatore) && !OK_generatore){
    for(int i=0; i <5 ;i++ ) Serial.println("generatoreDone");
    digitalWrite(luce_quarto, HIGH);
    //digitalWrite(luce_terzo, HIGH);
    OK_generatore = true;
    }
    if(OK_generatore){
    sign_motore = digitalRead(in_motore);
    }
    if ((!sign_motore || H_motore) && !OK_motore){
    for(int i=0; i <5 ;i++ ) Serial.println("motoreDone");
    digitalWrite(M2, LOW); // open the door
    digitalWrite(M11, LOW);
    delay(2000);
    //digitalWrite(luce_terzo, LOW);
    //digitalWrite(luce_quarto, LOW);
    digitalWrite(monaco, HIGH);
    OK_motore = true;
    }

    // if the players are on the second floor
    if (second_floor && !OK_secondFloor){
    digitalWrite(M11, HIGH); //cella croce
    delay(200);
    digitalWrite(monaco, LOW);
    digitalWrite(candele, HIGH);
    OK_secondFloor = true;
    }
    // waiting for operator "_vent" & off tutti i caschi
    // waiting for operator unlock the BIG BOX (JOHN JAVA) _scatolaGrande
    if (OK_secondFloor){
    sign_croce = digitalRead(in_croce);
    }
    if ((!sign_croce || H_croce) && !OK_croce){
    for(int i=0; i <5 ;i++ ) Serial.println("croceDone");
    digitalWrite(M7, HIGH); //sblocca scatola piccola
    delay(20);
    digitalWrite(M11, LOW); //cella della croce
    delay(20);
    digitalWrite(foto, HIGH);
    OK_croce = true;
    }
    if(OK_croce) {
    sign_foto = digitalRead(in_foto);
    }
    if ((!sign_foto || H_foto) && !OK_foto){
    for(int i=0; i <5 ;i++ ) Serial.println("fotoDone");
    digitalWrite(stereo, HIGH);
    delay(3000);
    digitalWrite(culla, HIGH); // accende la culla
    delay(20);
    OK_foto = true;
    }
    if(OK_foto) {
    sign_stereo = digitalRead(in_stereo);
    }
    if ((!sign_stereo || H_stereo) && !OK_stereo){
    for(int i=0; i <5 ;i++ ) Serial.println("stereoDone");
    digitalWrite(culla, LOW);
    delay(4000);
    digitalWrite(stereo, LOW);
    delay(1000);
    digitalWrite(culla, HIGH);
    OK_stereo = true;
    }
    if(OK_stereo) {
    sign_culla = digitalRead(in_culla);
    }
    if ((!sign_culla || H_culla) && !OK_culla){
    for(int i=0; i <5 ;i++ ) Serial.println("cullaDone");
    digitalWrite(M10, LOW); // sblocca cella timone
    delay(50);
    // special sound timone
    digitalWrite(4, 1);
    digitalWrite(5, 1);
    myDFPlayer.volume(30); // min = 0 max = 30
    myDFPlayer.play(3);
    delay(100);
    digitalWrite(timone, HIGH);
    digitalWrite(M7, LOW); //rilascia la calamita scatola piccola
    OK_culla = true;
    }
    if(OK_culla){
    sign_timone = digitalRead(in_timone);
    }
    if ((!sign_timone || H_timone) && !OK_timone) {
    for(int i=0; i <5 ;i++ ) Serial.println("timoneDone");
    digitalWrite(M9, LOW); //sblocca la porta per gli orologi
    digitalWrite(orologi, HIGH);
    OK_timone = true;
    }
    delay(1000);
    if(OK_timone){
    sign_orologi = digitalRead(in_orologi);
    }
    if ((!sign_orologi || H_orologi) && !OK_orologi) {
    for(int i=0; i <5 ;i++ ) Serial.println("orologiDone");
    digitalWrite(M5, LOW);// apre porta per il nano
    //digitalWrite(luce_primo, HIGH);
    delay(6000);
    digitalWrite(nano, HIGH);
    delay(100);
    digitalWrite(organo, HIGH);
    delay(200);
    digitalWrite(pulsanti, HIGH);
    OK_orologi = true;
    }
    if(OK_orologi){
    sign_organo = digitalRead(in_interruttori);
    }
    if ((!sign_organo || H_organo) && !OK_organo) {
    for(int i=0; i <5 ;i++ ) Serial.println("organoDone");
    digitalWrite(nano,LOW);
    digitalWrite(luce_secondo, HIGH); // accendi la luce finale
    delay(10000);
    digitalWrite(mano, HIGH);
    OK_organo = true;
    }
    if(OK_organo){
    //reset all
    }
  }
}

void lettura() {
  sign_cella1 = digitalRead(in_cella1);
  delay(10);
  sign_cella2 = !digitalRead(in_cella2);
  delay(10);
  sign_cella3 = digitalRead(in_cella3);
  delay(10);
  sign_cella4 = digitalRead(in_cella4);
  delay(10);
  sign_fusibili = digitalRead(in_fusibili);
  delay(10);
  sign_grata = digitalRead(in_grata);
  
  if (!sign_valvole){
    Serial.println("valvole risolte");
  }
  delay(100);
  if (!sign_generatore){
    Serial.println("generatore risolto");
  }
  delay(100);
  if (!sign_motore){
    Serial.println("motore risolte");
  }
  delay(100);
  if (!sign_interruttori){
    Serial.println("interruttori risolti");
  }
  delay(100);
  if (!sign_stereo){
    Serial.println("stereo risolte");
  }
  delay(100);
  if(!sign_culla){
    Serial.println("culla risolta");
  }
  delay(100);
  if(!sign_croce){
    Serial.println("croce risolta");
  }
  delay(100);
  if(!sign_foto){
    Serial.println("foto risolta");
  }
  delay(100);
  if(!sign_timone){
    Serial.println("timone risolto");
  }
  delay(100);
  if(!sign_orologi){
    Serial.println("orologi risolti");
  }
  delay(100);
  if(!sign_organo){
    Serial.println("organo risolto");
  }
  delay(100);

}

void serialEvent() {
  Serial.flush();
  //Serial.begin(9600);
  delay(20);
  // Read any serial input
  while (Serial.available())
  {
    inChar = (char)Serial.read(); // Read in one char at a time
    input += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

void seriale() {
  int index = input.indexOf(',');
  int pin;
  if(index != -1){
    for (int k=0; k<35; k++){
      if (input.substring(0,index) == outputs[k].str)
        pin = outputs[k].pin;
    }
    int state = (input.substring(index+1,index+2)).toInt();
    digitalWrite(pin,state);
  for (int k=0; k<13; k++){
      if (input.substring(0,index) == okHints[k].str)
        okHints[k].OK = true;
    }
  }

  // animations
  else if (input == "_vent\n")
  {
  digitalWrite(ventilatore, HIGH);
  delay(5000);
  digitalWrite(candele, LOW);
  delay(200);
  digitalWrite(ventilatore, LOW);
  digitalWrite(luce_primo, HIGH);
  }
  else if (input == "_nano\n"){
    digitalWrite(nano, LOW);
    delay(200);
    digitalWrite(nano, HIGH);
  }

  // start
  else if (input == "_startGame\n" && !start_game){
    start_game = true;
    game_started = false;
  }

  // second floor
  else if (input == "_secondFloor\n" && !second_floor){
  second_floor = true;
  Serial.println("Gamers on second floors!");
  }
  // scatola grande
  else if (input == "_scatolaGrande\n" && !scatolaGrande){
  scatolaGrande = true;
  digitalWrite(M8, LOW);
  // Special Audio cross
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  myDFPlayer.volume(20); // min = 0 max = 30
  myDFPlayer.play(7);
  delay(50);
  }
  // preparation
  //(remember the big box that have the "scrocco" not electromagnets)
  else if (input == "_preparation\n" && !preparation){
  preparation = true;
  Serial.println("Go to close all the doors!");
  digitalWrite(organo,HIGH);
  // close all the doors
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  digitalWrite(M3, HIGH);
  digitalWrite(M4, HIGH);
  digitalWrite(M5, HIGH);
  digitalWrite(M6, HIGH);
  digitalWrite(M7, LOW); // scatola piccola
  digitalWrite(M8, HIGH);
  digitalWrite(M9, HIGH);
  digitalWrite(M10, HIGH);
  digitalWrite(monaco, HIGH);
  digitalWrite(timone, HIGH);
  digitalWrite(culla_gira, HIGH);
  // switch on all the lights
  digitalWrite(luce_primo, HIGH);
  delay(200);
  digitalWrite(luce_secondo, HIGH);
  delay(200);
  digitalWrite(luce_terzo, HIGH);
  delay(200);
  digitalWrite(luce_quarto, HIGH);
  delay(200);
  digitalWrite(organo_start,HIGH);
  delay(2000);
  digitalWrite(organo_start,LOW);

  }
  // open all
  else if (input == "_openAll\n"){
  // open all the doors
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  digitalWrite(M3, LOW);
  digitalWrite(M4, LOW);
  digitalWrite(M5, LOW);
  digitalWrite(M6, LOW);
  digitalWrite(M7, HIGH);
  delay(100);
  digitalWrite(M7, LOW);
  digitalWrite(M8, LOW);
  digitalWrite(M9, LOW);
  digitalWrite(M10, LOW);
  digitalWrite(M11, LOW);
  // switch on all the lights
  digitalWrite(luce_primo, HIGH);
  delay(200);
  digitalWrite(luce_secondo, HIGH);
  delay(200);
  digitalWrite(luce_terzo, HIGH);
  delay(200);
  digitalWrite(luce_quarto, HIGH);
  }
  // Test all pins ON
  /*else if (input == "_allON\n");
  for (int i = 22; i < 54; i++){
    digitalWrite(i, HIGH);
    Serial.print("Accensione pin: ");
    Serial.println(i);
    delay(1000);
  }
  */
  // lettura giochi
  else if (input == "_lettura\n"){
  Serial.println("\nLettura input");
  lettura();
  }

  // special sound
  else if (input == "_special1\n"){
    // change on cross audio
    digitalWrite(4, 0);
    digitalWrite(5, 0);
    myDFPlayer.volume(30); // min = 0 max = 30
    myDFPlayer.play(8);
    delay(5000);
    }
  else if (input == "_special2\n"){
    // change on timone audio
    digitalWrite(4, 1);
    digitalWrite(5, 1);
    myDFPlayer.volume(30);
    myDFPlayer.play(5);
    delay(5000);
  }
  else if (input == "_special3\n"){
    // change on timone audio
    digitalWrite(4, 1);
    digitalWrite(5, 1);
    myDFPlayer.volume(30);
    myDFPlayer.play(3);
    delay(5000);
  }
  // test serial
  else if (input == "_test_on\n")
  {
    for (int i = 0; i < 10; i++) {
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    }
  }
}
