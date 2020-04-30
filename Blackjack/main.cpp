#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>
#include "Window.h"
#include "Font.h"

const int WINDOW_WIDTH = 1024;
const int WINDOW_HEIGHT = 768;

bool initSDL(Uint32 sdlFlags, int imgFlags);
void logSDLError(std::ostream& stream, const char* message);
void closeSDL();

int main(int argc, char* argv[]) {
	// Initialize SDL
	if (!initSDL(SDL_INIT_VIDEO | SDL_INIT_EVENTS, IMG_INIT_PNG)) {
		logSDLError(std::cout, "SDL_Init");
		return 1;
	} else {
		// Create SDL Window
		Window mainWindow("Blackjack", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
		if (!mainWindow.successful()) {
			logSDLError(std::cout, "SDL_CreateWindow");
			return 1;
		}
		mainWindow.setIcon("img/blackjack-icon.ico");

		// Load resources
		SDL_Texture* cards = mainWindow.loadTexture("img/cards.png");
		SDL_Texture* background = mainWindow.loadTexture("img/casino-background.png");

		Font mainFont("fonts/calibri.ttf", 36);
		SDL_Texture* titleText = mainWindow.convertToTexture(mainFont.renderFontSolid("Blackjack", { 0, 0, 0, 255 }));


		// Main loop
		bool quit = false;
		SDL_Event e;

		while (!quit) {
			// Events
			while (SDL_PollEvent(&e)) {

				switch (e.type) {

				case SDL_QUIT:
					quit = true;
					break;

				}
			}

			// Logic


			// Render

			mainWindow.clear();

			mainWindow.copy(background, NULL, NULL);
			mainWindow.copy(titleText, NULL, 0, 0, mainFont.getWidth("Blackjack"), 36);

			mainWindow.update();

			SDL_WaitEvent(NULL);
		}

		SDL_DestroyTexture(cards);
		SDL_DestroyTexture(background);
	}



	closeSDL();

	return 0;
}

// Initializes SDL and sub-libraries, inluding SDL_IMG and SDL_TTF
// Returns true on successful initialization, false otherwise
bool initSDL(Uint32 sdlFlags, int imgFlags) {
	if (SDL_Init(sdlFlags)) {
		logSDLError(std::cout, "SDL_Init");
		return false;
	} else {
		if (!(IMG_Init(imgFlags) & imgFlags)) {
			logSDLError(std::cout, "IMG_Init");
			return false;
		} else {
			if (TTF_Init()) {
				logSDLError(std::cout, "TTF_Init");
				return false;
			}
		}
	}
	return true;
}

// Quits SDL and sub-libraries
void closeSDL() {
	SDL_Quit();
	IMG_Quit();
	TTF_Quit();
}

// Logs SDL errors to specified stream with message
void logSDLError(std::ostream& stream, const char* message) {
	stream << message << ": " << SDL_GetError() << std::endl;
}
