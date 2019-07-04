#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#define PI 3.1415926535898
#define janela_altura 835
#define janela_largura 1590

int posCar[7] = { 0,0,0,0,0,0,0 };
int cary[7] = { 0,0,0,0,0,0,0 };
int cary2[7] = { 0,0,0,0,0,0,0 };
void display(void);
void tela(GLsizei w, GLsizei h);
void attCar();
void telaDeJogo(int value);
void car();
int larguraGalinha = -155.0;
int alturaGalinha = -410;
int velocidadeGalinha = 8;
float galinha_x = -195.0;
float galinha_y = -360;
void galinha(float x, float y, float width, float height);
void keyboard();
void music();


int main(int argc, char** argv)
{
	
	glutInit(&argc, argv); // suporte a janelas
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// PADRAO DE CORES
	glutInitWindowSize(janela_largura, janela_altura); // tamanho da janela
	glutInitWindowPosition(0, 0); // posicao que surge a janela
	glutCreateWindow("FreeWay"); // cria janela
												 //glutFullScreen();
	glutReshapeFunc(tela); // configura a tela
	music();
	glutDisplayFunc(display);
	glutTimerFunc((1000 / 60), telaDeJogo, 0);
	glutMainLoop(); // redesenhar
	return(0);
}

void keyboard() {
	if (GetAsyncKeyState(VK_UP) && (alturaGalinha < 835 / 2)) {
		galinha_y += velocidadeGalinha;
		alturaGalinha += velocidadeGalinha;
	}
	else if(GetAsyncKeyState(VK_UP) && (galinha_y > 835/2)){
		galinha_y = -360;
		alturaGalinha = -410;
	}
	if (GetAsyncKeyState(VK_DOWN) && alturaGalinha > -835/2) {
		galinha_y -= velocidadeGalinha;
		alturaGalinha -= velocidadeGalinha;
	}

}

void desenhar()
{
	glPushMatrix();
	glColor3f(0.67f, 0.67f, 0.67f);
	glBegin(GL_QUADS);
	glVertex3f(795.0, 380.0, 0.0);
	glVertex3f(-795.0, 380.0, 0.0);
	glVertex3f(-795.0, -415.0, 0.0);
	glVertex3f(795.0, -415.0, 0.0);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex3f(795.0, 345.0, 0.0);
	glVertex3f(-795.0, 345.0, 0.0);
	glVertex3f(-795.0, 340.0, 0.0);
	glVertex3f(795.0, 340.0, 0.0);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(795.0, -360.0, 0.0);
	glVertex3f(-795.0, -360.0, 0.0);
	glVertex3f(-795.0, -365.0, 0.0);
	glVertex3f(795.0, -365.0, 0.0);
	glEnd();
	int x1 = 0;
	int x2 = 0;
	int y1 = -250.0;
	int y2 = -255.0;
	for (int i = 0; i < 6; i++) {
		x1 = -735.0;
		x2 = -775.0;
		for (int y = 0; y < 20;y++) {
			glColor3ub(255, 255, 0);
			glBegin(GL_QUADS);
			glVertex3f(x1, y1, 0.0);
			glVertex3f(x2, y1, 0.0);
			glVertex3f(x2, y2, 0.0);
			glVertex3f(x1, y2, 0.0);
			glEnd();
			x1 += 80;
			x2 += 80;
		}
		y1 += 100;
		y2 += 100;
	}

	car();
	
	glPopMatrix(); //restaurei a matriz da pilha

	galinha(galinha_x, galinha_y, larguraGalinha, alturaGalinha);
}

void car() {
	int y1;
	int y2;
	y1 = -340.0;
	y2 = -260.0;
	for (int i = 0; i < 7; i++) {
		glPushMatrix();
		glTranslated((__int64)posCar[i], 0, 0);
		glColor3ub(0, 0, 0);
		glBegin(GL_QUADS);
		glVertex3f(-745.0, y1 - 5, 0.0);
		glVertex3f(-725.0, y1 - 5, 0.0);
		glVertex3f(-725.0, y2 + 5, 0.0);
		glVertex3f(-745.0, y2 + 5, 0.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-785.0, y1 - 5, 0.0);
		glVertex3f(-775.0, y1 - 5, 0.0);
		glVertex3f(-775.0, y2 + 5, 0.0);
		glVertex3f(-785.0, y2 + 5, 0.0);
		glEnd();

		glColor3ub(150, 250, 150);
		glBegin(GL_QUADS);
		glVertex3f(-795.0, y1, 0.0);
		glVertex3f(-705.0, y1, 0.0);
		glVertex3f(-705.0, y2, 0.0);
		glVertex3f(-795.0, y2, 0.0);
		glEnd();
		
		glColor3ub(250, 80, 0);
		glBegin(GL_QUADS);
		glVertex3f(-795.0, y1 + 5, 0.0);
		glVertex3f(-775.0, y1 + 5, 0.0);
		glVertex3f(-775.0, y2 - 5, 0.0);
		glVertex3f(-795.0, y2 - 5, 0.0);
		glEnd();
		glPopMatrix();
		cary[i] = y1;
		cary2[i] = y2;
		y1 += 100;
		y2 += 100;
	}
}

