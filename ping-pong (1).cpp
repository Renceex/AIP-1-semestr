#include "GL/freeglut.h"
#include <ctime>

bool Q = true;

struct pol
{
    int y, x;
} pl, bot;

struct BOLL
{
    int x, 
        y, 
        speedX,
        speedY;
} boll;

void Fon()
{
    glPushMatrix();
    glBegin(GL_QUADS);

    glColor3f(.9, .9, .9);
    glVertex2f(1, 1);
    glVertex2f(-1, 1);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);

    glEnd();
    glPopMatrix();
}

void dravBoll(BOLL Boll)
{
    glPushMatrix();
    glScalef(0.05, 0.05, 1);
    glTranslatef(Boll.x, Boll.y, 0);
    glBegin(GL_QUADS);

    glColor3f(.9, .9, .9);
    glVertex2f(0, 0);
    glVertex2f(0, 1);
    glVertex2f(1, 1);
    glVertex2f(1, 0);

    glEnd();
    glPopMatrix();
}

void dravPol(pol Pol)
{
    glPushMatrix();
    glScalef(0.05, 0.05, 1);
    glTranslatef(Pol.x, Pol.y, 0);
    glBegin(GL_QUADS);

    glColor3f(.9, .9, .9);
    glVertex2f(0, 0);
    glVertex2f(0, 4);
    glVertex2f(1, 4);
    glVertex2f(1, 0);

    glEnd();
    glPopMatrix();
}

void ReturnGame()
{
    pl.x = 17;
    bot.x = -18;
    boll.x = 0;
    boll.y = 0;
    boll.speedX = 1;
    boll.speedY = -1;
    //
    bot.y = 0;
    pl.y = 0;
}

void fizic()
{
    if (boll.x >= 16)
    {
        if ((boll.y == pl.y + 1) || 
            (boll.y == pl.y + 2)) boll.speedX *= (-1);

        if (boll.y == pl.y + 3)
        {
            boll.speedX *= (-1);
            boll.speedY = 1;
        }

        if (boll.y == pl.y)
        {
            boll.speedX *= (-1);
            boll.speedY = -1;
        }
    }

    if (boll.x <= -17)
    {
        if ((boll.y == bot.y + 1) ||
            (boll.y == bot.y + 2)) boll.speedX *= (-1);

        if (boll.y == bot.y + 3)
        {
            boll.speedX *= (-1);
            boll.speedY = 1;
        }

        if (boll.y == bot.y)
        {
            boll.speedX *= (-1);
            boll.speedY = -1;
        }
    }

    if (boll.x > 19 || boll.x < -19)
            ReturnGame();

    if (boll.y >= 19 || boll.y < -19)
        boll.speedY *= (-1);

    if (boll.speedX > 0) boll.x += boll.speedX;
    else boll.x -= (boll.speedX*(-1));

    if (boll.speedY > 0) boll.y += boll.speedY;
    else boll.y -= (boll.speedY * (-1));
}

void fizicsBot()
{
    if (boll.y > (bot.y + 1) && (bot.y + 4) <= 19)
        bot.y += 1;

    if (boll.y < (bot.y + 1))
        bot.y -= 1;
}

void tik(int n)
{
    fizic();
    fizicsBot();

    glutPostRedisplay();
    glutTimerFunc(100, tik, 0);
}

void renderScene(void);

void processKeys(unsigned char key, int x, int y)
{
    //Логика упровления
    if ((key == 119 || key == 246) && (pl.y <= 15))//w
        pl.y += 1;

    if ((key == 115 || key == 251) && (pl.y >= -19))//s
        pl.y -= 1;

    if (key == 114 || key == 234)//r
        ReturnGame();


    glutPostRedisplay();
}

int main(int argc, char* argv[])
{
    srand(time(0));

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(605, 200);
    glutInitWindowSize(650, 650);
    glutCreateWindow("Ping-pong");
    glutDisplayFunc(renderScene);
    glutTimerFunc(100, tik, 0);
    glutKeyboardFunc(processKeys);
    glutMainLoop();
    return 0;
}

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // эта функция должна быть первой в renderScene
    
    if (Q)
    {
        ReturnGame();
        Q = false;
    }

    dravBoll(boll);

    dravPol(pl);

    dravPol(bot);

    glutSwapBuffers(); // эта функция должна быть последний в renderScene
}