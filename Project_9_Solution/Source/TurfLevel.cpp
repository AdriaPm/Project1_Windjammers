#include "TurfLevel.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "Char2.h"

TurfLevel::TurfLevel(bool startEnabled) : Module(startEnabled)
{

}

TurfLevel::~TurfLevel()
{

}

// Load assets
bool TurfLevel::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/Spriteswind/Sprites/TURF_SPRITES/BACKGROUND_ANIMATION/sprite_public1_lawnMap.png");
	bgTexture2 = App->textures->Load("Assets/Spriteswind/Sprites/TURF_SPRITES/BACKGROUND_ANIMATION/sprite_public2_lawnMap.png");
	bgTexture3= App->textures->Load("Assets/Spriteswind/Sprites/TURF_SPRITES/BACKGROUND_ANIMATION/sprite_public3_lawnMap.png");
	bgTexture4= App->textures->Load("Assets/Spriteswind/Sprites/TURF_SPRITES/BACKGROUND_ANIMATION/sprite_public4_lawnMap.png");

	App->audio->PlayMusic("Assets/Music/turf.ogg", 1.0f);

	///TURF MAP Colliders
	//Upperside collider
	App->collisions->AddCollider({ 0, 0, 304, 40 }, Collider::Type::WALL);
	//Bottomside collider
	App->collisions->AddCollider({ 0, 199, 304, 25 }, Collider::Type::WALL);
	//Leftside goal
	App->collisions->AddCollider({ 0, 17, 10, 200 }, Collider::Type::GOAL);
	//Rightside goal
	App->collisions->AddCollider({ 295, 17, 9, 200 }, Collider::Type::GOAL);
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

	App->player->Enable();
	App->char2->Enable();
	App->enemies->Enable();

	return ret;
}

Update_Status TurfLevel::Update()
{

	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status TurfLevel::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 0, NULL);
	App->render->Blit(bgTexture2, 0, 0, NULL);
	App->render->Blit(bgTexture3, 0, 0, NULL);
	App->render->Blit(bgTexture4, 0, 0, NULL);

	return Update_Status::UPDATE_CONTINUE;
}

bool TurfLevel::CleanUp()
{
	App->player->Disable();
	App->char2->Disable();
	App->enemies->Disable();

	// TODO 5 (old): Remove All Memory Leaks - no solution here guys ;)

	return true;
}