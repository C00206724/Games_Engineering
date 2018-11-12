#include "EntityComponent.h"
#include "Component.h"
#include "HealthSystem.h"
#include "HealthComponent.h"
#include "PositionComponent.h"
#include "PositionSystem.h"
#include "RenderSystem.h"
#include "AI.h"
#include "ControlSystem.h"
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
//const int SPRITE_SIZE = 510;
//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image
SDL_Surface* loadSurface(std::string path);

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//Current displayed PNG image
SDL_Surface* gImageSurface = NULL;

SDL_Rect sourceRect;
SDL_Rect destRect;


int m_count = 0;

bool init()
{
	//Initialization flag
	bool success = true;

	sourceRect.x = 200;
	sourceRect.y = -100;
	sourceRect.w = 100;
	sourceRect.y = 100;

	destRect.x = 0;
	destRect.y = 0;
	destRect.w = 210;
	destRect.h = 265.6;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				success = false;
			}
			else
			{
				//Get window surface
				gScreenSurface = SDL_GetWindowSurface(gWindow);
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load PNG surface
	/*gImageSurface = loadSurface("square.png");
	if (gImageSurface == NULL)
	{
	printf("Failed to load PNG image!\n");
	success = false;
	}*/
	
	return success;
}

void close()
{
	//Free loaded image
	SDL_FreeSurface(gImageSurface);
	gImageSurface = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Surface* loadSurface(std::string path)
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, NULL);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}

int main(int argc, char* args[])
{

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


			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			Entity player("Player");
			player.addComponent(new HealthComponent(200));
			player.addComponent(new PositionComponent(100, 100));
			player.addComponent(new ControlComponent());


			Entity alien("Alien");
			alien.addComponent(new HealthComponent(60));
			alien.addComponent(new PositionComponent(200, 500));

			Entity dog("Dog");
			dog.addComponent(new HealthComponent(150));
			dog.addComponent(new PositionComponent(400, 500));

			Entity cat("Cat");
			cat.addComponent(new HealthComponent(90));
			cat.addComponent(new PositionComponent(1000, 500));
	

			HealthSystem healthS;
			RenderSystem renderS;
			AiSystem aiS;
			ControlSystem controlS;

			healthS.addEntity(player);
			healthS.addEntity(alien);
			healthS.addEntity(dog);
			healthS.addEntity(cat);


			renderS.addEntity(player);
			renderS.addEntity(alien);
			renderS.addEntity(dog);
			renderS.addEntity(cat);

			aiS.addEntity(alien);
			aiS.addEntity(dog);
			aiS.addEntity(cat);

			controlS.addEntity(player);

			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					controlS.input(e);

					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}
				aiS.update();


				//Apply the PNG image
				SDL_BlitSurface(gImageSurface, &destRect, gScreenSurface, &sourceRect);

				//Update the surface
				SDL_UpdateWindowSurface(gWindow);

			}
		}
	}

	//close SDL
	close();

	return 0;
}