#include "Right_Japanese_Player.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFonts.h"

#include <stdio.h>

Right_Japanese_Player::Right_Japanese_Player(bool startEnabled) : Module(startEnabled)
{
	///CHAR1: Japanese
	// idle animation
	idleAnim.PushBack({ 228, 359, 22, 37 });
	idleAnim.PushBack({ 250, 359, 24, 39 });
	idleAnim.PushBack({ 274, 359, 25, 36 });
	idleAnim.PushBack({ 299, 359, 24, 35 });
	idleAnim.PushBack({ 323, 359, 24, 36 });
	idleAnim.PushBack({ 347, 359, 23, 36 });
	idleAnim.PushBack({ 370, 359, 23, 35 });
	idleAnim.PushBack({ 393, 359, 23, 36 });
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
	rightAnim.PushBack({ 269, 148, 41, 35 });
	rightAnim.PushBack({ 310, 148, 29, 36 });
	rightAnim.PushBack({ 339, 148, 46, 29 });
	rightAnim.PushBack({ 385, 148, 41, 36 });
	rightAnim.PushBack({ 426, 148, 28, 33 });
	rightAnim.PushBack({ 454, 148, 45, 32 });
	rightAnim.loop = true;
	rightAnim.speed = 0.1f;

	//Move left
	leftAnim.PushBack({ 269, 404, 41, 35 });
	leftAnim.PushBack({ 310, 404, 29, 36 });
	leftAnim.PushBack({ 339, 404, 46, 29 });
	leftAnim.PushBack({ 385, 404, 41, 36 });
	leftAnim.PushBack({ 426, 404, 28, 33 });
	leftAnim.PushBack({ 456, 404, 45, 32 });
	leftAnim.loop = true;
	leftAnim.speed = 0.1f;

	//Slide Left
	SlideLAnim.PushBack({ 474, 359, 30, 33 });
	SlideLAnim.PushBack({ 0, 404, 43, 31 });
	SlideLAnim.PushBack({ 43, 404, 51, 24 });
	SlideLAnim.loop = false;
	SlideLAnim.speed = 2;

	//Slide Right
	SlideRAnim.PushBack({ 474, 103, 30, 33 });
	SlideRAnim.PushBack({ 0, 148, 43, 31 });
	SlideRAnim.PushBack({ 43, 148, 51, 24 });
	SlideRAnim.loop = false;
	SlideRAnim.speed = 2;

	//Slide Up
	SlideUAnim.PushBack({ 374, 191, 28, 33 });
	SlideUAnim.PushBack({ 402, 191, 31, 24 });
	SlideUAnim.PushBack({ 433, 191, 25, 53 });
	SlideUAnim.loop = false;
	SlideUAnim.speed = 2;

	//Slide Down
	SlideDAnim.PushBack({ 213, 46, 32, 41 });
	SlideDAnim.PushBack({ 245, 46, 32, 49 });
	SlideDAnim.PushBack({ 277, 46, 25, 57 });
	SlideDAnim.loop = false;
	SlideDAnim.speed = 2;

	//Slide Up Right
	SlideUpRightAnim.PushBack({ 270, 191, 27, 37 });
	SlideUpRightAnim.PushBack({ 297, 191, 32, 30 });
	SlideUpRightAnim.PushBack({ 329, 191, 45, 41 });
	SlideUpRightAnim.loop = false;
	SlideUpRightAnim.speed = 2;

	//Slide Up Left
	SlideUpLeftAnim.PushBack({ 270, 447, 27, 27 });
	SlideUpLeftAnim.PushBack({ 297, 447, 32, 30 });
	SlideUpLeftAnim.PushBack({ 329, 447, 45, 41 });
	SlideUpLeftAnim.loop = false;
	SlideUpLeftAnim.speed = 2;

	//Slide Down Right
	SlideDownRightAnim.PushBack({ 107, 46, 33, 35 });
	SlideDownRightAnim.PushBack({ 140, 46, 37, 40 });
	SlideDownRightAnim.PushBack({ 177, 46, 36, 48 });
	SlideDownRightAnim.loop = false;
	SlideDownRightAnim.speed = 2;

	//Slide Down Left
	SlideDownLeftAnim.PushBack({ 107, 302, 33, 35 });
	SlideDownLeftAnim.PushBack({ 140, 302, 37, 40 });
	SlideDownLeftAnim.PushBack({ 177, 302, 36, 48 });
	SlideDownLeftAnim.loop = false;
	SlideDownLeftAnim.speed = 2;

	//Victory
	victAnim.PushBack({ 77, 0, 33, 40 });
	victAnim.PushBack({ 110, 0, 34, 41 });
	victAnim.PushBack({ 144, 0, 33, 40 });
	victAnim.PushBack({ 177, 0, 34, 41 });
	victAnim.loop = true;
	victAnim.speed = 0.05f;

	//Lose
	loseAnim.PushBack({ 44, 103, 22, 40 });
	loseAnim.PushBack({ 66, 103, 24, 39 });
	loseAnim.PushBack({ 90, 103, 24, 39 });
	loseAnim.PushBack({ 114, 103, 23, 40 });
	loseAnim.PushBack({ 137, 103, 22, 40 });
	loseAnim.loop = true;
	loseAnim.speed = 0.05f;

	//Got scored on
	ScoredOn.PushBack({ 159, 103, 22, 36 });

	//Scored
	Scored.PushBack({ 21, 359, 23, 37 });

	//Throw---TODO: Put the disk in the trowing animation.
	/*
	Throw.PushBack({ , , , });
	Throw.PushBack({ , , , });
	Throw.PushBack({ , , , });
	*/

	//Disk Holding TURF MAP

	//Disk Holding CLAY MAP

	//Disk Holding BEACH MAP
	diskHoldBEACH.PushBack({ 252, 604, 51, 52 });
	diskHoldBEACH.PushBack({ 201, 607, 50, 49 });
	diskHoldBEACH.PushBack({ 149, 609, 50, 47 });
	diskHoldBEACH.PushBack({ 97, 606, 51, 50 });
	diskHoldBEACH.PushBack({ 45, 604, 51, 52 });
	diskHoldBEACH.loop = true;
	diskHoldBEACH.speed = 0.1f;

}

