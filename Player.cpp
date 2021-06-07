#include <GL/freeglut.h>

class Player
{
private:
    float x1, x2, x3,x4;
    float y1, y2, y3,y4;

public:
    void start()
    {
        x1 = 15;
        y1 = 3;
        x2 = 15;
        y2 = -3;
        x3 = -15;
        y3 = -3;
        x4 = -15;
        y4 = 3;
    }

    void setPlayer()
    {
        glPushMatrix();
        glTranslatef(0,-80,0);
        glColor3f(0,0,1);
        glBegin(GL_QUADS);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glVertex2f(x3,y3);
        glVertex2f(x4,y4);
        glEnd();
        glPopMatrix();
    }
};
