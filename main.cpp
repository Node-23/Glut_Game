#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/freeglut.h>

float R, G, B, A;

void init(void){
	glClearColor(1.0,1.0,1.0,1.0);
	R=255.0;
	G=255.0;
	B=255.0;
    A=255.0;
}

void draw(void);

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(512,512);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Game-Project");
	init();
	glutMainLoop();
	return 0;
}