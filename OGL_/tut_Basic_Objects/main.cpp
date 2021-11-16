#include "GL/freeglut.h"
#define _USE_MATH_DEFINES
#include"cmath"
// блок объявлений функций
float pos_x = 0, pos_y = 0;
bool isRight = true;
float angle = 0.0;

void renderScene(void);
void processKeys(unsigned char key, int x, int y); // определение фнкции перед фукнцией main
void drawGrafiik() {
    glScalef(.1, .1, 0);
    glBegin(GL_LINES);
    glVertex2f(-1000, 0);
    glVertex2f(1000, 0);
    glVertex2f(0, 1000);
    glVertex2f(0, -1000);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glScalef(0.01, 0.01, 0);
    for (float i = -100; i < 100; i += 0.1) {
        //glVertex2f(4 * exp(2 * i) * cos(3 * i + 1), 4 * exp(2 * i) * sin(4 * i + 2));
       // glVertex2f(pow(i + sin(i), 3), i);
       // glVertex2f(exp(i + 3) / tan(i), i);
        // glColor3f(0, 0.3, .5);
        // glVertex2f(5 * cos(i * 22), sin(i));
       // glVertex2f(cos(i) + 0.4 * cos(i) * cos(20 * i), sin(i) + 0.4 * sin(i) * cos(20 * i));
          // glVertex2f(i, -(5 + 4 * i) * (5 + 4 * i) + 8 * i);
       // glVertex2f(i, (2+ i) * (2+ i) + 3 * i);
        //glVertex2f(i, -i*(3+2*i)*(3+2*i)+3*i+sin(2*i));

    }
    glEnd();

}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(200,000);
    glutInitWindowSize(700,700);
    glutCreateWindow("OpenGL Start Application");
    glutDisplayFunc(renderScene);
    glutKeyboardFunc(processKeys);
    glutMainLoop();
    return 0;
}
//glTranslatef(x,y,z);
//glRotatef(a,x,y,z);
//glScalef(x,y,z);



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
        isRight = false;
    }
    if (key == 119) {
        pos_y = pos_y + 0.1;
        isRight = true;
    }
    if (key == 113) {
        angle += 5;

    }
    if (key == 101) {
        angle -= 5;

    }


    if (key == 13)
        exit(0); // close app
   

    glutPostRedisplay(); // отрисовка
}
 void DrawCat(float x, float y, bool IsRight,float a) {
    // кот
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(.65, .65, 0);
    glRotatef(90 + a, 0, 0, 1);
    if (isRight)
        glRotatef(180, 0, 0, 1);
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

    /*
    glBegin(GL_QUADS);

     //Задний план
    glColor3f(.8, .8, .0);
    glVertex2f(2, 2);
    glColor3f(.02, .02, .79);
    glVertex2f(2, -2);
    glVertex2f(-2, -2);
    glVertex2f(-2, 2);
    // земля
    glColor3f(.0, .72, .0);
    glVertex2f(1, -.5);
    glColor3f(.0, .5, .0);
    glVertex2f(-1, -.5);
    glColor3f(.0, .5, .0);
    glVertex2f(-1, -1);
    glColor3f(.0, .5, .0);
    glVertex2f(1, -1);
    //дорога
    glColor3f(.0, .0, .0);
    glVertex2f(1, -.5);
    glColor3f(.0, .0, .0);
    glVertex2f(-1, -.5);
    glColor3f(.0, .0, .0);
    glVertex2f(-1, -.2);
    glColor3f(.0, .0, .0);
    glVertex2f(1, -.2);
    //разметка на дороге
    glColor3f(.0, .0, .0);
    glVertex2f(1, -.5);
    glColor3f(.0, .0, .0);
    glVertex2f(-1, -.5);
    glColor3f(.0, .0, .0);
    glVertex2f(-1, -.2);
    glColor3f(.0, .0, .0);
    glVertex2f(1, -.2);
    //следующая линия
    glColor3f(.0, .0, .0);
    glVertex2f(1, -.5);
    glColor3f(.0, .0, .0);
    glVertex2f(-1, -.5);
    glColor3f(.0, .0, .0);
    glVertex2f(-1, -.2);
    glColor3f(.0, .0, .0);
    glVertex2f(1, -.2);
    glEnd();


    //кораблик
    glBegin(GL_QUADS);
    //корпус коробля
    glColor3f(.5, .2, .0);
    glVertex2f(.2, .6);
    glVertex2f(.93, .6);
    glVertex2f(.78, .44);
    glVertex2f(.35, .44);
    //мачта
    glColor3f(.5, .2, .0);
    glVertex2f(.55, .97);
    glVertex2f(.55, .6);
    glVertex2f(.59, .6);
    glVertex2f(.59, .97);
    glEnd();
    glBegin(GL_TRIANGLES);
    //флаг 1
    glColor3f(.9, .9, .9);
    glVertex2f(.59, .97);
    glVertex2f(.59, .6);
    glVertex2f(.71, .62);
    //флаг 2
    glColor3f(.5, .9, .9);
    glVertex2f(.55, .97);
    glVertex2f(.55, .6);
    glVertex2f(.32, .70);
    glEnd();


    //часть дома
    glBegin(GL_QUADS);
    //труба дома
    glColor3f(.9, .9, .9);
    glVertex2f(-.42, .5);
    glColor3f(.5, .5, .5);
    glVertex2f(-.42, .0);
    glColor3f(.9, .9, .9);
    glVertex2f(-.3, .0);
    glVertex2f(-.3, .5);
    glEnd();


    //Дом
    glScalef(1.3, 1.3, 1.3);
    glTranslatef(-.2, .0, .0);
    glBegin(GL_TRIANGLES);
    // стены 1
    glColor3f(.9, .9, .9);
    glVertex2f(.0, .0);
    glVertex2f(-.5, .0);
    glVertex2f(.0, -.5);
    // стены 2
    glColor3f(.5, .5, .5);
    glVertex2f(-.5, -.5);
    glColor3f(.9, .9, .9);
    glVertex2f(-.5, .0);
    glVertex2f(.0, -.5);
    //крыша
    glColor3f(.5, .1, .1);
    glVertex2f(-.6, .0);
    glColor3f(.9, .5, .5);
    glVertex2f(-.25, .3);
    glVertex2f(.1, .0);
    glEnd();
    glTranslatef(.0, -.23, .0);
    glBegin(GL_QUADS);
    // Дверь дома
    glColor3f(.9, .0, .0);
    glVertex2f(-.1, -.27);
    glVertex2f(-.22, -.27);
    glVertex2f(-.22, .0);
    glVertex2f(-.1, .0);
    // Окно дома
    glColor3f(.8, .8, .4);
    glVertex2f(-.43, -.05);
    glVertex2f(-.43, .1);
    glVertex2f(-.28, .1);
    glVertex2f(-.28, -.05);
    // рама окна
    glColor3f(1, 1, 1);
    glVertex2f(-.42, -.04);
    glVertex2f(-.42, .09);
    glVertex2f(-.29, .09);
    glVertex2f(-.29, -.04);
    glEnd();


    // Машина
    glScalef(0.8, 0.8, 0);
    glBegin(GL_QUADS);
    //колесо Л
    glColor3f(.11, .93, .41);
    glVertex2f(.68, .04);
    glVertex2f(.76, -.04);
    glVertex2f(.68, -.12);
    glVertex2f(.60, -.04);
    //колесо П
    glColor3f(.21, .67, .84);
    glVertex2f(.3, .04);
    glVertex2f(.38, -.04);
    glVertex2f(.3, -.12);
    glVertex2f(.22, -.04);
    //Корпус
    glColor3f(.71, .7, .71);
    glVertex2f(.2, .0);
    glVertex2f(.78, .0);
    glVertex2f(.78, .24);
    glVertex2f(.2, .24);
    //Бампер машины
    glColor3f(.71, .7, .71);
    glVertex2f(.90, .0);
    glVertex2f(.78, .0);
    glVertex2f(.78, .13);
    glVertex2f(.90, .13);
    //окно машины
    glColor3f(.3, .3, .3);
    glVertex2f(.67, .23);
    glVertex2f(.67, .14);
    glVertex2f(.76, .14);
    glVertex2f(.76, .23);

    glEnd();

    glBegin(GL_TRIANGLES);//на запас

    //
    glEnd();
    */


    //второй котик
     // drawCat();

    // елка
   // drawSpruce(0,0,0);

    //собака
   // drawDog();



    // drawGrafiik();

    DrawCat(pos_x, pos_y, isRight,angle);



    glutSwapBuffers(); // эта функция должна быть последней в renderScene
}