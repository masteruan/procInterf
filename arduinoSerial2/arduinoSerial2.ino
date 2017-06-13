/*
*
*
*/
boolean stringComplete;
String input = "";
char inChar;

void setup()
{
 pinMode(13, OUTPUT);
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
  }

void loop(){
  if (stringComplete) {
    Serial.println(input);
    seriale();
    input = "";
    stringComplete = false;
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
