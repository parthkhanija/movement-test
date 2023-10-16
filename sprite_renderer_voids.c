#include "sprite_renderer_voids.h"
#include "cprocessing.h"
#include <stdlib.h>
#include <stdio.h>

void sprite_splice(CP_Image* imageArray ,CP_Image sheet, int sheet_col_amount, int amount, int row) {
	//** taken from CProcessing Example
	// Create the array using the image size and the size of a CP_Color
	CP_Color* colorArray_sheet = malloc((CP_Image_GetWidth(sheet) * CP_Image_GetHeight(sheet)) * sizeof(CP_Color));

	// Get the array of pixel colors from the image
	CP_Image_GetPixelData(sheet, colorArray_sheet);
	//** end of code taken from example

	int spriteSize = CP_Image_GetWidth(sheet) / sheet_col_amount;

	int* pixelNumArray = malloc(sizeof(int) * (spriteSize*spriteSize));

	CP_Color* colorArray_sprite = malloc(sizeof(CP_Color) * (spriteSize * spriteSize));
	unsigned char* charArray = malloc((sizeof(int) * 4) * (spriteSize * spriteSize));

	if (colorArray_sprite == NULL) { }; //kill the running executable throwing a return error.
	if (pixelNumArray == NULL) { }; //kill the running executable throwing a return error.

	int pixelIndex;
	for (int i = 0; i < amount; i++) {
		load_pixels_in_sprite_array(pixelNumArray, sheet, sheet_col_amount, row, i);
		for (int j = 0; j < (spriteSize * spriteSize); j++) {
			
			//assigns pixel index that will be passed into 
			pixelIndex = pixelNumArray[j];
			colorArray_sprite[j] = colorArray_sheet[pixelIndex]; 
			
		}
		loadCharArray(charArray, colorArray_sprite, (spriteSize*spriteSize));
		imageArray[i] = CP_Image_CreateFromData(spriteSize, spriteSize, charArray);
	}

	free(colorArray_sheet);
	free(pixelNumArray);
	free(colorArray_sprite);
	free(charArray);
}

//loads array that holds all indexes of the sprite returned (will be proccessed as one image, an array element in the image array returrned)
void load_pixels_in_sprite_array(int* pixelNumArray, CP_Image sheet, int sheet_col_amount, int row, int spriteNum) {

	//to find the amount of pixels in each sprite
	int sheetWidth = CP_Image_GetWidth(sheet);
	int spriteSize = CP_Image_GetWidth(sheet) / sheet_col_amount;

	//returns all indexes of pixels at sprite at row, and spriteNum, ex: row 0, sprite 0 is first top left sprite
	int count = 0;
	for (int i = 0; i < spriteSize; i++) {
		int topleft = sheetWidth * (row * spriteSize) + spriteNum * spriteSize;
		for (int j = 0; j < spriteSize; j++) {
			pixelNumArray[count] = sheetWidth * i + topleft + j;
			count += 1;
		}
	}
}

void loadCharArray(unsigned char* charArray, CP_Color* array, int c_arrayLength) {
	int charIndex = 0;
	for (int i = 0; i < c_arrayLength; i++) {
		charArray[charIndex] = array[i].r;
		charArray[charIndex + 1] = array[i].g;
		charArray[charIndex + 2] = array[i].b;
		charArray[charIndex + 3] = array[i].a;
		charIndex += 4;
	}
}

//function to free sprite splices
void spriteSpliceFree(CP_Image* splice, int arrayLength) {
	for (int i = 0; i < arrayLength; i++) {
		CP_Image_Free(&splice[i]);
	}
}

//function to animate sprite splice
