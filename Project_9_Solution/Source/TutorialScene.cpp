#include "TutorialScene.h"
#include <SDL/include/SDL.h>

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
	idleAnim.speed = 0.2f;

	// move upwards
	upAnim.PushBack({ 0, 191, 30, 50 });
	upAnim.PushBack({ 30, 191, 30, 53 });
	upAnim.PushBack({ 60, 191, 30, 40 });
	upAnim.PushBack({ 90, 191, 30, 50 });
	upAnim.PushBack({ 120, 191, 30, 53 });
	upAnim.PushBack({ 150, 191, 30, 40 });
	upAnim.loop = true;
	upAnim.speed = 0.2f;

	// Move down
	downAnim.PushBack({ 94, 148, 31, 34 });
	downAnim.PushBack({ 125, 148, 30, 38 });
	downAnim.PushBack({ 155, 148, 24, 43 });
	downAnim.PushBack({ 179, 148, 29, 35 });
	downAnim.PushBack({ 208, 148, 32, 38 });
	downAnim.PushBack({ 240, 148, 29, 43 });
	downAnim.loop = true;
	downAnim.speed = 0.2f;

	//Move right

	rightAnim.PushBack({ 310, 148, 29, 36 });
	rightAnim.PushBack({ 269, 148, 41, 35 });
	rightAnim.PushBack({ 454, 148, 45, 32 });
	rightAnim.PushBack({ 426, 148, 28, 33 });
	rightAnim.PushBack({ 385, 148, 41, 36 });
	rightAnim.PushBack({ 339, 148, 46, 29 });
	rightAnim.PushBack({ 385, 148, 41, 36 });
	rightAnim.loop = true;
	rightAnim.speed = 0.2f;

	//Move left
	leftAnim.PushBack({ 269, 404, 42, 36 });
	leftAnim.PushBack({ 310, 404, 30, 37 });
	leftAnim.PushBack({ 339, 404, 47, 30 });
	leftAnim.PushBack({ 385, 404, 42, 37 });
	leftAnim.PushBack({ 426, 404, 29, 34 });
	leftAnim.PushBack({ 456, 404, 46, 33 });
	leftAnim.loop = true;
	leftAnim.speed = 0.2f;

	//Slide Left
	SlideLAnim.PushBack({ 474, 359, 30, 33 });
	SlideLAnim.PushBack({ 0, 404, 43, 31 });
	SlideLAnim.PushBack({ 43, 404, 51, 24 });
	SlideLAnim.loop = true;
	SlideLAnim.speed = 0.02f;

	//Slide Right
	SlideRAnim.PushBack({ 474, 103, 30, 33 });
	SlideRAnim.PushBack({ 0, 148, 43, 31 });
	SlideRAnim.PushBack({ 43, 148, 51, 24 });
	SlideRAnim.loop = true;
	SlideRAnim.speed = 0.02f;

	//Slide Up
	SlideUAnim.PushBack({ 374, 191, 28, 33 });
	SlideUAnim.PushBack({ 402, 191, 31, 24 });
	SlideUAnim.PushBack({ 433, 191, 25, 33 });
	SlideUAnim.loop = true;
	SlideUAnim.speed = 0.02f;

	//Slide Down
	SlideDAnim.PushBack({ 213, 46, 32, 41 });
	SlideDAnim.PushBack({ 245, 46, 32, 49 });
	SlideDAnim.PushBack({ 277, 46, 25, 57 });
	SlideDAnim.loop = true;
	SlideDAnim.speed = 0.02f;

	//Joystick and Buttons Animations
	//AnimationButtons[0] = &ButtonsidleAnim;
	ButtonsidleAnim.PushBack({ 0, 0, 171, 65 });
	ButtonsidleAnim.speed = 0.2f;
	ButtonsidleAnim.loop = true;

	//AnimationButtons[1] = &ButtonsrightAnim;
	ButtonsrightAnim.PushBack({ 171, 0, 171, 65});
	ButtonsrightAnim.speed = 0.2f;
	ButtonsrightAnim.loop = true;

	//AnimationButtons[2] = &ButtonsleftAnim;
	ButtonsleftAnim.PushBack({ 342, 0, 190, 65 });
	ButtonsleftAnim.speed = 0.2f;
	ButtonsleftAnim.loop = true;

	//AnimationButtons[3] = &ButtonsupAnim;
	ButtonsupAnim.PushBack({ 532, 0, 171, 65 });
	ButtonsupAnim.speed = 0.2f;
	ButtonsupAnim.loop = true;

	//AnimationButtons[4] = &ButtonsdownAnim;
	ButtonsdownAnim.PushBack({ 703, 0, 171, 65 });
	ButtonsdownAnim.speed = 0.2f;
	ButtonsdownAnim.loop = true;

	//AnimationButtons[5] = &ButtonsUpRightAnim;
	ButtonsUpRightAnim.PushBack({ 874, 0, 170, 65 });
	ButtonsUpRightAnim.speed = 0.2f;
	ButtonsUpRightAnim.loop = true;

	//AnimationButtons[6] = &ButtonsDownLeftAnim;
	ButtonsDownLeftAnim.PushBack({ 0, 76, 182, 65 });
	ButtonsDownLeftAnim.speed = 0.2f;
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
	charPos.x = 50;
	charPos.y = 75;
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/Spriteswind/Sprites/UI/TutorialBG.png");
	buttonsTexture = App->textures->Load("Assets/Spriteswind/Sprites/UI/JoystickAndButtons.png");
	currentAButtons = &ButtonsidleAnim;

	characterTexture = App->textures->Load("Assets/Spriteswind/Sprites/CHAR1/JapaneseSpriteALL.png");
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
	
	SceneAnimations();
	
	//ChangeScene
	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->chooseCharacter, 90);
	}

	currentAnimation->Update();
	currentAButtons->Update();
	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status TutorialScene::PostUpdate()
{
	SDL_Rect rect = currentAnimation->GetCurrentFrame();
	
	SDL_Rect rect2 = currentAButtons->GetCurrentFrame();
	//currentAnimCount++;

	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 0, NULL);
	App->render->Blit(bgTexture, SCREEN_WIDTH, 0, NULL);
	App->render->Blit(buttonsTexture, 60, 150, &rect2, false);
	App->render->Blit(characterTexture, charPos.x, charPos.y, &rect, false);

	return Update_Status::UPDATE_CONTINUE;
}

