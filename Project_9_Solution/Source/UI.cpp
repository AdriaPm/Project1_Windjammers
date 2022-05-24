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

	leftScore = 0;
	rightScore = 0;

	uiSprites = App->textures->Load("Assets/Spriteswind/Sprites/UI/UISpriteSheetFinal.png");

	char lookupTable1[] = { "0123456789" };
	char lookupTable2[] = { "0123456789GO" };

	ScoreFont = App->fonts->Load("Assets/Fonts/Score.png", lookupTable1, 1);
	scoreCounterFont = App->fonts->Load("Assets/Fonts/Score_Counter.png", lookupTable2, 1);
	
	return ret;
}

Update_Status UI::Update()
{
	if (App->input->keys[SDL_SCANCODE_F3] == Key_State::KEY_DOWN)
	{
		leftScore = 1500;
	}
	else if (App->input->keys[SDL_SCANCODE_F4] == Key_State::KEY_DOWN)
	{
		rightScore = 1500;
	}

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status UI::PostUpdate()
{
	// Draw UI 

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

	App->render->Blit(uiSprites, 144, 13, &time);

	return Update_Status::UPDATE_CONTINUE;
}

//void UI::OnCollision(Collider* c1, Collider* c2)
//{
//	if (godMode == false) 
//	{
//		if (c1->type == Collider::Type::DISK && c2->type == Collider::Type::RIGHT_3P_GOAL)
//		{
//			//App->ui->leftScore += 300;
//			counterLeftScore += 3;
//		}
//		else if (c1->type == Collider::Type::DISK && c2->type == Collider::Type::RIGHT_5P_GOAL)
//		{
//			//App->ui->leftScore += 500;
//			counterLeftScore += 5;
//		}
//		else if (c1->type == Collider::Type::DISK && c2->type == Collider::Type::LEFT_3P_GOAL)
//		{
//			//App->ui->leftScore += 300;
//			counterRightScore += 3;
//		}
//		else if (c1->type == Collider::Type::DISK && c2->type == Collider::Type::LEFT_5P_GOAL)
//		{
//			//App->ui->leftScore += 500;
//			counterRightScore += 5;
//		}
//	}
//}

bool UI::CleanUp()
{
	return true;
}