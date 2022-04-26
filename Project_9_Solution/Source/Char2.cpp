#include "Char2.h"

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

Char2::Char2(bool startEnabled) : Module(startEnabled)
{
	// idle animation
	idleAnim.PushBack({ 68, 324, 24, 34 });
	idleAnim.PushBack({ 92, 324, 23, 36 });
	idleAnim.PushBack({ 115, 324, 23, 35 });
	idleAnim.PushBack({ 115, 324, 23, 35 });
	idleAnim.PushBack({ 92, 324, 23, 36 });
	idleAnim.PushBack({ 68, 324, 24, 34 });
	idleAnim.loop = true;
	idleAnim.speed = 0.1f;

	// move upwards
	upAnim.PushBack({ 96, 367, 32, 34 });
	upAnim.PushBack({ 67, 367, 29, 39 });
	upAnim.PushBack({ 32, 367, 30, 36 });
	upAnim.PushBack({ 1, 367, 31, 34 });
	upAnim.loop = true;
	upAnim.speed = 0.1f;

	// Move down
	downAnim.PushBack({ 138, 324, 26, 30 });
	downAnim.PushBack({ 164, 324, 31, 30 });
	downAnim.PushBack({ 195, 324, 31, 30 });
	downAnim.PushBack({ 226, 324, 29, 30 });
	downAnim.loop = true;
	downAnim.speed = 0.1f;


	////Move Right
	rightAnim.PushBack({ 1, 406, 28, 33 });
	rightAnim.PushBack({ 58, 406, 27, 33 });
	rightAnim.PushBack({ 85, 406, 21, 33 });
	rightAnim.PushBack({ 106, 406, 25, 33 });
	rightAnim.PushBack({ 131, 406, 30, 33 });
	rightAnim.PushBack({ 161, 406, 21, 33 });
	rightAnim.loop = true;
	rightAnim.speed = 0.1f;


	////Move Left
	leftAnim.PushBack({ 52, 440, 28, 34 });
	leftAnim.PushBack({ 80, 440, 27, 34 });
	leftAnim.PushBack({ 107, 440, 21, 34 });
	leftAnim.loop = true;
	leftAnim.speed = 0.1f;

	////Move Up right
	UpRightAnim.PushBack({ 233, 367, 22, 34 });
	UpRightAnim.PushBack({ 29, 406, 29, 33 });
	UpRightAnim.PushBack({ 106, 406, 25, 33 });
	UpRightAnim.PushBack({ 131, 406, 30, 33 });
	UpRightAnim.loop = true;
	UpRightAnim.speed = 0.1f;

	//Move Up Left
	UpLeftAnim.PushBack({ 211, 440, 26, 34 });
	UpLeftAnim.PushBack({ 1, 440, 29, 34 });
	UpLeftAnim.PushBack({ 30, 440, 20, 34 });
	UpLeftAnim.PushBack({ 211, 440, 26, 34 });
	UpLeftAnim.PushBack({ 1, 440, 29, 34 });
	UpLeftAnim.PushBack({ 30, 440, 20, 34 });
	UpLeftAnim.loop = true;
	UpLeftAnim.speed = 0.1f;
	

	//Move Down Left -- DONE
	DownLeftAnim.PushBack({ 98, 474, 27, 31 });
	DownLeftAnim.PushBack({ 78, 474, 20, 31 });
	DownLeftAnim.PushBack({ 30, 440, 20, 34 });
	DownLeftAnim.PushBack({ 52, 474, 26, 34 });
	DownLeftAnim.loop = true;
	DownLeftAnim.speed = 0.1f;

	////Move Down right
	DownRightAnim.PushBack({ 156, 440, 26, 33 });
	DownRightAnim.PushBack({ 182, 440, 21, 33 });
	DownRightAnim.PushBack({ 203, 440, 26, 33 });
	DownRightAnim.PushBack({ 156, 440, 26, 33 });
	DownRightAnim.PushBack({ 182, 440, 21, 33 });
	DownRightAnim.PushBack({ 203, 440, 26, 33 });
	DownRightAnim.loop = true;
	DownRightAnim.speed = 0.1f;

	//Victory
	victAnim.PushBack({ 179, 14, 26, 39 });
	victAnim.PushBack({ 209, 14, 30, 39 });
	victAnim.loop = false;
	victAnim.speed = 0.1f;

	//Slide Left
	SlideLAnim.PushBack({ 224, 239, 31, 31 });
	SlideLAnim.PushBack({ 168, 239, 56, 31 });
	SlideLAnim.PushBack({ 139, 239, 29, 31 });
	SlideLAnim.PushBack({ 107, 239, 32, 31 });
	SlideLAnim.loop = true;
	SlideLAnim.speed = 0.1f;

	//Slide Right
	SlideRAnim.PushBack({ 1, 188, 31, 31 });
	SlideRAnim.PushBack({ 32, 188, 31, 31 });
	SlideRAnim.PushBack({ 63, 188, 29, 31 });
	SlideRAnim.PushBack({ 92, 188, 57, 31 });
	SlideRAnim.PushBack({ 149, 188, 32, 31 });
	SlideRAnim.loop = true;
	SlideRAnim.speed = 0.1f;

	//Slide Up
	SlideUAnim.PushBack({ 1, 238, 28, 50 });
	SlideUAnim.PushBack({ 29, 238, 24, 50 });
	SlideUAnim.PushBack({ 53, 238, 31, 50 });
	SlideUAnim.PushBack({ 84, 238, 23, 50 });
	SlideUAnim.PushBack({ 107, 238, 32, 31 });
	SlideUAnim.loop = true;
	SlideUAnim.speed = 0.1f;


	//Slide Down
	SlideDAnim.PushBack({ 29, 239, 24, 49 });
	SlideDAnim.PushBack({ 1, 239, 28, 49 });
	SlideDAnim.PushBack({ 84, 239, 23, 49 });
	SlideDAnim.PushBack({ 53, 239, 31, 49 });
	SlideDAnim.loop = true;
	SlideDAnim.speed = 0.1f;


	//Slide Up Right
	SlideUpRightAnim.PushBack({ 68, 140, 39, 48 });
	SlideUpRightAnim.PushBack({ 38, 140, 30, 48 });
	SlideUpRightAnim.PushBack({ 1, 140, 37, 48 });
	SlideUpRightAnim.PushBack({ 213, 92, 26, 42 });
	SlideUpRightAnim.loop = true;
	SlideUpRightAnim.speed = 0.1f;


	//Slide Up Left
	SlideUpLeftAnim.PushBack({ 31, 91, 40, 59 });
	SlideUpLeftAnim.PushBack({ 1, 91, 30, 59 });
	SlideUpLeftAnim.PushBack({ 219, 53, 37, 35 });
	SlideUpLeftAnim.PushBack({ 191, 53, 28, 35 });
	SlideUpLeftAnim.PushBack({ 107, 238, 32, 31 });
	SlideUpLeftAnim.loop = true;
	SlideUpLeftAnim.speed = 0.1f;


	//Slide Down Left
	SlideDownLeftAnim.PushBack({ 168, 92, 45, 42});
	SlideDownLeftAnim.PushBack({ 137,  92, 31, 42 });
	SlideDownLeftAnim.PushBack({ 102, 92, 35, 42 });
	SlideDownLeftAnim.PushBack({ 71, 92, 31, 42 });
	SlideDownLeftAnim.loop = true;
	SlideDownLeftAnim.speed = 0.1f;


	//Slide Down Right 
	SlideDownRightAnim.PushBack({ 169, 140, 45, 42 });
	SlideDownRightAnim.PushBack({ 138, 140, 31, 42 });
	SlideDownRightAnim.PushBack({ 107, 140, 31, 42 });
	SlideDownRightAnim.PushBack({ 215, 140, 31, 42 });
	SlideDownRightAnim.loop = true;
	SlideDownRightAnim.speed = 0.1f;
}

