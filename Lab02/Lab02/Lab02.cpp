#include "stdafx.h"
#include <glut.h>
#include <glu.h>

float year = 0;
float month = 0;
float day = 0;
float revolutionMecury = 0;
float revolutionVenus = 0;
float revolutionMars = 0;
float revolutionJupiter = 0;
float revolutionEuropa = 0;
float revolutionGanymede = 0;
float revolutionSaturn = 0;
float revolutionUranus = 0;
float revolutionNeptune = 0;
float X = 0;
float Y = 0;
float Z = 100;

void light0() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_LIGHTING);

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	GLfloat light_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 0.0, 0.0, 0.0, 1.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_LIGHT0);
	
	glDepthFunc(GL_LESS);
}

void revolutionRings(GLfloat d[4], GLfloat e[4]) {
	e[0] = 0.2;
	e[1] = 0.2;
	e[2] = 0.2;
	glMaterialfv(GL_FRONT, GL_EMISSION, e);
	d[1] = 0;
	d[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
	glutWireTorus(0.001, 4, 3, 100);
	glutWireTorus(0.001, 8, 3, 100);
	glutWireTorus(0.001, 12, 3, 100);
	glutWireTorus(0.001, 16, 3, 100);
	glutWireTorus(0.001, 22, 3, 100);
	glutWireTorus(0.001, 28, 3, 100);
	glutWireTorus(0.001, 34, 3, 100);
	glutWireTorus(0.001, 40, 3, 100);
}

void planetColor(float r, float g, float b) {
	GLfloat d[] = { r, g, b, 1.0 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, d);
}

void display() {
	light0();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(X, Y, Z, X, Y, 0, 0, 1, 0);

	GLfloat mat_ambient[] = { 0.15, 0.15, 0.15, 1.0 };
	GLfloat mat_diffuse[] = { 0.0, 0.5, 1.0, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 120.0 };
	GLfloat emission[] = { 0.0, 0.0, 0.0, 1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, emission);

	//태양
	glPushMatrix();

	//수성
	glPushMatrix();
	planetColor(0.7, 0.8, 0.8);
	glRotatef(revolutionVenus, 0, 0, 1);
	glTranslatef(4, 0, 0);
//	glRotatef(0, 0, 0, 1);
	glutSolidSphere(0.4, 100, 100);
	glPopMatrix();

	//금성
	glPushMatrix();
	planetColor(0.8, 0.6, 0.5);
	glRotatef(revolutionMecury, 0, 0, 1);
	glTranslatef(8, 0, 0);
//	glRotatef(0, 0, 0, 1);
	glutSolidSphere(0.9, 100, 100);
	glPopMatrix();

	//지구
	glPushMatrix();
	planetColor(0.3, 0.4, 0.9);
	glRotatef(year, 0, 0, 1);
	glTranslatef(12, 0, 0);
//	glRotatef(day, 0, 0, 1);
	glutSolidSphere(1, 100, 100);

	//달
	glPushMatrix();
	planetColor(1.0, 1.0, 0);
	glRotatef(month, 0, 0, 1);
	glTranslatef(1.7, 0, 0);
//	glRotatef(day, 0, 0, 1);
	glutSolidSphere(0.3, 100, 100);
	glPopMatrix();

	glPopMatrix();

	//화성
	glPushMatrix();
	planetColor(1.0, 0.3, 0.1);
	glRotatef(revolutionMars, 0, 0, 1);
	glTranslatef(16, 0, 0);
//	glRotatef(0, 0, 0, 1);
	glutSolidSphere(0.5, 100, 100);
	glPopMatrix();

	//목성
	glPushMatrix();
	planetColor(0.7, 0.6, 0.4);
	glRotatef(revolutionJupiter, 0, 0, 1);
	glTranslatef(22, 0, 0);
//	glRotatef(0, 0, 0, 1);
	glutSolidSphere(2, 100, 100);

	//유로파
	glPushMatrix();
	glRotatef(revolutionEuropa, 0, 0, 1);
	glTranslatef(2.6, 0, 0);
	glutSolidSphere(0.27, 100, 100);
	glPopMatrix();

	//가니메데
	glPushMatrix();
	planetColor(0.3, 0.2, 0.2);
	glRotatef(revolutionGanymede, 0, 0, 1);
	glTranslatef(3.5, 0, 0);
	glutSolidSphere(0.45, 100, 100);
	glPopMatrix();

	glPopMatrix();

	//토성
	glPushMatrix();
	planetColor(0.5, 0.4, 0.1);
	glRotatef(revolutionSaturn, 0, 0, 1);
	glTranslatef(28, 0, 0);
	glRotatef(30, 0, 0, 1);
//	glRotatef(0, 0, 0, 1);
	glutSolidSphere(1.8, 100, 100);

	glPushMatrix();
	glRotatef(75, 1, 0, 0);
	glScalef(1, 1, 0.1);
	glutWireTorus(0.3, 3, 100, 30);
	glPopMatrix();

	glPopMatrix();

	//천왕성
	glPushMatrix();
	planetColor(0.1, 0.6, 0.9);
	glRotatef(revolutionUranus, 0, 0, 1);
	glTranslatef(34, 0, 0);
//	glRotatef(0, 0, 0, 1);
	glutSolidSphere(1.5, 100, 100);
	glPopMatrix();

	//해왕성
	glPushMatrix();
	planetColor(0.1, 0.4, 1.0);
	glRotatef(revolutionNeptune, 0, 0, 1);
	glTranslatef(40, 0, 0);
//	glRotatef(0, 0, 0, 1);
	glutSolidSphere(1.5, 100, 100);
	glPopMatrix();

	revolutionRings(mat_diffuse, emission);

	emission[0] = 1.0;
	glMaterialfv(GL_FRONT, GL_EMISSION, emission);
	glutSolidSphere(1, 100, 100);

	glPopMatrix();

	glFlush();
}

void reshape(int w, int h) {
	float ratio = w / (float)h;

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, ratio, 10, 100);
}

void idle() {
	month += 1.3;
	day += 0.1;
	year += 0.1;
	revolutionVenus += 0.4;
	revolutionMecury += 0.162;
	revolutionMars += 0.053;
	revolutionJupiter += 0.0084;
	revolutionEuropa = month*0.93;
	revolutionGanymede = month*0.74;
	revolutionSaturn += 0.0034;
	revolutionUranus += 0.0012;
	revolutionNeptune += 0.00061;

	display();
}

void keyboard(unsigned char key, int x, int y) {

	switch (key) {
	case 'W':
	case 'w':
		Y++;
		break;
	case 'A':
	case 'a':
		X--;
		break;
	case 'S':
	case 's':
		Y--;
		break;
	case 'D':
	case 'd':
		X++;
		break;
	//확대
	case 'Q':
	case 'q':
		if (Z > 14) {
			Z--;
		}
		break;
	//축소
	case 'E':
	case 'e':
		if (Z < 100) {
			Z++;
		}
		break;
	default:
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("test");

	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}
