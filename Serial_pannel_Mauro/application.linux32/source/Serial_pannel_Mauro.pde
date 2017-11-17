/* Hostel control System
* 11 Ottobre 2017
* 
* 
* 
* First    Second    Thirt    Four
* Porta1             Null     start
* Porta2             Null     reset
* Porta3             Null     spazio
* Porta4             Null     seq leva
* Porta5             Null     seq. grata
* Porta6             Null     spazio
* Porta7             Null     open all
* Porta8             Null     exit
*/

import static javax.swing.JOptionPane.*;
import processing.serial.*;
PFont f;
PImage img;

int bounce = 100; // debounce value

color c1 = #FF0000; // red
color c2 = #FFC000; // orange
color c3 = #E0FF00; // green
color c4 = #000000; // black
color c5 = #66cd00; // green 2
color c6 = #FFFF33; // yellow
color c7 = #33FFFF; // light blue
color c8 = #FFFFF0; // white

int buttColour = 100;
int textColour = 0;
int colors[] = {c5,c6,c4,c1}; // Button colors for column
int colorsEdge[] = {c8,c8,c4,c8}; // Button colors edge 

Serial myPort;  // Create object from Serial class
final boolean selectSerial = false; // select the selection of serial
final boolean debug = true;

char inChar;
String input;
String[] sommario = {""};
boolean stringComplete = false;

// Buttons variables
int dimW = 300; // 130
int dimH = 80; // 60
int buttonS = 40; // Spaziatura Y (20)
int buttonT = 100; // 100
int marginSx = 100; // 60

// dimensions game menu
int menuW = 200;
int menuH = 500;

// boolean doors switch
boolean OP1 = false;
boolean OP11 = false;
boolean OP12 = false;

boolean OP2 = false;
boolean OP21 = false;
boolean OP22 = false;

boolean OP3 = false;
boolean OP31 = false;
boolean OP32 = false;

boolean OP4 = false;
boolean OP41 = false;
boolean OP42 = false;

boolean OP5 = false;
boolean OP51 = false;
boolean OP52 = false;

boolean OP6 = false;
boolean OP61 = false;
boolean OP62 = false;

boolean OP7 = false;
boolean OP71 = false;
boolean OP72 = false;

boolean OP8 = false;
boolean OP81 = false;
boolean OP82 = false;

int posX[] = {buttonS + marginSx, (dimW + (buttonS*2) + marginSx), ((dimW * 2) +(buttonS * 3) + marginSx), ((dimW * 3) + (buttonS * 4) + marginSx)};

int posY[] = { buttonS + dimH + buttonT,
              (buttonS*2) + (dimH*2) + buttonT,
              (buttonS*3) + (dimH*3) + buttonT,
              (buttonS*4) + (dimH*4) + buttonT,
              (buttonS*5) + (dimH*5) + buttonT,
              (buttonS*6) + (dimH*6) + buttonT,
              (buttonS*7) + (dimH*7) + buttonT,
              (buttonS*8) + (dimH*8) + buttonT,
              (buttonS*9) + (dimH*9) + buttonT,
              (buttonS*10) + (dimH*10) + buttonT,
            };

String[] pulsanti = {"Ingresso",  "Armadio",  "nome3",  "Start Game",
                     "Cella 1",   "Polsini",  "nome7",  "     Leva",
                     "Cella 2",   "Box 3",    "nome11", "Attiva Grata",
                     "Cella 3",   "Box 4",    "nome15", "Attiva Vocale",
                     "Cella 4",   "Fusibili", "nome19", "Luci Neon",
                     "Fake",      "Grata",    "nome23", "Lampeggiante",
                     "Ufficio",   "Vocale",   "nome27", "Reset Game",
                     "Uscita",    "",         "nome31", "Stop Game"};



int psX[] = {posX[0], posX[1], posX[2],posX[3]};
int psY[] = {posY[0], posY[1], posY[2], posY[3], posY[4], posY[5], posY[6], posY[7], posY[8]};

