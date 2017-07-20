// Processing button

import static javax.swing.JOptionPane.*;
import processing.serial.*;
PFont f;
PImage img;

color c1 = #FF0000; // red
color c2 = #FFC000; // orange
color c3 = #E0FF00; // green

int buttColour = 100;
int textColour = 0;
int colors[] = {c3,c3,c2,c1};

Serial myPort;  // Create object from Serial class
final boolean selectSerial = false; // select the selection of serial
final boolean debug = true;

char inChar;
String input;
String[] sommario = {""};
boolean stringComplete = false;

// Buttons variables
int dimW = 130;
int dimH = 60;
int buttonS = 20;
int buttonT = 100;

// dimensions game menu
int menuW = 200;
int menuH = 500;

int posX[] = {buttonS, (dimW + (buttonS*2)), ((dimW * 2) + (buttonS * 3)), ((dimW * 3) + (buttonS * 4))};

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

String[] pulsanti = {"Porta 1",  "Armad 1",    "nome3",     "Start",
                     "Porta 2",  "Polsi",        "nome7",   "Stop",
                     "Porta 3",  "Sca c.3",  "nome11",      "Sq.Leva",
                     "Porta 4",  "Sca c.4",  "nome15",      "Sq.Grata",
                     "Porta 5",  "Fusibili",     "nome19",  "nome20",
                     "Porta 6",  "Grata",        "nome23",  "nome24",
                     "Porta 7",  "Neon",         "nome27",   "OpenAll",
                     "Porta 8",  "Lampe",   "nome31",        "Exit"};



int psX[] = {posX[0], posX[1], posX[2],posX[3]};
int psY[] = {posY[0], posY[1], posY[2], posY[3], posY[4], posY[5], posY[6], posY[7], posY[8]};

void setup(){
 String COMx, COMlist = "";
 size (1024,900);

 //size(1900, 1180);
 //fullScreen(); //start at full screen
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
void keyPressed() {
  if (key == 'x') {
    exit();
  }
}

void draw(){
 //textFont(f,20);
 textSize(20);
 background(0);
 noFill();
 
 // Logo
 image(img, 20, 40, 150,50);
 fill(255,0,0);
 textSize(50);
 text("Hostel Control System", 300,80);
 textSize(20);
 
 // menu giochi
 fill(255);
 rect (width - menuW - buttonS, buttonS + dimH + buttonT, menuW, menuH,7);
 fill(buttColour);
 // Button giochi
 rect (width - dimW - buttonS - 80, (buttonS*8) + (dimH*8) + buttonT, dimW+80, dimH, 7);
 fill(textColour);
 
 // Text button giochi
 text("Giochi risolti", width - dimW - buttonS - 80 + 30,(buttonS*8) + (dimH*8) + buttonT + 40);
 fill(255,0,0);
 text(sommario[0], width - dimW - buttonS - 80 + 30, 220);
 text("Controllo giochi", width - dimW - buttonS - 80 + 30, 200);
 
 
 // buttons and buttons text
 for (int n = 0; n < 8; n = n+1) {
   for (int i = 0; i < 4; i = i+1) {
     //fill(buttColour);
     fill(colors[i]);
     stroke(255, 102, 0); // shape buttons colour
     strokeWeight(2); // weight of edge
     rect (psX[i], psY[n], dimW, dimH, 7);
     fill(textColour);
     text (pulsanti[n+n+n+n+i], psX[i] + (dimW/4), psY[n]+(dimH/2));
   }
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