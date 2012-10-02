class Car {
  color c;
  float xpos;
  float ypos;
  float xspeed;

  Car(color tempC, float tempXpos, float tempYpos, float tempXspeed) { // The Constructor is defined with arguments.
    c = tempC;
    xpos = tempXpos;
    ypos = tempYpos;
    xspeed = tempXspeed;
  }

  void display() {
    fill(c);
    rectMode(CENTER);
    rect(xpos, ypos, 50, 25);
  }

  void move() {
    xpos = xpos + xspeed; //to make the car start again from xpos
    if (xpos > width+50) {
      xpos = -50; //to start from left side
    }
    if (xpos < -50) {
      xpos = width+50; //to start from right side
    }
    //Collision Detection
    if (dist(xpos, ypos, frogx, frogy)<=27) {
      frogx = width/2;
      frogy = height-d;
      rectMode(CORNER);
      fill(0);
      rect(0, 0, width, height);
    }
    if (dist(50,width, frogx, frogy)<=50){
      ellipse(width/2, 25, 25, 25);
    }
  }
}
