#pragma once
#include "cprocessing.h"

CP_Image* sprite_splice(CP_Image sheet, int sheet_col_amount, int amount, int row);
void spritePixelNum(int* pixeNumArray, CP_Image sheet, int sheet_col_amount, int row, int spriteNum);
unsigned char* returnCharArray(CP_Color* array, int arrayLength);