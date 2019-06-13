/// colisao de quadrados 
#include <stdio.h>
#include <stdlib.h> 
#include <GL/glut.h> 
#include<math.h>
#define janela_altura 400 
#define janela_largura 600 
#define PI 3.141615
float trans = 100;
float cateto1, cateto2, distancia;

struct vertices
{
	int x;
	int y;
};

struct vertices setaM;


void display(void);
void tela(GLsizei W, GLsizei h);
void movimentoM(int x, int y);

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	// suporte a janelas 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // PADRAO DE CORES 
	glutInitWindowSize(janela_largura, janela_altura); // tamanho da janela 
	glutInitWindowPosition(0, 0); // posicao que surge a janela 
	glutCreateWindow("Colisão"); // cria janela 

	glutPassiveMotionFunc(movimentoM);
	glutReshapeFunc(tela); // configura a tela 
	glutDisplayFunc(display);
	glutMainLoop(); // redesenhar 
	return(0);
}

void movimentoM(int x, int y)
{
	setaM.x = x - (janela_largura / 2);
	setaM.y = y - (janela_altura / 2);

	cateto1 = setaM.x;
	cateto2 = setaM.y;

	distancia = sqrt((cateto1 * cateto1) + (cateto2 * cateto2));

}


void desenhar()
{
	glScaled(1, -1, 1);
	glTranslatef(0, 0, 0);

	GLfloat circ_pnt = 500;
	GLfloat ang, raioX = 70.0f, raioY = 70.0f;

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX, sin(ang) * raioY);
	}
	glEnd();

	glTranslatef(setaM.x, setaM.y, 0);
	// cor 
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX, sin(ang) * raioY);
	}
	glEnd();
	glutPostRedisplay();
}
void display()
{
	glMatrixMode(GL_MODELVIEW); //coordenadas de desenho 
	glLoadIdentity();

	if (distancia >= 140) {

		glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
	}
	else {

		glClearColor(1.0f, 0.0f, 1.0f, 1.0f); // cor do fundo 
	}

	glClear(GL_COLOR_BUFFER_BIT); // EXECUTA LIMPESA 
								 
	glTranslatef(janela_largura / 2, janela_altura / 2, 0.0f);
	glViewport(0, 0, janela_largura, janela_altura);
	desenhar();
	glFlush();
	// execute o desenho 
}
void tela(GLsizei W, GLsizei h) {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// cria a janela (esq, direita, embaixo, em cima) 
	gluOrtho2D(0, janela_largura, 0, janela_altura);
	glMatrixMode(GL_MODELVIEW);
}