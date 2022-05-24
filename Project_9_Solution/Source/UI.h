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


	void OnCollision(Collider* c1, Collider* c2) override;


	int getLeftScore() { return leftScore; }
	int getRightScore() { return rightScore; }

	//God Mode
	bool godMode = false;

	SDL_Texture* uiSprites = nullptr;

	SDL_Rect winL;
	SDL_Rect winR;
	SDL_Rect loseL;
	SDL_Rect loseR;
	SDL_Rect time;

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

	//counter score
	uint counterRightScore = 000;
	char counterRightScoreText[10] = { "\0" };
	uint counterLeftScore = 000;
	char counterLeftScoreText[10] = { "\0" };
	int scoreCounterFont = -1;
};

#endif