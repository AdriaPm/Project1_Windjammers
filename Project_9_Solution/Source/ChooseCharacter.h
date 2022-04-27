#ifndef __ChooseCharacter_H__
#define __ChooseCharacter_H__

#define MaxCharacters 3

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

enum CharacterType
{
	Japanese,
	German,
	Spanish,
};

enum Player_Confirm {
	OneYes,
	TwoYes
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
	int player1conf;
	int player2conf;
	SDL_Texture* chooseCharacterTexture = nullptr;
	SDL_Texture* playerIcon = nullptr;

	Animation* currentAnimation1 = nullptr;
	Animation* currentAnimation2 = nullptr;

	Animation p1;
	Animation p2;

	void inccheck1() {
		firstcheck++;
	}

	void inccheck2() {
		secondcheck++;
	}

	int returncheck() {
		return firstcheck;
	}

	int returncheck2() {
		return secondcheck;
	}



private:
	int firstcheck = 0;
	int secondcheck = 0;
	int yMove1, xMove1, yMove2, xMove2;
};

#endif