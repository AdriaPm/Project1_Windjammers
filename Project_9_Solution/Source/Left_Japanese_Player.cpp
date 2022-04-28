#include "Left_Japanese_Player.h"

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

Left_Japanese_Player::Left_Japanese_Player(bool startEnabled) : Module(startEnabled)
{
	///CHAR1: Japanese
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
	rightAnim.PushBack({ 269, 148, 41, 35 });
	rightAnim.PushBack({ 310, 148, 29, 36 });
	rightAnim.PushBack({ 385, 148, 41, 36 });
	rightAnim.PushBack({ 339, 148, 46, 29 });
	rightAnim.PushBack({ 385, 148, 41, 36 });
	rightAnim.PushBack({ 426, 148, 28, 33 });
	rightAnim.PushBack({ 269, 148, 41, 35 });
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
	ScoredOn.PushBack({ 159, 359, 22, 36 });

	//Scored
	Scored.PushBack({ 21, 103, 23, 37 });

	//Throw---TODO: Put the disk in the trowing animation.
	/*
	Throw.PushBack({ , , , });
	Throw.PushBack({ , , , });
	Throw.PushBack({ , , , });
	*/

	//Disk Holding TURF MAP

	//Disk Holding CLAY MAP

	//Disk Holding BEACH MAP
	diskHoldBEACH.PushBack({ 0, 500, 51, 52 });
	diskHoldBEACH.PushBack({ 52, 503, 50, 49 });
	diskHoldBEACH.PushBack({ 104, 505, 50, 47 });
	diskHoldBEACH.PushBack({ 155, 502, 51, 50 });
	diskHoldBEACH.PushBack({ 207, 500, 51, 52 });
	diskHoldBEACH.loop = true;
	diskHoldBEACH.speed = 0.1f;

}

Left_Japanese_Player::~Left_Japanese_Player()
{

}

bool Left_Japanese_Player::Start()
{
	LOG("Loading player textures");

	bool ret = true;

	texture = App->textures->Load("Assets/Spriteswind/Sprites/CHAR1/JapaneseSpriteALL.png");
	currentAnimation = &idleAnim;

	slidingSFX = App->audio->LoadFx("Assets/Sound_Effects(SFX)wind/Sliding.wav");
	discThrowSFX = App->audio->LoadFx("Assets/Sound_Effects(SFX)wind/Disc/Throwing_1.wav");

	position.x = 60;
	position.y = 130;

	destroyed = false;

	collider = App->collisions->AddCollider({ position.x, position.y, 25, 40 }, Collider::Type::PLAYER, this);

	// TODO 0: Notice how a font is loaded and the meaning of all its arguments 
	//char lookupTable[] = { "!  ,_./0123456789$;<&?abcdefghijklmnopqrstuvwxyz" };
	//scoreFont = App->fonts->Load("Assets/Fonts/rtype_font.png", "! @,_./0123456789$;<&?abcdefghijklmnopqrstuvwxyz", 1);

	// TODO 4: Try loading "rtype_font3.png" that has two rows to test if all calculations are correct
	char lookupTable[] = { "0123456789" };
	scoreJapFontLeft = App->fonts->Load("Assets/Fonts/Score.png", lookupTable, 1);

	return ret;
}

Update_Status Left_Japanese_Player::Update()
{
	//In this function are all the movement inputs and animations updates
	Movement();
	
	collider->SetPos(position.x, position.y);

	currentAnimation->Update();

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status Left_Japanese_Player::PostUpdate()
{
	if (!destroyed)
	{
		SDL_Rect rect = currentAnimation->GetCurrentFrame();
		App->render->Blit(texture, position.x, position.y, &rect);
	}

	//// Draw UI (score) --------------------------------------
	sprintf_s(scoreJapTextLeft, 10, "%d", scoreJapLeft);

	App->fonts->BlitText(66, 8, scoreJapFontLeft, scoreJapTextLeft);

	return Update_Status::UPDATE_CONTINUE;
}

void Left_Japanese_Player::OnCollision(Collider* c1, Collider* c2)
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
		position.y = 199-40;
	}

	//Collider player-left goal
	if (c1->type == Collider::Type::PLAYER && c2->type == Collider::Type::LEFT_3P_GOAL){
		position.x = 10;
	}

	//Collider player-right goal
	if (c1->type == Collider::Type::PLAYER && c2->type == Collider::Type::RIGHT_3P_GOAL) {
		position.x = 295-25;
	}

	//Collider player-net
	if (c1->type == Collider::Type::PLAYER && c2->type == Collider::Type::NET) {
		position.x = 150 - 24;
	}


	//Score points
	if (c1->type == Collider::Type::DISK && c2->type == Collider::Type::RIGHT_3P_GOAL)
	{
		scoreJapLeft += 300;
	}

	if (c1->type == Collider::Type::DISK && c2->type == Collider::Type::RIGHT_5P_GOAL)
	{
		scoreJapLeft += 500;
	}
}

