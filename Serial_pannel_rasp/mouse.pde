void mouse() {
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