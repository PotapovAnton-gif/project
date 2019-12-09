#include <iostream>
#include <GL/glut.h>
#include <cmath>
using namespace std;
void renderBall(double x, double y) {
	double r = 0.1;
	double cx = x;
	double cy = y;
	glColor3f(1.0, 1.0, 0.0);
	int num_segments = 20;
	glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++) {
		double theta = 2 * 3.14 * float(ii) / float(num_segments);
		double x = r * cosf(theta);
		double y = r * sinf(theta);
		glVertex2d(x + cx, y + cy);
	}
	glEnd();
}

double Vx = 1, Vy = 3, g = 9.81, x = 0, y = 0, a = 0 , m = 2, t = 0;
double const T = 3.06122, dt = 0.0001;
void display() {

	t += dt;
	cout << t << " " << x << " " << y << endl;
	if (Vy > 0) {
		Vy -= g * dt + (Vy * a) / m * dt;
	}
	else {
		Vy -= g * dt - (Vy * a) / m * dt;
	}
	Vx -= (Vx * a) / m * dt;

	x += Vx * dt;
	y += Vy * dt;
	glBegin(GL_POINTS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x, y);
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
	glClearColor(1.0, 1.0, 1.0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, 0.0, 0.0);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}