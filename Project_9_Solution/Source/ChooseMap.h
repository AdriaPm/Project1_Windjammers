#ifndef __ChooseMap_H__
#define __ChooseMap_H__

#define NumMaps 3

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

	Animation remark;
};


#endif