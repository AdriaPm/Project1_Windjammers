#include "ModuleParticles.h"

#include "Application.h"

#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollisions.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles(bool startEnabled) : Module(startEnabled)
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		particles[i] = nullptr;
}

ModuleParticles::~ModuleParticles()
{

}

bool ModuleParticles::Start()
{
	LOG("Loading particles");
	texture_disk = App->textures->Load("Assets/Spriteswind/Sprites/TURF_SPRITES/sprite_disk_lawnMap.png");
	texture_particles = App->textures->Load("Assets/Spriteswind/Particles/particlesAndEffects.png");
	//texture = App->textures->Load("Assets/Sprites/particles.png");
	textureFX = App->textures->Load("Assets/Spriteswind/Particles/particlesAndEffects.png");

	//// Explosion particle
	//explosion.anim.PushBack({274, 296, 33, 30});
	//explosion.anim.PushBack({313, 296, 33, 30});
	//explosion.anim.PushBack({346, 296, 33, 30});
	//explosion.anim.PushBack({382, 296, 33, 30});
	//explosion.anim.PushBack({419, 296, 33, 30});
	//explosion.anim.PushBack({457, 296, 33, 30});
	//explosion.anim.loop = false;
	//explosion.anim.speed = 0.3f;

	//laser.anim.PushBack({ 232, 103, 16, 12 });
	//laser.anim.PushBack({ 249, 103, 16, 12 });
	//laser.speed.x = 5;
	//laser.lifetime = 180;
	//laser.anim.speed = 0.2f;

	diskL.anim.PushBack({ 117, 48, 17, 17});
	diskL.anim.PushBack({ 149, 48, 17, 17});
	diskL.anim.PushBack({ 181, 48, 17, 17});
	diskL.anim.PushBack({ 213, 48, 17, 17});
	diskL.lifetime = 1000;
	diskL.speed.x = 5;
	diskL.anim.speed = 0.2f;

	diskR.anim.PushBack({ 117, 48, 17, 17 });
	diskR.anim.PushBack({ 149, 48, 17, 17 });
	diskR.anim.PushBack({ 181, 48, 17, 17 });
	diskR.anim.PushBack({ 213, 48, 17, 17 });
	diskR.lifetime = 1000;
	diskR.speed.x = -5;
	diskR.anim.speed = 0.2f;

	wallCollision.anim.PushBack({ 232, 142, 58, 51});
	wallCollision.anim.speed = 0.1f;
	wallCollision.lifetime = 500;

	caught.anim.PushBack({ 232, 202, 70, 69 });
	caught.lifetime = 3;
	caught.speed.x = 0;
	caught.anim.speed = 0.2f;

	goalscoredleft.anim.PushBack({ 4, 192, 41, 77 });
	goalscoredleft.anim.PushBack({ 42, 192, 51, 81 });
	goalscoredleft.anim.PushBack({ 92, 191, 42, 86 });
	goalscoredleft.anim.PushBack({ 134, 191, 54, 79 });
	goalscoredleft.lifetime = 15;
	goalscoredleft.speed.x = 0;
	goalscoredleft.anim.speed = 0.1f;

	goalscoredright.anim.PushBack({ 251, 285, 46, 68 });
	goalscoredright.anim.PushBack({ 204, 280, 49, 79 });
	goalscoredright.anim.PushBack({ 157, 280, 49, 79 });
	goalscoredright.anim.PushBack({ 110, 280, 45, 79 });
	goalscoredright.lifetime = 15;
	goalscoredright.speed.x = 0;
	goalscoredright.anim.speed = 0.1f;



	return true;
}

Update_Status ModuleParticles::PreUpdate()
{
	// Remove all particles scheduled for deletion
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (particles[i] != nullptr && particles[i]->pendingToDelete)
		{
			delete particles[i];
			particles[i] = nullptr;
		}
	}

	return Update_Status::UPDATE_CONTINUE;
}

bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");

	// Delete all remaining active particles on application exit 
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if(particles[i] != nullptr)
		{
			delete particles[i];
			particles[i] = nullptr;
		}
	}

	return true;
}

void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		// Always destroy particles that collide
		if (particles[i] != nullptr && particles[i]->collider == c1) //&& !particles[i]->collider->DISK
		{
			particles[i]->pendingToDelete = true;
			particles[i]->collider->pendingToDelete = true;
			break;
		}
	}
}

Update_Status ModuleParticles::Update()
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* particle = particles[i];

		if(particle == nullptr)	continue;

		// Call particle Update. If it has reached its lifetime, destroy it
		if(particle->Update() == false)
		{
			particles[i]->SetToDelete();
		}
	}

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModuleParticles::PostUpdate()
{
	//Iterating all particle array and drawing any active particles
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* particle = particles[i];

		if (particle != nullptr && particle->isAlive)
		{
			App->render->Blit(texture_particles, particle->position.x, particle->position.y, &(particle->anim.GetCurrentFrame()));
			App->render->Blit(texture_disk, particle->position.x, particle->position.y, &(particle->anim.GetCurrentFrame()));
		}
	}

	return Update_Status::UPDATE_CONTINUE;
}

Particle* ModuleParticles::AddParticle(const Particle& particle, int x, int y, Collider::Type colliderType, uint delay)
{
	Particle* newParticle = nullptr;

	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		//Finding an empty slot for a new particle
		if (particles[i] == nullptr)
		{
			newParticle = new Particle(particle);
			newParticle->frameCount = -(int)delay;			// We start the frameCount as the negative delay
			newParticle->position.x = x;						// so when frameCount reaches 0 the particle will be activated
			newParticle->position.y = y;

			//Adding the particle's collider
			if (colliderType != Collider::Type::NONE)
				newParticle->collider = App->collisions->AddCollider(newParticle->anim.GetCurrentFrame(), colliderType, this);

			particles[i] = newParticle;
			break;
		}
	}

	return newParticle;
}