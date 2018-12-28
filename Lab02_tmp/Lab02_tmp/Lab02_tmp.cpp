/*#include <glut.h>
#include <glu.h>
#include <glaux.h>
#pragma comment(lib, "glaux.lib")
#pragma comment(lib, "legacy_stdio_definitions.lib")

float year = 0;
float month = 0;
float day = 0;
float rotateSun = 0;
float rotateMecury = 0;
float rotateVenus = 0;
float rotateMars = 0;
float rotateJupiter = 0;
float rotateSaturn = 0;
float rotateUranus = 0;
float rotateNeptune = 0;
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

unsigned int ids[11];
AUX_RGBImageRec *tex[11]; /* structure to contain a texture image */
/*GLUquadric *sphere;

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
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);

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

	//Sun
	glPushMatrix();

	revolutionRings(mat_diffuse, emission);

	//Mercury
	glPushMatrix();
	planetColor(0.7, 0.8, 0.8);
	glRotatef(revolutionVenus, 0, 0, 1);
	glTranslatef(4, 0, 0);
	glRotatef(-0.01, 0, 1, 0);
	glRotatef(rotateMecury, 0, 0, 1);
	glBindTexture(GL_TEXTURE_2D, ids[0]);
	gluSphere(sphere, 0.4, 100, 100);
	glPopMatrix();

	//Venus
	glPushMatrix();
	planetColor(0.8, 0.6, 0.5);
	glRotatef(revolutionMecury, 0, 0, 1);
	glTranslatef(8, 0, 0);
	glRotatef(-2.64, 0, 1, 0);
	glRotatef(rotateVenus, 0, 0, 1);
	glBindTexture(GL_TEXTURE_2D, ids[1]);
	gluSphere(sphere, 0.9, 100, 100);
	glPopMatrix();

	//Earth
	glPushMatrix();
	glRotatef(year, 0, 0, 1);
	glTranslatef(12, 0, 0);

	//Moon
	glPushMatrix();
	glRotatef(month, 0, 0, 1);
	glTranslatef(1.7, 0, 0);
	planetColor(1.0, 1.0, 0);
	glBindTexture(GL_TEXTURE_2D, ids[3]);
	gluSphere(sphere, 0.3, 100, 100);
	glPopMatrix();

	glRotatef(-23.5, 0, 1, 0);
	glRotatef(day, 0, 0, 1);
	planetColor(0.3, 0.4, 0.9);
	glBindTexture(GL_TEXTURE_2D, ids[2]);
	gluSphere(sphere, 1, 100, 100);
	glPopMatrix();

	//Mars
	glPushMatrix();
	planetColor(1.0, 0.3, 0.1);
	glRotatef(revolutionMars, 0, 0, 1);
	glTranslatef(16, 0, 0);
	glRotatef(-25.19, 0, 1, 0);
	glRotatef(rotateMars, 0, 0, 1);
	glBindTexture(GL_TEXTURE_2D, ids[4]);
	gluSphere(sphere, 0.5, 100, 100);
	glPopMatrix();

	//Jupiter
	glPushMatrix();
	glRotatef(revolutionJupiter, 0, 0, 1);
	glTranslatef(X, 0, 0);

	//Europa
	glPushMatrix();
	glRotatef(revolutionEuropa, 0, 0, 1);
	glTranslatef(2.6, 0, 0);
	glRotatef(-0.1, 0, 1, 0);
	glBindTexture(GL_TEXTURE_2D, ids[0]);
	gluSphere(sphere, 0.27, 100, 100);
	glPopMatrix();

	//Ganymede
	glPushMatrix();
	planetColor(0.3, 0.2, 0.2);
	glRotatef(revolutionGanymede, 0, 0, 1);
	glTranslatef(3.5, 0, 0);
	glRotatef(0.33, 0, 1, 0);
	glBindTexture(GL_TEXTURE_2D, ids[0]);
	gluSphere(sphere, 0.45, 100, 100);
	glPopMatrix();

	glRotatef(-3.13, 0, 1, 0);
	glRotatef(rotateJupiter, 0, 0, 1);
	planetColor(0.7, 0.6, 0.4);
	glBindTexture(GL_TEXTURE_2D, ids[5]);
	gluSphere(sphere, 2, 100, 100);
	glPopMatrix();

	//Saturn
	glPushMatrix();
	planetColor(0.5, 0.4, 0.1);
	glRotatef(revolutionSaturn, 0, 0, 1);
	glTranslatef(28, 0, 0);
	glRotatef(-26.73, 0, 1, 0);

	//ring
	glPushMatrix();
	glScalef(1, 1, 0.1);
	glutWireTorus(0.3, 3, 100, 30);
	glPopMatrix();

	glRotatef(rotateSaturn, 0, 0, 1);
	glBindTexture(GL_TEXTURE_2D, ids[6]);
	gluSphere(sphere, 1.8, 100, 100);
	glPopMatrix();

	//Uranus
	glPushMatrix();
	planetColor(0.1, 0.6, 0.9);
	glRotatef(revolutionUranus, 0, 0, 1);
	glTranslatef(34, 0, 0);
	glRotatef(-97.77, 0, 1, 0);
	glRotatef(rotateUranus, 0, 0, 1);
	glBindTexture(GL_TEXTURE_2D, ids[7]);
	gluSphere(sphere, 1.5, 100, 100);
	glPopMatrix();

	//Neptune
	glPushMatrix();
	planetColor(0.1, 0.4, 1.0);
	glRotatef(revolutionNeptune, 0, 0, 1);
	glTranslatef(40, 0, 0);
	glRotatef(-28.32, 0, 1, 0);
	glRotatef(rotateNeptune, 0, 0, 1);
	glBindTexture(GL_TEXTURE_2D, ids[8]);
	gluSphere(sphere, 1.5, 100, 100);
	glPopMatrix();

	glRotatef(rotateSun, 0, 0, 1);
	emission[0] = 1.0;
	glMaterialfv(GL_FRONT, GL_EMISSION, emission);
	glBindTexture(GL_TEXTURE_2D, ids[9]);
	gluSphere(sphere, 1, 100, 100);

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
	month += 1.2;
	day += 36.5;
	year += 0.1;
	revolutionVenus += 0.415;
	rotateVenus += 0.622;
	revolutionMecury += 0.162;
	rotateMecury += 0.15;
	revolutionMars += 0.053;
	rotateMars += 35.74;
	revolutionJupiter += 0.0084;
	rotateJupiter += 87.6;
	revolutionEuropa += 10.28;
	revolutionGanymede += 5.1;
	revolutionSaturn += 0.0034;
	rotateSaturn += 83.43;
	revolutionUranus += 0.0012;
	rotateUranus += 50.78;
	revolutionNeptune += 0.00061;
	rotateNeptune += 54.4;
	rotateSun += 0.25;

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
	GLfloat plane_coef_s[] = { 1.0, 0.0, 0.0, 1.0 };
	GLfloat plane_coef_t[] = { 0.0, 1.0, 0.0, 1.0 };

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("test");

	glEnable(GL_TEXTURE_GEN_S);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_S, GL_OBJECT_PLANE, plane_coef_s);

	glEnable(GL_TEXTURE_GEN_T);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_T, GL_OBJECT_PLANE, plane_coef_t);

	sphere = gluNewQuadric();
	gluQuadricTexture(sphere, GL_TRUE);

	
	tex[0] = auxDIBImageLoad("Venus.bmp");
	tex[1] = auxDIBImageLoad("Mercury.bmp");
	tex[2] = auxDIBImageLoad("Earth.bmp");
	tex[3] = auxDIBImageLoad("moon.bmp");
	tex[4] = auxDIBImageLoad("Mars.bmp");
	tex[5] = auxDIBImageLoad("Jupiter.bmp");
	tex[6] = auxDIBImageLoad("Saturn.bmp");
	tex[7] = auxDIBImageLoad("Uranus.bmp");
	tex[8] = auxDIBImageLoad("Neptune.bmp");
	tex[9] = auxDIBImageLoad("Sun.bmp");

	for (int i = 0; i < 10; i++) {
		glGenTextures(2, &ids[i]); /* generate texture id 
		glBindTexture(GL_TEXTURE_2D, ids[i]); /* specify tex_id to bind properties to 
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); /* define how to map the texture 
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, tex[i]->sizeX, tex[i]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, tex[i]->data); /* give the texture image to be used 
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); /* define texture blend mode 
	}

	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}*/

