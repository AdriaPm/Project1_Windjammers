#include "RightGermanPlayer.h"
#include "Left_Japanese_Player.h"
#include "Right_Japanese_Player.h"
#include "LeftGermanPlayer.h"
#include "LeftEnglishPlayer.h"
#include "RightEnglishPlayer.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFonts.h"
#include "UI.h"
#include "SDL/include/SDL.h"

#include <stdio.h>

#define initialXPos 240
#define initialYPos 105

RightGermanPlayer::RightGermanPlayer(bool startEnabled) : Module(startEnabled)
{
	// idle animation
	idleAnim.PushBack({ 47, 324, 24, 34 });
	idleAnim.PushBack({ 24, 324, 23, 36 });
	idleAnim.PushBack({ 1, 324, 23, 35 });
	idleAnim.PushBack({ 1, 324, 23, 35 });
	idleAnim.PushBack({ 24, 324, 23, 36 });
	idleAnim.PushBack({ 47, 324, 24, 34 });
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
	SlideLAnim.PushBack({ 224, 239, 31, 31 });
	SlideLAnim.PushBack({ 139, 239, 29, 31 });
	SlideLAnim.PushBack({ 107, 239, 32, 31 });
	SlideLAnim.loop = false;
	SlideLAnim.speed = 1.0f;

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
	SlideUAnim.PushBack({ 149, 188, 31, 50 });
	SlideUAnim.loop = false;
	SlideUAnim.speed = 0.1f;


	//Slide Down
	SlideDAnim.PushBack({ 29, 239, 24, 49 });
	SlideDAnim.PushBack({ 1, 239, 28, 49 }); 
	SlideDAnim.PushBack({ 84, 239, 23, 49 });
	SlideDAnim.PushBack({ 53, 239, 31, 49 });
	SlideDAnim.loop = false;
	SlideDAnim.speed = 10.0f;


	//Slide Up Right
	SlideUpRightAnim.PushBack({ 68, 140, 39, 48 });
	SlideUpRightAnim.PushBack({ 38, 140, 30, 48 });
	SlideUpRightAnim.PushBack({ 1, 140, 37, 48 });
	SlideUpRightAnim.PushBack({ 213, 92, 26, 42 });
	SlideUpRightAnim.loop = false;
	SlideUpRightAnim.speed = 0.5f;


	//Slide Up Left
	SlideUpLeftAnim.PushBack({ 31, 91, 40, 49 });
	SlideUpLeftAnim.PushBack({ 1, 91, 30, 49 });
	SlideUpLeftAnim.PushBack({ 219, 53, 37, 35 });
	SlideUpLeftAnim.PushBack({ 191, 53, 28, 35 });
	SlideUpLeftAnim.PushBack({ 107, 238, 32, 31 });
	SlideUpLeftAnim.loop = false;
	SlideUpLeftAnim.speed = 0.5f;


	//Slide Down Left
	SlideDownLeftAnim.PushBack({ 168, 92, 45, 42 });
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
	SlideDownRightAnim.speed = 0.1f;
	SlideDownRightAnim.loop = false;

	//Throw 

	Throw.PushBack({ 161, 288, 23, 35 });
	Throw.PushBack({ 137, 288, 24, 35 });
	Throw.PushBack({ 107, 288, 30, 35 });
	Throw.PushBack({ 79, 288, 28, 35 });
	Throw.PushBack({ 49, 288, 30, 35 });
	Throw.PushBack({ 23, 288, 26, 35 });
	Throw.PushBack({ 49, 288, 30, 35 });
	Throw.PushBack({ 79, 288, 28, 35 });
	Throw.PushBack({ 1, 288, 22, 35 });
	Throw.loop = false;
	Throw.speed = 1.0f;

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

	HoldingAnim.PushBack({ 161, 287, 23, 36 });
	HoldingAnim.PushBack({ 137, 287, 24, 36 });
	HoldingAnim.loop = true;
	HoldingAnim.speed = 0.1f;

	//SHADOW EFFECT
	shadowAnim.PushBack({ 0,0,31,31 });
	shadowAnim.PushBack({ 0,31,31,31 });
	shadowAnim.loop = true;
	shadowAnim.speed = 0.3f;
}

RightGermanPlayer::~RightGermanPlayer()
{

}

