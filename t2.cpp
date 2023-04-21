#include "glew.h"
#include "glut.h"
#include <cmath>
GLfloat rot = 0;
void RenderScene(void);
void ChangeSize(GLsizei w, GLsizei h);
void square(int x, int y, int size);
void triangle(int x, int y, int radius);
void TimerFunction(int value);
void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1024, 768);
	glutCreateWindow("TaskTwo");
	glClearColor(0, 0, 0, 0);
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutTimerFunc(33, TimerFunction, 1);
	glutMainLoop();
}
void TimerFunction(int value) {
	rot1 += 0.1;
	glutPostRedisplay();
	glutTimerFunc(33, TimerFunction, 1);
}
void square(int x, int y, int size) {
	glBegin(GL_QUADS);
	{
		glVertex2f(x - size / 2, y - size / 2);
		glVertex2f(x - size / 2, y + size / 2);
		glVertex2f(x + size / 2, y + size / 2);
		glVertex2f(x + size / 2, y - size / 2);
	}
	glEnd();
}
void triangle(int x, int y, int radius) {
	glBegin(GL_TRIANGLES);
	{
		glVertex2f(x - radius * (sqrt(3) / 2),  y - radius / 2);
		glVertex2f(x, y + radius);
		glVertex2f(x + radius * (sqrt(3) / 2), y - radius / 2);
	}
	glEnd();
}
void RenderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0.5, 0);
		glBegin(GL_QUADS);
			double x1, y1;
			for (double a = rot1; a < acos(-1) * 2 + rot1; a += (acos(-1) / 2)) {
				x1 = 256 * cos(a);
				y1 = 256 * sin(a);
				glVertex2f(x1, y1);
			}
		glEnd();
	glLoadIdentity();
	glutSwapBuffers();
}
void ChangeSize(GLsizei w, GLsizei h) {
	GLfloat aspectRatio;
	if (h == 0)
		h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	aspectRatio = (GLfloat)w / (GLfloat)h;
	if (w <= h)
		glOrtho(-512, 512, -512 / aspectRatio, 512 / aspectRatio, 1.0, -1.0);
	else
		glOrtho(-512 * aspectRatio, 512 * aspectRatio, -512, 512, 1.0, -1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}