/*
*
*
*/

boolean stringComplete;
String input = "";
char inChar;

boolean sign_uno = true;

boolean sign_due = true;

int games[] = {A0,A1,A2,A3,A4,A5};


void setup()
{
 pinMode(13, OUTPUT);
 for (int i = 0; i < 6; i++){
      pinMode(games[i], INPUT_PULLUP);
    }
 digitalWrite(13, LOW);
 Serial.begin(9600);
 Serial.flush();
}

void seriale() {
  if (input[0] == 'A'){
    digitalWrite(13, HIGH);
  }
  else if (input == "_spegni\n") {
    digitalWrite(13, LOW);
  }
  else if (input == "_lettura\n") {
    lettura();
  }
  }

void loop(){
  if (stringComplete) {
    //Serial.println(input);
    seriale();
    input = "";
    stringComplete = false;
  }
}

void lettura() {
  sign_uno = digitalRead(A0);
  sign_due = digitalRead(A1);
  delay(10);
  if (!sign_uno){
    Serial.print("Gioco 1 OK\n");
  }
  if (!sign_due){
    Serial.print("Gioco 2 OK ");
  }
  Serial.print("\r");

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
