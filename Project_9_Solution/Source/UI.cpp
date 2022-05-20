#include "UI.h"

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
}

UI::~UI()
{

}

bool UI::Start()
{
	bool ret = true;

	uiSprites = App->textures->Load("Assets/Spriteswind/Sprites/UI/UISpriteSheetFinal.png");

	char lookupTable[] = { "0123456789" };
	scoreFont = App->fonts->Load("Assets/Fonts/Score.png", lookupTable, 1);
	
	return ret;
}

Update_Status UI::Update()
{
	return Update_Status::UPDATE_CONTINUE;
}

Update_Status UI::PostUpdate()
{
	// Draw UI (score) --------------------------------------
	sprintf_s(rightScoreText, 10, "%d", rightScore);

	App->fonts->BlitText(204, 8, scoreFont, rightScoreText);//right


	sprintf_s(leftScoreText, 10, "%d", leftScore);

	App->fonts->BlitText(66, 8, scoreFont, leftScoreText);//left

	if (App->input->keys[SDL_SCANCODE_F3] == Key_State::KEY_DOWN)
	{
		leftScore = 1500;
	}
	else if (App->input->keys[SDL_SCANCODE_F4] == Key_State::KEY_DOWN)
	{
		rightScore = 1500;
	}
	else if (getRightScore() > getLeftScore() && getRightScore() > 1200)
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