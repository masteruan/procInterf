void mouse() {
// Mouse Action 
 if(mousePressed){
  // pulsante menu giochi
  if(mouseX > 525 && mouseX < 525 + dimW && mouseY > 600 && mouseY < 600 + dimH){
  delay(200);
  println("menu giochi");
  myPort.write("_lettura\n");
  }
  
  // first raw
  if(mouseX > psX[0] && mouseX < psX[0] + dimW && mouseY > psY[0] && mouseY < psY[0] + dimH){
   if(!OP1){
     delay(200);
     println("apro prima porta");
     myPort.write("A\n");
     OP1=true;
   }
   else {
     println("chiudo prima porta");
     OP1= false;
     delay(200);
   }
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
  if(mouseX > psX[3] && mouseX < psX[3] + dimW && mouseY > psY[0] && mouseY < psY[0] + dimH ){
   delay(200);
   println("Forth button");
  }
  
  // second raw
  if(mouseX > psX[0] && mouseX < psX[0] + dimW && mouseY > psY[1] && mouseY < psY[1] + dimH ){
   if(!OP2){
     delay(200);
     println("apro seconda porta");
     myPort.write("A\n");
     OP2=true;
   }
   else {
     println("chiudo seconda porta");
     OP2 = false;
     delay(200);
   }
  }
  if(mouseX > psX[1] && mouseX < psX[1] + dimW && mouseY > psY[1] && mouseY < psY[1] + dimH ){
   delay(200);
   println("Six button");
  }
  if(mouseX > psX[2] && mouseX < psX[2] + dimW && mouseY > psY[1] && mouseY < psY[1] + dimH ){
   delay(200);
   println("Second button");
  }
  if(mouseX > psX[3] && mouseX < psX[3] + dimW && mouseY > psY[1] && mouseY < psY[1] + dimH ){
   delay(200);
   println("Second button");
  }
  
  // tirth raw
  if(mouseX > psX[0] && mouseX < psX[0] + dimW && mouseY > psY[2] && mouseY < psY[2] + dimH ){
   if(!OP3){
     delay(200);
     println("apro terza porta");
     myPort.write("A\n");
     OP3 = true;
   }
   else {
     println("chiudo terza porta");
     OP3 = false;
     delay(200);
   }
  }
  if(mouseX > psX[1] && mouseX < psX[1] + dimW && mouseY > psY[2] && mouseY < psY[2] + dimH ){
   delay(200);
   println("Second button");
  }
  if(mouseX > psX[2] && mouseX < psX[2] + dimW && mouseY > psY[2] && mouseY < psY[2] + dimH ){
   delay(200);
   println("Second button");
  }
  if(mouseX > psX[3] && mouseX < psX[3] + dimW && mouseY > psY[2] && mouseY < psY[2] + dimH ){
   delay(200);
   println("Second button");
  }
  
  // fourth raw
  if(mouseX > psX[0] && mouseX < psX[0] + dimW && mouseY > psY[3] && mouseY < psY[3] + dimH ){
   if(!OP4){
     delay(200);
     println("apro quarta porta");
     myPort.write("A\n");
     OP4 = true;
   }
   else {
     println("chiudo quarta porta");
     OP4 = false;
     delay(200);
   }
  }
  if(mouseX > psX[1] && mouseX < psX[1] + dimW && mouseY > psY[3] && mouseY < psY[3] + dimH ){
   delay(200);
   println("Second button");
  }
  if(mouseX > psX[2] && mouseX < psX[2] + dimW && mouseY > psY[3] && mouseY < psY[3] + dimH ){
   delay(200);
   println("Second button");
  }
  if(mouseX > psX[3] && mouseX < psX[3] + dimW && mouseY > psY[3] && mouseY < psY[3] + dimH ){
   delay(200);
   println("Second button");
  }
  // five raw
   if(mouseX > psX[0] && mouseX < psX[0] + dimW && mouseY > psY[4] && mouseY < psY[4] + dimH ){
   if(!OP5){
     delay(200);
     println("apro quinta porta");
     myPort.write("A\n");
     OP5 = true;
   }
   else {
     println("chiudo quinta porta");
     OP5 = false;
     delay(200);
   }
  }
   if(mouseX > psX[1] && mouseX < psX[1] + dimW && mouseY > psY[4] && mouseY < psY[4] + dimH ){
   delay(200);
   println("Second button");
   }
   if(mouseX > psX[2] && mouseX < psX[2] + dimW && mouseY > psY[4] && mouseY < psY[4] + dimH ){
   delay(200);
   println("Second button");
   }
   if(mouseX > psX[3] && mouseX < psX[3] + dimW && mouseY > psY[4] && mouseY < psY[4] + dimH ){
   delay(200);
   println("Second button");
   }
  // six raw
   if(mouseX > psX[0] && mouseX < psX[0] + dimW && mouseY > psY[5] && mouseY < psY[5] + dimH ){
   if(!OP6){
     delay(200);
     println("apro seconda porta");
     myPort.write("A\n");
     OP6 = true;
   }
   else {
     println("chiudo seconda porta");
     OP6 = false;
     delay(200);
   }
 }
   if(mouseX > psX[1] && mouseX < psX[1] + dimW && mouseY > psY[5] && mouseY < psY[5] + dimH ){
   delay(200);
   println("Second button");
   }
   if(mouseX > psX[2] && mouseX < psX[2] + dimW && mouseY > psY[5] && mouseY < psY[5] + dimH ){
   delay(200);
   println("Second button");
   }
   if(mouseX > psX[3] && mouseX < psX[3] + dimW && mouseY > psY[5] && mouseY < psY[5] + dimH ){
   delay(200);
   println("Second button");
   }
  
  // seven raw
   if(mouseX > psX[0] && mouseX < psX[0] + dimW && mouseY > psY[6] && mouseY < psY[6] + dimH ){
   if(!OP7){
     delay(200);
     println("apro settima porta");
     myPort.write("A\n");
     OP7 = true;
   }
   else {
     println("chiudo settima porta");
     OP7 = false;
     delay(200);
   }
 }
   if(mouseX > psX[1] && mouseX < psX[1] + dimW && mouseY > psY[6] && mouseY < psY[6] + dimH ){
   delay(200);
   println("Second button");
  }
   if(mouseX > psX[2] && mouseX < psX[2] + dimW && mouseY > psY[6] && mouseY < psY[6] + dimH ){
   delay(200);
   println("Second button");
  }
   if(mouseX > psX[3] && mouseX < psX[3] + dimW && mouseY > psY[6] && mouseY < psY[6] + dimH ){
   delay(200);
   println("Second button");
  }
  
  // eight raw
   if(mouseX > psX[0] && mouseX < psX[0] + dimW && mouseY > psY[7] && mouseY < psY[7] + dimH ){
   if(!OP8){
     delay(200);
     println("apro ottava porta");
     myPort.write("A\n");
     OP8 = true;
   }
   else {
     println("chiudo ottava porta");
     OP8 = false;
     delay(200);
   }
 }
   if(mouseX > psX[1] && mouseX < psX[1] + dimW && mouseY > psY[7] && mouseY < psY[7] + dimH ){
   delay(200);
   println("Second button");
  }
   if(mouseX > psX[2] && mouseX < psX[2] + dimW && mouseY > psY[7] && mouseY < psY[7] + dimH ){
   delay(200);
   println("Second button");
  }
   if(mouseX > psX[3] && mouseX < psX[3] + dimW && mouseY > psY[7] && mouseY < psY[7] + dimH ){
   delay(200);
   println("Exit");
   exit();
  }
 }
}