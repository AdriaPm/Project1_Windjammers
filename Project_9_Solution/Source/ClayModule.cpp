#include "ClayModule.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleEnemies.h"
<<<<<<< Updated upstream
#include "Left_Japanese_Player.h"
#include "Char2.h"
=======
#include "ModulePlayer.h"
#include "LeftGermanPlayer.h"
>>>>>>> Stashed changes

ClayModule::ClayModule(bool startEnabled) : Module(startEnabled)
{

	background.PushBack({ 0, 0, 304, 224 });
	background.PushBack({ 304, 0, 304, 224 });
	background.PushBack({ 608, 0, 304, 224 });
	background.PushBack({ 912, 0, 304, 224 });
	background.speed = 0.05f;
	background.loop = true;

}

ClayModule::~ClayModule()
{

}

// Load assets
bool ClayModule::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/Spriteswind/Sprites/CLAY_SPRITES/ClayMap_spritesheet.png");

	App->audio->PlayMusic("Assets/Music/ClayCourt.ogg", 1.0f);

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

<<<<<<< Updated upstream
	App->LeftJapanesePlayer->Enable();
	App->char2->Enable();
=======
	App->player->Enable();
	App->leftgermanyplayer->Enable();
>>>>>>> Stashed changes
	App->enemies->Enable();

	return ret;
}

Update_Status ClayModule::Update()
{
	background.Update();

	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status ClayModule::PostUpdate()
{
	// Draw everything --------------------------------------
	// Animation of the public
	App->render->Blit(bgTexture, 0, 0, &(background.GetCurrentFrame()), 0.5f);


	return Update_Status::UPDATE_CONTINUE;
}

bool ClayModule::CleanUp()
{
<<<<<<< Updated upstream
	App->LeftJapanesePlayer->Disable();
	App->char2->Disable();
=======
	App->player->Disable();
	App->leftgermanyplayer->Disable();
>>>>>>> Stashed changes
	App->enemies->Disable();

	// TODO 5 (old): Remove All Memory Leaks - no solution here guys ;)

	return true;
}