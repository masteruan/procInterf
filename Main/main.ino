/*
 Main
 22 Luglio 2017
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
 in_cella1 tastierino numerico cella uno
 in_cella2 interruttore cella 2 stacca polsi
 in_cella3 cavi jack per scatola cella tre
 in_cella4 deviatori tre posizioni

 in_leva leva apricelle
 in_fusibili fusibili corridoio

 in_grata detonatore
 in_retina scansione retina

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
int games[] = {A0,A1,A2,A3,A4,A5,A6,A7};

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

int in_leva = A4;
boolean sign_fusibili = true;
boolean OK_fusibili = false;

int in_fusibili = A5;
boolean sign_fusibili = true;
boolean OK_fusibili = false;

int in_grata = A6;
boolean sign_grata = true;
boolean OK_grata = false;

int in_retina = A7;
boolean sign_retina = true;
boolean OK_retina = false;

// out
int M1 = 25; // arduino nella grata
int M2 = 26; // arduino retina

int L1 = 27; // neon
int L2 = 28; // lampeggiante

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

int doors[] = {2,3,4,5,6,7,8,9}; // seven doors

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
      OK_leva = false;
      OK_fusibili = false;
      OK_grata = false;
      OK_retina = false;

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
    sign_cella1 = digitalRead(in_cella1);
    delay(20);
    sign_cella2 = digitalRead(in_cella2);
    delay(20);
    sign_cella3 = digitalRead(in_cella3);
    delay(20);
    sign_cella4 = digitalRead(in_cella4);

    if (!sign_cella1 && !OK_cella1){
    Serial.println("cella1OK");
    //do anything
    OK_cella1 = true;
    }
    delay(10);
    if (!sign_cella2 && !OK_cella2){
      Serial.println("cella2OK");
      //do anything
      OK_cella2 = true;
    }
    delay(10);
    if (!sign_cella3 && !OK_cella3){
      Serial.println("cella3OK");
      //do anything
      OK_cella3 = true;
    }
    delay(10);
    if (!sign_cella4 && !OK_cella4){
      Serial.println("cella4OK");
      //do anything
      OK_cella4 = true;
    }
    delay(10);

    if (OK_cella1 && OK_cella2 && OK_cella3 && OK_cella4 && !OK_leva){
      sign_leva = digitalRead(in_leva);
      if (!sign_leva){
        // switch neon, switch on lampeggiante open doors
        OK_leva = true;
      }
    }

    if (OK_leva && !OK_grata){
    sign_grata = digitalRead(in_grata);
    if (!sign_grata){
      // explosion
      digitalWrite(M1, HIGH);
      OK_grata = true;
    }
  }
    if(OK_grata){
      digitalWrite(M2, HIGH); // swith on retina
      sign_retina = digitalRead(in_retina);
      if (!sign_retina){
        // the end open the doors
      }
    }
}



void seriale() {
  // open doors
  if (input[0] == '1'){
  }
  else if (input[0] == '2'){

  }
  else if (input[0] == '3'){

  }
  else if (input[0] == '4'){

  }
  else if (input[0] == '5'){

  }
  else if (input[0] == '6'){

  }
  else if (input[0] == '7'){

  }
  else if (input[0] == '8'){

  }
  // close the doors
  else if (input[0] == '!'){

  }
  else if (input[0] == '""'){

  }
  else if (input[0] == '£'){

  }
  else if (input[0] == '$'){

  }
  else if (input[0] == '%'){

  }
  else if (input[0] == '&'){

  }
  else if (input[0] == '/'){

  }
  else if (input[0] == '('){

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

  else if (input == "_preparation\n" && !preparation){
    for (int i = 0; i < 8; i++){
      digitalWrite(doors[i], HIGH);
      delay (100);
    }
  }

  else if (input == "_openAll\n"){
    for (int i = 0; i < 8; i++){
      digitalWrite(doors[i], LOW);
      delay (100);
    }
  }
}

void lettura() {
  sign_cella1 = digitalRead(in_cella1);
  delay(10);
  sign_cella2 = digitalRead(in_cella2);
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
  if (!sign_leva){
    Serial.println("leva OK");
  }
  delay(50);
  if (!sign_fusibili){
    Serial.println("fusibili OK");
  }
  delay(50);
  if (!sign_grata){
    Serial.println("grata OK");
  }
  delay(50);
  if (!sign_retina){
    Serial.println("retina OK");
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