Char2::~Char2()
{

}

bool Char2::Start()
{
	LOG("Loading player textures");

	bool ret = true;

	texture2 = App->textures->Load("Assets/Spriteswind/Sprites/CHAR2/CHAR2ALL.png");
	currentAnimation = &idleAnim;

	laserFx = App->audio->LoadFx("Assets/Fx/laser.wav");
	explosionFx = App->audio->LoadFx("Assets/Fx/explosion.wav");

	position.x = 80;
	position.y = 135;

	destroyed = false;

	collider = App->collisions->AddCollider({ position.x, position.y, 25, 40 }, Collider::Type::PLAYER, this);

	// TODO 0: Notice how a font is loaded and the meaning of all its arguments 
	//char lookupTable[] = { "!  ,_./0123456789$;<&?abcdefghijklmnopqrstuvwxyz" };
	//scoreFont = App->fonts->Load("Assets/Fonts/rtype_font.png", "! @,_./0123456789$;<&?abcdefghijklmnopqrstuvwxyz", 1);

	// TODO 4: Try loading "rtype_font3.png" that has two rows to test if all calculations are correct
	/*char lookupTable[] = { "! @,_./0123456789$;< ?abcdefghijklmnopqrstuvwxyz" };
	scoreFont = App->fonts->Load("Assets/Fonts/rtype_font3.png", lookupTable, 2);*/

	return ret;
}

