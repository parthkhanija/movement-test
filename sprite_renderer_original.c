#include "sprite_renderer.h"
#include "cprocessing.h"
#include <stdlib.h>
#include <stdio.h>

//get pixel data of the whole sprite sheet
//create image from data of wanted sprite
//organize accordingly

/*
CP_Image CP_Image_CreateFromData(int w, int h, unsigned char* pixelDataInput);

w (int) - The width you want the created image to be (must correspond to the size of the data given).
h (int) - The height you want the created image to be (must correspond to the size of the data given).
pixelDataInput (unsigned char*) - The data to use to create the new image.
*/
CP_Image* sprite_splice(CP_Image sheet, int sheet_col_amount, int amount, int row) {

	//array of images to return
	CP_Image* imageArray = malloc(sizeof(CP_Image) * amount);

	//** taken from CProcessing Example
	// Create the array using the image size and the size of a CP_Color
	CP_Color* colorArray_sheet = malloc((CP_Image_GetWidth(sheet) * CP_Image_GetHeight(sheet)) * sizeof(CP_Color));

	// Get the array of pixel colors from the image
	CP_Image_GetPixelData(sheet, colorArray_sheet);
	//** end of code taken from example

	int spriteSize = CP_Image_GetWidth(sheet) / sheet_col_amount;

	int* pixelNumArray = malloc(sizeof(int) * (spriteSize*spriteSize));

	////to find the amount of pixels in each sprite
	//int sheetWidth = CP_Image_GetWidth(sheet);
	//int spriteSize = CP_Image_GetWidth(sheet) / sheet_col_amount;

	//int spriteNum = 0;

	////array holds all indexes of the sprite returned (will be proccessed as one image, an array element in the image array returrned)
	//int* pixelNumArray = malloc(sizeof(int) * (spriteSize * spriteSize));

	////returns all indexes of pixels at sprite at row, and spriteNum, ex: row 0, sprite 0 is first top left sprite
	//int count = 0;
	//for (int i = 0; i < spriteSize; i++) {
	//	int topleft = sheetWidth * (row * spriteSize) + spriteNum * spriteSize;
	//	for (int j = 0; j < spriteSize; j++) {
	//		pixelNumArray[count] = sheetWidth * i + topleft + j;
	//		count += 1;
	//	}
	//}

	CP_Color* colorArray_sprite = malloc(sizeof(CP_Color) * (spriteSize * spriteSize));

	for (int i = 0; i < amount; i++) {
		pixelNumArray = returnSpritePixelNum(sheet, sheet_col_amount, row, i);
		for (int j = 0; j < (spriteSize * spriteSize); j++) {
			colorArray_sprite[j] = colorArray_sheet[pixelNumArray[j]]; 
		}
		imageArray[i] = CP_Image_CreateFromData(spriteSize, spriteSize, returnCharArray(colorArray_sprite));
	}
	

	/*
	* for i in amount 
	* run method
	* get array of pixel indices
	* run return charArray method
	* for i in amount
	* set imageArray[i] to create image from data (w=spritesize, h=spritesize, returnChararray)
	* 
	* alternatively
	* for i in amount
	* ruun method to get array of i^th sprite (pixel numbers)
	* create cpcolor array with same size as int array
	* for i in colorarraysize set colorarray[i] = colorArray_sheet(intarray[i])
	* set imageArray[i] to create image from data (w=spritesize, h=spritesize, returnChararray(colorarray of pixel))
	
	*/


	return imageArray;
}

int* returnSpritePixelNum(CP_Image sheet, int sheet_col_amount, int row, int spriteNum) {
	//to find the amount of pixels in each sprite
	int sheetWidth = CP_Image_GetWidth(sheet);
	int spriteSize = CP_Image_GetWidth(sheet) / sheet_col_amount;

	//array holds all indexes of the sprite returned (will be proccessed as one image, an array element in the image array returrned)
	int* pixelNumArray = malloc(sizeof(int) * (spriteSize * spriteSize));

	//returns all indexes of pixels at sprite at row, and spriteNum, ex: row 0, sprite 0 is first top left sprite
	int count = 0;
	for (int i = 0; i < spriteSize; i++) {
		int topleft = sheetWidth * (row * spriteSize) + spriteNum * spriteSize;
		for (int j = 0; j < spriteSize; j++) {
			pixelNumArray[count] = sheetWidth * i + topleft + j;
			count += 1;
		}
	}

	return pixelNumArray;
}

unsigned char* returnCharArray(CP_Color* array) {
	int arrayLength = (sizeof(array) / sizeof(CP_Color));
	unsigned char* charArray = malloc((sizeof(int) * 4) * arrayLength );

	int charIndex = 0;
	for (int i = 0; i < arrayLength; i++) {
		charArray[charIndex] = array[i].r;
		charArray[charIndex + 1] = array[i].g;
		charArray[charIndex + 2] = array[i].b;
		charArray[charIndex + 3] = array[i].a;
		charIndex += 4;
	}

	return charArray;

}
