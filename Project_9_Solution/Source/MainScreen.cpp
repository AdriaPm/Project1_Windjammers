#include "MainScreen.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

MainScreen::MainScreen(bool startEnabled) : Module(startEnabled)
{
	
	//Purple letters anim
	Letters.PushBack({ 227, 103, 24, 37 });
	Letters.PushBack({ 251, 103, 24, 39 });
	Letters.PushBack({ 275, 103, 24, 36 });
	Letters.PushBack({ 299, 103, 24, 35 });
	Letters.PushBack({ 323, 103, 24, 36 });
	Letters.PushBack({ 347, 103, 23, 36 });
	Letters.PushBack({ 370, 103, 23, 35 });
	Letters.PushBack({ 393, 103, 23, 36 });
	Letters.speed = 0.1f;

	//main logo anim
	Logo.PushBack({ 227, 103, 24, 37 });
	Logo.PushBack({ 251, 103, 24, 39 });
	Logo.PushBack({ 275, 103, 24, 36 });
	Logo.PushBack({ 299, 103, 24, 35 });
	Logo.PushBack({ 323, 103, 24, 36 });
	Logo.PushBack({ 347, 103, 23, 36 });
	Logo.PushBack({ 370, 103, 23, 35 });
	Logo.PushBack({ 393, 103, 23, 36 });
	Logo.speed = 0.1f;
}

MainScreen::~MainScreen()
{

}

// Load assets
bool MainScreen::Start()
{
	LOG("Loading background assets");

	bool ret = true;
	bgTexture = App->textures->Load("Assets/Spriteswind/Sprites/UI/Dont Use/introbg.png");
	bgTexture = App->textures->Load("Assets/Spriteswind/Sprites/UI/Dont Use/Start1.png");
	
	App->audio->PlayMusic("Assets/Music/introTitle.ogg", 1.0f);

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

Update_Status MainScreen::Update()
{
	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->tutorialScene, 90);
	}

	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status MainScreen::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 0, NULL);

	return Update_Status::UPDATE_CONTINUE;
}