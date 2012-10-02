/*
 * Simple Frogger
 * Jeannette Subero
 * 9/12
 * Based on the arcade game Frogger.
 * Move the frog UP-DOWN-LEFT-RIGHT to get to the other side without getting hit by the cars.
 * Code adapted from "Example 8-2: Two Car objects"
 * by Daniel Shiffman. Source code can be found
 * here:http://www.learningprocessing.com/examples/chapter-8/example-8-2/
 */

Car[] thisCar = new Car[3];
Car[] thisCar2 = new Car[4];
Car[] thisCar3 = new Car [4];
Car[] thisCar4 = new Car [3];

float d;
float frogx;
float frogy;
float distance;
boolean moveLeft, moveRight, moveUp, moveDown;

void setup() {
  size(500, 350);
  for (int i = 0; i < thisCar.length; i++) {
    thisCar [i] = new Car(color (random(255), random(255), random(255)), i*200, 275, 4);
  }
  for (int i = 0; i < thisCar2.length; i++) {
    thisCar2 [i] = new Car(color (random(255), random(255), random(255)), i*100, 225, 2);
  }
  for (int i = 0; i < thisCar3.length; i++) {
    thisCar3 [i] = new Car(color (random(255), random(255), random(255)), i*125, 125, -3);
  }
  for (int i = 0; i < thisCar4.length; i++) {
    thisCar4 [i] = new Car(color (random(255), random(255), random(255)), i*175, 75, -2);
  }

  d = 25;
  frogx = width/2;
  frogy = height-d;
  distance = 2;
  moveLeft = moveRight = moveUp = moveDown = false;
}

void draw() {
  background(125); //background for street
  noStroke();
  smooth();
  fill(130, 190, 50); //fill color for grass
  rectMode(CORNER);
  rect(0, 0, width, 50); //grass patches
  rect(0, 150, width, 50); //grass patches
  rect(0, 300, width, 50); //grass patches

  for (int i = 0; i < thisCar.length; i++) {
    thisCar[i].move();
    thisCar[i].display();
  }
  for (int i = 0; i < thisCar2.length; i++) {
    thisCar2[i].move();
    thisCar2[i].display();
  }

  for (int i = 0; i < thisCar3.length; i++) {
    thisCar3[i].move();
    thisCar3[i].display();
  }
  for (int i = 0; i < thisCar4.length; i++) {
    thisCar4[i].move();
    thisCar4[i].display();
  }


  fill(255, 50, 50);

  if (moveLeft) frogx -= distance;
  if (moveRight) frogx += distance;
  if (moveUp) frogy -= distance;
  if (moveDown) frogy += distance;

  ellipse(frogx, frogy, d, d);
}

void keyPressed() {
  if (key == CODED) {
    if (keyCode == LEFT) {
      moveLeft = true;
    } 
    else if (keyCode == RIGHT) {
      moveRight = true;
    } 
    else if (keyCode == UP) {
      moveUp = true;
    } 
    else if (keyCode == DOWN) {
      moveDown = true;
    }
  }
}

void keyReleased() {
  if (key == CODED) {
    if (keyCode == LEFT) {
      moveLeft = false;
    } 
    else if (keyCode == RIGHT) {
      moveRight = false;
    } 
    else if (keyCode == UP) {
      moveUp = false;
    } 
    else if (keyCode == DOWN) {
      moveDown = false;
    }
  }
}
