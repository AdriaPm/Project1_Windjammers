#include "TurfLevel.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleEnemies.h"
#include "Left_Japanese_Player.h"
#include "Right_Japanese_Player.h"
#include "LeftGermanPlayer.h"
#include "RightGermanPlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFonts.h"

#include <stdio.h>

TurfLevel::TurfLevel(bool startEnabled) : Module(startEnabled)
{

	background.PushBack({ 0, 0, 304, 224 });
	background.PushBack({ 304, 0, 304, 224 });
	background.PushBack({ 608, 0, 304, 224 });
	background.PushBack({ 912, 0, 304, 224 });
	background.speed = 0.07f;
	background.loop = true;

	winR = {224, 86, 100, 32};
	winL = {324, 86, 112, 32};
	loseR = {393, 27, 99, 27};
	loseL = {0, 54, 100, 27};
	time = {175, 11, 15, 5 };
}

TurfLevel::~TurfLevel()
{

}

// Load assets
bool TurfLevel::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/Spriteswind/Sprites/TURF_SPRITES/TurfMap_spritesheet.png");
	uiSprites = App->textures->Load("Assets/Spriteswind/Sprites/UI/UISpriteSheetFinal.png");

	char lookupTable[] = { "0123456789" };
	counter = App->fonts->Load("Assets/Fonts/.png", lookupTable, 1);

	App->audio->PlayMusic("Assets/Music/turf.ogg", 1.0f);

	///TURF MAP Colliders
	//Upperside collider
	App->collisions->AddCollider({ 0, 0, 304, 40 }, Collider::Type::UPPER_WALL);
	//Bottomside collider
	App->collisions->AddCollider({ 0, 199, 304, 25 }, Collider::Type::LOWER_WALL);
	//Leftside 3points goal
	App->collisions->AddCollider({ 0, 17, 10, 88 }, Collider::Type::LEFT_3P_GOAL);
	App->collisions->AddCollider({ 0, 151, 10, 66 }, Collider::Type::LEFT_3P_GOAL);
	//Leftside 5points goal
	App->collisions->AddCollider({ 0, 105, 10, 46 }, Collider::Type::LEFT_5P_GOAL);
	//Rightside 3points goal
	App->collisions->AddCollider({ 295, 17, 10, 88 }, Collider::Type::RIGHT_3P_GOAL);
	App->collisions->AddCollider({ 295, 151, 10, 66 }, Collider::Type::RIGHT_3P_GOAL);
	//Rightside 5points goal
	App->collisions->AddCollider({ 295, 105, 10, 46 }, Collider::Type::RIGHT_5P_GOAL);
	//Center net
	App->collisions->AddCollider({ 151, 32, 3, 171 }, Collider::Type::NET);

	////First two columns colliders
	//App->collisions->AddCollider({ 1375, 0, 111, 96 }, Collider::Type::WALL);
	//App->collisions->AddCollider({ 1375, 145, 111, 96 }, Collider::Type::WALL);

	//// Enemies ---
	//App->enemies->AddEnemy(Enemy_Type::REDBIRD, 600, 80);
	//App->enemies->AddEnemy(Enemy_Type::REDBIRD, 625, 80);
	//App->enemies->AddEnemy(Enemy_Type::REDBIRD, 640, 80);
	//App->enemies->AddEnemy(Enemy_Type::REDBIRD, 665, 80);

	//App->enemies->AddEnemy(Enemy_Type::REDBIRD, 735, 120);
	//App->enemies->AddEnemy(Enemy_Type::REDBIRD, 750, 120);
	//App->enemies->AddEnemy(Enemy_Type::REDBIRD, 775, 120);
	//App->enemies->AddEnemy(Enemy_Type::REDBIRD, 790, 120);

	//App->enemies->AddEnemy(Enemy_Type::BROWNSHIP, 830, 100);
	//App->enemies->AddEnemy(Enemy_Type::BROWNSHIP, 850, 100);
	//App->enemies->AddEnemy(Enemy_Type::BROWNSHIP, 870, 100);
	//App->enemies->AddEnemy(Enemy_Type::BROWNSHIP, 890, 100);

	//App->enemies->AddEnemy(Enemy_Type::MECH, 900, 195);

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	switch (App->choice1)
	{
	case Player_Chosen_Left::German:
		App->leftgermanyplayer->Enable();
		break;
	case Player_Chosen_Left::Japanese:
		App->LeftJapanesePlayer->Enable();
		//App->LeftJapanesePlayer->hasDisc = true;
		break;
	/*case Player_Chosen_Left::Spanish:
		App->leftgermanyplayer->Enable();
		break;*/
	}


	switch (App->choice2)
	{
	case Player_Chosen_Right::German:
		App->rightgermanyplayer->Enable();
		break;
	case Player_Chosen_Right::Japanese:
		App->RightJapanesePlayer->Enable();
		break;
	/*case Player_Chosen_Right::Spanish:
		App->leftgermanyplayer->Enable();
		break;*/
	}

	App->enemies->Enable();

	//case Player_Chosen_Right::Spanish:
	//	/*	App->leftgermanyplayer->Enable();*/
	//	break;

	
	//App->leftgermanyplayer->Enable();
	//App->LeftJapanesePlayer->Enable();
	//App->rightgermanyplayer->Enable();
	//
	//App->rightgermanyplayer->Enable();

	return ret;
}

