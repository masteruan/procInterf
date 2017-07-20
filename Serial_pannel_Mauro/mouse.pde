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
  if(mouseX > psX[3] && mouseX < psX[3] + dimW && mouseY > psY[0] && mouseY < psY[0] + dimH ){
   delay(200);
   println("Forth button");
  }
  
  // second raw
  if(mouseX > psX[0] && mouseX < psX[0] + dimW && mouseY > psY[1] && mouseY < psY[1] + dimH ){
   delay(200);
   println("Five button");
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
   delay(200);
   println("Second button");
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
   delay(200);
   println("Second button");
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
   delay(200);
   println("Second button");
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
   delay(200);
   println("Second button");
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
   delay(200);
   println("Second button");
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
   delay(200);
   println("Second button");
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