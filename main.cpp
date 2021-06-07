#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include "Player.cpp"

Player player;
float R, G, B, A;

void init(void){
	glClearColor(255,255,255,255);
	player.start();
}

void draw(void);

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(512,512);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Game-Project");
	init();
	glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}

void draw(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100,100,-100,100,-1,1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	player.setPlayer();
	glutSwapBuffers();
}