Right_Japanese_Player::~Right_Japanese_Player()
{

}

bool Right_Japanese_Player::Start()
{
	LOG("Loading player textures");

	bool ret = true;

	texture = App->textures->Load("Assets/Spriteswind/Sprites/CHAR1/JapaneseSpriteALL.png");
	currentAnimation = &idleAnim;

	slidingSFX = App->audio->LoadFx("Assets/Sound_Effects(SFX)wind/Sliding.wav");

	position.x = 160;
	position.y = 130;

	destroyed = false;

	collider = App->collisions->AddCollider({ position.x, position.y, 25, 40 }, Collider::Type::PLAYER, this);

	// TODO 0: Notice how a font is loaded and the meaning of all its arguments 
	//char lookupTable[] = { "!  ,_./0123456789$;<&?abcdefghijklmnopqrstuvwxyz" };
	//scoreFont = App->fonts->Load("Assets/Fonts/rtype_font.png", "! @,_./0123456789$;<&?abcdefghijklmnopqrstuvwxyz", 1);

	// TODO 4: Try loading "rtype_font3.png" that has two rows to test if all calculations are correct
	char lookupTable[] = { "0123456789" };
	scoreJapFontRight = App->fonts->Load("Assets/Fonts/Score.png", lookupTable, 1);

	return ret;
}

