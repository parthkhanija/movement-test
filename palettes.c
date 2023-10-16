#include "palettes.h"
#include "cprocessing.h"

//typedef enum Color {
//	spaceCadet = color { 32, 30, 80, 255 },
//	MEDIUM,
//	HIGH
//}Color;

typedef struct Palette {
	CP_Color c[50];
}Palette;

CP_Color white() {
	return CP_Color_Create(255, 255, 255, 255);
}

CP_Color black() {
	return CP_Color_Create(0, 0, 0, 255);
}

void load_basic_palette(CP_Color *array) {
	array[0] = white();
	array[1] = black();
} 

void load_grayscale_palette(CP_Color *array) {
	array[0] = CP_Color_Create(248, 249, 250 , 255);
	array[1] = CP_Color_Create(233, 236, 240, 255);
	array[2] = CP_Color_Create(210, 213, 217, 255);
	array[3] = CP_Color_Create(192, 198, 204, 255);
	array[4] = CP_Color_Create(166, 172, 179, 255);
	array[5] = CP_Color_Create(148, 154, 161, 255);
	array[6] = CP_Color_Create(108, 117, 125, 255);
	array[7] = CP_Color_Create(73, 80, 87, 255);
	array[8] = CP_Color_Create(57, 63, 69, 255);
	array[9] = CP_Color_Create(24, 28, 31, 255);
}

void load_greens_palette(CP_Color* array) {
	array[0] = CP_Color_Create(202, 210, 197, 255);
	array[1] = CP_Color_Create(132, 169, 140, 255);
	array[2] = CP_Color_Create(82, 121, 111, 255);
	array[3] = CP_Color_Create(53, 79, 82, 255);
	array[4] = CP_Color_Create(47, 62, 70, 255);
}

void load_yellows_palette(CP_Color* array) {
	array[0] = CP_Color_Create(255, 227, 71, 255);
	array[1] = CP_Color_Create(251, 172, 36, 255);
	array[2] = CP_Color_Create(248, 121, 0, 255);
	array[3] = CP_Color_Create(227, 199, 123, 255);
	array[4] = CP_Color_Create(154, 3, 30, 255);
}

void load_blues_palette(CP_Color* array) {
	array[0] = CP_Color_Create(158, 179, 194, 255);
	array[1] = CP_Color_Create(28, 114, 147, 255);
	array[2] = CP_Color_Create(6, 90, 130, 255);
	array[3] = CP_Color_Create(27, 59, 111, 255);
	array[4] = CP_Color_Create(33, 41, 92, 255);
}

void load_purple_palette(CP_Color* array) {
	array[0] = CP_Color_Create(150, 161, 200, 255);
	array[1] = CP_Color_Create(130, 89, 183, 255);
	array[2] = CP_Color_Create(71, 53, 135, 255);
	array[3] = CP_Color_Create(32, 30, 80, 255);
	array[4] = CP_Color_Create(102, 0, 0, 255);
}
