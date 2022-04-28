#include "DataEast.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

DataEast::DataEast(bool startEnabled) : Module(startEnabled)
{
	DElogo.PushBack({ 0, 41, 99, 33 });
	DElogo.PushBack({ 108, 41, 141, 32 });
	DElogo.PushBack({ 251, 41, 250, 29});
	DElogo.PushBack({ 502, 38, 250, 31});
	DElogo.PushBack({ 753, 35, 250, 44 });
	DElogo.PushBack({ 1004, 32, 250, 50 });
	DElogo.PushBack({ 1254, 29, 250, 54 });
	DElogo.PushBack({ 1506, 28, 253, 61 });
	DElogo.PushBack({ 1757, 25, 250, 70 });
	DElogo.PushBack({ 2008, 22, 250, 71 });
	DElogo.PushBack({ 2259, 19, 253, 75 });
	DElogo.PushBack({ 2510, 17, 252, 78 });
	DElogo.PushBack({ 2716, 11, 252, 82 });
	DElogo.PushBack({ 3012, 15, 251, 86 });
	DElogo.PushBack({ 3268, 8, 252, 85 });
	DElogo.PushBack({ 3514, 6, 251, 88 });
	DElogo.PushBack({ 3765, 3, 252, 89 });
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
	DELogo = App->textures->Load("Assets/Spriteswind/Sprites/UI/Start2.png");
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