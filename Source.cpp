#include <iostream>
#include <GL/glut.h>
#include <cmath>
using namespace std;
double ang = 0, PI = 1.0471975512, w = 5.0, t = 0, Vx = 2 , Vy = 3, x = 0, y = 0, a = 2, m = 2, b = 1.0;
double const T = 3.06122, dt = 0.0001, g = 9.81;



void sphera(double x, double y) {

	glBegin(GL_TRIANGLES);
	int n = 0;
	while (n != 6*8) {
		if (n % 2 == 0) {
			glColor3f(1.0, 0.50, 0.30);
		}
		else {
			glColor3f(0.50, 1.0, 0.30);
		} n++;
		ang += PI / 8;
		glVertex2f(x, y);
		glVertex2f(x + 0.1 * cos(ang + w * t), y + 0.1 * sin(ang + w * t));
		glVertex2f(x + 0.1 * cos(ang + PI/8 + w * t), y + 0.1 * sin(ang + PI/8 + w * t));
	}
	

	glEnd();
	glFlush();
	
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	t += dt;
	if (Vy > 0) {
		Vy -= g * dt + (Vy * a) / m * dt;
	}
	else {
		Vy -= g * dt - (Vy * a) / m * dt;
	}
	if (Vx != 0) {
		Vx -= ((Vx * a) / m) * dt;
	}
	if (w > 0) {
		w -= ((w * b) / m) * dt;
	}
	
	x += Vx * dt;
	y += Vy * dt;
	sphera(x, y);
	glEnd();
	glFlush();
	if (y >= 0) {
		glutPostRedisplay();
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1080, 720);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Experement");
	glClearColor(0.0, 0.0, 0.0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, 0.0, 0.0);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}