bool TutorialScene::CleanUp()
{

	App->tutorialScene->Disable();

	return true;
}

void TutorialScene::SceneAnimations() 
{
	if (currentAnimation->GetLoopCount() >= 1 && currentAButtons->GetLoopCount() >= 1)
	{
		currentAnimation = &rightAnim;
		currentAButtons = &ButtonsrightAnim;
		charPos.x += speed;

		//currentAnimation->ResetLoopCount();
		//currentAButtons->ResetLoopCount();
	}
	
	if (currentAnimation->GetLoopCount() >= 2 && currentAButtons->GetLoopCount() >= 2)
	{
		currentAnimation = &leftAnim;
		currentAButtons = &ButtonsleftAnim;
		charPos.x -= speed;
	}
	
	if (currentAnimation->GetLoopCount() >= 4 && currentAButtons->GetLoopCount() >= 4)
	{
		currentAnimation = &rightAnim;
		currentAButtons = &ButtonsrightAnim;
	}
	
	if (currentAnimation->GetLoopCount() >= 4.9 && currentAButtons->GetLoopCount() >= 4.75)
	{
		currentAnimation = &idleAnim;
		currentAButtons = &ButtonsidleAnim;
	}

	
	if (currentAnimation->GetLoopCount() >= 5 && currentAButtons->GetLoopCount() >= 5)
	{
		
		currentAnimation = &upAnim;
		currentAButtons = &ButtonsupAnim;
	}
	
	if (currentAnimation->GetLoopCount() >= 6 && currentAButtons->GetLoopCount() >= 6)
	{
		currentAnimation = &downAnim;
		currentAButtons = &ButtonsdownAnim;
	}

	if (currentAnimation->GetLoopCount() >= 8 && currentAButtons->GetLoopCount() >= 8)
	{
		currentAnimation = &upAnim;
		currentAButtons = &ButtonsupAnim;
	}

	if (currentAnimation->GetLoopCount() >= 8.9 && currentAButtons->GetLoopCount() >= 8.75)
	{
		currentAnimation = &idleAnim;
		currentAButtons = &ButtonsidleAnim;
	}
	
	if (currentAnimation->GetLoopCount() >= 9 && currentAButtons->GetLoopCount() >= 9)
	{
		currentAnimation = &upRightAnim;
		currentAButtons = &ButtonsUpRightAnim;
	}
	
	if (currentAnimation->GetLoopCount() >= 10 && currentAButtons->GetLoopCount() >= 10)
	{
		currentAnimation = &downLeftAnim;
		currentAButtons = &ButtonsDownLeftAnim;
	}
	
	if (currentAnimation->GetLoopCount() >= 12 && currentAButtons->GetLoopCount() >= 12)
	{
		currentAnimation = &upRightAnim;
		currentAButtons = &ButtonsUpRightAnim;
	}
	
	if (currentAnimation->GetLoopCount() >= 12.9 && currentAButtons->GetLoopCount() >= 12.9)
	{
		currentAnimation = &idleAnim;
		currentAButtons = &ButtonsidleAnim;
	}
}