Update_Status Right_Japanese_Player::Update()
{
	//Left anim
	if (App->input->keys[SDL_SCANCODE_LEFT] == Key_State::KEY_REPEAT)
	{
		position.x -= speed;
		if (currentAnimation != &leftAnim)
		{
			leftAnim.Reset();
			currentAnimation = &leftAnim;
		}
	}

	//Right anim
	if (App->input->keys[SDL_SCANCODE_RIGHT] == Key_State::KEY_REPEAT)
	{
		position.x += speed;
		if (currentAnimation != &rightAnim)
		{
			rightAnim.Reset();
			currentAnimation = &rightAnim;
		}
	}

	//Down anim
	if (App->input->keys[SDL_SCANCODE_DOWN] == Key_State::KEY_REPEAT)
	{
		position.y += speed;
		if (currentAnimation != &downAnim)
		{
			downAnim.Reset();
			currentAnimation = &downAnim;
		}
	}

	//Up anim
	if (App->input->keys[SDL_SCANCODE_UP] == Key_State::KEY_REPEAT)
	{
		position.y -= speed;
		if (currentAnimation != &upAnim)
		{
			upAnim.Reset();
			currentAnimation = &upAnim;
		}
	}

	//Up Left Anim
	if (App->input->keys[SDL_SCANCODE_LEFT] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_UP] == Key_State::KEY_REPEAT)
	{
		position.x -= speedcross;
		position.y -= speedcross;

		if (currentAnimation != &leftAnim)
		{
			currentAnimation = &leftAnim;
		}
	}

	//Up Right Anim
	if (App->input->keys[SDL_SCANCODE_RIGHT] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_UP] == Key_State::KEY_REPEAT)
	{
		position.x += speedcross;
		position.y -= speedcross;

		if (currentAnimation != &rightAnim)
		{
			currentAnimation = &rightAnim;
		}
	}

	// Down Left Anim
	if (App->input->keys[SDL_SCANCODE_DOWN] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_LEFT] == Key_State::KEY_REPEAT)
	{
		position.x -= speedcross;
		position.y += speedcross;

		if (currentAnimation != &leftAnim)
		{
			currentAnimation = &leftAnim;
		}
	}

	// Down Right Anim
	if (App->input->keys[SDL_SCANCODE_DOWN] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_RIGHT] == Key_State::KEY_REPEAT)
	{
		position.x += speedcross;
		position.y += speedcross;

		if (currentAnimation != &rightAnim)
		{
			currentAnimation = &rightAnim;
		}
	}

	//Left Slide
	if (App->input->keys[SDL_SCANCODE_LEFT] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_N] == Key_State::KEY_REPEAT)
	{
		position.x -= speedslide;
		if (currentAnimation != &SlideLAnim)
		{
			SlideLAnim.Reset();
			currentAnimation = &SlideLAnim;
		}
		App->audio->PlayFx(slidingSFX);
	}

	//Right Slide
	if (App->input->keys[SDL_SCANCODE_RIGHT] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_N] == Key_State::KEY_REPEAT)
	{
		position.x += speedslide;
		if (currentAnimation != &SlideRAnim)
		{
			SlideRAnim.Reset();
			currentAnimation = &SlideRAnim;
		}
		App->audio->PlayFx(slidingSFX);
	}

	//Down Slide
	if (App->input->keys[SDL_SCANCODE_DOWN] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_N] == Key_State::KEY_REPEAT)
	{
		position.y += speedslide;
		if (currentAnimation != &SlideDAnim)
		{
			SlideDAnim.Reset();
			currentAnimation = &SlideDAnim;
		}
		App->audio->PlayFx(slidingSFX);
	}

	//Up Slide
	if (App->input->keys[SDL_SCANCODE_UP] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_N] == Key_State::KEY_REPEAT)
	{
		position.y -= speedslide;
		if (currentAnimation != &SlideUAnim)
		{
			SlideUAnim.Reset();
			currentAnimation = &SlideUAnim;
		}
		App->audio->PlayFx(slidingSFX);
	}

	//Up Left Slide
	if (App->input->keys[SDL_SCANCODE_UP] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_LEFT] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_N] == Key_State::KEY_REPEAT)
	{
		position.y -= speedslide;
		position.x -= speedslide;
		if (currentAnimation != &SlideUpLeftAnim)
		{
			SlideUpLeftAnim.Reset();
			currentAnimation = &SlideUpLeftAnim;
		}
		App->audio->PlayFx(slidingSFX);
	}

	//Up Right Slide
	if (App->input->keys[SDL_SCANCODE_UP] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_RIGHT] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_N] == Key_State::KEY_REPEAT)
	{
		position.y -= speedslide;
		position.x += speedslide;
		if (currentAnimation != &SlideUpRightAnim)
		{
			SlideUpRightAnim.Reset();
			currentAnimation = &SlideUpRightAnim;
		}
		App->audio->PlayFx(slidingSFX);
	}

	//Down Left Slide
	if (App->input->keys[SDL_SCANCODE_DOWN] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_LEFT] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_N] == Key_State::KEY_REPEAT)
	{
		position.y += speedslide;
		position.x -= speedslide;
		if (currentAnimation != &SlideDownLeftAnim)
		{
			SlideDownLeftAnim.Reset();
			currentAnimation = &SlideDownLeftAnim;
		}
		App->audio->PlayFx(slidingSFX);
	}

	//Down Right Slide
	if (App->input->keys[SDL_SCANCODE_DOWN] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_RIGHT] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_N] == Key_State::KEY_REPEAT)
	{
		position.y += speedslide;
		position.x += speedslide;
		if (currentAnimation != &SlideDownRightAnim)
		{
			SlideDownRightAnim.Reset();
			currentAnimation = &SlideDownRightAnim;
		}
		App->audio->PlayFx(slidingSFX);
	}

	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
	{
		Particle* newParticle = App->particles->AddParticle(App->particles->explosion, position.x + 20, position.y, Collider::Type::PLAYER_SHOT);
		newParticle->collider->AddListener(this);
		/*App->audio->PlayFx(laserFx);*/
	}

	// If no up/down left/right movement detected, set the current animation back to idle
	if (App->input->keys[SDL_SCANCODE_DOWN] == Key_State::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_UP] == Key_State::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_RIGHT] == Key_State::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_LEFT] == Key_State::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_N] == Key_State::KEY_IDLE)
		currentAnimation = &idleAnim;

	collider->SetPos(position.x, position.y);

	currentAnimation->Update();

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status Right_Japanese_Player::PostUpdate()
{
	if (!destroyed)
	{
		SDL_Rect rect = currentAnimation->GetCurrentFrame();
		App->render->Blit(texture, position.x, position.y, &rect);
	}

	// Draw UI (score) --------------------------------------
	sprintf_s(scoreJapTextRight, 10, "%d", scoreJapRight);

	App->fonts->BlitText(204, 8, scoreJapFontRight, scoreJapTextRight);

	return Update_Status::UPDATE_CONTINUE;
}

