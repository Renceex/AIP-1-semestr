#include "GL/freeglut.h"
#define _USE_MATH_DEFINES
#include"cmath"
#include"drawLibLOZKO.h"
// блок объявлений функций
float pos_x = 0, pos_y = 0;
bool isRight = true;
float angle = 0.0;
bool isGetFlowers[4] = { false,false,false,false };
int Apples = 0;
bool Win = false;
float Apple_x = 0, Apple_y = 0;

void renderScene(void);
void processKeys(unsigned char key, int x, int y); // определение фнкции перед фукнцией main
void drawGrafiik();
void drawSquad(float x, float y);
int main(int argc, char* argv[])
{
    srand(10);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(000,000);
    glutInitWindowSize(500,500);
    glutCreateWindow("OpenGL Start Application");
    glutDisplayFunc(renderScene);
    glutKeyboardFunc(processKeys);
    glutMainLoop();
    return 0;
}
//glTranslatef(x,y,z);
//glRotatef(a,x,y,z);
//glScalef(x,y,z);
float fun(float x) {
    float y;
    if (x > 3)
        y = 2 * x - 10;
    else if (x < 3)
        y = ((2*x + 1)*(2 * x + 1))-1;
    else
        y = 10;
    return y;
}
void drawGrafiik() {
    glPushMatrix();
    glScalef(.05, .05, 1);
    glTranslatef(-3, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(-1000, 0);
    glVertex2f(1000, 0);
    glVertex2f(0, 1000);
    glVertex2f(0, -1000);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glScalef(0.01, 0.01, 0);
    //for (float i = -100; i < 100; i += 0.1) {
        //glVertex2f(4 * exp(2 * i) * cos(3 * i + 1), 4 * exp(2 * i) * sin(4 * i + 2));
       // glVertex2f(pow(i + sin(i), 3), i);
       // glVertex2f(exp(i + 3) / tan(i), i);
        // glColor3f(0, 0.3, .5);
        // glVertex2f(5 * cos(i * 22), sin(i));
       // glVertex2f(cos(i) + 0.4 * cos(i) * cos(20 * i), sin(i) + 0.4 * sin(i) * cos(20 * i));
          // glVertex2f(i, -(5 + 4 * i) * (5 + 4 * i) + 8 * i);
       // glVertex2f(i, (2+ i) * (2+ i) + 3 * i);
        //glVertex2f(i, -i*(3+2*i)*(3+2*i)+3*i+sin(2*i));

    //}
    float x = -100.0;
    while (x < 100) {
        glVertex2f(x, x * x * sin(x));
        glVertex2f(x, fun(x));
        x += 0.01;
    }
    glEnd();
    glPopMatrix();

}
void processKeys(unsigned char key, int x, int y) {
    if (key == 100) {
        pos_x = pos_x + 0.1;
        isRight = false;
    }
    if (key == 97) {
        pos_x = pos_x - 0.1;
        isRight = true;
    }
    if (key == 115) {
        pos_y = pos_y - 0.1;
      
    }
    if (key == 119) {
        pos_y = pos_y + 0.1;
       
    }
    if (key == 113) {
        angle += 5;

    }
    if (key == 101) {
        angle -= 5;

    }


    if (key == 13)
        exit(0); // close app
    // Логика поведения
    if((pos_x >= 1.2) && (pos_x <= 1.35) && 
        (pos_y >= - 1.4) && (pos_y <= -1.25))
    {
        isGetFlowers[0] = true;
    }
    if ((pos_x >= -1.3) && (pos_x <= -1.15) &&
        (pos_y >= -1.4) && (pos_y <= -1.25))
    {
        isGetFlowers[1] = true;
    }
    if ((pos_x >= -1.3) && (pos_x <= -1.15) &&
        (pos_y >= 1.25) && (pos_y <= 1.4))
    {
        isGetFlowers[2] = true;

    }
    if ((pos_x >= Apple_x - 0.2) && (pos_x <= Apple_x + 0.2) &&
        (pos_y >= Apple_y - 0.2) && (pos_y <= Apple_y + 0.2))
    {
        Apples++;
        Apple_x = 2 * (float)rand() / RAND_MAX - 1;
        Apple_y = 2 * (float)rand() / RAND_MAX - 1;
        Win = Apples = 10;


    }

    
  

    glutPostRedisplay(); // отрисовка
}
void drawSquad(float x, float y) {
    glPushMatrix();
    glTranslatef(x,y,0);
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.1, 0.7);
    glVertex2f(-0.1, -0.1);
    glVertex2f(-0.1, 0.1);
    glVertex2f(0.1, 0.1);
    glVertex2f(0.1, -0.1);
    glEnd();
    glPopMatrix();
}


 void DrawCat(float x, float y, bool IsRight,float a) {
    // кот
    glPushMatrix();
    glScalef(.65, .65, 0);
    glTranslatef(x, y, 0);
    glRotatef( a, 0, 0, 1);
    if (!isRight)
        glRotatef(180, 0, 1, 0);
    glBegin(GL_TRIANGLES);//хвостик
    glColor3f(1, .3, .0);
    glVertex2f(-.2, -.3);
    glVertex2f(.4, .0);
    glVertex2f(.55, -.02);
    //тело
    glColor3f(1, .3, .0);
    glVertex2f(-.2, -.3);
    glColor3f(.7, .7, .7);
    glVertex2f(.2, -0.3);
    glColor3f(1, .3, .0);
    glVertex2f(0, .2);
    //голова
    glColor3f(1, .3, .0);
    glVertex2f(.2, .3);
    glColor3f(1, .3, .0);
    glVertex2f(0, -.1);
    glColor3f(.7, .7, .7);
    glVertex2f(-.2, .3);
    //ухо Л
    glColor3f(8, .8, .8);
    glVertex2f(-.1, .3);
    glColor3f(1, .2, .0);
    glVertex2f(-.15, .4);
    glVertex2f(-.2, .3);
    //ухо П
    glColor3f(8, .8, .8);
    glVertex2f(.1, .3);
    glColor3f(1, .2, .0);
    glVertex2f(.15, .4);
    glVertex2f(.2, .3);
    //глаз Л
    glColor3f(.3, .6, .3);
    glVertex2f(-.11, .25);
    glVertex2f(-.03, .25);
    glVertex2f(-.07, .19);
    //глаз П
    glColor3f(.3, .6, .3);
    glVertex2f(.11, .25);
    glVertex2f(.03, .25);
    glVertex2f(.07, .19);
    //лапка П
    glColor3f(.2, .2, .2);
    glVertex2f(.25, -.31);
    glVertex2f(.15, -.31);
    glVertex2f(.2, -.24);
    //лапка Л
    glColor3f(.2, .2, .2);
    glVertex2f(-.25, -.31);
    glVertex2f(-.15, -.31);
    glVertex2f(-.2, -.24);
    //нос
    glColor3f(.9, .2, .1);
    glVertex2f(.0, .16);
    glVertex2f(-.03, .13);
    glVertex2f(.03, .13);
    glEnd();
    glPopMatrix();
}
void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // эта функция должна быть первой в renderScene
  
   

    //второй котик
     // drawCat();

    // елка
   // drawSpruce(0,0,0);

    //собака
    //drawDog(Apple_x,Apple_y);



    // drawGrafiik();
     //plotGraph();
    /*
    DrawCat(pos_x, pos_y, isRight, angle);
    if (!isGetFlowers[0])
        drawSquad(0.8, -0.9);
    if (!isGetFlowers[1])
        drawSquad(-0.8, -0.9);
    if (!isGetFlowers[2])
        drawSquad(-0.8, 0.9);
    if (isGetFlowers[0] && isGetFlowers[1] && isGetFlowers[2])
        drawSquad(0, 0);
    if (!isGetFlowers[3])
        drawSquad(Apple_x, Apple_y);
    */
  /*
    Figra Cat;
  Cat.x = 0;
  Cat.y = 0;
  Cat.z = 0;
  Cat.color[0] = 1;
  Cat.color[1] = .4;
  Cat.color[2] = .1;
    drawCat(Cat);
    */
   // DrawCat(pos_x,pos_y,0,0.1);

  

    glutSwapBuffers(); // эта функция должна быть последней в renderScene
}