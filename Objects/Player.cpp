#include <GL/freeglut.h>

#define PLAYER_R 0.0f
#define PLAYER_G 0.5f
#define PLAYER_B 1.0f

class Player
{
private:
    float x1, x2, x3, x4;
    float y1, y2, y3, y4;
    float moveX;

public:
    void start()
    {
        //If you change the value of X, dont forget to change it on the movePlayer function
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
        glTranslatef(0, -80, 0);
        glColor3f(PLAYER_R, PLAYER_G, PLAYER_B);
        glBegin(GL_QUADS);
        glVertex2f(x1 + moveX, y1);
        glVertex2f(x2 + moveX, y2);
        glVertex2f(x3 + moveX, y3);
        glVertex2f(x4 + moveX, y4);
        glEnd();
        glPopMatrix();
    }

    void setMoveX(float NewMoveX)
    {
        moveX += NewMoveX;
    }

    float getMoveX()
    {
        return moveX;
    }
};
