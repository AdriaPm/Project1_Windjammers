#include "LeftGermanPlayer.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFonts.h"
#include "Left_Japanese_Player.h"
#include "Right_Japanese_Player.h"
#include "LeftGermanPlayer.h"
#include "RightGermanPlayer.h"

#include <stdio.h>

LeftGermanPlayer::LeftGermanPlayer(bool startEnabled) : Module(startEnabled)
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
	UpLeftAnim.PushBack({ 1, 440, 29, 34 });
	UpLeftAnim.PushBack({ 30, 440, 20, 34 });
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
	SlideLAnim.PushBack({ 168, 239, 56, 31 });
	SlideLAnim.PushBack({ 139, 239, 29, 31 });
	SlideLAnim.PushBack({ 107, 239, 32, 31 });
	SlideLAnim.PushBack({ 224, 239, 31, 31 });
	SlideLAnim.loop = false;
	SlideLAnim.speed = 0.1f;

	//Slide Right
	SlideRAnim.PushBack({ 92, 188, 57, 31 });
	SlideRAnim.PushBack({ 63, 188, 29, 31 });
	SlideRAnim.PushBack({ 32, 188, 31, 31 });
	SlideRAnim.PushBack({ 1, 188, 31, 31 });
	SlideRAnim.loop = false;
	SlideRAnim.speed = 0.1f;

	//Slide Up
	SlideUAnim.PushBack({ 232, 188, 23, 51 });
	SlideUAnim.PushBack({ 203, 188, 29, 50 });
	SlideUAnim.PushBack({ 180, 188, 23, 50 });
	SlideUAnim.PushBack({ 149, 188, 31, 34 });
	SlideUAnim.loop = false;
	SlideUAnim.speed = 0.1f;


	//Slide Down
	SlideDAnim.PushBack({ 29, 239, 24, 49 });
	SlideDAnim.PushBack({ 1, 239, 28, 49 });
	SlideDAnim.PushBack({ 84, 239, 23, 49 });
	SlideDAnim.PushBack({ 53, 239, 31, 49 });
	SlideDAnim.loop = false;
	SlideDAnim.speed = 0.1f;


	//Slide Up Right
	SlideUpRightAnim.PushBack({ 68, 140, 39, 48 });
	SlideUpRightAnim.PushBack({ 38, 140, 30, 48 });
	SlideUpRightAnim.PushBack({ 1, 140, 37, 48 });
	SlideUpRightAnim.PushBack({ 213, 92, 26, 42 });
	SlideUpRightAnim.loop = false;
	SlideUpRightAnim.speed = 0.1f;


	//Slide Up Left
	SlideUpLeftAnim.PushBack({ 31, 91, 40, 49 });
	SlideUpLeftAnim.PushBack({ 1, 91, 30, 50 });
	SlideUpLeftAnim.PushBack({ 219, 53, 37, 35 });
	SlideUpLeftAnim.PushBack({ 191, 53, 28, 35 });
	SlideUpLeftAnim.PushBack({ 107, 238, 32, 31 });
	SlideUpLeftAnim.loop = false;
	SlideUpLeftAnim.speed = 0.1f;


	//Slide Down Left
	SlideDownLeftAnim.PushBack({ 168, 92, 45, 42});
	SlideDownLeftAnim.PushBack({ 137,  92, 31, 42 });
	SlideDownLeftAnim.PushBack({ 102, 92, 35, 42 });
	SlideDownLeftAnim.PushBack({ 71, 92, 31, 42 });
	SlideDownLeftAnim.loop = false;
	SlideDownLeftAnim.speed = 0.1f;


	//Slide Down Right 
	SlideDownRightAnim.PushBack({ 169, 140, 45, 42 });
	SlideDownRightAnim.PushBack({ 138, 140, 31, 42 });
	SlideDownRightAnim.PushBack({ 107, 140, 31, 42 });
	SlideDownRightAnim.PushBack({ 215, 140, 31, 42 });
	SlideDownRightAnim.loop = false;
	SlideDownRightAnim.speed = 0.1f;

	//Throw 
	Throw.PushBack({ 69, 288, 23, 35 });
	Throw.PushBack({ 92, 288, 24, 35 });
	Throw.PushBack({ 116, 288, 30, 35 });
	Throw.PushBack({ 146, 288, 28, 35 });
	Throw.PushBack({ 174, 288, 30, 35 });
	Throw.PushBack({ 204, 288, 26, 35 });
	Throw.PushBack({ 174, 288, 30, 35 });
	Throw.PushBack({ 230, 288, 22, 35 });
	Throw.loop = false;
	Throw.speed = 0.1f;

	//Holding Disk GET SPRITE WITH DIFFERENT COLOUR DISKS FOR EACH MAP -------------------

	//GET UNDERNEATH ANIMATION FOR WHEN DISK IS FALLING, 2 FRAMES ------------------

	//WON THE SET ARMS CROSSED -----------------

	//Got Scored On
	ScoredOn.PushBack({ 119, 14, 34 ,29 });

	//Scored
	Scored.PushBack({ 153, 14, 26, 29 });

	//Victory 
	victAnim.PushBack({ 179, 14, 29, 29 });
	victAnim.PushBack({ 208, 14, 31, 29 });

	HoldingAnim.PushBack({184, 288, 22, 31});
	HoldingAnim.loop = true;
	HoldingAnim.speed = 0.1f;


}

