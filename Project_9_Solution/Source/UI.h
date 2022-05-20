#ifndef __UI_H__
#define __UI_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class UI : public Module
{
public:

	UI(bool startEnabled);

	~UI();


	bool Start() override;

	Update_Status Update() override;

	Update_Status PostUpdate() override;

	bool CleanUp();


	int getLeftScore() { return leftScore; }
	int getRightScore() { return rightScore; }


	SDL_Texture* uiSprites = nullptr;

	SDL_Rect winL;
	SDL_Rect winR;
	SDL_Rect loseL;
	SDL_Rect loseR;
	SDL_Rect time;


	uint rightScore = 000;
	char rightScoreText[10] = { "\0" };
	int rightScoreFont = -1;

	uint leftScore = 000;
	char leftScoreText[10] = { "\0" };
	int leftScoreFont = -1;

	uint counter = 000;
	int counterFont = -1;
	char counterText[10] = { "\0" };

};

#endif