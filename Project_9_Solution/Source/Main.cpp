#include "Application.h"
#include "Globals.h"
#include "MemLeaks.h"
#include <stdio.h>

#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib")
#pragma comment( lib, "SDL/libx86/SDL2main.lib")


enum class Main_States
{
	MAIN_CREATION,
	MAIN_START,
	MAIN_UPDATE,
	MAIN_FINISH,
	MAIN_EXIT
};

Application* App = nullptr;

//int fps = 60;
//int desiredDelta = 1000 / fps;  //desired time b/w frames

int main(int argc, char* argv[])
{
	ReportMemoryLeaks();

	int main_return = EXIT_FAILURE;
	Main_States state = Main_States::MAIN_CREATION;

	//int starttick = SDL_GetTicks();

	while (state != Main_States::MAIN_EXIT)
	{
		switch (state)
		{
			case Main_States::MAIN_CREATION:
			{
				LOG("Application Creation --------------\n");
				App = new Application();
				state = Main_States::MAIN_START;
			}	break;

			case Main_States::MAIN_START:
			{
				LOG("Application Start --------------\n");
				if(App->Init() == false)
				{
					LOG("Application Init exits with error -----\n");
					state = Main_States::MAIN_EXIT;
				}
				else
				{
					state = Main_States::MAIN_UPDATE;
				}
			}	break;

			case Main_States::MAIN_UPDATE:
			{
				Update_Status status = App->Update();

				if (status == Update_Status::UPDATE_ERROR)
				{
					LOG("Application Update exits with error -----\n");
					state = Main_States::MAIN_EXIT;
				}
				else if (status == Update_Status::UPDATE_STOP)
				{
					state = Main_States::MAIN_FINISH;
				}
			}	break;

			case Main_States::MAIN_FINISH:
			{
				LOG("Application Finish --------------\n");
				if (App->CleanUp() == true)
				{
					main_return = EXIT_SUCCESS;
				}
				else
				{
					LOG("Application CleanUp exits with error -----\n");
				}
				state = Main_States::MAIN_EXIT;
			}
		}
		//int delta = SDL_GetTicks() - starttick;     //actual time b/w frames

		//int avgFPS = 1000 / (desiredDelta - delta);  //calculating FPS HERE

		//if (delta < desiredDelta)
		//{
		//	SDL_Delay(desiredDelta - delta);
		//}
		
	}

	LOG("\nBye :)\n");

	delete App;

	return main_return;
}