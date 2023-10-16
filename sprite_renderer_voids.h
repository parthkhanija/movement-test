#pragma once
#include "cprocessing.h"

void sprite_splice(CP_Image* imageArray, CP_Image sheet, int sheet_col_amount, int amount, int row);
void load_pixels_in_sprite_array(int* pixelNumArray, CP_Image sheet, int sheet_col_amount, int row, int spriteNum);
void loadCharArray(unsigned char* charArray, CP_Color* array, int c_arrayLength);
void spriteSpliceFree(CP_Image* splice, int arrayLength);