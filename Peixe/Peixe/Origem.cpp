#include<GL/glew.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>

#define windowH 600
#define windowW 1400


float fScale = 3.5;
float sScale = 1;
float tx = 0.0;
float ty = 0.0;
float xStep = 1;
float yStep = 0.25;
float PI = atanf(1.0f)*4.0f;
float R = 70;
float G = 96;
float B = 72;
float R2 = 253;
float G2 = 196;
float B2 = 255;

//
GLfloat circ_pnt = 500;
GLfloat ang, raioX, raioY;

void display(void);
void screen(GLsizei w, GLsizei h);
void keyboard(unsigned char key, int x, int y);
void anima(int value);

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(windowW, windowH);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("PEIXaO");
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	glutReshapeFunc(screen);
	glutDisplayFunc(display);
	glutKeyboardFunc(&keyboard);
	glutTimerFunc(40, anima, 1);
	glutMainLoop();

	return(0);
}

void anima(int value) {
	if ((tx)>(50) || (tx) < (-70)) {
		xStep = -xStep;
	}
	if ((ty)>(15) || (ty) < (-5)) {
		yStep = -yStep;
	}
	tx += xStep;
	ty += yStep;

	glutPostRedisplay();
	glutTimerFunc(20, anima, 1);
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
		//glColor3ub(235, 235, 224);
	case '1':
		R = 0;
		G = 77;
		B = 0;

		R2 = 102;
		G2 = 20;
		B2 = 0;
		break;
	case '2':
		R = 153;
		G = 153;
		B = 0;

		R2 = 153;
		G2 = 38;
		B2 = 0;
		break;
	case '3':
		R = 95;
		G = 33;
		B = 65;

		R2 = 70;
		G2 = 96;
		B2 = 72;
		break;
	case '4':
		R = 153;
		G = 153;
		B = 255;

		R2 = 253;
		G2 = 196;
		B2 = 255;
		break;
	}
}

void peixao() {
	glPushMatrix();
	if (xStep == 1) {
		glScaled(sScale, sScale, sScale);
	}

	if (xStep == -1) {
		glScaled(-(sScale), sScale, sScale);
	}


	//RABO
	glBegin(GL_TRIANGLES);
	glColor3ub(R2, G2, B2);
	glVertex2f(-15,15);
	glVertex2f(-10, -0);
	glVertex2f(-15, -15);
	glEnd();

	raioX = 10.0f;
	raioY = 8.0f;
	//PEIXÂO
	glBegin(GL_POLYGON);
	
	glBegin(GL_POLYGON);
	glColor3ub(R, G, B);
	for (int i = 0;i<100; i++) {
		ang = (2 * PI*i) / 100;
		glVertex2f(cos(ang)*raioX, sin(ang)*raioY);
	}
	glEnd();
	//OLHO
	raioX = 2.5;
	raioY = 2.5;
	glPushMatrix();
	glTranslatef(20, 0, 0);
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 102);
	for (int i = 0;i<100; i++) {
		ang = (2 * PI*i) / 100;
		glVertex2f(cos(ang)*raioX-15, sin(ang)*raioY+2);
	}
	glEnd();
	
	glPopMatrix();
	glPopMatrix();
}

void aqua() {
	raioX = 100;
	raioY = 80;

	glColor4ub(204, 224, 255, 150);
	glBegin(GL_POLYGON);
	for (int i = circ_pnt; i > circ_pnt/2; i--) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2d(cos(ang) * raioX, sin(ang) * raioY + 35);
	}
	glEnd();

	glLineWidth(10.0);
	glColor3ub(191, 191, 191);
	glBegin(GL_LINE_STRIP);
	for (int i = circ_pnt; i > circ_pnt / 2; i--) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2d(cos(ang) * raioX, sin(ang) * raioY+ 35);
	}
	glEnd();


}
void elementos() {
	glLoadIdentity();
	glPushMatrix();
	glTranslatef((windowW) / 2, (windowH) / 2, 0);
	glScalef(fScale, fScale, fScale);

	//MOvimento do Peixe
	glPushMatrix();
	glTranslatef(tx, ty, 0);
	peixao();
	glPopMatrix();
	
	glPushMatrix();
	glScalef(-0.8, 1, 1);
	glRotatef(8, 0, 0, 1);
	glTranslatef(2, 0, 0);
	glPopMatrix();
	aqua();
	glPopMatrix();
}

void display() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(0.91, 0.91, 0.88, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glViewport(0, 0, windowW, windowH);
	elementos();

	glFlush();
}

void screen(GLsizei w, GLsizei h) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0, windowW, 0, windowH);
	glMatrixMode(GL_MODELVIEW);
}