void Left_Japanese_Player::Movement() 
{
	if (hasDisc == false)
	{
		//Left anim
		if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT)
		{
			position.x -= speed;
			if (currentAnimation != &leftAnim)
			{
				leftAnim.Reset();
				currentAnimation = &leftAnim;
			}
		}

		//Right anim
		if (App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT)
		{
			position.x += speed;
			if (currentAnimation != &rightAnim)
			{
				rightAnim.Reset();
				currentAnimation = &rightAnim;
			}
		}

		//Down anim
		if (App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT)
		{
			position.y += speed;
			if (currentAnimation != &downAnim)
			{
				downAnim.Reset();
				currentAnimation = &downAnim;
			}
		}

		//Up anim
		if (App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT)
		{
			position.y -= speed;
			if (currentAnimation != &upAnim)
			{
				upAnim.Reset();
				currentAnimation = &upAnim;
			}
		}

		//Up Left Anim
		if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT)
		{
			position.x -= speedcross;
			position.y -= speedcross;

			if (currentAnimation != &leftAnim)
			{
				currentAnimation = &leftAnim;
			}
		}

		//Up Right Anim
		if (App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT)
		{
			position.x += speedcross;
			position.y -= speedcross;

			if (currentAnimation != &rightAnim)
			{
				currentAnimation = &rightAnim;
			}
		}

		// Down Left Anim
		if (App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT)
		{
			position.x -= speedcross;
			position.y += speedcross;

			if (currentAnimation != &leftAnim)
			{
				currentAnimation = &leftAnim;
			}
		}

		// Down Right Anim
		if (App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT)
		{
			position.x += speedcross;
			position.y += speedcross;

			if (currentAnimation != &rightAnim)
			{
				currentAnimation = &rightAnim;
			}
		}

		//Left Slide
		if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_REPEAT)
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
		if (App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_REPEAT)
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
		if (App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_REPEAT)
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
		if (App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_REPEAT)
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
		if (App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_REPEAT)
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
		if (App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_REPEAT)
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
		if (App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_REPEAT)
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
		if (App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_REPEAT)
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
	}
	else if (hasDisc == true)
	{
		if (App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_DOWN)
		{
			App->particles->diskL.speed.x = 5;
			App->particles->diskL.speed.y = 0;
			Particle* newParticle = App->particles->AddParticle(App->particles->diskL, position.x + 20, position.y, Collider::Type::DISK);
			newParticle->collider->AddListener(this);
			hasDisc = false;
			App->audio->PlayFx(discThrowSFX);
		}

		if (App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_DOWN && App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT)
		{
			
			Particle* newParticle = App->particles->AddParticle(App->particles->diskL, position.x + 20, position.y, Collider::Type::DISK);
			App->particles->diskL.speed.x = 2;
			App->particles->diskL.speed.y = -5;
			App->particles->diskL.position.x += App->particles->diskL.speed.x;
			App->particles->diskL.position.y += App->particles->diskL.speed.y;
			newParticle->collider->AddListener(this);
			hasDisc = false;
			App->audio->PlayFx(discThrowSFX);
		}

		if (App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_DOWN && App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT)
		{
			
			Particle* newParticle = App->particles->AddParticle(App->particles->diskL, position.x + 20, position.y, Collider::Type::DISK);
			App->particles->diskL.speed.x = 2;
			App->particles->diskL.speed.y = 5;
			App->particles->diskL.position.x += App->particles->diskL.speed.x;
			App->particles->diskL.position.y += App->particles->diskL.speed.y;
			newParticle->collider->AddListener(this);
			hasDisc = false;
			App->audio->PlayFx(discThrowSFX);
		}
	}

	// If no up/down left/right movement detected, set the current animation back to idle
	if (App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_IDLE)
		currentAnimation = &idleAnim;
}