void music() {
	Beep(330, 100);Sleep(100);
	Beep(330, 100);Sleep(300);
	Beep(330, 100);Sleep(300);
	Beep(262, 100);Sleep(100);
	Beep(330, 100);Sleep(300);
	Beep(392, 100);Sleep(700);
	Beep(196, 100);Sleep(700);
	Beep(262, 300);Sleep(300);
	Beep(196, 300);Sleep(300);
	Beep(164, 300);Sleep(300);
	Beep(220, 300);Sleep(100);
	Beep(246, 100);Sleep(300);
	Beep(233, 200);
}

void galinha(float x, float y, float width, float height) {
	glPushMatrix();

	glColor3ub(253, 223, 27);
	glBegin(GL_TRIANGLES);
	glVertex3f(x, y, 0.0);
	glVertex3f(width, y, 0.0);
	glVertex3f(width + 10, height + 10, 0.0);
	glEnd();

	glColor3ub(253, 223, 27);
	glBegin(GL_TRIANGLES);
	glVertex3f(x, y, 0.0);
	glVertex3f(width + 5, y + 5, 0.0);
	glVertex3f(width, height, 0.0);
	glEnd();

	glColor3ub(253, 223, 27);
	glBegin(GL_TRIANGLES);
	glVertex3f(x, y, 0.0);
	glVertex3f(width, y, 0.0);
	glVertex3f(width - 7, height - 7, 0.0);
	glEnd();

	glColor3ub(253, 223, 27);
	glBegin(GL_TRIANGLES);
	glVertex3f(x, y, 0.0);
	glVertex3f(width, y, 0.0);
	glVertex3f(width - 14, height - 14, 0.0);
	glEnd();

	glColor3ub(223, 195, 9);
	glBegin(GL_QUADS);
	glVertex3f(x, y, 0.0);
	glVertex3f(width, y, 0.0);
	glVertex3f(width, height, 0.0);
	glVertex3f(x, height, 0.0);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex3f(x + 22, y - 8, 0.0);
	glVertex3f(width- 5 , y - 8, 0.0);
	glVertex3f(width - 5, height + 33, 0.0);
	glVertex3f(x + 22, height + 33, 0.0);
	glEnd();

	

	glPopMatrix();
}

void telaDeJogo(int value) {

	keyboard();

	attCar();

	glutTimerFunc((1000 / 60), telaDeJogo, 0);

	glutPostRedisplay();
}

void attCar()
{
	int j=5;
	for (int i = 0; i < 7; i++) {
		j += 2;
		posCar[i] += 1 * j;
	}
	if (posCar[0] == 1596) {
		posCar[0] = 0;
	}
	else if (posCar[1] == 1593) {
		posCar[1] = 0;
	}
	else if (posCar[2] == 1573) {
		posCar[2] = 0;
	}
	else if (posCar[3] == 1573) {
		posCar[3] = 0;
	}
	else if (posCar[4] == 1590) {
		posCar[4] = 0;
	}
	else if (posCar[5] == 1615) {
		posCar[5] = 0;
	}
	else if (posCar[6] == 1577) {
		posCar[6] = 0;
	}
	/*printf("%i \t %f \n", posCar[0], galinha_x);
	Sleep(100);*/

	if (posCar[0] < 660 && posCar[0] > 510 && cary[0] < galinha_y && cary2[0] > alturaGalinha){
		galinha_y += -100;
		alturaGalinha += -100;
		Beep(523, 50);
	}
	if (posCar[1] < 660 && posCar[1] > 510 && cary[1] < galinha_y && cary2[1] > alturaGalinha) {
		galinha_y += -100;
		alturaGalinha += -100;
		Beep(523, 50);
	}
	if (posCar[2] < 660 && posCar[2] > 510 && cary[2] < galinha_y && cary2[2] > alturaGalinha) {
		galinha_y += -100;
		alturaGalinha += -100;
		Beep(523, 50);
	}
	if (posCar[3] < 660 && posCar[3] > 510 && cary[3] < galinha_y && cary2[3] > alturaGalinha) {
		galinha_y += -100;
		alturaGalinha += -100;
		Beep(523, 50);
	}
	if (posCar[4] < 660 && posCar[4] > 510 && cary[4] < galinha_y && cary2[4] > alturaGalinha) {
		galinha_y += -100;
		alturaGalinha += -100;
		Beep(523, 50);
	}
	if (posCar[5] < 660 && posCar[5] > 510 && cary[5] < galinha_y && cary2[5] > alturaGalinha) {
		galinha_y += -100;
		alturaGalinha += -100;
		Beep(523, 50);
	}
	if (posCar[6] < 660 && posCar[6] > 510 && cary[6] < galinha_y && cary2[6] > alturaGalinha) {
		galinha_y += -100;
		alturaGalinha += -100;
		Beep(523, 50);
	}

}
void display()
{
	glMatrixMode(GL_MODELVIEW); //coordenadas de desenho
	glLoadIdentity();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // cor do fundo
	glClear(GL_COLOR_BUFFER_BIT); // EXECUTA LIMPESA
								  // Especificar o local aonde o desenho acontece: bem no centro da janela
	glTranslatef(janela_largura / 2, janela_altura / 2, 0.0f);
	glViewport(0, 0, janela_largura, janela_altura);
	desenhar();

	glFlush(); // execute o desenho
}
void tela(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// cria a janela (esq, direita, embaixo, em cima)
	gluOrtho2D(0, janela_largura, 0, janela_altura);
	glMatrixMode(GL_MODELVIEW);
}


