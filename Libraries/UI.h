#include <string>
#include <string.h>
#include <GL/freeglut.h>

void displayText(float x, float y, float r, float g, float b, const char *string)
{
    int j = strlen(string);

    glColor3f(r, g, b);
    glRasterPos2f(x, y);
    for (int i = 0; i < j; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
    }
}

char* intToString(int data) {
    std::string strData = std::to_string(data);

    char* temp = new char[strData.length() + 1];
    strcpy(temp, strData.c_str());

   return temp;
}

void displayPoints(float x, float y, float r, float g, float b, const int value)
{
    char* number = intToString(value);
    int j = strlen(number);

    glColor3f(r, g, b);
    glRasterPos2f(x, y);
    for (int i = 0; i < j; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, number[i]);
    }
}
