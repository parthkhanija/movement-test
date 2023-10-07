#include "button.h"
#include "cprocessing.h"
#include <stdio.h>
#include <stdlib.h>

void createButton(char text[], float x, float y, float width, float height, float roundness, void (*f)(void), CP_Color colorDefault, CP_Color colorHover, CP_Color colorDown, CP_Color textColor, float textSize) {
	CP_Color buttonColor = colorDefault;

	//button collision
	if (CP_Input_GetMouseX() > x - width / 2.0f &&
		CP_Input_GetMouseX() < x + width / 2.0f &&
		CP_Input_GetMouseY() > y - height / 2.0f &&
		CP_Input_GetMouseY() < y + height / 2.0f)
	{
		buttonColor = colorHover;								   //color of button when hovering
		if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT)) {
			buttonColor = colorDown;							   //color of button when holding on the button
		}
		if (CP_Input_MouseReleased(MOUSE_BUTTON_LEFT)) {
			f();
		}
	}
	else {
		buttonColor = colorDefault;		  //normal color of button
	}

	//button visual
	CP_Settings_Fill(buttonColor);
	CP_Graphics_DrawRectAdvanced(x, y, width, height, 0, roundness);
	CP_Settings_Fill(textColor);
	CP_Settings_TextSize(textSize);

	char buffer[50] = { 0 };
	sprintf_s(buffer, _countof(buffer), "%s", text);

	CP_Font_DrawText(buffer, x, y);
}