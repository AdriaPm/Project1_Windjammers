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
	NeoGeo.PushBack({ 1, 225, 226, 7 });
	NeoGeo.PushBack({ 227, 452, 226, 11 });
	NeoGeo.PushBack({ 455, 679, 229, 17 });
	NeoGeo.PushBack({ 682, 905, 226, 18 });
	NeoGeo.PushBack({ 908, 1133, 226, 19 });
	NeoGeo.PushBack({ 1137, 1360, 226, 17 });
	NeoGeo.PushBack({ 1361, 1587, 227, 25 });
	NeoGeo.PushBack({ 1588, 1813, 228, 23 });
	NeoGeo.PushBack({ 1815, 2040, 228, 27 });
	NeoGeo.PushBack({ 2043, 2267, 228, 26 });
	NeoGeo.PushBack({ 2268, 2494, 228, 32 });
	NeoGeo.PushBack({ 2495, 2722, 228, 33 });
	NeoGeo.PushBack({ 2722, 2949, 229, 33 });
	NeoGeo.PushBack({ 2949, 3176, 228, 37 });
	NeoGeo.PushBack({ 3176, 3403, 228, 41 });
	NeoGeo.PushBack({ 3403, 3630, 228, 40 });
	NeoGeo.PushBack({ 3636, 3850,215 , 42 });
	NeoGeo.PushBack({ 3870, 4070, 201, 41 });	
	
	NeoGeo.speed = 0.4f;
	NeoGeo.loop = false;
	
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
	Max.speed = 0.4f;
	Max.loop = false;
}

SceneIntro::~SceneIntro()
{

}

// Load assets
bool SceneIntro::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	
	bgTexture_white = App->textures->Load("Assets/Spriteswind/Sprites/UI/Dont_Use/introbg_white.png");
	bgTexture_black = App->textures->Load("Assets/Spriteswind/Sprites/UI/Dont_Use/introbg_black.png");

	NeoGeoLOGO = App->textures->Load("Assets/Spriteswind/Sprites/UI/Start1def.png");
	//MaxLOGO = App->textures->Load("Assets/Spriteswind/Sprites/UI/Start5.png");

	currentAnimation = &NeoGeo;
	
	App->audio->PlayMusic("Assets/Music/Neo Geo AESMVS Intro.ogg", 1.0f);

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

Update_Status SceneIntro::Update()
{


	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->dataEast, 40);
	}

	currentAnimation->Update();

	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status SceneIntro::PostUpdate()
{
	SDL_Rect rect = NeoGeo.GetCurrentFrame();

	// Draw everything --------------------------------------
	App->render->Blit(bgTexture_white, 0, 0, NULL);
	App->render->Blit(NeoGeoLOGO, 50, 50, &rect, false);


	return Update_Status::UPDATE_CONTINUE;
}