LeftGermanPlayer::~LeftGermanPlayer()
{

}

bool LeftGermanPlayer::Start()
{
	LOG("Loading player textures");

	bool ret = true;

	texture2 = App->textures->Load("Assets/Spriteswind/Sprites/CHAR2/CHAR2ALLDISKTHROW.png");
	currentAnimation = &idleAnim;
	/*App->P1Status = Player_State_Left::PLAYER_IDLE;*/

	ShotFx = App->audio->LoadFx("Assets/Sound_Effects(SFX)wind/GermanCharacter/German_3.wav");

	/*laserFx = App->audio->LoadFx("Assets/Fx/laser.wav");
	explosionFx = App->audio->LoadFx("Assets/Fx/explosion.wav");*/

	position.x = 80;
	position.y = 135;

	destroyed = false;

	collider = App->collisions->AddCollider({ position.x, position.y, 15, 40 }, Collider::Type::PLAYER, this);

	char lookupTable[] = { "0123456789" };
	scoreFontGerLeft = App->fonts->Load("Assets/Fonts/Score.png", lookupTable, 1);

	return ret;
}

Update_Status LeftGermanPlayer::Update()
{
	Movement();

	collider->SetPos(position.x, position.y);

	currentAnimation->Update();

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status LeftGermanPlayer::PostUpdate()
{
	if (!destroyed)
	{
		SDL_Rect rect = currentAnimation->GetCurrentFrame();
		App->render->Blit(texture2, position.x, position.y, &rect);
	}

	// Draw UI (score) --------------------------------------
	sprintf_s(scoreTextGerLeft, 10, "%d", scoreGerLeft);

	// TODO 3: Blit the text of the score in at the bottom of the screen
	App->fonts->BlitText(66, 8, scoreFontGerLeft, scoreTextGerLeft);

	return Update_Status::UPDATE_CONTINUE;
}

void LeftGermanPlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (c1 == collider && destroyed == false)
	{
		//App->particles->AddParticle(App->particles->explosion, position.x, position.y, Collider::Type::NONE, 9);
		//App->particles->AddParticle(App->particles->explosion, position.x + 8, position.y + 11, Collider::Type::NONE, 14);
		//App->particles->AddParticle(App->particles->explosion, position.x - 7, position.y + 12, Collider::Type::NONE, 40);
		//App->particles->AddParticle(App->particles->explosion, position.x + 5, position.y - 5, Collider::Type::NONE, 28);
		//App->particles->AddParticle(App->particles->explosion, position.x - 4, position.y - 4, Collider::Type::NONE, 21);

		/*App->audio->PlayFx(explosionFx);*/
		/*App->fade->FadeToBlack((Module*)App->turflevel, (Module*)App->sceneIntro, 60);*/

		if (position.x <= 10) {
			position.x = 10;
		}

		if (position.x >= 295 - 25) {
			position.x = 295 - 25;
		}

		if (position.y <= 40) {
			position.y = 40;
		}

		if (position.y >= 199 - 40) {
			position.y = 199 - 40;
		}
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
		position.x = 150 - 24;
	}

	if (c1->type == Collider::Type::PLAYER_SHOT && c2->type == Collider::Type::ENEMY)
	{
		scoreGerLeft += 23;
	}

	
	///Score points
	if (App->input->keys[SDL_SCANCODE_F1] == Key_State::KEY_DOWN) {
		godMode = !godMode;
	}

	if (godMode == false) {

		if (c1->type == Collider::Type::DISK && c2->type == Collider::Type::RIGHT_3P_GOAL)
		{
			scoreGerLeft += 300;
			App->rightgermanyplayer->hasDisk = true;
			App->RightJapanesePlayer->hasDisk = true;
		}

		if (c1->type == Collider::Type::DISK && c2->type == Collider::Type::RIGHT_5P_GOAL)
		{
			scoreGerLeft += 500;
			App->rightgermanyplayer->hasDisk = true;
			App->RightJapanesePlayer->hasDisk = true;
		}
	}
	else if (godMode == true) {
		if (c1->type == Collider::Type::DISK && c2->type == Collider::Type::RIGHT_3P_GOAL ||
			c1->type == Collider::Type::DISK && c2->type == Collider::Type::RIGHT_5P_GOAL)
		{
			scoreGerLeft += 0;
		}
	}

	if (c1->type == Collider::Type::DISK && c2->type == Collider::Type::UPPER_WALL)
	{
		App->particles->diskL.speed.x = 1.0f;
		App->particles->diskL.speed.y = -3.5f;
		App->particles->diskL.position.x += App->particles->diskL.speed.x;
		App->particles->diskL.position.y += App->particles->diskL.speed.y;
		Particle* newParticle = App->particles->AddParticle(App->particles->diskL, c1->rect.x, c1->rect.y, Collider::Type::DISK);
		newParticle->collider->AddListener(this);
	}

	if (c1->type == Collider::Type::DISK && c2->type == Collider::Type::LOWER_WALL)
	{
		App->particles->diskL.speed.x = 1.0f;
		App->particles->diskL.speed.y = 3.5f;
		App->particles->diskL.position.x += App->particles->diskL.speed.x;
		App->particles->diskL.position.y += App->particles->diskL.speed.y;
		Particle* newParticle = App->particles->AddParticle(App->particles->diskL, c1->rect.x, c1->rect.y, Collider::Type::DISK);
		newParticle->collider->AddListener(this);
	}
	
	if (c1->type == Collider::Type::PLAYER && c2->type == Collider::Type::DISK)
	{
		hasDisk = true;
	}
	
}

