/**
* Jeannette Subero
* Processing Sketch for controlling Arduino to open a password protected "Vault"
* Still needs to work with any word. It only works with correct word.
*
* Based on
* ControlP5 Textfield
* by Andreas Schlegel, 2012
* www.sojamo.de/libraries/controlp5
*
*/


import processing.serial.*;

Serial port;

import controlP5.*;
ControlP5 cp5;
String textValue = "";

boolean isPressed;

void setup() {
  size(450,250);
  
  PFont font = createFont("arial",20);
  
  cp5 = new ControlP5(this);
  
  cp5.addTextfield("Insert Password")
     .setPosition(100,100)
     .setSize(200,40)
     .setFont(font)
     .setFocus(true)
     .setColor(color(255));
               
  textFont(font);
  
  println(Serial.list());
  port = new Serial(this, Serial.list()[0], 9600);
  
  isPressed = false;
}

void draw() {
  background(0);
  smooth();
  fill(255);
  String password = (cp5.get(Textfield.class,"Insert Password").getText());
  String jeannette = "jeannette";
  String arduino = "arduino";
  String processing = "processing";
  String chocolate = "chocolate";
  
  fill(255,0,0);
  ellipse(350, 120, 25, 25);
  
  
  if (password.equals(chocolate) && isPressed == true){
    port.write('H');
  }
  else
  {
    port.write('L');
  }
  if (password.equals(jeannette) && isPressed == true){
    port.write('X');
  }
  if (password.equals(arduino) && isPressed == true){
    port.write('X');
  }
  if (password.equals(processing) && isPressed == true){
    port.write('X');
  }
  if (isPressed == true) {
    isPressed = false;
  }
}

void mousePressed() {
    if (dist(mouseX, mouseY, 350, 120) < 30) {
    isPressed = true;
  } 
}
