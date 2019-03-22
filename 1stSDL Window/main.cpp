
#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#pragma comment(lib, "Winmm.lib")
#include <iostream>

using namespace std;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;


//Starts up SDL and creates window
bool init() {
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}

//Loads media
bool loadMedia() {
	//Loading success flag
	bool success = true;

	//Load splash image
	gHelloWorld = SDL_LoadBMP("hello_world.bmp");
	if (gHelloWorld == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "hello_world.bmp", SDL_GetError());
		success = false;
	}

	return success;
}

bool loadMedia2() {
	bool success = true;
	//Load 2nd splash image
	gHelloWorld = SDL_LoadBMP("POOTIS.bmp");
	if (gHelloWorld == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "POOTIS.bmp", SDL_GetError());
		success = false;
	}
	return success;
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}


int main(int argc, char* args[]) {
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			int tfmenu;
			cout << "Please select a class" << endl << " " << endl << "1 - Scout" << endl << "2 - Soldier" << endl << "3 - Pyro" << endl << "4 - Demoman" << endl << "5 - Heavy" << endl << "6 - Engineer" << endl << "7 - Medic" << endl << "8 - Sniper" << endl << "Spy" << endl;
			cin >> tfmenu;


			//Deallocate surface & Change Image
			SDL_FreeSurface(gHelloWorld);
			gHelloWorld = NULL;
			if (tfmenu == 5) {
				gHelloWorld = SDL_LoadBMP("POOTIS.bmp");
			}

			//Apply the new image
			SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

			//Update the surface
			SDL_UpdateWindowSurface(gWindow);

			//Play Sound
			if (tfmenu == 5) {
				PlaySound("defopoot.wav", NULL, SND_FILENAME);
			}
			else if (tfmenu == 4) {
				PlaySound("When DeadFace queues as Demoman.wav", NULL, SND_FILENAME);
			}
		}
	}
	//Free resources and close SDL
	close();
	
	
	
	return 0;
}