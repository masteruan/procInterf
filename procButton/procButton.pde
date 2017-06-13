// Processing button

import processing.serial.*;

Serial myPort;  // Create object from Serial class


int posX[] = {10, 180, 350};
int posY[] = {10, 110, 210, 310, 410};

int dimW = 150;
int dimH = 80;

int psX[] = {posX[0], posX[1], posX[2]};
int psY[] = {posY[0], posY[1], posY[2], posY[3], posY[4]};

void setup(){
 size(510,500);
 background(255);
 stroke(0);
 noFill();
 String portName = Serial.list()[0]; //change the 0 to a 1 or 2 etc. to match your port
 myPort = new Serial(this, portName, 9600);
}

void draw(){
 background(255);
 for (int n = 0; n < 5; n = n+1) {
   for (int i = 0; i < 3; i = i+1) {
     rect (psX[i], psY[n], dimW, dimH);
   }
 }

 fill(255);
 if(mousePressed){

  if(mouseX > psX[0] && mouseX < psX[0] + dimW && mouseY > psY[0] && mouseY < psY[0] + dimH){
   delay(200);
   println("Primo bottone");
   myPort.write("A\n");
   fill(0);
   //do stuff
  }
  if(mouseX > psX[1] && mouseX < psX[1] + dimW && mouseY > psY[0] && mouseY < psY[0] + dimH ){
   delay(200);
   println("Second button");
   myPort.write("_spegni\n");
   fill(0);

   //do stuff
  }
  if(mouseX > psX[2] && mouseX < psX[2] + dimW && mouseY > psY[0] && mouseY < psY[0] + dimH ){
   delay(200);
   println("Thirth button");
   fill(0);
   //do stuff
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
  // get the byte:
  int inByte = myPort.read();
  // print it:
  println(inByte);
}
