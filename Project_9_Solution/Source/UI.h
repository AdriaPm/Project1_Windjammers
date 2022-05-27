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
	int getCounterLeftScore() { return leftScore; }
	int getCounterRightScore() { return rightScore; }
	float getSeconds() { return seconds; }

	//God Mode
	bool godMode = false;

	SDL_Texture* uiSprites = nullptr;

	Animation* currentAnimation = nullptr;

	SDL_Rect winL;
	SDL_Rect winR;
	SDL_Rect loseL;
	SDL_Rect loseR;
	SDL_Rect time;

	Animation time_thirty;
	Animation time_fifteen;
	Animation time_ten;

	//score
	uint rightScore = 000;
	char rightScoreText[10] = { "\0" };
	uint leftScore = 000;
	char leftScoreText[10] = { "\0" };
	int ScoreFont = -1;

	//time
	uint timeCounter = 000;
	int timeCounterFont = -1;
	char timeCounterText[10] = { "\0" };
	int timeControl;

	//counter score
	uint counterRightScore = 000;
	char counterRightScoreText[10] = { "\0" };
	uint counterLeftScore = 000;
	char counterLeftScoreText[10] = { "\0" };
	int scoreCounterFont = -1;

	int t1, t2;
	float seconds;

};

#endif