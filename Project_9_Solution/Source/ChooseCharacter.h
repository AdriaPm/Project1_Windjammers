#ifndef __ChooseCharacter_H__
#define __ChooseCharacter_H__

#define MaxCharacters 3

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

enum CharacterType
{

};

class ChooseCharacter : public Module
{
public:
	ChooseCharacter(bool startEnabled);

	~ChooseCharacter();

	bool Start() override;

	Update_Status Update() override;

	Update_Status PostUpdate() override;

public:
	SDL_Texture* chooseCharacterTexture = nullptr;
	SDL_Texture* selectCharacter = nullptr;
};

#endif