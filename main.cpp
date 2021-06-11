#include <string.h>
#include <GL/freeglut.h>
#include "Objects/Player.cpp"
#include "Objects/Scene.cpp"
#include "Libraries/UI.h"

#define BACKGROUND_R 0.1f
#define BACKGROUND_G 0.1f
#define BACKGROUND_B 0.0f
#define BACKGROUND_ALPHA 255

#define TEXT_R 1.0f
#define TEXT_G 1.0f
#define TEXT_B 1.0f

Player player;
Scene scene;

void init(void)
{
	glClearColor(BACKGROUND_R, BACKGROUND_G, BACKGROUND_B, BACKGROUND_ALPHA);
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
	scene.setScene();
	player.setPlayer();
	displayText(-50,92,TEXT_R,TEXT_G,TEXT_B,"Lifes:");
	displayPoints(-25,92,TEXT_R,TEXT_G,TEXT_B,10);
	displayText(0,92,TEXT_R,TEXT_G,TEXT_B,"Score:");
	displayPoints(25,92,TEXT_R,TEXT_G,TEXT_B,18574);
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
	case 'A':
		moveLeft();
		break;
	case 'd':
	case 'D':
		moveRight();
		break;
	}
	glutPostRedisplay();
}