bool RightGermanPlayer::Start()
{
	LOG("Loading player textures");

	bool ret = true;

	shadowTexture = App->textures->Load("Assets/Spriteswind/Particles/Shadow_spritesheet.png");
	
	texture2 = App->textures->Load("Assets/Spriteswind/Sprites/CHAR2/CHAR2ALLRIGHTDISKTHROW.png");


	currentAnimation = &idleAnim;

	t1 = SDL_GetTicks();

	/*laserFx = App->audio->LoadFx("Assets/Fx/laser.wav");
	explosionFx = App->audio->LoadFx("Assets/Fx/explosion.wav");*/

	ShotFx = App->audio->LoadFx("Assets/Sound_Effects(SFX)wind/GermanCharacter/German_3.wav");
	slidingSFX = App->audio->LoadFx("Assets/Sound_Effects(SFX)wind/Sliding.wav");
	discThrowSFX = App->audio->LoadFx("Assets/Sound_Effects(SFX)wind/Disc/Throwing_1.wav");
	diskCollisionSFX = App->audio->LoadFx("Assets/Sound_Effects(SFX)wind/Disc/WallCollision.wav");
	goalSFX = App->audio->LoadFx("Assets/Sound_Effects(SFX)wind/Disc/Goal.wav");
	crowdGoalSFX = App->audio->LoadFx("Assets/Sound_Effects(SFX)wind/Crowd/Crowd1.wav");
	crowdWinSFX = App->audio->LoadFx("Assets/Sound_Effects(SFX)wind/Crowd/CrowdWin.wav");

	referee3ptsSFX = App->audio->LoadFx("Assets/Sound_Effects(SFX)wind/Referee/ThreePoints.wav");
	referee5ptsSFX = App->audio->LoadFx("Assets/Sound_Effects(SFX)wind/Referee/FivePoints.wav");

	position.x = initialXPos;
	position.y = initialYPos;

	destroyed = false;

	collider = App->collisions->AddCollider({ position.x, position.y, 15, 40 }, Collider::Type::PLAYER, this);

	

	return ret;
}