void setup(){
 String COMx, COMlist = "";
 size (1900,1200);
 //size(1900, 1180);
 //fullScreen(); //start at full screen
 //f = createFont("Roboto",22,true);
 f = createFont("viga.otf",22,true);
 img = loadImage("logo.png");
 
 background(255);
 stroke(0);
 noFill();
 
 if (!selectSerial){
 printArray(Serial.list());
 String portName = Serial.list()[0]; //change the 0 to a 1 or 2 etc. to match your port
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
void keyPressed() {
  if (key == 'x') {
    exit();
  }
}

void draw(){
 textFont(f,20);
 //textSize(20);
 background(0);
 noFill();
 
 // Logo
 image(img, 20, 40, 300,100);
 fill(255);
 textSize(100);
 text("Hostel Control System", 470,120);
 textSize(50);
 
 
 // buttons and buttons text
 for (int n = 0; n < 8; n = n+1) {
   for (int i = 0; i < 4; i = i+1) {
     //fill(buttColour);
     fill(colors[i]);
     stroke(colorsEdge[i]); // shape buttons colour
     strokeWeight(2); // weight of edge
     
     // double last column
     if(i==3){
       rect (psX[i], psY[n], dimW*2, dimH, 7);
     }
     else{
       rect (psX[i], psY[n], dimW, dimH, 7);
     }
     fill(textColour);
     if(i==3){
     text (pulsanti[n+n+n+n+i], psX[i] + (dimW/2) + 20, psY[n]+(dimH/2) + 20);
     }
    else{
     text (pulsanti[n+n+n+n+i], psX[i] + (dimW/4) - 30, psY[n]+(dimH/2) + 20);
    }
 }
 }
 // led port opened
 fill(0,255,0);
 stroke(0);
 
 if(OP1){
   ellipse(psX[0] + (dimW/4) + 200, psY[0]+(dimH/2) + 20, 20, 20);
 }
 if(OP2){
   ellipse(psX[0] + (dimW/4) + 200, psY[1]+(dimH/2) + 20, 20, 20);
 }
 if(OP3){
   ellipse(psX[0] + (dimW/4) + 200, psY[2]+(dimH/2) + 20, 20, 20);
 }
 if(OP4){
   ellipse(psX[0] + (dimW/4) + 200, psY[3]+(dimH/2) + 20, 20, 20);
 }
 if(OP5){
   ellipse(psX[0] + (dimW/4) + 200, psY[4]+(dimH/2) + 20, 20, 20);
 }
 if(OP6){
   ellipse(psX[0] + (dimW/4) + 200, psY[5]+(dimH/2) + 20, 20, 20);
 }
 if(OP7){
   ellipse(psX[0] + (dimW/4) + 200, psY[6]+(dimH/2) + 20, 20, 20);
 }
 if(OP8){
   ellipse(psX[0] + (dimW/4) + 200, psY[7]+(dimH/2) + 20, 20, 20);
 }
 if(OP11){
   ellipse(psX[1] + (dimW/4) + 200, psY[0]+(dimH/2) + 20, 20, 20);
 }
 if(OP21){
   ellipse(psX[1] + (dimW/4) + 200, psY[1]+(dimH/2) + 20, 20, 20);
 }
 if(OP31){
   ellipse(psX[1] + (dimW/4) + 200, psY[2]+(dimH/2) + 20, 20, 20);
 }
 if(OP41){
   ellipse(psX[1] + (dimW/4) + 200, psY[3]+(dimH/2) + 20, 20, 20);
 }
 if(OP51){
   ellipse(psX[1] + (dimW/4) + 200, psY[4]+(dimH/2) + 20, 20, 20);
 }
 if(OP61){
   ellipse(psX[1] + (dimW/4) + 200, psY[5]+(dimH/2) + 20, 20, 20);
 }
 if(OP71){
   ellipse(psX[1] + (dimW/4) + 200, psY[6]+(dimH/2) + 20, 20, 20);
 }
 if(OP81){
   ellipse(psX[1] + (dimW/4) + 200, psY[7]+(dimH/2) + 20, 20, 20);
 }
 if(OP12){
   ellipse(psX[3] + (dimW/4) + 500, psY[0]+(dimH/2) + 20, 20, 20);
 }
  if(OP22){
   ellipse(psX[3] + (dimW/4) + 500, psY[1]+(dimH/2) + 20, 20, 20);
 }
  if(OP32){
   ellipse(psX[3] + (dimW/4) + 500, psY[2]+(dimH/2) + 20, 20, 20);
 }
  if(OP42){
   ellipse(psX[3] + (dimW/4) + 500, psY[3]+(dimH/2) + 20, 20, 20);
 }
  if(OP52){
   ellipse(psX[3] + (dimW/4) + 500, psY[4]+(dimH/2) + 20, 20, 20);
 }
  if(OP62){
   ellipse(psX[3] + (dimW/4) + 500, psY[5]+(dimH/2) + 20, 20, 20);
 }
  if(OP72){
   ellipse(psX[3] + (dimW/4) + 500, psY[6]+(dimH/2) + 20, 20, 20);
 }
  if(OP82){
   ellipse(psX[3] + (dimW/4) + 500, psY[7]+(dimH/2) + 20, 20, 20);
 }
 
 if (stringComplete) {
   println(input);
   sommario [0] = input;
   stringComplete = false;
   input = "";
 }
 mouse();
}

void serialEvent (Serial myPort) {
  inChar = (char)myPort.read();
  input += inChar;
  if(inChar == '\r'){
   stringComplete = true;
  }

}