#include "ChooseMap.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

ChooseMap::ChooseMap(bool startEnabled) : Module(startEnabled)
{
	remark = {19, 33, 112, 14};
}

ChooseMap::~ChooseMap()
{

}

bool ChooseMap::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	MapType::Turf;

	chooseMapTexture = App->textures->Load("Assets/Spriteswind/Sprites/UI/ChooseMap.png");
	selectMap = App->textures->Load("Assets/Spriteswind/Sprites/UI/UISpriteSheetFinal.png");
	App->audio->PlayMusic("Assets/Music/introTitle.ogg", 1.0f);

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	App->chooseMap->Enable();

	return ret;
}

Update_Status ChooseMap::Update()
{
	if (App->input->keys[SDL_SCANCODE_DOWN] == Key_State::KEY_DOWN)
	{
		if (MapType::Turf)
		{
			MapType::Beach;
		}
		if (MapType::Beach)
		{
			MapType::Clay;
		}
	}
	if (App->input->keys[SDL_SCANCODE_UP] == Key_State::KEY_DOWN)
	{
		if (MapType::Beach)
		{
			MapType::Turf;
		}
		if (MapType::Clay)
		{
			MapType::Beach;
		}
	}

	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
	{
		if (MapType::Turf)
		{
			App->fade->FadeToBlack(this, (Module*)App->turflevel, 90);
		}
		if (MapType::Beach)
		{
			App->fade->FadeToBlack(this, (Module*)App->turflevel, 90);
		}
		if (MapType::Clay)
		{
			App->fade->FadeToBlack(this, (Module*)App->turflevel, 90);
		}
	}

	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status ChooseMap::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(chooseMapTexture, 0, 0, NULL);
	if (MapType::Turf)
	{
		App->render->Blit(selectMap, 168, 61, &remark);
	}
	else if (MapType::Beach)
	{
		App->render->Blit(selectMap, 168, 85, &remark);
	}
	else if (MapType::Clay)
	{
		App->render->Blit(selectMap, 167, 110, &remark);
	}
	
	return Update_Status::UPDATE_CONTINUE;
}