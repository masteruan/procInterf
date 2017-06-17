// Processing button

import processing.serial.*;
PFont f;

Serial myPort;  // Create object from Serial class
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

void setup(){
 size(700,700);
 f = createFont("Arial",16,true);
 println(Serial.list());
 background(255);
 stroke(0);
 noFill();

 String portName = Serial.list()[1]; //change the 0 to a 1 or 2 etc. to match your port
 myPort = new Serial(this, portName, 9600);
}

void draw(){
 background(255);
 noFill();

 // menu giochi
 rect (520, 10, 160,570);
 fill(0);
 textFont(f,20);
 text("Giochi risolti:", 525,35);
 text(sommario[0], 550, 60);
 fill(100);
 rect (525, 600, dimW, dimH);
 fill(0);
 text("Controllo giochi", 530, 640);

 for (int n = 0; n < 5; n = n+1) {
   for (int i = 0; i < 3; i = i+1) {
     fill(100);
     rect (psX[i], psY[n], dimW, dimH);
     fill(0);

     text (pulsanti[n+n+n+i], psX[i] + 40, psY[n]+40);

   }
 }

 if (stringComplete) {
   println(input);
   sommario [0] = input;
   stringComplete = false;
   input = "";
 }


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
 }
}

void serialEvent (Serial myPort) {
  inChar = (char)myPort.read();// (char)myPort.read();
  input += inChar;
  if(inChar == '\r'){
   stringComplete = true;
  }

}
