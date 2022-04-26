#include "ChooseCharacter.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

ChooseCharacter::ChooseCharacter(bool startEnabled) : Module(startEnabled)
{

}

ChooseCharacter::~ChooseCharacter()
{

}

bool ChooseCharacter::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	//CharacterType::Turf;

	chooseCharacterTexture = App->textures->Load("Assets/Spriteswind/Sprites/UI/ChooseCharacter.png");
	selectCharacter = App->textures->Load("Assets/Spriteswind/Sprites/UI/UISpriteSheetFinal.png");
	App->audio->PlayMusic("Assets/Music/introTitle.ogg", 1.0f);

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

Update_Status ChooseCharacter::Update()
{
	if (App->input->keys[SDL_SCANCODE_DOWN] == Key_State::KEY_DOWN)
	{
	
	}
	if (App->input->keys[SDL_SCANCODE_UP] == Key_State::KEY_DOWN)
	{
	
	}
	if (App->input->keys[SDL_SCANCODE_RIGHT] == Key_State::KEY_DOWN)
	{

	}
	if (App->input->keys[SDL_SCANCODE_LEFT] == Key_State::KEY_DOWN)
	{

	}

	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
	{	
			App->fade->FadeToBlack(this, (Module*)App->chooseMap, 90);
	}

	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status ChooseCharacter::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(chooseCharacterTexture, 0, 0, NULL);

	return Update_Status::UPDATE_CONTINUE;
}