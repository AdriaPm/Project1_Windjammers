#include "TutorialScene.h"

#include "Application.h"
#include "Globals.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

TutorialScene::TutorialScene(bool startEnabled) : Module(startEnabled)
{

	//Character Animations
	// idle animation
	idleAnim.PushBack({ 227, 103, 24, 37 });
	idleAnim.PushBack({ 251, 103, 24, 39 });
	idleAnim.PushBack({ 275, 103, 24, 36 });
	idleAnim.PushBack({ 299, 103, 24, 35 });
	idleAnim.PushBack({ 323, 103, 24, 36 });
	idleAnim.PushBack({ 347, 103, 23, 36 });
	idleAnim.PushBack({ 370, 103, 23, 35 });
	idleAnim.PushBack({ 393, 103, 23, 36 });
	idleAnim.loop = true;
	idleAnim.speed = 0.1f;

	// move upwards
	upAnim.PushBack({ 0, 191, 30, 50 });
	upAnim.PushBack({ 30, 191, 30, 53 });
	upAnim.PushBack({ 60, 191, 30, 40 });
	upAnim.PushBack({ 90, 191, 30, 50 });
	upAnim.PushBack({ 120, 191, 30, 53 });
	upAnim.PushBack({ 150, 191, 30, 40 });
	upAnim.loop = true;
	upAnim.speed = 0.1f;

	// Move down
	downAnim.PushBack({ 94, 148, 31, 34 });
	downAnim.PushBack({ 125, 148, 30, 38 });
	downAnim.PushBack({ 155, 148, 24, 43 });
	downAnim.PushBack({ 179, 148, 29, 35 });
	downAnim.PushBack({ 208, 148, 32, 38 });
	downAnim.PushBack({ 240, 148, 29, 43 });
	downAnim.loop = true;
	downAnim.speed = 0.1f;

	//Move right

	rightAnim.PushBack({ 310, 148, 29, 36 });
	rightAnim.PushBack({ 269, 148, 41, 35 });
	rightAnim.PushBack({ 454, 148, 45, 32 });
	rightAnim.PushBack({ 426, 148, 28, 33 });
	rightAnim.PushBack({ 385, 148, 41, 36 });
	rightAnim.PushBack({ 339, 148, 46, 29 });
	rightAnim.PushBack({ 385, 148, 41, 36 });
	rightAnim.loop = true;
	rightAnim.speed = 0.1f;

	//Joystick and Buttons Animations
	AnimationButtons[0] = &ButtonsidleAnim;
	ButtonsidleAnim.PushBack({ 0, 0, 172, 65 });
	ButtonsidleAnim.speed = 0.1f;
	ButtonsidleAnim.loop = true;

	AnimationButtons[1] = &ButtonsrightAnim;
	ButtonsrightAnim.PushBack({ 172, 0, 172, 65});
	ButtonsrightAnim.speed = 0.1f;
	ButtonsrightAnim.loop = true;

	AnimationButtons[2] = &ButtonsleftAnim;
	ButtonsleftAnim.PushBack({ 342, 0, 191, 65 });
	ButtonsleftAnim.speed = 0.1f;
	ButtonsleftAnim.loop = true;

	AnimationButtons[3] = &ButtonsupAnim;
	ButtonsupAnim.PushBack({ 531, 0, 172, 65 });
	ButtonsupAnim.speed = 0.1f;
	ButtonsupAnim.loop = true;

	AnimationButtons[4] = &ButtonsdownAnim;
	ButtonsdownAnim.PushBack({ 703, 0, 172, 65 });
	ButtonsdownAnim.speed = 0.1f;
	ButtonsdownAnim.loop = true;

	AnimationButtons[5] = &ButtonsUpRightAnim;
	ButtonsUpRightAnim.PushBack({ 874, 0, 172, 65 });
	ButtonsUpRightAnim.speed = 0.1f;
	ButtonsUpRightAnim.loop = true;

	AnimationButtons[6] = &ButtonsDownLeftAnim;
	ButtonsDownLeftAnim.PushBack({ 0, 76, 182, 65 });
	ButtonsDownLeftAnim.speed = 0.1f;
	ButtonsDownLeftAnim.loop = true;
	/*
	
	ButtonsSlideLAnim.PushBack({ ,,, });
	ButtonsSlideRAnim.PushBack({ ,,, });
	ButtonsSlideUAnim.PushBack({ ,,, });
	ButtonsSlideDAnim.PushBack({ ,,, });*/

}

TutorialScene::~TutorialScene()
{

}

// Load assets
bool TutorialScene::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/Spriteswind/Sprites/UI/TutorialBG.png");
	buttonsTexture = App->textures->Load("Assets/Spriteswind/Sprites/UI/JoystickAndButtons.png");
	currentAButtons = AnimationButtons[0];

	characterTexture = App->textures->Load("Assets/Spriteswind/Sprites/CHAR1/CHAR1_IDLE/SPRITESHEET/CHAR1JapaneseSpriteSheet.png");
	currentAnimation = &idleAnim;

	App->audio->PlayMusic("Assets/Music/001 Windjammers _ Flying Power Disc (wjammers) [#002] Get Ready! (Select).ogg", 1.0f);

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

Update_Status TutorialScene::Update()
{
	App->render->camera.x += 2;
	if (App->render->camera.x >= SCREEN_WIDTH*3) App->render->camera.x = 0;

	for (size_t i = 0; i < 7; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			if (currentAnimation->GetLoopCount() >= 5 && currentAButtons->GetLoopCount() >= 5)
			{
				currentAnimation = &rightAnim;
				currentAButtons = AnimationButtons[i];
			}
		}
		
	}
	
	/*currentAnimation = &rightAnim;
	currentAnimationButtons = &ButtonsrightAnim;*/
	
	//ChangeScene
	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->chooseCharacter, 40);
	}

	currentAnimation->Update();
	AnimationButtons[currentAnim]->Update();
	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status TutorialScene::PostUpdate()
{
	SDL_Rect rect = currentAnimation->GetCurrentFrame();
	
	SDL_Rect rect2 = AnimationButtons[currentAnim]->GetCurrentFrame();
	currentAnim++;
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 0, NULL);
	App->render->Blit(bgTexture, SCREEN_WIDTH, 0, NULL);
	App->render->Blit(buttonsTexture, 50, 150, &rect2, false);
	App->render->Blit(characterTexture, 0, 0, &rect, false);

	return Update_Status::UPDATE_CONTINUE;
}