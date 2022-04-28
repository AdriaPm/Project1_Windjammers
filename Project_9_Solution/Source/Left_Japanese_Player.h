#ifndef __MODULE_PLAYER_H__
#define __MODULE_PLAYER_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;
struct Collider;

class Left_Japanese_Player : public Module
{
public:
	// Constructor
	Left_Japanese_Player(bool startEnabled);

	// Destructor
	~Left_Japanese_Player();

	// Called when the module is activated
	// Loads the necessary textures for the player
	bool Start() override;

	// Called at the middle of the application loop
	// Processes new input and handles player movement
	Update_Status Update() override;

	// Called at the end of the application loop
	// Performs the render call of the player sprite
	Update_Status PostUpdate() override;

	// Collision callback, called when the player intersects with another collider
	void OnCollision(Collider* c1, Collider* c2) override;

	uint getScoreL(){return scoreLeft;}

	void Movement();

public:
	// Position of the player in the map
	iPoint position;

	// The speed in which we move the player (pixels per frame)
	int speed = 1;
	int speedslide = 0.75;
	int speedcross = 0.25;

	// The player spritesheet loaded into an SDL_Texture
	SDL_Texture* texture = nullptr;
	
	// The pointer to the current player animation
	// It will be switched depending on the player's movement direction
	Animation* currentAnimation = nullptr;

	// A set of animations
	Animation idleAnim;
	Animation upAnim;
	Animation downAnim;
	Animation rightAnim;
	Animation leftAnim;
	Animation victAnim;
	Animation loseAnim;
	Animation SlideLAnim;
	Animation SlideRAnim;
	Animation SlideUAnim;
	Animation SlideDAnim;
	Animation UpRightAnim;
	Animation UpLeftAnim;
	Animation DownRightAnim;
	Animation DownLeftAnim;
	Animation SlideUpLeftAnim;
	Animation SlideUpRightAnim;
	Animation SlideDownRightAnim;
	Animation SlideDownLeftAnim;
	Animation Throw;
	Animation ScoredOn;
	Animation Scored;
	Animation diskHoldBEACH;

	// The player's collider
	Collider* collider = nullptr;

	// A flag to detect when the player has been destroyed
	bool destroyed = false;

	// Sound effects indices
	uint slidingSFX = 0;
	uint discThrowSFX = 0;

	// Font score index
	uint scoreLeft = 000;
	int scoreFontLeft = -1;
	char scoreTextLeft[10] = { "\0" };

	uint counter = 00;
	int counterFont = -1;
	char counterText[5] = { "\0" };

	//Detect if has disc
	bool hasDisc = true;
};

#endif //!__MODULE_PLAYER_H__