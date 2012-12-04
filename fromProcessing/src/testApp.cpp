#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofBackground(0,0,0);
    ofEnableSmoothing();
    ofSetWindowTitle("fromProcessing");
    ofSetFrameRate(50);


    //Ball Size
xBall = 50;
yBall = 50;

//Initial Position of BallA
xPosA = 25;
yPosA = 25;

//Initial Position of BallB
xPosB = 400;
yPosB = 25;

//Initial Position of Ball C
xPosC = 775;
yPosC = 50;

//Velocity of the Balls
xVelA = 10;
yVelA = 5;
xVelB = 5;
yVelB = 10;
xVelC = 10;
yVelC = 5;

//Verrazano Bridge Bounding Box
xVrrznPos = 300;
yVrrznPos = 350;
xVrrzn = 200;
yVrrzn = 450;


ofTrueTypeFont::setGlobalDpi(72);
verdana14.loadFont("verdana.ttf", 14, true, true);
	verdana14.setLineHeight(18.0f);
	verdana14.setLetterSpacing(1.037);

}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){


if (isColor == true) {
ofSetColor((int)ofRandom(0,255),(int)ofRandom(0,255),(int)ofRandom(0,255));
}
else {
ofSetColor (255);
}
  ofFill();
  ofRect (xVrrznPos, yVrrznPos, xVrrzn, yVrrzn);

  ofSetColor(0);
  ofFill();
  ofRect (xVrrznPos+50, yVrrznPos+150, xVrrzn/2, yVrrzn-150);
  ofSetCircleResolution(100);
  ofCircle(xVrrznPos+100, yVrrzn+50, xBall);


  //Bouncing Balls
  //BallA
  ofSetColor(0,200,200);
  ofSetCircleResolution(100);
  ofFill();
  ofCircle(xPosA, yPosA, xBall/2);
  //BallB
  ofSetColor(255,0,200);
  ofSetCircleResolution(100);
  ofFill();
  ofCircle(xPosB, yPosB, xBall/2);
  //BallC
  ofSetColor(255,255,0);
  ofSetCircleResolution(100);
  ofFill();
  ofCircle(xPosC, yPosC, xBall/2);

  xPosA=xPosA+xVelA;
  yPosA=yPosA+yVelA;

  xPosB=xPosB+xVelB;
  yPosB=yPosB+yVelB;

  xPosC=xPosC+xVelC;
  yPosC=yPosC+yVelC;


  //Ball Collision with borders
  //BallA Right and Left
  if (xPosA>800 -xBall/2||xPosA<xBall/2) {
    xVelA=-xVelA;
  }
  //BallA Bottom and Top
  if (yPosA>800-xBall/2||yPosA<xBall/2) {
    yVelA=-yVelA;
  }
  //BallB Right and Left
  if (xPosB>800-xBall/2||xPosB<xBall/2) {
    xVelB=-xVelB;
  }
  //BallB Bottom and Top
  if (yPosB>800-xBall/2||yPosB<xBall/2) {
    yVelB=-yVelB;
  }
  //BallC Right and Left
  if (xPosC>800-xBall/2||xPosC<xBall/2) {
    xVelC=-xVelC;
  }
  //Ball C Bottom and Top
  if (yPosC>800-xBall/2||yPosC<xBall/2) {
    yVelC=-yVelC;
  }

  //Ball Collision (with each other)
  if (ofDist(xPosA, yPosA, xPosB, yPosB)<=xBall) { //BallA and BallB
    xVelA=-xVelA;
    yVelA=-yVelA;
    xVelB=-xVelB;
    yVelB=-yVelB;
  }
  if (ofDist(xPosA, yPosA, xPosC, yPosC)<=xBall) { //BallA and BallC
    xVelA=-xVelA;
    yVelA=-yVelA;
    xVelC=-xVelC;
    yVelC=-yVelC;
  }
  if (ofDist(xPosB, yPosB, xPosC, yPosC)<=xBall) { //BallB and BallC
    xVelB=-xVelB;
    yVelB=-yVelB;
    xVelC=-xVelC;
    yVelC=-yVelC;
  }

  //Balls - Bridge Collision
  //BallA - BridgeLeft
  if (ofDist(xPosA, yPosA, 300, 350)<=xBall/2) {
    xVelA = -xVelA;
    yVelA = -yVelA;
  }
  if (ofDist(xPosA, yPosA, 300, 400)<=xBall/2) {
    xVelA = -xVelA;
    yVelA = -yVelA;
  }
  if (ofDist(xPosA, yPosA, 300, 450)<=xBall/2) {
    xVelA = -xVelA;
    yVelA = -yVelA;
  }
  if (ofDist(xPosA, yPosA, 300, 500)<=xBall/2) {
    xVelA = -xVelA;
    yVelA = -yVelA;
  }
  if (ofDist(xPosA, yPosA, 300, 550)<=xBall/2) {
    xVelA = -xVelA;
    yVelA = -yVelA;
  }
  if (ofDist(xPosA, yPosA, 300, 600)<=xBall/2) {
    xVelA = -xVelA;
    yVelA = -yVelA;
  }
  if (ofDist(xPosA, yPosA, 300, 650)<=xBall/2) {
    xVelA = -xVelA;
    yVelA = -yVelA;
  }
  if (ofDist(xPosA, yPosA, 300, 700)<=xBall/2) {
    xVelA = -xVelA;
    yVelA = -yVelA;
  }
  if (ofDist(xPosA, yPosA, 300, 750)<=xBall/2) {
    xVelA = -xVelA;
    yVelA = -yVelA;
  }
  //BallA - BridgeRight
  if (ofDist(xPosA, yPosA, 500, 350)<=xBall/2) {
    xVelA = -xVelA;
    yVelA = -yVelA;
  }
  if (ofDist(xPosA, yPosA, 500, 400)<=xBall/2) {
    xVelA = -xVelA;
    yVelA = -yVelA;
  }
  if (ofDist(xPosA, yPosA, 500, 450)<=xBall/2) {
    xVelA = -xVelA;
    yVelA = -yVelA;
  }
  if (ofDist(xPosA, yPosA, 500, 500)<=xBall/2) {
    xVelA = -xVelA;
    yVelA = -yVelA;
  }
  if (ofDist(xPosA, yPosA, 500, 550)<=xBall/2) {
    xVelA = -xVelA;
    yVelA = -yVelA;
  }
  if (ofDist(xPosA, yPosA, 500, 600)<=xBall/2) {
    xVelA = -xVelA;
    yVelA = -yVelA;
  }
  if (ofDist(xPosA, yPosA, 500, 650)<=xBall/2) {
    xVelA = -xVelA;
    yVelA = -yVelA;
  }
  if (ofDist(xPosA, yPosA, 500, 700)<=xBall/2) {
    xVelA = -xVelA;
    yVelA = -yVelA;
  }
  if (ofDist(xPosA, yPosA, 500, 750)<=xBall/2) {
    xVelA = -xVelA;
    yVelA = -yVelA;
  }
  //BallA - BridgeTop
  if (ofDist(xPosA, yPosA, 350, 350)<=xBall/2) {
    xVelA = -xVelA;
    yVelA = -yVelA;
  }
  if (ofDist(xPosA, yPosA, 350, 400)<=xBall/2) {
    xVelA = -xVelA;
    yVelA = -yVelA;
  }
  if (ofDist(xPosA, yPosA, 350, 450)<=xBall/2) {
    xVelA = -xVelA;
    yVelA = -yVelA;
  }
  //BallB - BridgeLeft
  if (ofDist(xPosB, yPosB, 300, 350)<=xBall/2) {
    xVelB = -xVelB;
    yVelB = -yVelB;
  }
  if (ofDist(xPosB, yPosB, 300, 400)<=xBall/2) {
    xVelB = -xVelB;
    yVelB = -yVelB;
  }
  if (ofDist(xPosB, yPosB, 300, 450)<=xBall/2) {
    xVelB = -xVelB;
    yVelB = -yVelB;
  }
  if (ofDist(xPosB, yPosB, 300, 500)<=xBall/2) {
    xVelB = -xVelB;
    yVelB = -yVelB;
  }
  if (ofDist(xPosB, yPosB, 300, 550)<=xBall/2) {
    xVelB = -xVelB;
    yVelB = -yVelB;
  }
  if (ofDist(xPosB, yPosB, 300, 600)<=xBall/2) {
    xVelB = -xVelB;
    yVelB = -yVelB;
  }
  if (ofDist(xPosB, yPosB, 300, 650)<=xBall/2) {
    xVelB = -xVelB;
    yVelB = -yVelB;
  }
  if (ofDist(xPosB, yPosB, 300, 700)<=xBall/2) {
    xVelB = -xVelB;
    yVelB = -yVelB;
  }
  if (ofDist(xPosB, yPosB, 300, 750)<=xBall/2) {
    xVelB = -xVelB;
    yVelB = -yVelB;
  }
  //BallB - BridgeRight
  if (ofDist(xPosB, yPosB, 500, 350)<=xBall/2) {
    xVelB = -xVelB;
    yVelB = -yVelB;
  }
  if (ofDist(xPosB, yPosB, 500, 400)<=xBall/2) {
    xVelB = -xVelB;
    yVelB = -yVelB;
  }
  if (ofDist(xPosB, yPosB, 500, 450)<=xBall/2) {
    xVelB = -xVelB;
    yVelB = -yVelB;
  }
  if (ofDist(xPosB, yPosB, 500, 500)<=xBall/2) {
    xVelB = -xVelB;
    yVelB = -yVelB;
  }
  if (ofDist(xPosB, yPosB, 500, 550)<=xBall/2) {
    xVelB = -xVelB;
    yVelB = -yVelB;
  }
  if (ofDist(xPosB, yPosB, 500, 600)<=xBall/2) {
    xVelB = -xVelB;
    yVelB = -yVelB;
  }
  if (ofDist(xPosB, yPosB, 500, 650)<=xBall/2) {
    xVelB = -xVelB;
    yVelB = -yVelB;
  }
  if (ofDist(xPosB, yPosB, 500, 700)<=xBall/2) {
    xVelB = -xVelB;
    yVelB = -yVelB;
  }
  if (ofDist(xPosB, yPosB, 500, 750)<=xBall/2) {
    xVelB = -xVelB;
    yVelB = -yVelB;
  }
  //BallB - BridgeTop
  if (ofDist(xPosB, yPosB, 350, 350)<=xBall/2) {
    xVelB = -xVelB;
    yVelB = -yVelB;
  }
  if (ofDist(xPosB, yPosB, 350, 400)<=xBall/2) {
    xVelB = -xVelB;
    yVelB = -yVelB;
  }
  if (ofDist(xPosB, yPosB, 350, 450)<=xBall/2) {
    xVelB = -xVelB;
    yVelB = -yVelB;
  }
  //BallC - BridgeLeft
  if (ofDist(xPosC, yPosC, 300, 350)<=xBall/2) {
    xVelC = -xVelC;
    yVelC = -yVelC;
  }
  if (ofDist(xPosC, yPosC, 300, 400)<=xBall/2) {
    xVelC = -xVelC;
    yVelC = -yVelC;
  }
  if (ofDist(xPosC, yPosC, 300, 450)<=xBall/2) {
    xVelC = -xVelC;
    yVelC = -yVelC;
  }
  if (ofDist(xPosC, yPosC, 300, 500)<=xBall/2) {
    xVelC = -xVelC;
    yVelC = -yVelC;
  }
  if (ofDist(xPosC, yPosC, 300, 550)<=xBall/2) {
    xVelC = -xVelC;
    yVelC = -yVelC;
  }
  if (ofDist(xPosC, yPosC, 300, 600)<=xBall/2) {
    xVelC = -xVelC;
    yVelC = -yVelC;
  }
  if (ofDist(xPosC, yPosC, 300, 650)<=xBall/2) {
    xVelC = -xVelC;
    yVelC = -yVelC;
  }
  if (ofDist(xPosC, yPosC, 300, 700)<=xBall/2) {
    xVelC = -xVelC;
    yVelC = -yVelC;
  }
  if (ofDist(xPosC, yPosC, 300, 750)<=xBall/2) {
    xVelC = -xVelC;
    yVelC = -yVelC;
  }
  //BallC - BridgeRight
  if (ofDist(xPosC, yPosC, 500, 350)<=xBall/2) {
    xVelC = -xVelC;
    yVelC = -yVelC;
  }
  if (ofDist(xPosC, yPosC, 500, 400)<=xBall/2) {
    xVelC = -xVelC;
    yVelC = -yVelC;
  }
  if (ofDist(xPosC, yPosC, 500, 450)<=xBall/2) {
    xVelC = -xVelC;
    yVelC = -yVelC;
  }
  if (ofDist(xPosC, yPosC, 500, 500)<=xBall/2) {
    xVelC = -xVelC;
    yVelC = -yVelC;
  }
  if (ofDist(xPosC, yPosC, 500, 550)<=xBall/2) {
    xVelC = -xVelC;
    yVelC = -yVelC;
  }
  if (ofDist(xPosC, yPosC, 500, 600)<=xBall/2) {
    xVelC = -xVelC;
    yVelC = -yVelC;
  }
  if (ofDist(xPosC, yPosC, 500, 650)<=xBall/2) {
    xVelC = -xVelC;
    yVelC = -yVelC;
  }
  if (ofDist(xPosC, yPosC, 500, 700)<=xBall/2) {
    xVelC = -xVelC;
    yVelC = -yVelC;
  }
  if (ofDist(xPosC, yPosC, 500, 750)<=xBall/2) {
    xVelC = -xVelC;
    yVelC = -yVelC;
  }
  //BallC - BridgeTop
  if (ofDist(xPosC, yPosC, 350, 350)<=xBall/2) {
    xVelC = -xVelC;
    yVelC = -yVelC;
  }
  if (ofDist(xPosC, yPosC, 350, 400)<=xBall/2) {
    xVelC = -xVelC;
    yVelC = -yVelC;
  }
  if (ofDist(xPosC, yPosC, 350, 450)<=xBall/2) {
    xVelC = -xVelC;
    yVelC = -yVelC;
  }

     ofSetColor(225);
	verdana14.drawString("Click on the Bridge!", mouseX, mouseY);


}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    //Flashing colors on bridge when clicked on
  if (mouseX > xVrrznPos && mouseX < xVrrznPos + 800) {
    if (mouseY > yVrrznPos && mouseY < yVrrznPos + 800) {
      if (mouseX < 800 - xVrrznPos) {
      isColor = !isColor;
    }
  }
}

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
