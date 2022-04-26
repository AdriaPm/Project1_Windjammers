#include "ClayModule.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "Char2.h"

ClayModule::ClayModule(bool startEnabled) : Module(startEnabled)
{

	background2.PushBack({ 0, 0, 304, 224 });
	background2.PushBack({ 304, 0, 304, 224 });
	background2.PushBack({ 608, 0, 304, 224 });
	background2.PushBack({ 912, 0, 304, 224 });
	background2.speed = 0.05f;
	background2.loop = true;


}

ClayModule::~ClayModule()
{

}

// Load assets
bool ClayModule::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/Spriteswind/Sprites/CLAY_SPRITEAS/ClaySpriteSheet.png");

	App->audio->PlayMusic("Assets/Music/ClayCourt.ogg", 1.0f);

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

Update_Status ClayModule::Update()
{
	background2.Update();

	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status ClayModule::PostUpdate()
{
	// Draw everything --------------------------------------
	// Animation of the public
	App->render->Blit(bgTexture, 0, 0, &(background2.GetCurrentFrame()), 0.5f);


	return Update_Status::UPDATE_CONTINUE;
}

bool ClayModule::CleanUp()
{
	App->player->Disable();
	App->char2->Disable();
	App->enemies->Disable();

	// TODO 5 (old): Remove All Memory Leaks - no solution here guys ;)

	return true;
}