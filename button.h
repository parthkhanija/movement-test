#pragma once
#include "cprocessing.h"

void createButton(char text[], float x, float y, float width, float height, float roundness, void (*f)(void), CP_Color colorDefault, CP_Color colorHover, CP_Color colorDown, CP_Color textColor, float textSize);