void Right_Japanese_Player::OnCollision(Collider* c1, Collider* c2)
{

	if (c1 == collider && destroyed == false)
	{
		/*
		App->particles->AddParticle(App->particles->explosion, position.x, position.y, Collider::Type::NONE, 9);
		App->particles->AddParticle(App->particles->explosion, position.x + 8, position.y + 11, Collider::Type::NONE, 14);
		App->particles->AddParticle(App->particles->explosion, position.x - 7, position.y + 12, Collider::Type::NONE, 40);
		App->particles->AddParticle(App->particles->explosion, position.x + 5, position.y - 5, Collider::Type::NONE, 28);
		App->particles->AddParticle(App->particles->explosion, position.x - 4, position.y - 4, Collider::Type::NONE, 21);

		App->audio->PlayFx(explosionFx);
		App->fade->FadeToBlack((Module*)App->turflevel, (Module*)App->sceneIntro, 60);
		*/
	
	}

	/// PLAYER COLLIDERS WITH THE MAP
	//Collider player-upper wall
	if (c1->type == Collider::Type::PLAYER && c2->type == Collider::Type::UPPER_WALL) {
		position.y = 40;
	}

	//Collider player-lower wall
	if (c1->type == Collider::Type::PLAYER && c2->type == Collider::Type::LOWER_WALL) {
		position.y = 199 - 40;
	}

	//Collider player-left goal
	if (c1->type == Collider::Type::PLAYER && c2->type == Collider::Type::LEFT_3P_GOAL) {
		position.x = 10;
	}

	//Collider player-right goal
	if (c1->type == Collider::Type::PLAYER && c2->type == Collider::Type::RIGHT_3P_GOAL) {
		position.x = 295 - 25;
	}

	//Collider player-net
	if (c1->type == Collider::Type::PLAYER && c2->type == Collider::Type::NET) {
		position.x = 150 + 4;
	}

	///Score points
	if (App->input->keys[SDL_SCANCODE_F1] == Key_State::KEY_DOWN) {
		godMode = !godMode;
	}

	if (godMode == false) {

		if (c1->type == Collider::Type::DISK && c2->type == Collider::Type::LEFT_3P_GOAL)
		{
			scoreJapRight += 300;
		}

		if (c1->type == Collider::Type::DISK && c2->type == Collider::Type::LEFT_5P_GOAL)
		{
			scoreJapRight += 500;
		}
	}
	else if (godMode == true) {
		if (c1->type == Collider::Type::DISK && c2->type == Collider::Type::LEFT_3P_GOAL ||
			c1->type == Collider::Type::DISK && c2->type == Collider::Type::LEFT_5P_GOAL)
		{
			scoreJapRight += 0;
		}
	}

}