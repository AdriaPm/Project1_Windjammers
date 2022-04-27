#include "Application.h"

#include "Module.h"
#include "ModuleWindow.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "Left_Japanese_Player.h"
#include "SceneIntro.h"
#include "DataEast.h"
#include "MainScreen.h"
#include "TutorialScene.h"
#include "TurfLevel.h"
#include "ClayModule.h"
#include "Left_German_Player.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModuleCollisions.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFonts.h"
#include "ModuleRender.h"
#include "ChooseMap.h"
#include "ChooseCharacter.h"

Application::Application()
{
	// The order in which the modules are added is very important.
	// It will define the order in which Pre/Update/Post will be called
	// Render should always be last, as our last action should be updating the screen


	modules[0] =	window =		new ModuleWindow(true);
	modules[1] =	input =			new ModuleInput(true);
	modules[2] =	textures =		new ModuleTextures(true);
	modules[3] =	audio =			new ModuleAudio(true);

	modules[4] =	sceneIntro =	new SceneIntro(true);
	modules[5] =	dataEast =		new DataEast(false);
	modules[6] =	mainScreen =	new MainScreen(false);
	modules[7] =	tutorialScene =	new TutorialScene(false);
	modules[8] = chooseCharacter =	new ChooseCharacter(false);
	modules[9] =	chooseMap =		new ChooseMap(false);		
	modules[10] =	turflevel =		new TurfLevel(false);		//Gameplay scene starts disabled
	modules[11] =	clay =			new ClayModule(false);
<<<<<<< Updated upstream
	modules[12] =	player =		new ModulePlayer(false);	//Player starts disabled
	modules[13] = LeftGermanPlayer =new Left_German_Player(false);
=======
<<<<<<< HEAD
	modules[12] =	LeftJapanesePlayer =		new Left_Japanese_Player(false);	//Player starts disabled
	modules[13] =	char2 =			new Char2(false);
=======
	modules[12] =	player =		new ModulePlayer(false);	//Player starts disabled
	modules[13] = LeftGermanPlayer =new Left_German_Player(false);
>>>>>>> c03a7d87e916d82da09814ce5fcdd0a24ded28b9
>>>>>>> Stashed changes
	modules[14] =	particles =		new ModuleParticles(true);
	modules[15] =	enemies =		new ModuleEnemies(false);	//Enemies start disabled

	modules[16] =	collisions =	new ModuleCollisions(true);
	modules[17] =	fade =			new ModuleFadeToBlack(true);
	modules[18] =	fonts =			new ModuleFonts(true);
	modules[19] =	render =		new ModuleRender(true);

	
	
}

Application::~Application()
{
	for (int i = 0; i < NUM_MODULES; ++i)
	{
		//Important: when deleting a pointer, set it to nullptr afterwards
		//It allows us for null check in other parts of the code
		delete modules[i];
		modules[i] = nullptr;
	}
}

bool Application::Init()
{
	bool ret = true;

	// All modules (active and disabled) will be initialized
	for (int i = 0; i < NUM_MODULES && ret; ++i)
		ret = modules[i]->Init();

	// Only active modules will be 'started'
	for (int i = 0; i < NUM_MODULES && ret; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;

	return ret;
}

Update_Status Application::Update()
{
	Update_Status ret = Update_Status::UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == Update_Status::UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : Update_Status::UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == Update_Status::UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : Update_Status::UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == Update_Status::UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : Update_Status::UPDATE_CONTINUE;

	return ret;
}
 
bool Application::CleanUp()
{
	bool ret = true;

	for (int i = NUM_MODULES - 1; i >= 0 && ret; --i)
		ret = modules[i]->IsEnabled() ? modules[i]->CleanUp() : true;

	return ret;
}
