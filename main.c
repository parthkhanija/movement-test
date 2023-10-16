//---------------------------------------------------------
// file:	main.c
// author:	Parth Khanija
// email:	parth.khanija@digipen.com
//
// brief:	Main entry point for the sample project
//			of the CProcessing library
//
// documentation link:
// https://github.com/DigiPen-Faculty/CProcessing/wiki
//
// Copyright © 2020 DigiPen, All rights reserved.
//---------------------------------------------------------

#include "cprocessing.h"
#include "button.h"
#include "palettes.h"
#include "sprite_renderer_voids.h"
#include <stdlib.h>
#include <stdio.h>

CP_Color backgroundColor;

float posX;
float posY;
CP_Vector pos;
CP_Vector velocity = { 0,0 };
CP_Color palette[50];
float speed;

CP_Image spriteSheet;
CP_Image test2x2;

CP_Color* pixelData;

CP_Image* spriteTest;

int keyPressed;

// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program
void game_init(void)
{
	// initialize variables and CProcessing settings for this gamestate
	CP_System_SetWindowSize(900, 600);
	CP_Settings_RectMode(CP_POSITION_CENTER);
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);

	pos.x = CP_System_GetWindowWidth() / 2.0f;
	pos.y = CP_System_GetWindowHeight() / 2.0f;
	speed = 300.0f;

	backgroundColor = CP_Color_Create(190,190,190,255);

	load_grayscale_palette(palette);

	spriteSheet = CP_Image_Load("./Assets/monkey_sprites_transparent_scaled.png");
	test2x2 = CP_Image_Load("./Assets/test2x2.png");

	pixelData = malloc(CP_Image_GetWidth(test2x2) * CP_Image_GetHeight(test2x2) * sizeof(CP_Color));

	//CP_Color pixelData[4];
	CP_Image_GetPixelData(test2x2, pixelData);

	spriteTest = malloc(sizeof(CP_Image) + 4);
	sprite_splice(spriteTest, spriteSheet, 8, 4, 0);
}


void game_update(void)
{
	CP_Graphics_ClearBackground(palette[4]);

	CP_Settings_Fill(CP_Color_Create(60, 60, 60, 255));
	CP_Settings_NoStroke();

	//player movement
	/*pos.x = pos.x + velocity.x * CP_System_GetDt();
	pos.y = pos.y + velocity.y * CP_System_GetDt();

	if (CP_Input_KeyDown(KEY_W) ||
		CP_Input_KeyDown(KEY_A) ||
		CP_Input_KeyDown(KEY_S) ||
		CP_Input_KeyDown(KEY_D)) {
		keyPressed = 1;
	}
	else {
		keyPressed = 0;
	}

	velocity.x = 0.0f;
	velocity.y = 0.0f;

	if (keyPressed) {
		if (CP_Input_KeyDown(KEY_D)) {
			velocity.x = speed;
		}
		if (CP_Input_KeyDown(KEY_A)) {
			velocity.x = -speed;
		}
		if (CP_Input_KeyDown(KEY_W)) {
			velocity.y = -speed;
		}
		if (CP_Input_KeyDown(KEY_S)) {
			velocity.y = speed;
		}
	}
	else {
		velocity.x = 0;
		velocity.y = 0;
	}

	CP_Graphics_DrawRect(pos.x, pos.y, 90.0f, 100.0f);*/
	//player movement


	//peleg movement method
	CP_Vector input = CP_Vector_Set(speed*((float)CP_Input_KeyDown(KEY_D) - (float)CP_Input_KeyDown(KEY_A)),speed*((float)CP_Input_KeyDown(KEY_S) - (float)CP_Input_KeyDown(KEY_W)));
	//pos = CP_Vector_Add(pos, input);
	velocity = input;
	velocity = CP_Vector_Add(CP_Vector_Scale(velocity, 0.9999f), CP_Vector_Scale(input, 0.0001f));
	pos.x += velocity.x * CP_System_GetDt();
	pos.y += velocity.y * CP_System_GetDt();
	CP_Graphics_DrawRect(pos.x, pos.y, 90.0f, 100.0f);
	//end of peleg method

	CP_Color colorButton = CP_Color_Create(150, 150, 150, 255);
	CP_Color colorHover = CP_Color_Create(120, 120, 120, 255);
	CP_Color colorDown = CP_Color_Create(90, 90, 90, 255);

	createButton("Test", 90.0f, 50.0f, 90.0f, 60.0f, 20.0f, CP_Engine_Terminate, colorButton, colorHover, colorDown, CP_Color_Create(255,255,255,255), 30.0f);





	//CP_Color pixelData[] = malloc(CP_Image_GetWidth(test2x2) * CP_Image_GetHeight(test2x2) * sizeof(CP_Color));

	////CP_Color pixelData[4];
	//CP_Image_GetPixelData(test2x2, pixelData);


	CP_Settings_Fill(CP_Color_Create(255,255,255,255));
	CP_Settings_TextSize(50.0f);
	char buffer[50] = { 0 };
	sprintf_s(buffer, _countof(buffer), "%d %d %d, %d %d %d", pixelData[0].r, pixelData[0].g, pixelData[0].b, pixelData[1].r, pixelData[1].g, pixelData[1].b);
	CP_Font_DrawText(buffer, 500, 300);





	//CP_Image_Draw(spriteSheet, pos.x, pos.y, 300.0f, 300.0f, 255);

	/*CP_Image* spriteTest = malloc(sizeof(CP_Image) * 5);
	spriteTest = sprite_splice(spriteSheet, 8, 4, 0);*/
	//CP_Image_DrawSubImage(spriteSheet, pos.x, pos.y, 100.0, 100.0f, 0.0f, 0.0f, 16.0f, 16.0f, 255);

	//unsigned char pixelData[] = {
	//	255, 0, 0, 255, 255, 0, 0, 255, // 2 red pixels
	//	0, 0, 255, 255, 0, 0, 255, 255    // 2 blue pixels
	//};

	//CP_Image_Draw(
	//	CP_Image_CreateFromData(2,2,pixelData), pos.x, pos.y, 100.0f, 100.0f, 255);
	
	CP_Image_Draw(spriteTest[3], pos.x, pos.y, 120.0f, 120.0f, 255);


}


void game_exit(void)
{
	CP_Image_Free(&spriteSheet);
	CP_Image_Free(&test2x2);
	spriteSpliceFree(spriteTest, 4);
}

int main(void)
{
	CP_Engine_SetNextGameState(game_init, game_update, game_exit);
	CP_Engine_Run();
	return 0;
}
