#pragma once
#include"GL/freeglut.h"
#define _USE_MATH_DEFINES
#include"cmath"
struct Figra {
	float x, y, z;
	float color[3];
};
void drawGrafik();
void drawCat(Figra fig);
void drawDog();
void drawSpruce();
void DrawCat(float x, float y, bool IsRight, float a);

