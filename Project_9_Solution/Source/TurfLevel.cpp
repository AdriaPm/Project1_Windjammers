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

TurfLevel::TurfLevel(bool startEnabled) : Module(startEnabled)
{

	background.PushBack({ 0, 0, 304, 224 });
	background.PushBack({ 304, 0, 304, 224 });
	background.PushBack({ 608, 0, 304, 224 });
	background.PushBack({ 912, 0, 304, 224 });
	background.speed = 0.05f;
	background.loop = true;


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
	
	App->audio->PlayMusic("Assets/Music/turf.ogg", 1.0f);

	///TURF MAP Colliders
	//Upperside collider
	App->collisions->AddCollider({ 0, 0, 304, 40 }, Collider::Type::UPPER_WALL);
	//Bottomside collider
	App->collisions->AddCollider({ 0, 199, 304, 25 }, Collider::Type::LOWER_WALL);
	//Leftside goal
	App->collisions->AddCollider({ 0, 17, 10, 200 }, Collider::Type::LEFT_GOAL);
	//Rightside goal
	App->collisions->AddCollider({ 295, 17, 9, 200 }, Collider::Type::RIGHT_GOAL);
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
		break;
	}
	//case Player_Chosen_Left::Spanish:
	///*	App->leftgermanyplayer->Enable();*/
	//	break;
	//

	switch (App->choice2)
	{
	case Player_Chosen_Right::German:
		App->rightgermanyplayer->Enable();
		break;
	case Player_Chosen_Right::Japanese:
		App->RightJapanesePlayer->Enable();
		break;
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

	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status TurfLevel::PostUpdate()
{
	// Draw everything --------------------------------------
	// Animation of the public
	App->render->Blit(bgTexture, 0, 0, &(background.GetCurrentFrame()), 0.5f);
	

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
	}
	//case Player_Chosen_Left::Spanish:
	///*	App->leftgermanyplayer->Enable();*/
	//	break;
	//

	switch (App->choice2)
	{
	case Player_Chosen_Right::German:
		App->rightgermanyplayer->Disable();
		break;
	case Player_Chosen_Right::Japanese:
		App->RightJapanesePlayer->Disable();
		break;
	}

	App->enemies->Disable();
	// TODO 5 (old): Remove All Memory Leaks - no solution here guys ;)

	return true;
}