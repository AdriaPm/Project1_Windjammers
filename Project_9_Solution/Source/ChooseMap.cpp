#include "ChooseMap.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

ChooseMap::ChooseMap(bool startEnabled) : Module(startEnabled)
{
	//remark.PushBack({19, 33, 112, 14});
	//remark.speed = 0.1f;
	remark = { 15, 27, 120, 24 };
}

ChooseMap::~ChooseMap()
{

}

bool ChooseMap::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	MapType::Turf;
	yMove = 55;
	x1 = 24;
	x2 = -200;
	x3 = -200;

	chooseMapTexture = App->textures->Load("Assets/Spriteswind/Sprites/UI/ChooseMap.png");
	selectMap = App->textures->Load("Assets/Spriteswind/Sprites/UI/UISpriteSheetFinal.png");
	mapNames = App->textures->Load("Assets/Spriteswind/Sprites/UI/ChooseMap_Names.png");
	turfImg = App->textures->Load("Assets/Spriteswind/Sprites/UI/Lawn.png");
	beachImg = App->textures->Load("Assets/Spriteswind/Sprites/UI/Beach.png");
	clayImg = App->textures->Load("Assets/Spriteswind/Sprites/UI/Clay.png");

	App->audio->PlayMusic("Assets/Music/001 Windjammers _ Flying Power Disc (wjammers) [#002] Get Ready! (Select).ogg", 1.0f);

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	App->chooseMap->Enable();

	return ret;
}

Update_Status ChooseMap::Update()
{

	if (App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_DOWN)
	{
		if (yMove == 55)
		{
			MapType::Beach;
			yMove = 79;
			x1 = -200;
			x2 = 24;
		}
		else if (yMove == 79)
		{
			MapType::Clay;
			yMove = 104;
			x2 = -200;
			x3 = 24;
		}
		
	}
	if (App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_DOWN)
	{
		if (yMove == 79)
		{
			MapType::Turf;
			yMove = 55;
			x2 = -200;
			x1 = 24;
		}
		else if (yMove == 104)
		{
			MapType::Beach;
			yMove = 79;
			x3 = -200;
			x2 = 24;
		}
	}

	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
	{
		if (MapType::Turf)
		{
			App->fade->FadeToBlack(this, (Module*)App->turflevel, 40);
		}
		else if (MapType::Beach)
		{
			App->fade->FadeToBlack(this, (Module*)App->turflevel, 90);
		}
		else if (MapType::Clay)
		{
			App->fade->FadeToBlack(this, (Module*)App->clay, 90);
		}
	}

	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status ChooseMap::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(chooseMapTexture, 0, 0, NULL);
	App->render->Blit(selectMap, 164, yMove, &remark);
	App->render->Blit(mapNames, 6, 1, NULL);

	App->render->Blit(turfImg, x1, 84, NULL);
	App->render->Blit(beachImg, x2, 84, NULL);
	App->render->Blit(clayImg, x3, 84, NULL);
	
	return Update_Status::UPDATE_CONTINUE;
}