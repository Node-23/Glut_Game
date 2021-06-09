#include <GL/freeglut.h>

#define SCENE_R 0.0f
#define SCENE_G 0.5f
#define SCENE_B 1.0f

class Scene
{
public:
    void setScene()
    {
        glPushMatrix();
        glTranslatef(0, -80, 0);
        //-------------------Left----------------------------
        glColor3f(SCENE_R, SCENE_G, SCENE_B);
        glBegin(GL_POLYGON);
        glVertex2f(-100,170);
        glVertex2f(-97,170);
        glVertex2f(-97,-25);
        glVertex2f(-100,-25);
        glEnd();
        //-------------------Right----------------------------
        glColor3f(SCENE_R, SCENE_G, SCENE_B);
        glBegin(GL_POLYGON);
        glVertex2f(97,170);
        glVertex2f(100,170);
        glVertex2f(100,-25);
        glVertex2f(97,-25);
        glEnd();
        //---------------------Up--------------------------
        glColor3f(SCENE_R, SCENE_G, SCENE_B);
        glBegin(GL_POLYGON);
        glVertex2f(-100,167);
        glVertex2f(100,167);
        glVertex2f(100,170);
        glVertex2f(-100,170);
        glEnd();
        glPopMatrix();
    }

    
        
    
};
