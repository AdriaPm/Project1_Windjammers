#include "Application.h"
#include "Disc.h"

#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollisions.h"

Disc::Disc(bool startEnabled) : Module(startEnabled)
{
	
}

Disc::~Disc()
{
	if (collider != nullptr)
		collider->pendingToDelete = true;
}

bool Disc::Start()
{
	LOG("Loading Disc");
	texture = App->textures->Load("Assets/Spriteswind/Sprites/TURF_SPRITES/sprite_disk_lawnMap.png");

	anim.PushBack({ 117, 48, 17, 17 });
	anim.PushBack({ 149, 48, 17, 17 });
	anim.PushBack({ 181, 48, 17, 17 });
	anim.PushBack({ 213, 48, 17, 17 });
	speed.x = 5;
	anim.speed = 0.2f;


	return true;
}

Update_Status Disc::PreUpdate()
{
	

	return Update_Status::UPDATE_CONTINUE;
}

bool Disc::CleanUp()
{

	return true;
}

void Disc::OnCollision(Collider* c1, Collider* c2)
{
	//for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	//{
	//	// Always destroy particles that collide
	//	if (particles[i] != nullptr && particles[i]->collider == c1) //&& !particles[i]->collider->DISK
	//	{
	//		particles[i]->pendingToDelete = true;
	//		particles[i]->collider->pendingToDelete = true;
	//		break;
	//	}
	//}
}

Update_Status Disc::Update()
{
	


	return Update_Status::UPDATE_CONTINUE;
}

Update_Status Disc::PostUpdate()
{
	if (isAlive == true)
	{
		App->render->Blit(texture, position.x, position.y, &anim.GetCurrentFrame());
	}

	return Update_Status::UPDATE_CONTINUE;
}

//Disc* Disc::AddParticle(const Disc& particle, int x, int y, Collider::Type colliderType, uint delay)
//{
//	Particle* newParticle = nullptr;
//
//	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
//	{
//		//Finding an empty slot for a new particle
//		if (particles[i] == nullptr)
//		{
//			newParticle = new Particle(particle);
//			newParticle->frameCount = -(int)delay;			// We start the frameCount as the negative delay
//			newParticle->position.x = x;						// so when frameCount reaches 0 the particle will be activated
//			newParticle->position.y = y;
//
//			//Adding the particle's collider
//			if (colliderType != Collider::Type::NONE)
//				newParticle->collider = App->collisions->AddCollider(newParticle->anim.GetCurrentFrame(), colliderType, this);
//
//			particles[i] = newParticle;
//			break;
//		}
//	}
//
//	return newParticle;
//}