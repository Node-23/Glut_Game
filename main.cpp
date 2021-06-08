#include <string.h>
#include <GL/freeglut.h>
#include "Objects/Player.cpp"
#include "Libraries/UI.h"

Player player;
float R, G, B, A;

void init(void)
{
	glClearColor(255, 255, 255, 255);
	player.start();
}

void draw(void);
void movePlayer(int key, int x, int y);
void getKeyboard(unsigned char key, int x, int y);

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(512, 512);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Game-Project");
	init();
	glutDisplayFunc(draw);
	glutSpecialFunc(movePlayer);
	glutKeyboardFunc(getKeyboard);
	glutMainLoop();
	return 0;
}

void displayText(float x, float y, int r, int g, int b, const char *string)
{
	int j = strlen(string);

	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	for (int i = 0; i < j; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100, 100, -100, 100, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	player.setPlayer();
	displayText(-90,90,0,0,0,"Lifes:");
	displayText(-40,90,0,0,0,"Score:");
	glutSwapBuffers();
}

void moveLeft()
{
	if (player.getMoveX() > -85)
	{
		player.setMoveX(-5);
	}
}

void moveRight()
{
	if (player.getMoveX() < 85)
	{
		player.setMoveX(5);
	}
}

void movePlayer(int key, int x, int y)
{
	if (key == GLUT_KEY_LEFT)
	{
		moveLeft();
	}
	if (key == GLUT_KEY_RIGHT)
	{
		moveRight();
	}
	glutPostRedisplay();
}

void getKeyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	case 'a':
		moveLeft();
		break;
	case 'd':
		moveRight();
		break;
	}
	glutPostRedisplay();
}
