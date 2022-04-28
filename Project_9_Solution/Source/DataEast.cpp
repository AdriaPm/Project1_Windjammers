#include "DataEast.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

DataEast::DataEast(bool startEnabled) : Module(startEnabled)
{
	DElogo.PushBack({ 227, 103, 99, 33 });
	DElogo.PushBack({ 251, 103, 141, 32 });
	DElogo.PushBack({ 275, 103, 250, 29});
	DElogo.PushBack({ 299, 103, 250, 31});
	DElogo.PushBack({ 323, 103, 250, 44 });
	DElogo.PushBack({ 347, 103, 250, 50 });
	DElogo.PushBack({ 370, 103, 250, 54 });
	DElogo.PushBack({ 393, 103, 253, 61 });
	DElogo.PushBack({ 227, 103, 250, 70 });
	DElogo.PushBack({ 251, 103, 250, 71 });
	DElogo.PushBack({ 275, 103, 253, 75 });
	DElogo.PushBack({ 299, 103, 252, 78 });
	DElogo.PushBack({ 323, 103, 252, 82 });
	DElogo.PushBack({ 347, 103, 251, 86 });
	DElogo.PushBack({ 370, 103, 252, 85 });
	DElogo.PushBack({ 393, 103, 251, 88 });
	DElogo.PushBack({ 393, 103, 252, 89 });
	DElogo.speed = 0.1f;
}

DataEast::~DataEast()
{

}

// Load assets
bool DataEast::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/Spriteswind/Sprites/UI/DataEastScreendef.png");
	bgTexture = App->textures->Load("Assets/Spriteswind/Sprites/UI/Start2.png");
	App->audio->PlayMusic("Assets/Music/introTitle.ogg", 1.0f);

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

Update_Status DataEast::Update()
{
	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->mainScreen, 40);
	}

	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status DataEast::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 0, NULL);

	return Update_Status::UPDATE_CONTINUE;
}