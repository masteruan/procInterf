import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import static javax.swing.JOptionPane.*; 
import processing.serial.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class Serial_pannel_rasp extends PApplet {

// Processing button



PFont f;
PImage img;

int bounce = 100; // debounce value

int c1 = 0xffFF0000; // red
int c2 = 0xffFFC000; // orange
int c3 = 0xffE0FF00; // green
int c4 = 0xff000000; // black
int c5 = 0xff66cd00; // green 2
int c6 = 0xffFFFF33; // yellow
int c7 = 0xff33FFFF; // light blue
int c8 = 0xffFFFFF0; // white

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

boolean OP9 = false;
boolean OP91 = false;
boolean OP92 = false;

int buttColour = 100;
int textColour = 0;
int colors[] = {c5,c6,c1}; // Button colors for column
int colorsEdge[] = {c8,c8,c8}; // Button colors edge 

Serial myPort;  // Create object from Serial class
final boolean selectSerial = true; // select the selection of serial
final boolean debug = true;

char inChar;
String input;
String[] sommario = {""};
boolean stringComplete = false;

int posX[] = {20, 170, 320};
int posY[] = {10, 110, 210, 310, 410};

String[] pulsanti = {"nome1", "nome2", "nome3",
                     "nome4", "nome5", "nome6", 
                     "nome7", "nome8", "nome9"};

int dimW = 130;
int dimH = 80;

int psX[] = {posX[0], posX[1], posX[2]};
int psY[] = {posY[0], posY[1], posY[2]};

public void setup(){
 String COMx, COMlist = "";
 
 //fullScreen(); //start at full screen
 f = createFont("Arial",16,true);
 //img = loadImage("logo.png");
 
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
          COMlist += PApplet.parseChar(j+'a') + " = " + Serial.list()[j];
          if (++j < i) COMlist += ",  ";
        }
        COMx = showInputDialog("Which COM port is correct? (a,b,..):\n"+COMlist);
        if (COMx == null) exit();
        if (COMx.isEmpty()) exit();
        i = PApplet.parseInt(COMx.toLowerCase().charAt(0) - 'a') + 1;
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
public void keyPressed() {
  if (key == 'x') {
    exit();
  }
}

public void draw(){
 background(0);
 noFill();
 
 // Logo
 //image(img, 10, 10, 480, 320);
 
 // buttons and buttons text
 for (int n = 0; n < 3; n = n+1) {
   for (int i = 0; i < 3; i = i+1) {
     fill(colors[i]);
     stroke(colorsEdge[i]); // shape buttons colour
     strokeWeight(2); // weight of edge
     rect (psX[i], psY[n], dimW, dimH);
     fill(textColour);
     text (pulsanti[n+n+n+i], psX[i] + 40, psY[n]+42);
   }
 }
 // led port opened
 fill(0,255,0);
 stroke(0);
 
 if(OP1){
   ellipse(psX[0] + 10, psY[0] + 8, 8, 8);
 }
 if(OP2){
   ellipse(psX[1] + 10, psY[0] + 8 , 8, 8);
 }
 if(OP3){
   ellipse(psX[2] + 10, psY[0] + 8, 8, 8);
 }
 if(OP4){
   ellipse(psX[0] + 10, psY[1] + 8, 8, 8);
 }
 if(OP5){
   ellipse(psX[1] + 10, psY[1] + 8, 8, 8);
 }
 if(OP6){
   ellipse(psX[2] + 10, psY[1] + 8, 8, 8);
 }
 if(OP7){
   ellipse(psX[0] + 10, psY[2] + 8, 8, 8);
 }
 if(OP8){
   ellipse(psX[1] + 10, psY[2] + 8, 8, 8);
 }
 if(OP9){
   ellipse(psX[2] + 10, psY[2] + 8, 8, 8);
 }
 
 if (stringComplete) {
   println(input);
   sommario [0] = input;
   stringComplete = false;
   input = "";
 }

mouse();
}

public void serialEvent (Serial myPort) {
  inChar = (char)myPort.read();
  input += inChar;
  if(inChar == '\r'){
   stringComplete = true;
  }

}
public void mouse() {
 // Mouse Action 
 if(mousePressed){
  // Prima riga
  if(mouseX > psX[0] && mouseX < psX[0] + dimW && mouseY > psY[0] && mouseY < psY[0] + dimH){
   if(!OP1){
     println("Primo bottone");
     //myPort.write("6\n");
     OP1=true;
     delay(bounce);
   }
   else {
     //myPort.write("&\n");
     OP1= false;
     delay(bounce);
   }
  }
  if(mouseX > psX[1] && mouseX < psX[1] + dimW && mouseY > psY[0] && mouseY < psY[0] + dimH ){
   if(!OP2){
     println("Primo bottone");
     //myPort.write("6\n");
     OP2=true;
     delay(bounce);
   }
   else {
     //myPort.write("&\n");
     OP2= false;
     delay(bounce);
   }
  }
  if(mouseX > psX[2] && mouseX < psX[2] + dimW && mouseY > psY[0] && mouseY < psY[0] + dimH ){
   if(!OP3){
     println("Primo bottone");
     //myPort.write("6\n");
     OP3=true;
     delay(bounce);
   }
   else {
     //myPort.write("&\n");
     OP3= false;
     delay(bounce);
   }
  }
  
  // Seconda riga
  if(mouseX > psX[0] && mouseX < psX[0] + dimW && mouseY > psY[1] && mouseY < psY[1] + dimH ){
   if(!OP4){
     println("Primo bottone");
     //myPort.write("6\n");
     OP4=true;
     delay(bounce);
   }
   else {
     //myPort.write("&\n");
     OP4= false;
     delay(bounce);
   }
  }
  if(mouseX > psX[1] && mouseX < psX[1] + dimW && mouseY > psY[1] && mouseY < psY[1] + dimH ){
   if(!OP5){
     println("Primo bottone");
     //myPort.write("6\n");
     OP5=true;
     delay(bounce);
   }
   else {
     //myPort.write("&\n");
     OP5= false;
     delay(bounce);
   }
  }
  if(mouseX > psX[2] && mouseX < psX[2] + dimW && mouseY > psY[1] && mouseY < psY[1] + dimH ){
   if(!OP6){
     println("Primo bottone");
     //myPort.write("6\n");
     OP6=true;
     delay(bounce);
   }
   else {
     //myPort.write("&\n");
     OP6= false;
     delay(bounce);
   }
  }
  
  // Terza riga
  if(mouseX > psX[0] && mouseX < psX[0] + dimW && mouseY > psY[2] && mouseY < psY[2] + dimH ){
   if(!OP7){
     println("Primo bottone");
     //myPort.write("6\n");
     OP7=true;
     delay(bounce);
   }
   else {
     //myPort.write("&\n");
     OP7= false;
     delay(bounce);
   }
  }
  if(mouseX > psX[1] && mouseX < psX[1] + dimW && mouseY > psY[2] && mouseY < psY[2] + dimH ){
   if(!OP8){
     println("Primo bottone");
     //myPort.write("6\n");
     OP8=true;
     delay(bounce);
   }
   else {
     //myPort.write("&\n");
     OP8= false;
     delay(bounce);
   }
  }
  if(mouseX > psX[2] && mouseX < psX[2] + dimW && mouseY > psY[2] && mouseY < psY[2] + dimH ){
   if(!OP9){
     println("Primo bottone");
     //myPort.write("6\n");
     OP9 = true;
     delay(bounce);
   }
   else {
     //myPort.write("&\n");
     OP9 = false;
     delay(bounce);
     exit();
   }
  }
 }
}
  public void settings() {  size(480,320); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "Serial_pannel_rasp" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
