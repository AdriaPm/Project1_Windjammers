#ifndef __TUTORIAL_SCENE_H__
#define __TUTORIAL_SCENE_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class TutorialScene : public Module
{
public:
	//Constructor
	TutorialScene(bool startEnabled);

	//Destructor
	~TutorialScene();

	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start() override;

	// Called at the middle of the application loop
	// Updates the scene's background animations
	Update_Status Update() override;

	// Called at the end of the application loop.
	// Performs the render call of all the parts of the scene's background
	Update_Status PostUpdate() override;

public:
	// The scene sprite sheet loaded into an SDL_Texture
	SDL_Texture* bgTexture = nullptr; 
	SDL_Texture* buttonsTexture = nullptr;
	SDL_Texture* characterTexture = nullptr;

	Animation* currentAnimation = nullptr;

	// Character set of animations
	Animation idleAnim;
	Animation upAnim;
	Animation downAnim;
	Animation rightAnim;
	Animation leftAnim;
	Animation SlideLAnim;
	Animation SlideRAnim;
	Animation SlideUAnim;
	Animation SlideDAnim;
	

	Animation* currentAnimationButtons = nullptr;
	// Buttons set of animations
	Animation ButtonsidleAnim;
	Animation ButtonsupAnim;
	Animation ButtonsdownAnim;
	Animation ButtonsrightAnim;
	Animation ButtonsleftAnim;
	Animation ButtonsUpRightAnim;
	Animation ButtonsDownLeftAnim;
	Animation ButtonsUpLeftAnim;
	Animation ButtonsSlideLAnim;
	Animation ButtonsSlideRAnim;
	Animation ButtonsSlideUAnim;
	Animation ButtonsSlideDAnim;
};

#endif