Update_Status Char2::Update()
{

	//Left Anim
	if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT)
	{
		position.x -= speed;
		if (currentAnimation != &leftAnim)
		{
			leftAnim.Reset();
			currentAnimation = &leftAnim;
		}
	}

	//Right Anim
	if (App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT)
	{
		position.x += speed;
		if (currentAnimation != &rightAnim)
		{
			rightAnim.Reset();
			currentAnimation = &rightAnim;
		}
	}

	//Down Anim
	if (App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT)
	{
		position.y += speed;
		if (currentAnimation != &downAnim)
		{
			downAnim.Reset();
			currentAnimation = &downAnim;
		}
	}

	//Up Anim
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

		if (currentAnimation != &UpLeftAnim)
		{
			currentAnimation = &UpLeftAnim;
		}
	}
	
	//Up Right Anim
	if (App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT)
	{
		position.x += speedcross;
		position.y -= speedcross;

		if (currentAnimation != &UpRightAnim)
		{
			currentAnimation = &UpRightAnim;
		}
	}
	

	// Down Left Anim
	if (App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT)
	{
		position.x -= speedcross;
		position.y += speedcross;

		if (currentAnimation != &DownLeftAnim)
		{
			currentAnimation = &DownLeftAnim;
		}
	}

	// Down Right Anim
	if (App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT)
	{
		position.x += speedcross;
		position.y += speedcross;

		if (currentAnimation != &DownRightAnim)
		{
			currentAnimation = &DownRightAnim;
		}
	}


	//Right Slide Anim
	if (App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_REPEAT)
	{
		position.x += speedslide;
		if (currentAnimation != &SlideRAnim)
		{
			currentAnimation = &SlideRAnim;
		}
	}

	//Up Slide Anim
	if (App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_REPEAT)
	{
		position.y -= speedslide;
		if (currentAnimation != &SlideUAnim)
		{
			currentAnimation = &SlideUAnim;
		}
	}

	//Left Slide Anim
	if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_REPEAT)
	{
		position.x -= speedslide;
		if (currentAnimation != &SlideLAnim)
		{
			currentAnimation = &SlideLAnim;
		}
	}

	//Down Slide Anim
	if (App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_REPEAT)
	{
		position.y += speedslide;

		if (currentAnimation != &SlideDAnim)
		{
			currentAnimation = &SlideDAnim;
		}
	}

	//Up Left Slide Anim
	if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT 
		&& App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_REPEAT)
	{   
		position.x -= speedslide;
		position.y -= speedslide;

		if (currentAnimation != &SlideUpLeftAnim)
		{
			currentAnimation = &SlideUpLeftAnim;
		}
	}

	//Up Right Slide Anim
	if (App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT
		&& App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_REPEAT)
	{
		position.x += speedslide;
		position.y -= speedslide;

		if (currentAnimation != &SlideUpRightAnim)
		{
			currentAnimation = &SlideUpRightAnim;
		}
	}

	// Down Left Slide Anim
	if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT
		&& App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_REPEAT)
	{
		position.x -= speedslide;
		position.y += speedslide;

		if (currentAnimation != &SlideDownLeftAnim)
		{
			currentAnimation = &SlideDownLeftAnim;
		}
	}


	// Down Right Slide Anim
	if (App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT
		&& App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_REPEAT)
	{
		position.x += speedslide;
		position.y += speedslide;

		if (currentAnimation != &SlideDownRightAnim)
		{
			currentAnimation = &SlideDownRightAnim;
		}
	}

	
	//Shoot
	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
	{
		Particle* newParticle = App->particles->AddParticle(App->particles->laser, position.x + 20, position.y, Collider::Type::PLAYER_SHOT);
		newParticle->collider->AddListener(this);
		App->audio->PlayFx(laserFx);
	}

	// If no up/down left/right movement detected, set the current animation back to idle
	if (App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_IDLE)
		currentAnimation = &idleAnim;

	collider->SetPos(position.x, position.y);

	currentAnimation->Update();

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status Char2::PostUpdate()
{
	if (!destroyed)
	{
		SDL_Rect rect = currentAnimation->GetCurrentFrame();
		App->render->Blit(texture2, position.x, position.y, &rect);
	}

	// Draw UI (score) --------------------------------------
	sprintf_s(scoreText, 10, "%7d", score);

	// TODO 3: Blit the text of the score in at the bottom of the screen
	App->fonts->BlitText(58, 248, scoreFont, scoreText);

	App->fonts->BlitText(150, 248, scoreFont, "this is just a font test");

	return Update_Status::UPDATE_CONTINUE;
}

void Char2::OnCollision(Collider* c1, Collider* c2)
{
	if (c1 == collider && destroyed == false)
	{
		App->particles->AddParticle(App->particles->explosion, position.x, position.y, Collider::Type::NONE, 9);
		App->particles->AddParticle(App->particles->explosion, position.x + 8, position.y + 11, Collider::Type::NONE, 14);
		App->particles->AddParticle(App->particles->explosion, position.x - 7, position.y + 12, Collider::Type::NONE, 40);
		App->particles->AddParticle(App->particles->explosion, position.x + 5, position.y - 5, Collider::Type::NONE, 28);
		App->particles->AddParticle(App->particles->explosion, position.x - 4, position.y - 4, Collider::Type::NONE, 21);

		App->audio->PlayFx(explosionFx);
		App->fade->FadeToBlack((Module*)App->turflevel, (Module*)App->sceneIntro, 60);

		destroyed = true;
	}

	if (c1->type == Collider::Type::PLAYER_SHOT && c2->type == Collider::Type::ENEMY)
	{
		score += 23;
	}
}