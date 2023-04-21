#include "glew.h"
#include "glut.h"
#include <cmath>
void RenderScene(void);
void swap(float& one, float& two);
void ChangeSize(GLsizei w, GLsizei h);
void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(1024, 768);
	glutCreateWindow("TaskOne");
	glClearColor(0.5, 0.5, 1, 0);
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutMainLoop();
}
void swap(float& one, float& two) {
	float temp;
	temp = one;
	one = two;
	two = temp;
}
void RenderScene(void) {
	GLubyte roof[128];
	for (int i = 0; i < 128; i++) {
		if (i % 2 == 0)
			roof[i] = 0xaa;
	}
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 1, 0);
	glBegin(GL_QUADS); //земля
		glVertex3f(-1000, 0, 0); //координаты точек четырёхугольника
		glVertex3f(1000, 0, 0);
		glVertex3f(1000, -384, 0);
		glVertex3f(-1000, -384, 0);
	glEnd();
	glColor3f(1, 1, 0);
	glLineWidth(3);
	glBegin(GL_LINES); //лучи солнца
	{
		float x, y;
		for (float a = 0; a < acos(-1) * 2; a += (acos(-1) / 20))
		{
			x = 200 * cos(a) * 1.3 - 500;
			y = 200 * sin(a) + 250;
			glVertex2f(-500, 250);
			glVertex2f(x, y);
		}
	}
	glEnd();
	glBegin(GL_POLYGON); //солнце
	{
		float x, y;
		for (float a = 0; a < acos(-1) * 2; a += (acos(-1) / 20))
		{
			x = 80 * cos(a) * 1.3 - 500;
			y = 80 * sin(a) + 250;
			glVertex2f(x, y);
		}
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN); //тропинка
	glVertex2f(-100, -200);
	glVertex2f(-100, -100);
	glVertex2f(100, -100);
	glVertex2f(120, -200);
	glVertex2f(130, -250);
	glVertex2f(120, -300);
	glVertex2f(100, -384);
	glVertex2f(-200, -384);
	glEnd();
	glColor3f(0.5, 0, 0);
	glBegin(GL_TRIANGLE_STRIP); //ствол дерева 1
	{
		glVertex2f(-300, 100);
		glVertex2f(-250, 100);
		glVertex2f(-295, 80);
		glVertex2f(-269, 80);
		glVertex2f(-290, -20);
		glVertex2f(-240, -20);
	}
	glEnd();
	glBegin(GL_QUAD_STRIP); //ствол дерева 2
	{
		glVertex2f(300, 100);
		glVertex2f(250, 100);
		glVertex2f(295, 80);
		glVertex2f(269, 80);
		glVertex2f(290, -20);
		glVertex2f(250, -20);
	}
	glEnd();
	glColor3f(0, 0.4, 0);
	glBegin(GL_POLYGON); //листва дерева 1
	{
		float x, y;
		for (float a = 0; a < acos(-1) * 2; a += (acos(-1) / 20))
		{
			x = 50 * cos(a) - 270;
			y = 50 * sin(a) + 130;
			glVertex2f(x, y);
		}
	}
	glEnd();
	glBegin(GL_POLYGON); //листва дерева 2
	{
		float x, y;
		for (float a = 0; a < acos(-1) * 2; a += (acos(-1) / 20))
		{
			x = 50 * cos(a) + 270;
			y = 50 * sin(a) + 130;
			glVertex2f(x, y);
		}
	}
	glEnd();
	glColor3f(0.8, 0.5, 0);
	glPointSize(300);
	glBegin(GL_POINTS);
	glVertex3f(0, 0, 0); //дом
	glEnd();
	glLineWidth(10);
	glColor3f(0.5, 0.2, 0);
	glBegin(GL_LINE_LOOP); //контур дома
		float x = 200, y = 150;
		glVertex3f(x, y, 0);
		y *= -1;
		glVertex3f(x, y, 0);
		x *= -1;
		glVertex3f(x, y, 0);
		y *= -1;
		glVertex3f(x, y, 0);
	glEnd();
	glColor3f(0.2, 0.2, 0.2);
	glBegin(GL_TRIANGLES); //крыша 1
		glVertex2f(-230, 150);
		glVertex2f(0, 250);
		glVertex2f(230, 150);
	glEnd();
	glColor3f(0.5, 0, 0);
	glEnable(GL_POLYGON_STIPPLE);
	glPolygonStipple(roof);
	glBegin(GL_TRIANGLES); //крыша 2
		glVertex2f(-230, 150);
		glVertex2f(0, 250);
		glVertex2f(230, 150);
	glEnd();
	glDisable(GL_POLYGON_STIPPLE);
	glColor3f(0.2, 0, 0);
	glBegin(GL_QUADS);
	{
		glVertex2f(-100, -150);
		glVertex2f(-100, 50);
		glVertex2f(100, 50);
		glVertex2f(100, -150);
	}
	glEnd();
	glColor3f(0.3, 0, 0);
	glBegin(GL_LINE_STRIP);
	{
		glVertex2f(-100, -150);
		glVertex2f(-100, 50);
		glVertex2f(100, 50);
		glVertex2f(100, -150);
	}
	glEnd();
	glFlush();
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
		glOrtho(-512, 512, -384 / aspectRatio, 384 / aspectRatio, 1.0, -1.0);
	else
		glOrtho(-512 * aspectRatio, 512 * aspectRatio, -384, 384, 1.0, -1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}