#include "stdafx.h"
#include <glut.h>
#include<iostream>
#include <glaux.h>
#pragma comment(lib, "glaux.lib")
#pragma comment(lib, "legacy_stdio_definitions.lib")

using namespace std;

const int map[17][17] = {
	{ 1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,1 },
	{ 1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1 },
	{ 1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,1 },
	{ 1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1 },
	{ 1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1 },
	{ 1,0,1,1,1,0,1,0,0,0,1,0,1,1,1,1,1 },
	{ 1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1 },
	{ 1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1 },
	{ 1,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1 },
	{ 1,0,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1 },
	{ 1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1 },
	{ 1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,0,1 },
	{ 1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }//1인 부분이 벽, 0이 길
};
float cameraX = 8;
float cameraY = 8;
float cameraLookX = 9;
float cameraLookY = 8;
int angle = 10000;
int fovy = 90;
unsigned int ids[1];
AUX_RGBImageRec *tex[1];

GLfloat light_ambient[] = { 0.2f,0.2f,0.2f,1.0f };
GLfloat light_diffuse[] = { 0.8f,0.8f,0.8f,1.0f };
GLfloat light_specular[] = { 1.0f,1.0f,1.0f,1.0f };
GLfloat light_position[] = { 0.0f,0.0f,-1.0f,1.0f };

GLfloat mat_ambient[] = { 1.0f,1.0f,1.0f,1.0f };
GLfloat mat_diffuse[] = { 0.7f,0.7f,0.7f,1.0f };
GLfloat mat_specular[] = { 0.5f,0.5f,0.5f,1.0f };
GLfloat high_shininess[] = { 50.0f };

