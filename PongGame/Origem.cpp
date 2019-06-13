#include<GL/glew.h>
#include<GL/glut.h>
#include<GLFW/glfw3.h>
#include<GL/freeglut.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<sstream>


int larguraRaquete = 20;
int alturaRaquete = 80;
int velocidadeRaquete = 8;
float raqueteEsquerda_x = 20;
float raqueteEsquerda_y = 300;
float rx = 1;
float gx = 1;
float bx = 1;
float ry = 1;
float gy = 1;
float by = 1;
int largura = 800;
int altura = 700;
int intervalo = 1000 / 60;
int limite = 700-80;
float raqueteDireita_x = largura - larguraRaquete - 10;
float raqueteDireita_y = 300;
float posBola_x = largura / 2;
float posBola_y = altura / 2;
float dirBola_x = 5.0f;
float dirBola_y = 5.0f;
int tamanhoBola = 12;
int velocidadeBola = 1;
int i=0;


void telaDeJogo(int value);
void desenhar();
void enable2D(int width, int height);
void raquete(float x, float y, float width, float height, int r, int g, int b);
void attBola();
void keyboard();
void bola();
void attCor(int type, int palheta);



int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(largura, altura);
	glutCreateWindow("PONGJHONSON");

	//chamando as funcoes 
	glutDisplayFunc(desenhar);
	glutTimerFunc(intervalo, telaDeJogo, 0);

	enable2D(largura, altura);
	glColor3f(1.0f, 1.0f, 1.0f);


	glutMainLoop();
	return 0;
}

void keyboard() {
	// raquete esquerda
	if (GetAsyncKeyState(0x57) && raqueteEsquerda_y < limite) {
		raqueteEsquerda_y += velocidadeRaquete;
	}
	if (GetAsyncKeyState(0x53) && raqueteEsquerda_y > 0) {
		raqueteEsquerda_y -= velocidadeRaquete;
	}

	// raquete direita
	if (GetAsyncKeyState(VK_UP) && raqueteDireita_y<limite) {
		raqueteDireita_y += velocidadeRaquete;
	}
	if (GetAsyncKeyState(VK_DOWN) && raqueteDireita_y > 0) {
		raqueteDireita_y -= velocidadeRaquete;
	}

}

void desenhar() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	// desenhar as raquetes
	raquete(raqueteEsquerda_x, raqueteEsquerda_y, larguraRaquete, alturaRaquete, rx, gx, bx);
	raquete(raqueteDireita_x, raqueteDireita_y, larguraRaquete, alturaRaquete, ry, gy, by);

	// desenhar a bola
	bola();

	glutSwapBuffers();
}

void telaDeJogo(int value) {
	i++;
	keyboard();

	attBola();
	if (i > 10) {
		i = 0;
		attCor(0,3);
	}
	glutTimerFunc(intervalo, telaDeJogo, 0);

	glutPostRedisplay();
}

void enable2D(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, width, 0.0f, height, 0.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void raquete(float x, float y, float width, float height, int r, int g, int b) {
	glColor3f(r, g, b);
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);
	glVertex2f(x, y + height);
	glEnd();
}

void bola() {
	float PI = 3.14;

	glTranslated((__int64)posBola_x, (__int64)posBola_y, 0);

	// Bolinha
	GLfloat  circ_pnt = 200;
	GLfloat  ang, raioX = 10, raioY = 10;

	glColor3f(1, 1, 1);

	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX, sin(ang) * raioY);
	}
	glEnd();
}

void attCor(int type, int palheta) {
	if (type == 1 && palheta==1) {
		rx = 1;
		gx = 0;
		bx = 0;
	}
	else if (type == 1 && palheta == 2) {
		ry = 1;
		gy = 0;
		by = 0;
	}
	else if (type == 0) {
		rx = 1;
		gx = 1;
		bx = 1;
		ry = 1;
		gy = 1;
		by = 1;

	}
}

void attBola() {
	posBola_x += dirBola_x * velocidadeBola;
	posBola_y += dirBola_y * velocidadeBola;

	if (posBola_x > raqueteEsquerda_x &&
		posBola_x < raqueteEsquerda_x + larguraRaquete &&
		posBola_y < raqueteEsquerda_y + alturaRaquete &&
		posBola_y > raqueteEsquerda_y) {
		attCor(1,1);
		float t = ((posBola_y - raqueteEsquerda_y) / alturaRaquete) - 0.5f;
		dirBola_x = fabs(dirBola_x); 
		dirBola_y = t;

		
	}

	if (posBola_x > raqueteDireita_x &&
		posBola_x < raqueteDireita_x + larguraRaquete &&
		posBola_y < raqueteDireita_y + alturaRaquete &&
		posBola_y > raqueteDireita_y) {
		attCor(1,2);
		
		float t = ((posBola_y - raqueteDireita_y) / alturaRaquete) - 0.5f;
		dirBola_x = -fabs(dirBola_x); 
		dirBola_y = t;

		
	}

	if (posBola_x < 0) {
		posBola_x = largura / 2;
		posBola_y = altura / 2;
		dirBola_x = fabs(dirBola_x); 
		dirBola_y = 0;
	}

	if (posBola_x > largura) {
		posBola_x = largura / 2;
		posBola_y = altura / 2;
		dirBola_x = -fabs(dirBola_x); 
		dirBola_y = 0;
	}

	if (posBola_y > altura) {
		dirBola_y = -fabs(dirBola_y); 

	}

	if (posBola_y < 0) {
		dirBola_y = fabs(dirBola_y); 
	}
}




