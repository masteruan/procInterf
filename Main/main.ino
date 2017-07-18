/*
 Main Hostel
 18 Luglio 2017
 v 1.0
 Input OK

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


// switch
boolean start_game = false;
boolean game_started = false;

// serial
boolean stringComplete = false;
String input = ""; //String
char inChar ;

// input Variables
int games[] = {A0,A1,A2,A3,A4,A5};

int in_cella1 = A0;
boolean sign_cella1 = true;
boolean OK_cella1 = false;

int in_cella2 = A1 ;
boolean sign_cella2 = false;
boolean OK_cella2 = false;

int in_cella3 = A2;
boolean sign_cella3 = true;
boolean OK_cella3 = false;

int in_cella4 = A3;
boolean sign_cella4 = true;
boolean OK_cella4 = false;

int in_fusibili = A4;
boolean sign_fusibili = true;
boolean OK_fusibili = false;

int in_grata = A5;
boolean sign_grata = true;
boolean OK_grata = false;

// out
int M1 = 25; // arduino nella grata
int L1 = 26; // neon
int L2 = 27; // lampeggiante

// calamite
int C1 = 10; //armadio cella uno
int C2 = 11; //polsi poltrona
int C3 = 12; //scatola cella tre
int C4 = 22; //scatola cella quattro
int C5 = 23; //scatola dopo fusibili in corrdoio
int C6 = 24; //grata

// Porte
int P1 = 2;
int P2 = 3;
int P3 = 4;
int P4 = 5;
int P5 = 6;
int P6 = 7;
int P7 = 8;
int P8 = 9;

void setup() {

  // OUTPUT
  // da 2 a 13
  for (int i = 2; i < 14; i++){
    pinMode(i, OUTPUT);
  }
  // da 22 a 27
  for (int i = 22; i < 28; i++){
    pinMode(i, OUTPUT);
  }
  // INPUT
  // This input give FALSE if the input is open TRUE if the input is closed
  for (int i = 0; i < 6; i++){
      pinMode(games[i], INPUT_PULLUP);
  }

  // Start up serial connection
  Serial.begin(9600); //default 115200
  input.reserve(200);

  Serial.println("################");
  Serial.println("You are Welcome!");
  Serial.flush();
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
    //digitalWrite(valvole, HIGH);
    //sign_valvole = digitalRead(in_valvole);
    if (!sign_valvole && !OK_valvole){
    Serial.println("valvoleDone");
    //digitalWrite(danger, HIGH); // switch off "DANGER"
    //digitalWrite(motore, HIGH); // switch on motor
    //digitalWrite(M1, LOW); // open the door
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


void seriale() {
  if (input[0] == 'A'){
    }
  else if (input == "_spegni\n") {

  }
  else if (input == "_lettura\n") {
    lettura();
  }

  // start
  else if (input == "_startGame\n" && !start_game){
    start_game = true;
    game_started = false;
  }

  // preparation
  //(remember the big box that have the "scrocco" not electromagnets)
  else if (input == "_preparation\n" && !preparation){
  preparation = true;
  Serial.println("Go to close all the doors!");
  }
  // open all
  else if (input == "_openAll\n"){
  // open all the doors

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

  if (!sign_cella1){
    Serial.println("cella uno OK");
  }
  delay(50);
  if (!sign_cella2){
    Serial.println("cella due OK");
  }
  delay(50);
  if (!sign_cella3){
    Serial.println("cella tre OK");
  }
  delay(50);
  if (!sign_cella4){
    Serial.println("cella quattro OK");
  }
  delay(50);
  if (!sign_fusibili){
    Serial.println("fusibili OK");
  }
  delay(50);
  if (!sign_grata){
    Serial.println("grata OK");
  }
  Serial.print("\r");

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
