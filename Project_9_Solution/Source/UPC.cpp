#include "UPC.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

UPC::UPC(bool startEnabled) : Module(startEnabled)
{
	
}

UPC::~UPC()
{

}

// Load assets
bool UPC::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/Spriteswind/Sprites/UI/InitialScreen.png");
	
<<<<<<< Updated upstream
=======
<<<<<<< HEAD

=======
>>>>>>> 2d28d57055bda7e666e33e499ab500fdee35e74e
>>>>>>> Stashed changes
	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

Update_Status UPC::Update()
{
	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->sceneIntro, 40);
	}

	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status UPC::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 0, NULL);

	return Update_Status::UPDATE_CONTINUE;
}