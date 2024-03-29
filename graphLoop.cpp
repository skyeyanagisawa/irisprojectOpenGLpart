/* Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above notice and this permission notice shall be included in all copies
 * or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
/* File for "Transformations and Timers" lesson of the OpenGL tutorial on
 * www.videotutorialsrock.com
 */


/*
#include <iostream>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
*/
#include "graphLoop.h"
#include "iris_data.h"

using namespace std;

Iris_data temp;
vector<Iris_data> points;
vector<Iris_data>::iterator it;

//Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
		case 27: //Escape key
			exit(0);
	}
}

//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = 30.0f;
float _cameraAngle = 0.0f;

//Draws the 3D scene
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if(it != points.end()){
        temp.sepal_length = it->sepal_length;
        temp.petal_length = it->petal_length;
        temp.sepal_width = it->sepal_width;
        temp.petal_width = it->petal_width;
        temp.name = it->name;
        temp.start_time = it->start_time;
        temp.duration = it->duration;
        it++;
		}
	
	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glRotatef(-_cameraAngle, 0.0f, 1.0f, 0.0f); //Rotate the camera
	glTranslatef(0.0f, 0.0f, -3.0f); //Move forward 5 units
	
	glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(0.0f, 0.0f, 0.0f); //Move to the center of the trapezoid
	//glRotatef(_angle, 0.0f, 0.0f, 1.0f); //Rotate about the z-axis
	
	glBegin(GL_POLYGON);
	
	//current data point represented as a polygon
	glVertex3f( (temp.sepal_length), 0.0f, 0.0f);
	glVertex3f(0.0f, temp.sepal_width, 0.0f);
	glVertex3f(-(temp.petal_length), 0.0f, 0.0f);
	glVertex3f(0.0f, -(temp.petal_width), 0.0f);
	
	glEnd();

	glBegin(GL_LINE_LOOP);
	
	//square radial graph boundary
	glVertex3f( 1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, 0.0f);
	
	glEnd();

	glBegin(GL_LINES);

	//lines along the axes (from origin in pairs because odd polygons are not symmetrical)
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, 0.0f);

	//attempt to draw markings in tenths from the origin of the graph

	glVertex3f(0.1f, 0.05f, 0.0f);
	glVertex3f(0.1f, -0.05f, 0.0f);
	glVertex3f(0.2f, 0.05f, 0.0f);
	glVertex3f(0.2f, -0.05f, 0.0f);
	glVertex3f(0.3f, 0.05f, 0.0f);
	glVertex3f(0.3f, -0.05f, 0.0f);
	glVertex3f(0.4f, 0.05f, 0.0f);
	glVertex3f(0.4f, -0.05f, 0.0f);
	glVertex3f(0.5f, 0.05f, 0.0f);
	glVertex3f(0.5f, -0.05f, 0.0f);
	glVertex3f(0.6f, 0.05f, 0.0f);
	glVertex3f(0.6f, -0.05f, 0.0f);
	glVertex3f(0.7f, 0.05f, 0.0f);
	glVertex3f(0.7f, -0.05f, 0.0f);
	glVertex3f(0.8f, 0.05f, 0.0f);
	glVertex3f(0.8f, -0.05f, 0.0f);
	glVertex3f(0.9f, 0.05f, 0.0f);
	glVertex3f(0.9f, -0.05f, 0.0f);

	glEnd();

	glBegin(GL_LINES);

	glRotatef(_angle, 0.0f, 9.0f, 9.0f); //Rotate about the z-axis

	glVertex3f(0.1f, 0.05f, 0.0f);
	glVertex3f(0.1f, -0.05f, 0.0f);
	glVertex3f(0.2f, 0.05f, 0.0f);
	glVertex3f(0.2f, -0.05f, 0.0f);
	glVertex3f(0.3f, 0.05f, 0.0f);
	glVertex3f(0.3f, -0.05f, 0.0f);
	glVertex3f(0.4f, 0.05f, 0.0f);
	glVertex3f(0.4f, -0.05f, 0.0f);
	glVertex3f(0.5f, 0.05f, 0.0f);
	glVertex3f(0.5f, -0.05f, 0.0f);
	glVertex3f(0.6f, 0.05f, 0.0f);
	glVertex3f(0.6f, -0.05f, 0.0f);
	glVertex3f(0.7f, 0.05f, 0.0f);
	glVertex3f(0.7f, -0.05f, 0.0f);
	glVertex3f(0.8f, 0.05f, 0.0f);
	glVertex3f(0.8f, -0.05f, 0.0f);
	glVertex3f(0.9f, 0.05f, 0.0f);
	glVertex3f(0.9f, -0.05f, 0.0f);

	glVertex3f(-0.1f, 0.05f, 0.0f);
	glVertex3f(-0.1f, -0.05f, 0.0f);
	glVertex3f(-0.2f, 0.05f, 0.0f);
	glVertex3f(-0.2f, -0.05f, 0.0f);
	glVertex3f(-0.3f, 0.05f, 0.0f);
	glVertex3f(-0.3f, -0.05f, 0.0f);
	glVertex3f(-0.4f, 0.05f, 0.0f);
	glVertex3f(-0.4f, -0.05f, 0.0f);
	glVertex3f(-0.5f, 0.05f, 0.0f);
	glVertex3f(-0.5f, -0.05f, 0.0f);
	glVertex3f(-0.6f, 0.05f, 0.0f);
	glVertex3f(-0.6f, -0.05f, 0.0f);
	glVertex3f(-0.7f, 0.05f, 0.0f);
	glVertex3f(-0.7f, -0.05f, 0.0f);
	glVertex3f(-0.8f, 0.05f, 0.0f);
	glVertex3f(-0.8f, -0.05f, 0.0f);
	glVertex3f(-0.9f, 0.05f, 0.0f);
	glVertex3f(-0.9f, -0.05f, 0.0f);

	glVertex3f(0.05f, 0.1f, 0.0f);
	glVertex3f(-0.05f, 0.1f, 0.0f);
	glVertex3f(0.05f, 0.2f, 0.0f);
	glVertex3f(-0.05f, 0.2f, 0.0f);
	glVertex3f(0.05f, 0.3f, 0.0f);
	glVertex3f(-0.05f, 0.3f, 0.0f);
	glVertex3f(0.05f, 0.4f, 0.0f);
	glVertex3f(-0.05f, 0.4f, 0.0f);
	glVertex3f(0.05f, 0.5f, 0.0f);
	glVertex3f(-0.05f, 0.5f, 0.0f);
	glVertex3f(0.05f, 0.6f, 0.0f);
	glVertex3f(-0.05f, 0.6f, 0.0f);
	glVertex3f(0.05f, 0.7f, 0.0f);
	glVertex3f(-0.05f, 0.7f, 0.0f);
	glVertex3f(0.05f, 0.8f, 0.0f);
	glVertex3f(-0.05f, 0.8f, 0.0f);
	glVertex3f(0.05f, 0.9f, 0.0f);
	glVertex3f(-0.05f, 0.9f, 0.0f);

	glVertex3f(0.05f, -0.1f, 0.0f);
	glVertex3f(-0.05f, -0.1f, 0.0f);
	glVertex3f(0.05f, -0.2f, 0.0f);
	glVertex3f(-0.05f, -0.2f, 0.0f);
	glVertex3f(0.05f, -0.3f, 0.0f);
	glVertex3f(-0.05f, -0.3f, 0.0f);
	glVertex3f(0.05f, -0.4f, 0.0f);
	glVertex3f(-0.05f, -0.4f, 0.0f);
	glVertex3f(0.05f, -0.5f, 0.0f);
	glVertex3f(-0.05f, -0.5f, 0.0f);
	glVertex3f(0.05f, -0.6f, 0.0f);
	glVertex3f(-0.05f, -0.6f, 0.0f);
	glVertex3f(0.05f, -0.7f, 0.0f);
	glVertex3f(-0.05f, -0.7f, 0.0f);
	glVertex3f(0.05f, -0.8f, 0.0f);
	glVertex3f(-0.05f, -0.8f, 0.0f);
	glVertex3f(0.05f, -0.9f, 0.0f);
	glVertex3f(-0.05f, -0.9f, 0.0f);



	glEnd();

	
	glPopMatrix(); //Undo the move to the center of the trapezoid
	
	
	/*
	glPushMatrix(); //Save the current state of transformations
	glTranslatef(1.0f, 1.0f, 0.0f); //Move to the center of the pentagon
	glRotatef(_angle, 0.0f, 1.0f, 0.0f); //Rotate about the y-axis
	glScalef(0.7f, 0.7f, 0.7f); //Scale by 0.7 in the x, y, and z directions
	
	glBegin(GL_TRIANGLES);
	
	//Pentagon
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(-0.5f, 0.0f, 0.0f);
	
	glVertex3f(-0.5f, 0.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(0.5f, 0.0f, 0.0f);
	
	glVertex3f(-0.5f, 0.0f, 0.0f);
	glVertex3f(0.5f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	
	glEnd();
	
	glPopMatrix(); //Undo the move to the center of the pentagon
	glPushMatrix(); //Save the current state of transformations
	glTranslatef(-1.0f, 1.0f, 0.0f); //Move to the center of the triangle
	glRotatef(_angle, 1.0f, 2.0f, 3.0f); //Rotate about the the vector (1, 2, 3)
	
	glBegin(GL_TRIANGLES);
	
	//Triangle
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);
	
	glEnd();
	
	glPopMatrix(); //Undo the move to the center of the triangle
	*/

	
	glutSwapBuffers();
}

void update(int value) {
	_angle += 2.0f;
	if (_angle > 360) {
		_angle -= 360;
	}
	
	glutPostRedisplay(); //Tell GLUT that the display has changed
	
	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(1000, update, 0);
}

void graphLoop(int argc, char** argv, std::vector<Iris_data> vec) {
	points = vec;
	it = points.begin();
    

	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	
	//Create the window
	glutCreateWindow("test graph window");
	initRendering();
	
	//Set handler functions
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	
	glutTimerFunc(1000, update, 0); //Add a timer
	
	glutMainLoop();
	return;
}









