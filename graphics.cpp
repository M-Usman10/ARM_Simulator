//============================================================================
// Name        : SmartDraw
// Author      : Muhammad Usman
// Copyright   : (c) Reserved
//============================================================================
#ifndef GRAPHICS_CPP
#define GRAPHICS_CPP
#define H 680
#include <utility>
#include <unistd.h>
#include "util.h"
#include "objects.h"
#include <cmath>
#include <sys/wait.h>
#include <sys/types.h>
using namespace std;
template<class T, class T2>
class my_pair
{
public:
	T first;
	T2 second;
	my_pair(T f, T2 s)
	{
		first = f;
		second = s;
	}
	bool operator==(const my_pair<T, T2> & p) const
	{
		return first == p.first;
	}
};
void SetCanvasSize(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode( GL_MODELVIEW);
	glLoadIdentity();
}
int x,y;
Board B;
void Display()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
    B.draw_board();
    DrawString(1100,660,"Write Program",colors[BLUE]);
	DrawString(0,660,to_string(x).c_str(),colors[BLUE]);
    DrawString(100,660,to_string(y).c_str(),colors[BLUE]);
	glutSwapBuffers();

}

/*This function is called (automatically) whenever any non-printable (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y)
{
	if (key == GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/)
	{
// what to do when left key is pressed...

	}
	else if (key == GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/)
	{

	}
	else if (key == GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/)
	{

//b->canturn(3); //A function determines whether to turn the pacman or not
	}

	else if (key == GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/)
	{

	}
	else if (key == 19)
	{

	}
	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/
	/*
	 glutPostRedisplay();
	 */
}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y)
{
	if (key=='c')
	{
		B.P1.col++;
		cout<<B.P1.col<<endl;
	}

}
void MouseMoved(int x, int y) {

	::x=x;
	::y=H-y;
    glutPostRedisplay();
}

void MouseClicked(int button, int state, int x, int y)
{

	if (button == GLUT_LEFT_BUTTON && state==GLUT_DOWN) // dealing only with left button
	{
         if(x>1100 && x<1250 && H-y>660)
         {
            if (fork()==0)
            	execl("SB2/sublime_text","sublime_text","code.txt",NULL);
         }
		//Passsing the current position of mouse clicked to start Single player or multiplayer game
	}
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{

	}
//glutPostRedisplay();

}
/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m)
{

// implement your functionality here
	glutPostRedisplay();
// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0 / FPS, Timer, 0);
}

int main(int argc, char*argv[])
{
	glutInit(&argc, argv); // initialize the graphics library...
    int width=1300,height=680;
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width,height); // set the size of our window
	glutCreateWindow("ARM_Simulation"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...
	glutDisplayFunc(Display); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	glutMouseFunc(MouseClicked);
	glutTimerFunc(1000.0 / FPS, Timer, 0);
    glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMainLoop();
	return 1;
}
#endif /* PACMAN_CPP_ */
