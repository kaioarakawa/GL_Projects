#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include<math.h>
#define PI 3.1415926535898
#define janela_altura 400
#define janela_largura 600


void display(void);
void tela(GLsizei w, GLsizei h);

int main(int argc, char** argv)
{
	glutInit(&argc, argv); //suporte a janela

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Padrão de cores

	glutInitWindowSize(janela_largura, janela_altura);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Pascoa");

	glutReshapeFunc(tela);
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}

void desenhar()
{
	GLfloat circ_pnt = 500;
	GLfloat ang, raiox = 58.0f, raioy = 60.0f;

	//body
	raiox = 55.0f, raioy = 60.0f;
	glRotated(0, 0, 0, 1);
	glColor3f(0.85, 0.85, 0.95);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raiox, sin(ang) * raioy - 50);
	}
	glEnd();

	//body
	raiox = 35.0f, raioy = 45.0f;
	glRotated(0, 0, 0, 1);
	glColor3f(1, 0.98 , 0.94);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raiox, sin(ang) * raioy - 50);
	}
	glEnd();

	//orelha
	raiox = 20.0f, raioy = 50.0f;
	glRotated(0, 0, 0, 1);
	glColor3f(0.85, 0.85, 0.95);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raiox - 35, sin(ang) * raioy + 130);
	}
	glEnd();

	raiox = 10.0f, raioy = 40.0f;
	glRotated(0, 0, 0, 1);
	glColor3f(0.67, 0.94, 0.94);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raiox - 35, sin(ang) * raioy + 130);
	}
	glEnd();
	//orelha
	raiox = 20.0f, raioy = 50.0f;
	glRotated(0, 0, 0, 1);
	glColor3f(0.85, 0.85, 0.95);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raiox + 35, sin(ang) * raioy + 130);
	}
	glEnd();

	raiox = 10.0f, raioy = 40.0f;
	glRotated(0, 0, 0, 1);
	glColor3f(0.67, 0.94, 0.94);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raiox + 35, sin(ang) * raioy + 130);
	}
	glEnd();
	//rosto
	raiox = 55.0f, raioy = 60.0f;
	glRotated(0, 0, 0, 1);
	glColor3f(0.85, 0.85, 0.95);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raiox, sin(ang) * raioy + 60);
	}
	glEnd();


	//olho
	raiox = 9.0f, raioy = 15.0f;
	glRotated(0, 0, 0, 1);
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raiox+25, sin(ang) * raioy + 80);
	}
	glEnd();

	raiox = 3.0f, raioy = 3.0f;
	glRotated(0, 0, 0, 1);
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raiox + 22, sin(ang) * raioy + 85);
	}
	glEnd();

	raiox = 9.0f, raioy = 15.0f;
	glRotated(0, 0, 0, 1);
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raiox - 25, sin(ang) * raioy + 80);
	}
	glEnd();


	raiox = 3.0f, raioy = 3.0f;
	glRotated(0, 0, 0, 1);
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raiox - 27, sin(ang) * raioy + 85);
	}
	glEnd();

	//boca
	raiox = 9.0f, raioy = 12.0f;
	glRotated(0, 0, 0, 1);
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	for (int i = circ_pnt; i > circ_pnt/2; i--) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raiox + 7, sin(ang) * raioy + 38);
	}
	glEnd();

	raiox = 9.0f, raioy = 12.0f;
	glRotated(0, 0, 0, 1);
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	for (int i = circ_pnt; i > circ_pnt / 2; i--) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raiox - 9, sin(ang) * raioy + 38);
	}
	glEnd();


	//nariz
	glBegin(GL_TRIANGLES);
	glColor3f(1, 0.07f, 0.588f);
	glVertex2f(6.0f, 50.0f);
	glVertex2f(-9.0f, 50.0f);
	glVertex2f(-1.5f, 40.0f);
	glEnd();

	raiox = 5.0f, raioy = 7.0f;
	glRotated(0, 0, 0, 1);
	glColor3f(1, 0.07f, 0.588f);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt / 2; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raiox -3.5, sin(ang) * raioy + 48);
	}
	glEnd();

	raiox = 5.0f, raioy = 7.0f;
	glRotated(0, 0, 0, 1);
	
	glColor3f(1, 0.07f,0.588f);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt / 2; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raiox + 0.50, sin(ang) * raioy + 48);
	}
	glEnd();


	//pernas
	raiox = 20.0f, raioy = 30.0f;
	glRotated(0, 0, 0, 1);
	glColor3f(0.85, 0.85, 0.95);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raiox+40, sin(ang) * raioy - 100);
	}
	glEnd();

	raiox = 20.0f, raioy = 30.0f;
	glRotated(0, 0, 0, 1);
	glColor3f(0.75, 0.75, 0.75);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raiox + 40, sin(ang) * raioy - 100);
	}
	glEnd();

	raiox = 20.0f, raioy = 30.0f;
	glRotated(0, 0, 0, 1);
	glColor3f(0.85, 0.85, 0.95);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raiox - 40, sin(ang) * raioy - 100);
	}
	glEnd();

	raiox = 20.0f, raioy = 30.0f;
	glRotated(0, 0, 0, 1);
	glColor3f(0.75, 0.75, 0.75);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raiox - 40, sin(ang) * raioy - 100);
	}
	glEnd();

	//ovos
	raiox = 20.0f, raioy = 30.0f;
	glRotated(0, 0, 0, 1);
	glColor3f(0.75, 0.75, 0.75);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raiox - 200, sin(ang) * raioy - 100);
	}
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1, 0.07f, 0.588f);
	glVertex2f(-250.0f, -90.0f);
	glVertex2f(-250.0f, -50.0f);
	glVertex2f(-200.0f, -70.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1, 0.07f, 0.588f);
	glVertex2f(-150.0f, -90.0f);
	glVertex2f(-150.0f, -50.0f);
	glVertex2f(-200.0f, -70.0f);
	glEnd();

	raiox = 20.0f, raioy = 30.0f;
	glRotated(0, 0, 0, 1);
	glColor3f(0.75, 0.75, 0.75);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raiox + 135, sin(ang) * raioy - 30);
	}
	glEnd();


	glBegin(GL_TRIANGLES);
	glColor3f(1, 0.07f, 0.588f);
	glVertex2f(85.0f, -20.0f);
	glVertex2f(85.0f, 20.0f);
	glVertex2f(135.0f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1, 0.07f, 0.588f);
	glVertex2f(185.0f, -20.0f);
	glVertex2f(185.0f, 20.0f);
	glVertex2f(135.0f, 0.0f);
	glEnd();


	//braços
	raiox = 20.0f, raioy = 50.0f;
	glRotated(60, 0, 0, 1);
	glColor3f(0.85, 0.85, 0.95);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt ; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raiox , sin(ang) * raioy - 100);
	}
	glEnd();


	raiox = 20.0f, raioy = 50.0f;
	glRotated(60, 0, 0, 1);
	glColor3f(0.85, 0.85, 0.95);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raiox, sin(ang) * raioy + 100);
	}
	glEnd();
	glRotated(60, 0, 0, 1);













}

void display()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(0.52f, 0.80f, 0.85f, 1.0f);  // cor do fundo

	glClear(GL_COLOR_BUFFER_BIT);  // limpa a tela com a cor do fundo

	glTranslatef(janela_largura / 2, janela_altura / 2, 0.0f);
	glViewport(0, 0, janela_largura, janela_altura);
	desenhar();
	glFlush();
}
void tela(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0, janela_largura, 0, janela_altura);

	glMatrixMode(GL_MODELVIEW);
}