Update_Status RightGermanPlayer::Update()
{
	Movement();
	//Left Anim

	// If no up/down left/right movement detected, set the current animation back to idle


	collider->SetPos(position.x, position.y);

	currentAnimation->Update();
	shadowAnim.Update();
	

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status RightGermanPlayer::PostUpdate()
{
	if (!destroyed)
	{
		SDL_Rect shadowRect = shadowAnim.GetCurrentFrame();
		App->render->Blit(shadowTexture, position.x + 3, position.y + 20, &shadowRect);
		SDL_Rect rect = currentAnimation->GetCurrentFrame();
		App->render->Blit(texture2, position.x, position.y, &rect);
	
	}

	

	return Update_Status::UPDATE_CONTINUE;
}

void RightGermanPlayer::OnCollision(Collider* c1, Collider* c2)
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
		position.x = 150 + 4;
	}

	if (c1->type == Collider::Type::DISK && c2->type == Collider::Type::ENEMY)
	{
		scoreGerRight += 23;
	}

	if (c1->type == Collider::Type::DISK && c2->type == Collider::Type::PLAYER)
	{
		App->particles->diskR.HasDiskR == true;
	}

	if (godMode == false) {

		if (c1->type == Collider::Type::DISK && c2->type == Collider::Type::LEFT_3P_GOAL)
		{
			App->ui->rightScore += 300;
			App->ui->counterRightScore += 3;
			Particle* goalscoredleft = App->particles->AddParticle(App->particles->goalscoredleft, c1->rect.x, c1->rect.y - 10, Collider::Type::NONE);
			App->leftgermanyplayer->hasDisk = true;
			App->LeftJapanesePlayer->hasDisk = true;

			App->audio->PlayFx(goalSFX);
			App->audio->PlayFx(crowdGoalSFX);
			App->audio->PlayFx(referee3ptsSFX);

			position.x = initialXPos;
			position.y = initialYPos;
			App->leftgermanyplayer->position.x = 50;
			App->leftgermanyplayer->position.y = 105;

			App->LeftJapanesePlayer->position.x = 50;
			App->LeftJapanesePlayer->position.y = 105;

			App->leftenglishplayer->position.x = 50;
			App->leftenglishplayer->position.y = 105;
		}
		else if (c1->type == Collider::Type::DISK && c2->type == Collider::Type::LEFT_5P_GOAL)
		{
			App->ui->rightScore += 500;
			App->ui->counterRightScore += 5;
			Particle* goalscoredleft = App->particles->AddParticle(App->particles->goalscoredleft, c1->rect.x, c1->rect.y - 10, Collider::Type::NONE);
			App->leftgermanyplayer->hasDisk = true;
			App->LeftJapanesePlayer->hasDisk = true;

			App->audio->PlayFx(goalSFX);
			App->audio->PlayFx(crowdGoalSFX);
			App->audio->PlayFx(referee5ptsSFX);

			position.x = initialXPos;
			position.y = initialYPos;
			App->leftgermanyplayer->position.x = 50;
			App->leftgermanyplayer->position.y = 105;

			App->LeftJapanesePlayer->position.x = 50;
			App->LeftJapanesePlayer->position.y = 105;

			App->leftenglishplayer->position.x = 50;
			App->leftenglishplayer->position.y = 105;
		}
	}
	else if (godMode == true) {
		if (c1->type == Collider::Type::DISK && c2->type == Collider::Type::LEFT_3P_GOAL ||
			c1->type == Collider::Type::DISK && c2->type == Collider::Type::LEFT_5P_GOAL)
		{
			App->ui->rightScore += 0;

			App->audio->PlayFx(goalSFX);
			App->audio->PlayFx(crowdGoalSFX);
		}
	}

	if (c1->type == Collider::Type::DISK && c2->type == Collider::Type::UPPER_WALL)
	{
		App->particles->diskR.speed.x = -1.0f;
		App->particles->diskR.speed.y = 3.5f;
		App->particles->diskR.position.x += App->particles->diskR.speed.x;
		App->particles->diskR.position.y += App->particles->diskR.speed.y;
		Particle* newParticle = App->particles->AddParticle(App->particles->diskR, c1->rect.x, c1->rect.y, Collider::Type::DISK);
		newParticle->collider->AddListener(this);
		Particle* newParticleBounceTop = App->particles->AddParticle(App->particles->caught, c1->rect.x, c1->rect.y, Collider::Type::NONE);
		App->audio->PlayFx(diskCollisionSFX);
	}

	if (c1->type == Collider::Type::DISK && c2->type == Collider::Type::LOWER_WALL)
	{
		App->particles->diskR.speed.x = -1.0f;
		App->particles->diskR.speed.y = -3.5f;
		App->particles->diskR.position.x += App->particles->diskR.speed.x;
		App->particles->diskR.position.y += App->particles->diskR.speed.y;
		Particle* newParticle = App->particles->AddParticle(App->particles->diskR, c1->rect.x, c1->rect.y, Collider::Type::DISK);
		newParticle->collider->AddListener(this);
		App->audio->PlayFx(diskCollisionSFX);
	}
	
	if (c1->type == Collider::Type::PLAYER && c2->type == Collider::Type::DISK)
	{
		hasDisk = true;
	}

}


