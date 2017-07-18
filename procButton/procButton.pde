// Processing button

import static javax.swing.JOptionPane.*;
import processing.serial.*;
PFont f;
PImage img;

int buttColour = 100;
int textColour = 0;

Serial myPort;  // Create object from Serial class
final boolean selectSerial = false; // select the selection of serial
final boolean debug = true;

char inChar;
String input;
String[] sommario = {""};
boolean stringComplete = false;

int posX[] = {10, 180, 350};
int posY[] = {10, 110, 210, 310, 410};

String[] pulsanti = {"nome1", "nome2", "nome3",
                     "nome4", "nome5", "nome6",
                     "nome7", "nome8", "nome9",
                     "nome10","nome11","nome12",
                     "nome13","nome14","nome15"};

int dimW = 150;
int dimH = 80;

int psX[] = {posX[0], posX[1], posX[2]};
int psY[] = {posY[0], posY[1], posY[2], posY[3], posY[4]};

// set the font
PFont myFont;


void setup(){
 String COMx, COMlist = "";
 size(700,700);
 f = createFont("Arial",16,true);
 img = loadImage("logo.png");

 background(255);
 stroke(0);
 noFill();

 if (!selectSerial){
 printArray(Serial.list());
 String portName = Serial.list()[1]; //change the 0 to a 1 or 2 etc. to match your port
 myPort = new Serial(this, portName, 9600);
 }

 if(selectSerial){
 /*
  Other setup code goes here - I put this at
  the end because of the try/catch structure.
*/
  try {
    if(debug) printArray(Serial.list());
    int i = Serial.list().length;
    if (i != 0) {
      if (i >= 2) {
        // need to check which port the inst uses -
        // for now we'll just let the user decide
        for (int j = 0; j < i;) {
          COMlist += char(j+'a') + " = " + Serial.list()[j];
          if (++j < i) COMlist += ",  ";
        }
        COMx = showInputDialog("Which COM port is correct? (a,b,..):\n"+COMlist);
        if (COMx == null) exit();
        if (COMx.isEmpty()) exit();
        i = int(COMx.toLowerCase().charAt(0) - 'a') + 1;
      }
      String porteName = Serial.list()[i-1];
      if(debug) println(porteName);
      myPort = new Serial(this, porteName, 9600); // change baud rate to your liking
      myPort.bufferUntil('\n'); // buffer until CR/LF appears, but not required..
    }
    else {
      showMessageDialog(frame,"Device is not connected to the PC");
      exit();
    }
  }
  catch (Exception e)
  { //Print the type of error
    showMessageDialog(frame,"COM port is not available (may\nbe in use by another program)");
    println("Error:", e);
    exit();
  }
 }
}

void draw(){
 background(0);
 noFill();

 // Logo
 image(img, 40, 470, 400, 200);

 // menu giochi
 fill(255);
 rect (520, 10, 160,570);
 fill(buttColour);
 rect (525, 600, dimW, dimH);
 fill(textColour);
 textFont(f,20);
 text("Giochi risolti:", 525,35);
 text(sommario[0], 525, 60);
 text("Controllo giochi", 530, 640);

 // buttons and buttons text
 for (int n = 0; n < 5; n = n+1) {
   for (int i = 0; i < 3; i = i+1) {
     fill(buttColour);
     rect (psX[i], psY[n], dimW, dimH);
     fill(textColour);
     text (pulsanti[n+n+n+i], psX[i] + 40, psY[n]+42);
   }
  // Text Label
  noStroke();
  fill(150);
  text("Hello", 5, 5, 200, 75);
 }

 if (stringComplete) {
   println(input);
   sommario [0] = input;
   stringComplete = false;
   input = "";
 }

 // Mouse Action
 if(mousePressed){
  // pulsante menu giochi
  if(mouseX > 525 && mouseX < 525 + dimW && mouseY > 600 && mouseY < 600 + dimH){
  delay(200);
  println("menu giochi");
  myPort.write("_lettura\n");

  }
  if(mouseX > psX[0] && mouseX < psX[0] + dimW && mouseY > psY[0] && mouseY < psY[0] + dimH){
   delay(200);
   println("Primo bottone");
   myPort.write("A\n");
  }
  if(mouseX > psX[1] && mouseX < psX[1] + dimW && mouseY > psY[0] && mouseY < psY[0] + dimH ){
   delay(200);
   println("Second button");
   myPort.write("_spegni\n");
  }
  if(mouseX > psX[2] && mouseX < psX[2] + dimW && mouseY > psY[0] && mouseY < psY[0] + dimH ){
   delay(200);
   println("Thirth button");
   myPort.write("_lettura\n");
  }
  if(mouseX > psX[0] && mouseX < psX[0] + dimW && mouseY > psY[1] && mouseY < psY[1] + dimH ){
   delay(200);
   println("Forth button");
   fill(0);
   //do stuff
  }
  if(mouseX > psX[1] && mouseX < psX[1] + dimW && mouseY > psY[1] && mouseY < psY[1] + dimH ){
   delay(200);
   println("Five button");
   fill(0);
   //do stuff
  }
  if(mouseX > psX[2] && mouseX < psX[2] + dimW && mouseY > psY[1] && mouseY < psY[1] + dimH ){
   delay(200);
   println("Six button");
   fill(0);
   //do stuff
  }
  if(mouseX > psX[0] && mouseX < psX[0] + dimW && mouseY > psY[2] && mouseY < psY[2] + dimH ){
   delay(200);
   println("Second button");
   fill(0);
   //do stuff
  }
  if(mouseX > psX[1] && mouseX < psX[1] + dimW && mouseY > psY[2] && mouseY < psY[2] + dimH ){
   delay(200);
   println("Second button");
   fill(0);
   //do stuff
  }
  if(mouseX > psX[2] && mouseX < psX[2] + dimW && mouseY > psY[2] && mouseY < psY[2] + dimH ){
   delay(200);
   println("Second button");
   fill(0);
   //do stuff
  }
  if(mouseX > psX[0] && mouseX < psX[0] + dimW && mouseY > psY[3] && mouseY < psY[3] + dimH ){
   delay(200);
   println("Second button");
   fill(0);
   //do stuff
  }
  if(mouseX > psX[1] && mouseX < psX[1] + dimW && mouseY > psY[3] && mouseY < psY[3] + dimH ){
   delay(200);
   println("Second button");
   fill(0);
   //do stuff
  }
  if(mouseX > psX[2] && mouseX < psX[2] + dimW && mouseY > psY[3] && mouseY < psY[3] + dimH ){
   delay(200);
   println("Second button");
   fill(0);
   //do stuff
  }
  if(mouseX > psX[0] && mouseX < psX[0] + dimW && mouseY > psY[4] && mouseY < psY[4] + dimH ){
   delay(200);
   println("Second button");
   fill(0);
   //do stuff
  }
  if(mouseX > psX[1] && mouseX < psX[1] + dimW && mouseY > psY[4] && mouseY < psY[4] + dimH ){
   delay(200);
   println("Second button");
   fill(0);
   //do stuff
  }
  if(mouseX > psX[2] && mouseX < psX[2] + dimW && mouseY > psY[4] && mouseY < psY[4] + dimH ){
   delay(200);
   println("Second button");
   fill(0);
   //do stuff
  }
 }
}

void serialEvent (Serial myPort) {
  inChar = (char)myPort.read();
  input += inChar;
  if(inChar == '\r'){
   stringComplete = true;
  }

}
