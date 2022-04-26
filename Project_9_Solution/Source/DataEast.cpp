#include "DataEast.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

DataEast::DataEast(bool startEnabled) : Module(startEnabled)
{

}

DataEast::~DataEast()
{

}

// Load assets
bool DataEast::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Game/Assets/Spriteswind/Sprites/UI/DataEastScreen.png");
	App->audio->PlayMusic("Assets/Music/introTitle.ogg", 1.0f);

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

Update_Status DataEast::Update()
{
	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->mainScreen, 90);
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