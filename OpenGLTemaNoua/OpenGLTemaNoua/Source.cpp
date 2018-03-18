#include <windows.h>
#include <gl/freeglut.h>
#include <iostream>

using namespace std;

GLint winWidth = 600, winHeight = 600;
GLfloat x = 0.0, y = 0.0, z = 0.0;
GLfloat xref = 0.0, yref = 0.0, zref = 400.0;
GLfloat Vx = 0.0, Vy = 1.0, Vz = 0.0;

GLfloat xwMin = -200.0, ywMin = -200.0, xwMax = 200.0, ywMax = 200.0;

GLfloat dnear = 0.0, dfar = 600.0;

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glMatrixMode(GL_MODELVIEW);
	gluLookAt(x, y, z, xref, yref, zref, Vx, Vy, Vz);

	glMatrixMode(GL_PROJECTION);
	glOrtho(xwMin, xwMax, ywMin, ywMax, dnear, dfar);
}

struct vec
{
	int x, y, z;
};

vec ab;
vec cd;
float produsvece1(vec v, vec w)
{
	return v.y*w.z - v.z*w.y;
}

float produsvece2(vec v, vec w)
{
	return -(v.x*w.z - w.x*v.z);
}

float produsvece3(vec v, vec w)
{
	return v.x*w.y - v.y*w.x;
}

void desen1(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glLineWidth(2.0);
	
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3i(0, 0, 0);
	glVertex3i(ab.x, ab.y, ab.z);
	glVertex3i(0, 0, 0);
	glVertex3i(cd.x, cd.y, cd.z);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3i(0, 0, 0);
	glVertex3i(ab.y*cd.z - ab.z*cd.y, -(ab.x*cd.z - cd.x*ab.z), ab.x*cd.y - ab.y*cd.x);
	glEnd();

	glFlush();
}

void reshapeFcn(GLint newWidth, GLint newHeight)
{
	glViewport(0, 0, newWidth, newHeight);

	winWidth = newWidth;
	winHeight = newHeight;
}
void main(int argc, char** argv)
{
	cin >> ab.x >> ab.y >> ab.z;
	cout << endl;
	cin >> cd.x >> cd.y >> cd.z;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Poligoane 3D");

	init();
	glutDisplayFunc(desen1);
	glutReshapeFunc(reshapeFcn);
	glutMainLoop();
}

