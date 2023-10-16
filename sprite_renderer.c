#include "sprite_renderer.h"
#include "cprocessing.h"
#include <stdlib.h>
#include <stdio.h>

CP_Image* sprite_splice(CP_Image sheet, int sheet_col_amount, int amount, int row)
{
	CP_Image* imageArray = malloc(sizeof(CP_Image) * amount);
	CP_Color* colorArray_sheet = malloc((CP_Image_GetWidth(sheet) * CP_Image_GetHeight(sheet)) * sizeof(CP_Color));
	CP_Image_GetPixelData(sheet, colorArray_sheet);

	int spriteSize = CP_Image_GetWidth(sheet) / sheet_col_amount;
	int* pixelNumArray = malloc(sizeof(int) * (spriteSize*spriteSize));

	CP_Color *colorArray_sprite = malloc(sizeof(CP_Color) * (spriteSize * spriteSize));

	for (int i = 0; i < amount; i++) {
		spritePixelNum(pixelNumArray, sheet, sheet_col_amount, row, i);
		for (int j = 0; j < (spriteSize * spriteSize); j++) {
			colorArray_sprite[j] = colorArray_sheet[pixelNumArray[j]]; // peleg is sorry for fucking up code :( 
		}
		imageArray[i] = CP_Image_CreateFromData(spriteSize, spriteSize, returnCharArray(colorArray_sprite, (spriteSize * spriteSize)));
	}

	return imageArray;
}

void spritePixelNum(int* pixeNumArray, CP_Image sheet, int sheet_col_amount, int row, int spriteNum)
{
	int sheetWidth = CP_Image_GetWidth(sheet);
	int spriteSize = CP_Image_GetWidth(sheet) / sheet_col_amount;
	int* pixelNumArray = malloc(sizeof(int) * (spriteSize * spriteSize));

	int count = 0;
	for (int i = 0; i < spriteSize; i++) {
		int topleft = sheetWidth * (row * spriteSize) + spriteNum * spriteSize;
		for (int j = 0; j < spriteSize; j++) {
			pixelNumArray[count] = sheetWidth * i + topleft + j;
			count += 1;
		}
	}
}

unsigned char* returnCharArray(CP_Color* array, int arrayLength)
{
	unsigned char* charArray = malloc((sizeof(int) * 4) * arrayLength);

	int charIndex = 0;
	for (int i = 0; i < arrayLength; i++) {
		charArray[charIndex + 0] = array[i].r;
		charArray[charIndex + 1] = array[i].g;
		charArray[charIndex + 2] = array[i].b;
		charArray[charIndex + 3] = array[i].a;
		charIndex += 4;
	}

	return charArray;
}