void LeftGermanPlayer::Movement() {
	if (hasDisk == false) {
		//Left Anim
		if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT)
		{
			position.x -= speed;
			if (currentAnimation != &leftAnim)
			{
				leftAnim.Reset();
				currentAnimation = &leftAnim;
			}
			/*App->P1Status = Player_State_Left::PLAYER_MOVE;*/
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
			/*App->P1Status = Player_State_Left::PLAYER_MOVE;*/
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
			/*App->P1Status = Player_State_Left::PLAYER_MOVE;*/
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
			/*App->P1Status = Player_State_Left::PLAYER_MOVE;*/
		}

		//Up Left Anim
		if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT)
		{
			position.x -= speedcross;
			position.y -= speedcross;
			/*App->P1Status = Player_State_Left::PLAYER_MOVE;*/

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
			/*App->P1Status = Player_State_Left::PLAYER_MOVE;*/

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
			/*App->P1Status = Player_State_Left::PLAYER_MOVE;*/

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
			/*App->P1Status = Player_State_Left::PLAYER_MOVE;*/

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
				SlideRAnim.Reset();
				currentAnimation = &SlideRAnim;
			}
			/*App->P1Status = Player_State_Left::PLAYER_DIVE;*/
		}

		//Up Slide Anim
		if (App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_REPEAT)
		{
			position.y -= speedslide;
			if (currentAnimation != &SlideUAnim)
			{
				SlideUAnim.Reset();
				currentAnimation = &SlideUAnim;
			}
			/*App->P1Status = Player_State_Left::PLAYER_DIVE;*/
		}

		//Left Slide Anim
		if (App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT)
		{
			/*	App->P1Status = Player_State_Left::PLAYER_DIVE;*/
			position.x -= speedslide;

			if (currentAnimation != &SlideLAnim)
			{
				SlideLAnim.Reset();
				currentAnimation = &SlideLAnim;
			}

		}

		//Down Slide Anim
		if (App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_REPEAT)
		{
			position.y += speedslide;

			if (currentAnimation != &SlideDAnim)
			{
				SlideDAnim.Reset();
				currentAnimation = &SlideDAnim;
			}
			/*	App->P1Status = Player_State_Left::PLAYER_DIVE;*/
		}

		//Up Left Slide Anim
		if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT
			&& App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_REPEAT)
		{
			position.x -= speedslide;
			position.y -= speedslide;

			if (currentAnimation != &SlideUpLeftAnim)
			{
				SlideUpLeftAnim.Reset();
				currentAnimation = &SlideUpLeftAnim;
			}
			/*App->P1Status = Player_State_Left::PLAYER_DIVE;*/
		}

		//Up Right Slide Anim
		if (App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT
			&& App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_REPEAT)
		{
			position.x += speedslide;
			position.y -= speedslide;

			if (currentAnimation != &SlideUpRightAnim)
			{
				SlideUpRightAnim.Reset();
				currentAnimation = &SlideUpRightAnim;
			}
			/*App->P1Status = Player_State_Left::PLAYER_DIVE;*/
		}

		// Down Left Slide Anim
		if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT
			&& App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_REPEAT)
		{
			position.x -= speedslide;
			position.y += speedslide;

			if (currentAnimation != &SlideDownLeftAnim)
			{
				SlideDownLeftAnim.Reset();
				currentAnimation = &SlideDownLeftAnim;
			}
			/*App->P1Status = Player_State_Left::PLAYER_DIVE;*/
		}

		// Down Right Slide Anim
		if (App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT
			&& App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_REPEAT)
		{
			position.x += speedslide;
			position.y += speedslide;
			/*App->P1Status = Player_State_Left::PLAYER_DIVE;*/

			if (currentAnimation != &SlideDownRightAnim)
			{
				SlideDownRightAnim.Reset();
				currentAnimation = &SlideDownRightAnim;
			}
		}

		//Normal Throw Animation
	}
	else if (hasDisk == true) {

		if (App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_DOWN && App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_IDLE && App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_IDLE)
		{
			if (currentAnimation != &Throw)
			{
				Throw.Reset();
				currentAnimation = &Throw;
			}
			App->particles->diskL.speed.x = 5.0f;
			App->particles->diskL.speed.y = 0.0f;
			Particle* newParticle = App->particles->AddParticle(App->particles->diskL, position.x + 20, position.y, Collider::Type::DISK);
			newParticle->collider->AddListener(this);
			hasDisk = false;
			App->audio->PlayFx(discThrowSFX);
		}

		if (App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_DOWN && App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT)
		{
			App->particles->diskL.speed.x = 1.0f;
			App->particles->diskL.speed.y = -3.5f;
			App->particles->diskL.position.x += App->particles->diskL.speed.x;
			App->particles->diskL.position.y += App->particles->diskL.speed.y;
			Particle* newParticle = App->particles->AddParticle(App->particles->diskL, position.x + 20, position.y, Collider::Type::DISK);
			newParticle->collider->AddListener(this);
			hasDisk = false;
			App->audio->PlayFx(discThrowSFX);
		}

		if (App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_DOWN && App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT)
		{
			App->particles->diskL.speed.x = 1.0f;
			App->particles->diskL.speed.y = 3.5f;
			App->particles->diskL.position.x += App->particles->diskL.speed.x;
			App->particles->diskL.position.y += App->particles->diskL.speed.y;
			Particle* newParticle = App->particles->AddParticle(App->particles->diskL, position.x + 20, position.y, Collider::Type::DISK);
			newParticle->collider->AddListener(this);
			hasDisk = false;
			App->audio->PlayFx(discThrowSFX);
		}
	}

	if (App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_V] == Key_State::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_IDLE /*&&
		App->P1Status != Player_State_Left::PLAYER_HOLD
		&& App->P1Status != Player_State_Left::PLAYER_MOVE
		&& App->P1Status != Player_State_Left::PLAYER_THROW
		&& App->P1Status != Player_State_Left::PLAYER_DIVE*/) {
		currentAnimation = &idleAnim;
		/*App->P1Status = Player_State_Left::PLAYER_IDLE;*/
	}
}