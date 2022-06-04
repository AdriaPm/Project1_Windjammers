#include "UI.h"


#include "SDL/include/SDL.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleFonts.h"
#include "ModuleInput.h"
#include "ModuleCollisions.h"

#include "stdio.h"

UI::UI(bool startEnabled) : Module(startEnabled)
{
	winR = { 224, 86, 100, 32 };
	winL = { 324, 86, 112, 32 };
	loseR = { 393, 27, 99, 27 };
	loseL = { 0, 54, 100, 27 };
	time = { 175, 11, 15, 5 };

	time_thirty.PushBack({ 192, 86, 32, 32 });
	time_thirty.PushBack({ 192, 86, 32, 32 });
	time_thirty.PushBack({ 192, 86, 32, 32 });
	time_thirty.loop = true;
	time_thirty.speed = 0.2f;

	time_fifteen.PushBack({ 376, 54, 32, 32 });
	time_fifteen.loop = true;
	time_fifteen.speed = 0.1f;

	time_ten.PushBack({ 344, 54, 32, 32 });
	time_ten.loop = true;
	time_ten.speed = 0.1f;
}

UI::~UI()
{

}

bool UI::Start()
{
	bool ret = true;

	t1 = SDL_GetTicks();

	currentAnimation = &time_thirty;

	leftScore = 0;
	rightScore = 0;

	uiSprites = App->textures->Load("Assets/Spriteswind/Sprites/UI/UISpriteSheetFinal.png");

	char lookupTable1[] = { "0123456789" };
	char lookupTable2[] = { "0123456789GO" };
	char lookupTable3[] = { "0123456789UP" };

	ScoreFont = App->fonts->Load("Assets/Fonts/Score.png", lookupTable1, 1);
	scoreCounterFont = App->fonts->Load("Assets/Fonts/Score_Counter.png", lookupTable2, 1);
	timeCounterFont = App->fonts->Load("Assets/Fonts/Time_Counter.png", lookupTable3, 1);
	
	return ret;
}

Update_Status UI::Update()
{
	if (timeCounter == 0)
	{
		t1 = SDL_GetTicks();
	}

	t2 = SDL_GetTicks();
	seconds = (t2 - t1) / 1000;
	timeCounter = 30-(int)seconds;

	if (App->input->keys[SDL_SCANCODE_F3] == Key_State::KEY_DOWN)
	{
		leftScore = 1500;
	}
	else if (App->input->keys[SDL_SCANCODE_F4] == Key_State::KEY_DOWN)
	{
		rightScore = 1500;
	}

	currentAnimation->Update();

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status UI::PostUpdate()
{
	// Draw UI 

	//Time
	App->render->Blit(uiSprites, 144, 13, &time);

	sprintf_s(timeCounterText, 10, "%d", timeCounter);
	App->fonts->BlitText(145, 21, timeCounterFont, timeCounterText);
	
	//Score
	sprintf_s(rightScoreText, 10, "%d", rightScore);
	App->fonts->BlitText(204, 8, ScoreFont, rightScoreText);//right

	sprintf_s(leftScoreText, 10, "%d", leftScore);
	App->fonts->BlitText(66, 8, ScoreFont, leftScoreText);//left
	
	//Counter Score
	sprintf_s(counterRightScoreText, 10, "%2d", counterRightScore);
	App->fonts->BlitText(162, 17, scoreCounterFont, counterRightScoreText);

	sprintf_s(counterLeftScoreText, 10, "%2d", counterLeftScore);
	App->fonts->BlitText(114, 17, scoreCounterFont, counterLeftScoreText);

	//Time Counter
	sprintf_s(timeCounterText, 10, "%2d", timeCounter);
	App->fonts->BlitText(145, 21, timeCounterFont, timeCounterText);

	SDL_Rect rect = currentAnimation->GetCurrentFrame();

	if (timeCounter == 0)
	{
		App->render->Blit(uiSprites, 136, 8, &rect);
	}
	else if (timeCounter == 15)
	{
		App->render->Blit(uiSprites, 136, 8, &rect);
	}
	else if (timeCounter == 20)
	{
		App->render->Blit(uiSprites, 136, 8, &rect);
	}

	//Win Lose
	if (timeCounter == 0)
	{
		if (getRightScore() > getLeftScore())
		{
			App->render->Blit(uiSprites, 175, 54, &winR);
			App->render->Blit(uiSprites, 30, 54, &loseL);
		}
		else if (getRightScore() < getLeftScore())
		{
			App->render->Blit(uiSprites, 174, 54, &loseR);
			App->render->Blit(uiSprites, 18, 54, &winL);
		}
	}

	if (getRightScore() > getLeftScore() && getRightScore() > 1200)
	{
		App->render->Blit(uiSprites, 175, 54, &winR);
		App->render->Blit(uiSprites, 30, 54, &loseL);

	}
	else if (getRightScore() < getLeftScore() && getLeftScore() > 1200)
	{
		App->render->Blit(uiSprites, 174, 54, &loseR);
		App->render->Blit(uiSprites, 18, 54, &winL);
	}

	return Update_Status::UPDATE_CONTINUE;
}
	

bool UI::CleanUp()
{
	return true;
}