void RightGermanPlayer::Movement() {
	
	if (hasDisk == false) {
		if (App->input->keys[SDL_SCANCODE_LEFT] == Key_State::KEY_REPEAT)
		{
			position.x -= speed;
			if (currentAnimation != &leftAnim)
			{
				leftAnim.Reset();
				currentAnimation = &leftAnim;
			}
			/*App->P2Status = Player_State_Right::PLAYER_MOVE;*/
		}

		//Right Anim
		if (App->input->keys[SDL_SCANCODE_RIGHT] == Key_State::KEY_REPEAT)
		{
			position.x += speed;
			if (currentAnimation != &rightAnim)
			{
				rightAnim.Reset();
				currentAnimation = &rightAnim;
			}
			/*App->P2Status = Player_State_Right::PLAYER_MOVE;*/
		}

		//Down Anim
		if (App->input->keys[SDL_SCANCODE_DOWN] == Key_State::KEY_REPEAT)
		{
			position.y += speed;
			if (currentAnimation != &downAnim)
			{
				downAnim.Reset();
				currentAnimation = &downAnim;
			}
			/*App->P2Status = Player_State_Right::PLAYER_MOVE;*/
		}

		//Up Anim
		if (App->input->keys[SDL_SCANCODE_UP] == Key_State::KEY_REPEAT)
		{
			position.y -= speed;
			if (currentAnimation != &upAnim)
			{
				upAnim.Reset();
				currentAnimation = &upAnim;
			}
			/*App->P2Status = Player_State_Right::PLAYER_MOVE;*/
		}

		//Up Left Anim
		if (App->input->keys[SDL_SCANCODE_LEFT] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_UP] == Key_State::KEY_REPEAT)
		{
			position.x -= speedcross;
			position.y -= speedcross;
			App->P2Status = Player_State_Right::PLAYER_MOVE;

			if (currentAnimation != &UpLeftAnim)
			{
				
				currentAnimation = &UpLeftAnim;
			}

		}

		//Up Right Anim
		if (App->input->keys[SDL_SCANCODE_RIGHT] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_UP] == Key_State::KEY_REPEAT)
		{
			position.x += speedcross;
			position.y -= speedcross;

			if (currentAnimation != &UpRightAnim)
			{
				
				currentAnimation = &UpRightAnim;
				
			}
			/*App->P2Status = Player_State_Right::PLAYER_MOVE;*/
		}


		// Down Left Anim
		if (App->input->keys[SDL_SCANCODE_DOWN] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_LEFT] == Key_State::KEY_REPEAT)
		{
			position.x -= speedcross;
			position.y += speedcross;

			if (currentAnimation != &DownLeftAnim)
			{
				
				currentAnimation = &DownLeftAnim;
			}
			/*App->P2Status = Player_State_Right::PLAYER_MOVE;*/
		}

		// Down Right Anim
		if (App->input->keys[SDL_SCANCODE_DOWN] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_RIGHT] == Key_State::KEY_REPEAT)
		{
			position.x += speedcross;
			position.y += speedcross;

			if (currentAnimation != &DownRightAnim)
			{
				
				currentAnimation = &DownRightAnim;
			}
			/*App->P2Status = Player_State_Right::PLAYER_MOVE;*/
		}


		while (App->input->keys[SDL_SCANCODE_N] == Key_State::KEY_REPEAT) {
			inslide = true;
		}
	}

	else if (hasDisk == true) {

		currentAnimation = &HoldingAnim;	

		if (App->input->keys[SDL_SCANCODE_N] == Key_State::KEY_DOWN && App->input->keys[SDL_SCANCODE_UP] == Key_State::KEY_IDLE && App->input->keys[SDL_SCANCODE_DOWN] == Key_State::KEY_IDLE)
		{
			currentAnimation = &Throw;
				
			App->particles->diskR.speed.x = -5.0f;
			App->particles->diskR.speed.y = 0.0f;
			Particle* newParticle = App->particles->AddParticle(App->particles->diskR, position.x - 20, position.y, Collider::Type::DISK);
			newParticle->collider->AddListener(this);
			hasDisk = false;
			App->audio->PlayFx(discThrowSFX);
		}

		if (App->input->keys[SDL_SCANCODE_N] == Key_State::KEY_DOWN && App->input->keys[SDL_SCANCODE_UP] == Key_State::KEY_REPEAT)
		{
			App->particles->diskR.speed.x = -1.0f;
			App->particles->diskR.speed.y = -3.5f;
			App->particles->diskR.position.x += App->particles->diskR.speed.x;
			App->particles->diskR.position.y += App->particles->diskR.speed.y;
			Particle* newParticle = App->particles->AddParticle(App->particles->diskR, position.x - 20, position.y, Collider::Type::DISK);
			newParticle->collider->AddListener(this);
			hasDisk = false;
			App->audio->PlayFx(discThrowSFX);
		}

		if (App->input->keys[SDL_SCANCODE_N] == Key_State::KEY_DOWN && App->input->keys[SDL_SCANCODE_DOWN] == Key_State::KEY_REPEAT)
		{
			App->particles->diskR.speed.x = -1.0f;
			App->particles->diskR.speed.y = 3.5f;
			App->particles->diskR.position.x += App->particles->diskR.speed.x;
			App->particles->diskR.position.y += App->particles->diskR.speed.y;
			Particle* newParticle = App->particles->AddParticle(App->particles->diskR, position.x - 20, position.y, Collider::Type::DISK);
			newParticle->collider->AddListener(this);
			hasDisk = false;
			App->audio->PlayFx(discThrowSFX);
		}
	}

	if (App->input->keys[SDL_SCANCODE_DOWN] == Key_State::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_UP] == Key_State::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_RIGHT] == Key_State::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_LEFT] == Key_State::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_N] == Key_State::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_M] == Key_State::KEY_IDLE
		&& hasDisk != true){/*&&
		App->P2Status != Player_State_Right::PLAYER_HOLD
		&& App->P2Status != Player_State_Right::PLAYER_MOVE
		&& App->P2Status != Player_State_Right::PLAYER_THROW
		&& App->P2Status != Player_State_Right::PLAYER_DIVE*/ {
		currentAnimation = &idleAnim;
		}

		/*App->P2Status = Player_State_Right::PLAYER_IDLE;*/
	}

	if (inslide == true) {

		if (App->input->keys[SDL_SCANCODE_RIGHT] == Key_State::KEY_REPEAT)
		{
			position.x += speedslide;
			currentAnimation = &SlideRAnim;
			
		}

		//Up Slide Anim
		if (App->input->keys[SDL_SCANCODE_UP] == Key_State::KEY_REPEAT) {
			position.y -= speedslide;

			if (currentAnimation != &SlideUAnim)
			{
				SlideUAnim.Reset();
				currentAnimation = &SlideUAnim;
			}
		
		}

		//Left Slide Anim
		if (App->input->keys[SDL_SCANCODE_LEFT] == Key_State::KEY_REPEAT)
		{
			/*App->P2Status = Player_State_Right::PLAYER_DIVE;*/
			position.x -= speedslide;

			if (currentAnimation != &SlideLAnim)
			{
				SlideLAnim.Reset();
				currentAnimation = &SlideLAnim;
			}
		
		}

		//Down Slide Anim
		if (App->input->keys[SDL_SCANCODE_DOWN] == Key_State::KEY_REPEAT)
		{
			/*position.y += speedslide;*/
				SlideDAnim.Reset();
				currentAnimation = &SlideDAnim;
			
			/*App->P2Status = Player_State_Right::PLAYER_DIVE;*/
		}

		//Up Left Slide Anim
		if (App->input->keys[SDL_SCANCODE_LEFT] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_UP] == Key_State::KEY_REPEAT)
		{
			position.x -= speedcross;
			position.y -= speedcross;

			if (currentAnimation != &SlideUpLeftAnim)
			{
				SlideUpLeftAnim.Reset();
				currentAnimation = &SlideUpLeftAnim;
			}
			
		}

		//Up Right Slide Anim
		if (App->input->keys[SDL_SCANCODE_RIGHT] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_UP] == Key_State::KEY_REPEAT)
		{
			position.x += speedcross;
			position.y -= speedcross;

			if (currentAnimation != &SlideUpRightAnim)
			{
				SlideUpRightAnim.Reset();
				currentAnimation = &SlideUpRightAnim;
			}
			
			/*App->P2Status = Player_State_Right::PLAYER_DIVE;*/
		}

		// Down Left Slide Anim
		if (App->input->keys[SDL_SCANCODE_LEFT] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_DOWN] == Key_State::KEY_REPEAT)
		{
			position.x -= speedcross;
			position.y += speedcross;

			if (currentAnimation != &SlideDownLeftAnim)
			{
				SlideDownLeftAnim.Reset();
				currentAnimation = &SlideDownLeftAnim;
			}
			
		}

		// Down Right Slide Anim
		if (App->input->keys[SDL_SCANCODE_RIGHT] == Key_State::KEY_REPEAT && App->input->keys[SDL_SCANCODE_DOWN] == Key_State::KEY_REPEAT)
		{
			position.x += speedcross;
			position.y += speedcross;

			if (currentAnimation != &SlideDownRightAnim)
			{
				SlideDownRightAnim.Reset();
				currentAnimation = &SlideDownRightAnim;
			}
		}

	/*	if (App->input->keys[SDL_SCANCODE_RIGHT] != Key_State::KEY_REPEAT &&
			App->input->keys[SDL_SCANCODE_LEFT] != Key_State::KEY_REPEAT &&
			App->input->keys[SDL_SCANCODE_UP] != Key_State::KEY_REPEAT &&
			App->input->keys[SDL_SCANCODE_DOWN] != Key_State::KEY_REPEAT
			&& inslide == true) {
			
			
		}*/
	}

	if (isDefeated == true) {
		currentAnimation = &ScoredOn;
		App->leftgermanyplayer->isCelebrating = true;
		if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN) {
			isDefeated = false;
			currentAnimation = &HoldingAnim;
		}
	}

	if (isCelebrating == true) {
		currentAnimation = &victAnim;
		App->leftgermanyplayer->isDefeated = true;
			if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN) {
				isCelebrating = false;
				currentAnimation = &idleAnim;
			}
	}
}

