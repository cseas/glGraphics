#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>

//#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>

const int fact = 3;
const int x = 80;
// degree to radian
const double DEG2RAD = 3.1415926535897932384 / 180;

static double w = 200;
static int flag = 0;
static int walk = 0;
static int x_ = 2500;

void draw_curve(double theta, double inner_radius, double outer_radius, int x, int y, int sin_sign = 1, int cos_sign = 1) {
	glBegin(GL_POINTS);
	glColor3f(0.0 / 255.0, 0.0 / 255.0, 0.0 / 255.0);
	for (double r = outer_radius; r >= inner_radius; r -= 3.0) {
		for (double i = 0; i < theta; i++) {
			double degInRad = i * DEG2RAD;
			glVertex2f(cos_sign * cos(degInRad) * r + x, sin_sign * sin(degInRad) * r + y);
		}
	}
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);

		int x = 30;
		double len = 50;
		glColor3f((0) / 255.0, (0) / 255.0, (0) / 255.0);
		glBegin(GL_POLYGON);
		glVertex2f(x_, 250 * len);
		glVertex2f(x_ + x, 250 * len);
		glVertex2f(x_ + x, 650 * len);
		glVertex2f(x_, 650 * len);
		glEnd();

		draw_curve(180.0, 0.0, x / 2, x_ + x / 2, 650 * len);

		glBegin(GL_POLYGON);
		glVertex2f(x_ + x + 25, 400 * len);
		glVertex2f(x_ + x + 50, 400 * len);
		glVertex2f(x_ + x + 50, 600 * len);
		glVertex2f(x_ + x + 25, 600 * len);
		glEnd();

		draw_curve(180.0, 0.0, 25.0 / 2, x_ + x + 75.0 / 2, 600 * len);

		glBegin(GL_POLYGON);
		glVertex2f(x_ - 25, 400 * len);
		glVertex2f(x_ - 50, 400 * len);
		glVertex2f(x_ - 50, 600 * len);
		glVertex2f(x_ - 25, 600 * len);
		glEnd();

		draw_curve(180.0, 0.0, 25.0 / 2, x_ - 75.0 / 2, 600 * len);
		draw_curve(90.0, 25, 50, x_ + x, 400 * len, -1);
		draw_curve(90.0, 25, 50, x_, 400 * len, -1, -1);

	glFlush();
}

void myinit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 4999.0, 0.0, 4999.0);
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(5000, 5000);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Points");
	glutDisplayFunc(display);

	myinit();
	glutMainLoop();
}