void generateMap()
{
	for (int i = 0; i<17; ++i)
	{
		for (int j = 0; j<17; ++j)
		{
			if ((i + j) % 2 == 0)
				glColor3ub(0, 102, 0);
			else
				glColor3ub(0, 153, 0);

			if (i == 0 && j == 0) {
				glColor3ub(255, 0, 0);
			}

			if (map[i][j] == 1)
			{
				glPushMatrix();
				glScalef(1, 1, 2);
				glTranslatef(i, j, 0);
			/*	glBindTexture(GL_TEXTURE_2D, ids[0]);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);//앞
				glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
				glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, 1.0f);
				glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, 1.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);//뒤
				glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
				glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
				glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);//위
				glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f, 1.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f, 1.0f);
				glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
				glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);//오른?
				glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);//왼?
				glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
				glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, 1.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);//아래?
				glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
				glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, 1.0f);
				glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
				glEnd();*/
				glutSolidCube(1);
				glPopMatrix();
			}
		}
	}
	glColor3ub(255, 180, 0);
	glPushMatrix();
	glTranslatef(8, 8, -9);
//	glBindTexture(GL_TEXTURE_2D, ids[0]);
	
	glutSolidCube(17);//바닥
	glPopMatrix();
}

void init()
{
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);//법선벡터 normalize함
	glEnable(GL_COLOR_MATERIAL);//material에만 색 적용

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	double aspect = (double)viewport[2] / (double)viewport[3];
	gluPerspective(fovy, aspect, 0.1, 100);
	//(y축 시야각 시야각의 수직범위, 시야의 종횡비 너비와 높이의 비율, near,far 클립핑 평면의 거리)
	//시야각을 늘리면 시야가 넓어지는 대신 왜곡이 심함

	gluLookAt(cameraX, cameraY, 0, cameraLookX, cameraLookY, 0, 0, 0, 1);
//	gluLookAt(-2, 0, 0, -10, 0, 0, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
	generateMap();

	if (cameraX <= -1) {//중앙으로
		cameraX = 8;
		cameraY = 8;
		cameraLookX = 9;
		cameraLookY = 8;
	}

	glutSwapBuffers();
	/*back buffer에 그림을 다 그렸으면, 전면 버퍼와 교체한다.
	전면 버퍼와 교체함으로써 back buffer에 미리 그린 그림이 나타남*/
}

void collision() {
	switch (angle % 4)
	{
	case 0:
		if (map[(int)cameraX + 1][(int)cameraY] == 0) {
			cameraX += 1;
		}
		break;
	case 1:
		if (map[(int)cameraX][(int)cameraY - 1] == 0) {
			cameraY -= 1;
		}
		break;
	case 2:
		if (map[(int)cameraX - 1][(int)cameraY] == 0) {
			cameraX -= 1;
		}
		break;
	case 3:
		if (map[(int)cameraX][(int)cameraY + 1] == 0) {
			cameraY += 1;
		}
		break;
	default:
		break;
	}
}

void cameraLook() {
	switch (angle%4)
	{
	case 0:
		cameraLookX = cameraX + 1;
		cameraLookY = cameraY;
		break;
	case 1:
		cameraLookX = cameraX;
		cameraLookY = cameraY - 1;
		break;
	case 2:
		cameraLookX = cameraX - 1;
		cameraLookY = cameraY;
		break;
	case 3:
		cameraLookX = cameraX;
		cameraLookY = cameraY + 1;
		break;
	default:
		break;
	}
}

void specialkeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		collision();
		cameraLook();
		break;
	case GLUT_KEY_LEFT:
		angle--;
		cameraLook();
		break;
	case GLUT_KEY_RIGHT:
		angle++;
		cameraLook();
		break;
	}
}

void keyboard(unsigned char key, int x, int y) {

	switch (key) {
	case 'Q':
	case 'q':
		if (60 < fovy && fovy < 119) {
			fovy++;
		}
		break;
	case 'E':
	case 'e':
		if (61 < fovy && fovy < 120) {
			fovy--;
		}
		break;
	default:
		break;
	}
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
}

int main(int argc, char **argv)
{
	GLfloat plane_coef_s[] = { 1.0, 0.0, 0.0, 1.0 };
	GLfloat plane_coef_t[] = { 0.0, 1.0, 0.0, 1.0 };

	glutInit(&argc, argv);
	glutInitWindowSize(1280, 720);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutCreateWindow("MAZE");
	init();

/*	glEnable(GL_TEXTURE_GEN_S);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_S, GL_OBJECT_PLANE, plane_coef_s);

	glEnable(GL_TEXTURE_GEN_T);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_T, GL_OBJECT_PLANE, plane_coef_t);*/
	
//	tex[0] = auxDIBImageLoad("grass.bmp");

/*	glGenTextures(1, &ids[0]); 
	glBindTexture(GL_TEXTURE_2D, ids[0]);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, tex[0]->sizeX, tex[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, tex[0]->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);*/

	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(specialkeys);
	glutKeyboardFunc(keyboard);

	
	glClearColor(1, 1, 1, 1);
	glutMainLoop();
	return 0;
}