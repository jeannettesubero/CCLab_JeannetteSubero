#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		//Declaring
		//Ball
        int xBall;
        int yBall;

        int xPosA;
        int yPosA;

        int xPosB;
        int yPosB;

        int xPosC;
        int yPosC;

        //Velocity of the Balls
int xVelA;
int yVelA;
int xVelB;
int yVelB;
int xVelC;
int yVelC;

//Verrazano Bridge Bounding Box
int xVrrznPos;
int yVrrznPos;
int xVrrzn;
int yVrrzn;


bool isColor;
string typeStr;
ofTrueTypeFont	verdana14;

};
