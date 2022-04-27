#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"


#define NUM_MODULES 20



class Module;
class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleAudio;
class Left_Japanese_Player;
class SceneIntro;
class DataEast;
class MainScreen;
class TutorialScene;
class TurfLevel;
class ClayModule;
class ModuleParticles;
class ModuleCollisions;
class ModuleEnemies;
class ModuleFadeToBlack;
class ModuleFonts;
class ModuleRender;
class LeftGermanPlayer;
class ChooseMap;
class ChooseCharacter;


class Application
{

public:

	//Constructor. Creates all necessary modules for the application
	Application();

	//Destructor. Removes all module objects
	~Application();

	//Initializes all modules
	bool Init();

	//Updates all modules (PreUpdate, Update and PostUpdate)
	Update_Status Update();

	//Releases all the application data
	bool CleanUp();

public:
	// An array to store all modules
	Module* modules[NUM_MODULES];

	// All the modules stored individually
	ModuleWindow* window = nullptr;
	ModuleInput* input = nullptr;
	ModuleTextures* textures = nullptr;
	ModuleAudio* audio = nullptr;

	Left_Japanese_Player* LeftJapanesePlayer = nullptr;

	LeftGermanPlayer* leftgermanyplayer = nullptr;

	SceneIntro* sceneIntro = nullptr;
	DataEast* dataEast = nullptr;
	MainScreen* mainScreen = nullptr;
	TutorialScene* tutorialScene = nullptr;
	ChooseCharacter* chooseCharacter = nullptr;
	ChooseMap* chooseMap = nullptr;
	TurfLevel* turflevel = nullptr;
	ClayModule* clay = nullptr;
	ModuleEnemies* enemies = nullptr;
	ModuleParticles* particles = nullptr;

	ModuleCollisions* collisions = nullptr;
	ModuleFadeToBlack* fade = nullptr;
	ModuleFonts* fonts = nullptr;
	

	ModuleRender* render = nullptr;
};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__