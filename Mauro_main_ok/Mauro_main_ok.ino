/*
 Main Hostel
 per BreakOut

 11 Ottobre 2017
 v 1.3

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
boolean preparation = false;

// serial
boolean stringComplete = false;
String input = ""; //String
char inChar ;

// INPUT
int games[] = {A0,A1,A2,A3,A4,A5,A6,A7};

int in_leva = A0;
boolean sign_leva = true;
boolean OK_leva = false;
boolean regia_leva = false;

int L1 = 10; // neon 1
int L2 = 11; // neon 2
int lampeggiante = 12; // lampeggiante

// calamite dal 22 al 37
int C1 = 30; // Armadio cella 3
int C2 = 31; // Armadio cella 4
int C3 = 32; // Riconoscimennto vocale
int C4 = 33; // Grata
int C5 = 34; // Armadio fusibili
int C6 = 35; // Armadio cella 1
int C8 = 36; // Sedia con polsini
int C7 = 37; // Arduino Grata

// Giochi
int G1 = 29; // Autorizzazione vocale

// Porte
int P1 = 2; // Fake
int P2 = 3; // Cella 4
int P3 = 4; // Cella 3
int P4 = 5; // Cella 2
int P5 = 6; // Cella 1
int P6 = 7; // Ingresso
int P7 = 8; // Ufficio
int P8 = 9; // Uscita

// Arrays
int doors[] = {2,3,4,5,6,7,8,9}; // seven doors
int armadi[] = {30,31,32,33,34,35,36,37}; // giochi e armadi

void setup() {
  // Declare output
  // da 2 a 13
  for (int i = 2; i < 14; i++){
    pinMode(i, OUTPUT);
    delay(20);
    digitalWrite(i, HIGH);
  }
  // da 22 a 42
  for (int i = 22; i < 43; i++){
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }
  // Declare input
  // This input give FALSE if the input is open TRUE if the input is closed
  //for (int i = 0; i < 8; i++){
  //    pinMode(games[i], INPUT_PULLUP);
  //}
  pinMode(A0, INPUT_PULLUP);

  // Start up serial connection
  Serial.begin(9600); //default 115200
  input.reserve(200);

  Serial.println("####################################");
  Serial.println("You are Welcome into Breakout System");
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
}

void seriale() {
  // open doors
  if (input[0] == '1'){
    digitalWrite(P1, HIGH);
  }
  else if (input[0] == '2'){
    digitalWrite(P2, HIGH);
  }
  else if (input[0] == '3'){
    digitalWrite(P3, HIGH);
  }
  else if (input[0] == '4'){
    digitalWrite(P4, HIGH);
  }
  else if (input[0] == '5'){
    digitalWrite(P5, HIGH);
  }
  else if (input[0] == '6'){
    digitalWrite(P6, HIGH);
  }
  else if (input[0] == '7'){
    digitalWrite(P7, HIGH);
  }
  else if (input[0] == '8'){
    digitalWrite(P8, HIGH);
  }
  // close the doors
  else if (input[0] == '!'){
    digitalWrite(P1, LOW);
  }
  else if (input[0] == '@'){
    digitalWrite(P2, LOW);
  }
  else if (input[0] == '='){
    digitalWrite(P3, LOW);
  }
  else if (input[0] == '$'){
    digitalWrite(P4, LOW);
  }
  else if (input[0] == '%'){
    digitalWrite(P5, LOW);
  }
  else if (input[0] == '&'){
    digitalWrite(P6, LOW);
  }
  else if (input[0] == '/'){
    digitalWrite(P7, LOW);
  }
  else if (input[0] == '('){
    digitalWrite(P8, LOW);
  }
  // lights
  else if (input[0] == 'N'){
    digitalWrite(L1, LOW);
  }
  else if (input[0] == 'n'){
    digitalWrite(L1, HIGH);
  }
  else if (input[0] == 'O'){
    digitalWrite(L2, LOW);
  }
  else if (input[0] == 'o'){
    digitalWrite(L2, HIGH);
  }
  else if (input[0] == 'R'){
    digitalWrite(lampeggiante, LOW);
  }
  else if (input[0] == 'r'){
    digitalWrite(lampeggiante, HIGH);
  }

  // games
  else if (input[0] == 'Q'){
    digitalWrite(C1, LOW);
  }
  else if (input[0] == 'q'){
    digitalWrite(C1, HIGH);
  }
  else if (input[0] == 'W'){
    digitalWrite(C2, LOW);
  }
  else if (input[0] == 'w'){
    digitalWrite(C2, HIGH);
  }
  else if (input[0] == 'E'){
    digitalWrite(C3, LOW);
  }
  else if (input[0] == 'e'){
    digitalWrite(C3, HIGH);
  }
  else if (input[0] == 'D'){
    digitalWrite(C4, LOW);
  }
  else if (input[0] == 'd'){
    digitalWrite(C4, HIGH);
  }
  else if (input[0] == 'T'){
    digitalWrite(C5, LOW);
  }
  else if (input[0] == 't'){
    digitalWrite(C5, HIGH);
  }
  else if (input[0] == 'Y'){
    digitalWrite(C6, LOW);
  }
  else if (input[0] == 'y'){
    digitalWrite(C6, HIGH);
  }
  else if (input[0] == 'U'){
    digitalWrite(C7, LOW);
  }
  else if (input[0] == 'u'){
    digitalWrite(C7, HIGH);
  }
  else if (input[0] == 'P'){
    digitalWrite(C8, LOW);
  }
  else if (input[0] == 'p'){
    digitalWrite(C8, HIGH);
  }
  else if (input[0] == 'V'){
    digitalWrite(G1, LOW);
  }
  else if (input[0] == 'v'){
    digitalWrite(G1, HIGH);
  }
  // sequences

  else if (input == "_spegni\n") {
    for (int i = 0; i < 8; i++){
      digitalWrite(doors[i], HIGH);
      delay (100);
    }
    for (int i = 0; i < 8; i++){
      digitalWrite(armadi[i], HIGH);
      delay (100);
    }
    digitalWrite(L1, HIGH);
    delay(50);
    digitalWrite(L2, HIGH);
    delay(50);
    digitalWrite(lampeggiante, HIGH);
    delay(50);
  }

  else if (input == "_lettura\n") {
    lettura();
  }

  // start
  else if (input == "_startGame\n" && !start_game){
    start_game = true;
    game_started = false;
  }

  else if (input == "_reset\n" && !preparation){
    digitalWrite(L1, LOW);
    delay(50);
    digitalWrite(L2, LOW);
    delay(50);
    digitalWrite(lampeggiante, HIGH);
    delay(50);
    for (int i = 0; i < 8; i++){
      digitalWrite(doors[i], HIGH);
      delay (100);
    }
  }
  else if (input == "_leva\n"){
    regia_leva = true;
    Serial.println("Leva dalla regia");
  }
  else if (input == "_openAll\n"){
    for (int i = 0; i < 8; i++){
      digitalWrite(doors[i], HIGH);
      delay (100);
    }
    for (int i = 0; i < 8; i++){
      digitalWrite(armadi[i], HIGH);
      delay (100);
    }
    digitalWrite(L1, LOW);
    delay(50);
    digitalWrite(L2, LOW);
    delay(50);
    digitalWrite(lampeggiante, HIGH);
    delay(50);
  }
}

void lettura() {
  Serial.println("Verify the input");
  sign_leva = digitalRead(in_leva);
  delay(10);

  if (!sign_leva){
    Serial.println("leva OK");
  }
  delay(50);
  Serial.print("\r");

}
void game () {
   if (start_game){
      // reset booleane
      OK_leva = false;

      // Close all doors
      digitalWrite(P1, LOW);
      digitalWrite(P2, LOW);
      digitalWrite(P3, LOW);
      digitalWrite(P4, LOW);
      digitalWrite(P5, LOW);
      digitalWrite(P6, LOW);
      digitalWrite(P7, LOW);
      digitalWrite(P8, LOW);

      // Close all armadi
      digitalWrite(C1, LOW);
      digitalWrite(C2, LOW);
      digitalWrite(C3, LOW);
      digitalWrite(C4, LOW);
      digitalWrite(C5, LOW);
      digitalWrite(C6, LOW);
      digitalWrite(C7, HIGH); // Arduino grata OFF
      digitalWrite(C8, LOW);

      // Vocal
      digitalWrite(G1, HIGH); // Aut vocale

      // ON lights
      digitalWrite(L1, LOW);
      digitalWrite(L2, LOW);
      digitalWrite(lampeggiante, HIGH);
      start_game = false;
      game_started = true;
      regia_leva = false;
      Serial.println("gameStarted");
  }

  if (game_started){
    if (!OK_leva){
      sign_leva = digitalRead(in_leva);
      delay(50);
      if (!sign_leva||regia_leva){
        // switch neon, switch on lampeggiante open doors
        digitalWrite(L1,HIGH);
        digitalWrite(L2,HIGH);
        digitalWrite(lampeggiante, LOW);
        digitalWrite(P2, HIGH);
        delay(300);
        digitalWrite(P3, HIGH);
        delay(300);
        digitalWrite(P4, HIGH);
        delay(300);
        digitalWrite(P5, HIGH);
        Serial.println("LEVAOK");
        OK_leva = true;
      }
    }
  }
}

void serialEvent() {
  Serial.flush();
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