Update_Status TurfLevel::Update()
{
	background.Update();

	if (App->input->keys[SDL_SCANCODE_ESCAPE] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->dataEast, 90);
		App->LeftJapanesePlayer->scoreJapLeft = 0;
		App->RightJapanesePlayer->scoreJapRight = 0;
		App->leftgermanyplayer->scoreGerLeft = 0;
		App->rightgermanyplayer->scoreGerRight = 0;

		App->turflevel->Disable();
	}

	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status TurfLevel::PostUpdate()
{
	// Draw everything --------------------------------------
	// Animation of the public
	App->render->Blit(bgTexture, 0, 0, &(background.GetCurrentFrame()), 0.5f);
	App->render->Blit(uiSprites, 144, 13, &time);

	//sprintf_s(counterText, 2, "%d", counter);

	//App->fonts->BlitText(145, 21, counterFont, counterText);
	
	if (App->input->keys[SDL_SCANCODE_F3] == Key_State::KEY_DOWN)
	{
		App->LeftJapanesePlayer->scoreJapLeft = 1500;
		App->leftgermanyplayer->scoreGerLeft = 1500;

	}
	else if (App->input->keys[SDL_SCANCODE_F4] == Key_State::KEY_DOWN)
	{
		App->RightJapanesePlayer->scoreJapRight = 1500;
		App->rightgermanyplayer->scoreGerRight = 1500;
	}
	else if (App->RightJapanesePlayer->getJapScoreR() > App->LeftJapanesePlayer->getJapScoreL() && App->RightJapanesePlayer->getJapScoreR() > 1200)
	{
		App->render->Blit(uiSprites, 175, 54, &winR);
		App->render->Blit(uiSprites, 30, 54, &loseL);
		
	}
	else if (App->RightJapanesePlayer->getJapScoreR() < App->LeftJapanesePlayer->getJapScoreL() && App->LeftJapanesePlayer->getJapScoreL() > 1200)
	{
		App->render->Blit(uiSprites, 174, 54, &loseR);
		App->render->Blit(uiSprites, 18, 54, &winL);
	}
	else if (App->rightgermanyplayer->getGerScoreR() > App->leftgermanyplayer->getGerScoreL() && App->rightgermanyplayer->getGerScoreR() > 1200)
	{
		App->render->Blit(uiSprites, 175, 54, &winR);
		App->render->Blit(uiSprites, 30, 54, &loseL);
	}
	else if (App->rightgermanyplayer->getGerScoreR() < App->leftgermanyplayer->getGerScoreL() && App->leftgermanyplayer->getGerScoreL() > 1200)
	{
		App->render->Blit(uiSprites, 18, 54, &loseR);
		App->render->Blit(uiSprites, 174, 54, &winL);
	}

	return Update_Status::UPDATE_CONTINUE;
}

bool TurfLevel::CleanUp()
{
	switch (App->choice1)
	{
	case Player_Chosen_Left::German:
		App->leftgermanyplayer->Disable();
		break;
	case Player_Chosen_Left::Japanese:
		App->LeftJapanesePlayer->Disable();
		break;
	/*case Player_Chosen_Left::Spanish:
		App->leftgermanyplayer->Disable();
		break;*/
	}

	switch (App->choice2)
	{
	case Player_Chosen_Right::German:
		App->rightgermanyplayer->Disable();
		break;
	case Player_Chosen_Right::Japanese:
		App->RightJapanesePlayer->Disable();
		break;
	/*case Player_Chosen_Right::Spanish:
		App->leftgermanyplayer->Disable();
		break;*/
	}

	App->enemies->Disable();
	// TODO 5 (old): Remove All Memory Leaks - no solution here guys ;)

	return true;
}