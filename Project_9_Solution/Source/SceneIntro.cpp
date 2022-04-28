#include "SceneIntro.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

SceneIntro::SceneIntro(bool startEnabled) : Module(startEnabled)
{
	
	//Neo Geo Logo
	NeoGeo.PushBack({ 102, 126, 50, 40 });
	NeoGeo.PushBack({ 323, 360, 48, 40 });
	NeoGeo.PushBack({ 543, 595, 56, 39 });
	NeoGeo.PushBack({ 765, 827, 82, 40 });
	NeoGeo.PushBack({ 985, 1058, 99, 40 });
	NeoGeo.PushBack({ 1205, 1292, 115, 40 });
	NeoGeo.PushBack({ 1425, 1526, 127, 40 });
	NeoGeo.PushBack({ 1644, 1760, 150, 40 });
	NeoGeo.PushBack({ 1866, 1994, 172, 40 });
	NeoGeo.PushBack({ 2077, 2232, 153, 40 });
	NeoGeo.PushBack({ 2312, 2455, 184, 40 });
	NeoGeo.PushBack({ 2526, 2695, 200, 40 });
	NeoGeo.PushBack({ 2744, 2927, 210, 40 });
	NeoGeo.PushBack({ 2963, 3161, 215, 40 });
	NeoGeo.PushBack({ 3183, 3395, 232, 40 });
	NeoGeo.PushBack({ 3403, 3627, 226, 40 });
	NeoGeo.PushBack({ 3631, 3856, 227, 40 });
	NeoGeo.PushBack({ 3857, 4081, 227, 40 });
	NeoGeo.PushBack({ 4086, 4309, 227, 40 });
	NeoGeo.PushBack({ 4310, 4537, 227, 40 });
	NeoGeo.PushBack({ 4540, 4765, 227, 40 });
	NeoGeo.PushBack({ 4993, 5217, 228, 36 });
	NeoGeo.PushBack({ 5446, 5670, 232, 31 });
	NeoGeo.PushBack({ 5673, 5896, 228, 21 });
	NeoGeo.PushBack({ 5901, 6125, 227, 24 });
	NeoGeo.PushBack({ 6128, 6351, 225, 26 });
	NeoGeo.PushBack({ 6355, 6579, 232, 24 });
	NeoGeo.PushBack({ 6583, 6806, 232, 24 });	
	NeoGeo.PushBack({ 6812, 7032, 232, 24 });
	NeoGeo.speed = 0.1f;
	
	//Max logo
	Max.PushBack({ 227, 103, 24, 37 });
	Max.PushBack({ 251, 103, 24, 39 });
	Max.PushBack({ 275, 103, 24, 36 });
	Max.PushBack({ 299, 103, 24, 35 });
	Max.PushBack({ 323, 103, 24, 36 });
	Max.PushBack({ 347, 103, 23, 36 });
	Max.PushBack({ 370, 103, 23, 35 });
	Max.PushBack({ 393, 103, 23, 36 });
	Max.PushBack({ 227, 103, 24, 37 });
	Max.PushBack({ 251, 103, 24, 39 });
	Max.PushBack({ 275, 103, 24, 36 });
	Max.PushBack({ 299, 103, 24, 35 });
	Max.PushBack({ 323, 103, 24, 36 });
	Max.PushBack({ 347, 103, 23, 36 });
	Max.PushBack({ 370, 103, 23, 35 });
	Max.PushBack({ 393, 103, 23, 36 });
	Max.PushBack({ 227, 103, 24, 37 });
	Max.PushBack({ 251, 103, 24, 39 });
	Max.PushBack({ 275, 103, 24, 36 });
	Max.PushBack({ 299, 103, 24, 35 });
	Max.PushBack({ 323, 103, 24, 36 });
	Max.PushBack({ 347, 103, 23, 36 });
	Max.PushBack({ 370, 103, 23, 35 });
	Max.PushBack({ 393, 103, 23, 36 });
	Max.PushBack({ 227, 103, 24, 37 });
	Max.PushBack({ 251, 103, 24, 39 });
	Max.PushBack({ 275, 103, 24, 36 });
	Max.PushBack({ 299, 103, 24, 35 });
	Max.PushBack({ 323, 103, 24, 36 });
	Max.PushBack({ 347, 103, 23, 36 });
	Max.PushBack({ 370, 103, 23, 35 });
	Max.PushBack({ 393, 103, 23, 36 });
	Max.speed = 0.1f;
}

SceneIntro::~SceneIntro()
{

}

// Load assets
bool SceneIntro::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/Spriteswind/Sprites/UI/Dont_Use/intobg.png");
	App->audio->PlayMusic("Assets/Music/introTitle.ogg", 1.0f);

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

Update_Status SceneIntro::Update()
{
	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->tutorialScene, 40);
	}

	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status SceneIntro::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 0, NULL);

	return Update_Status::UPDATE_CONTINUE;
}