#ifndef __ChooseMap_H__
#define __ChooseMap_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

enum MapType
{
	Turf,
	Beach,
	Clay,
};

class ChooseMap : public Module
{
public:
	ChooseMap(bool startEnabled);

	~ChooseMap();

	bool Start() override;

	Update_Status Update() override;

	Update_Status PostUpdate() override;

public:
	SDL_Texture* chooseMapTexture = nullptr;
	SDL_Texture* selectMap = nullptr;
	SDL_Texture* mapNames = nullptr;
	SDL_Texture* turfImg = nullptr;
	SDL_Texture* beachImg = nullptr;
	SDL_Texture* clayImg = nullptr;

	//Animation remark;
	SDL_Rect remark;

private:
	int yMove, x1, x2, x3;

};


#endif