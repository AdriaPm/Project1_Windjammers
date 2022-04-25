#include "ChooseMap.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

ChooseMap::ChooseMap(bool startEnabled) : Module(startEnabled)
{

}

ChooseMap::~ChooseMap()
{

}

bool ChooseMap::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	chooseMapTexture = App->textures->Load("Assets/Sprites/ChooseMap.png");
	App->audio->PlayMusic("Assets/Music/introTitle.ogg", 1.0f);

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

Update_Status ChooseMap::Update()
{
	if (App->input->keys[SDL_SCANCODE_DOWN] == Key_State::KEY_DOWN)
	{

	}

	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->turflevel, 90);
	}

	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status ChooseMap::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(chooseMapTexture, 0, 0, NULL);

	return Update_Status::UPDATE_CONTINUE;
}