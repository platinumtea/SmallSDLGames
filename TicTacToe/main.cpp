#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include "Board.h"

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 640;

bool checkInput(Board* board, SDL_Event* e, Piece p);

int main(int argc, char* argv[]) {
	SDL_Window* window = NULL;

	SDL_Surface* windowSurface = NULL;


	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
		printf("Unable to initialize SDL: %s", SDL_GetError());
		return 1;

	} else {
		window = SDL_CreateWindow("Tic-Tac-Toe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL) {
			printf("Unable to create SDL window: %s", SDL_GetError());
		} else {
			windowSurface = SDL_GetWindowSurface(window);

			SDL_FillRect(windowSurface, NULL, SDL_MapRGB(windowSurface->format, 0, 153, 255));

			SDL_UpdateWindowSurface(window);

			// Initialize SDL_image
			if (IMG_Init(IMG_INIT_PNG) == 0) {
				printf("Unable to initialize SDL_Image: %s", IMG_GetError());
			} else {
				if (TTF_Init() != 0) {
					printf("Unable to initialize SDL_TTF: %s", TTF_GetError());
				} else {

					// Load resources
					TTF_Font* winFont = TTF_OpenFont("calibri.ttf", 128);

					if (winFont == NULL) {
						printf("Unable to load font: %s", TTF_GetError());
					} else {
						SDL_Surface* xIcon = IMG_Load("x.png");
						SDL_Surface* oIcon = IMG_Load("o.png");
						if (xIcon == NULL && oIcon == NULL) {
							printf("Unable to load PNG images: %s", IMG_GetError());
						} else {
							for (int i = 0; i < 3; i++) {
								for (int j = 0; j < 3; j++) {
									SDL_Rect rect = { i * 220, j * 220, 200, 200 };
									SDL_FillRect(windowSurface, &rect, SDL_MapRGB(windowSurface->format, 200, 200, 200));
								}
							}

							SDL_UpdateWindowSurface(window);

							bool quit = false;
							Board game;
							Piece currentPlayer = Piece::X;

							while (!quit) {
								SDL_Event e;


								while (SDL_PollEvent(&e)) {
									switch (e.type) {
									case SDL_MOUSEBUTTONDOWN:
										if (checkInput(&game, &e, currentPlayer)) {
											currentPlayer = (currentPlayer == Piece::X ? Piece::O : Piece::X);
										}
										break;
									case SDL_QUIT:
										quit = true;
										break;
									}
								}


								// Render all pieces
								for (int i = 0; i < 3; i++) {
									for (int j = 0; j < 3; j++) {
										SDL_Rect rect = { i * 220, j * 220, 200, 200 };
										switch (game.getPiece(i, j)) {
										case Piece::X:
											SDL_BlitSurface(xIcon, NULL, windowSurface, &rect);
											break;
										case Piece::O:
											SDL_BlitSurface(oIcon, NULL, windowSurface, &rect);
											break;
										}
									}
								}

								// Check win condition

								if (game.checkWin() != Piece::NONE || game.isFull()) {
									Piece winner = game.checkWin();
									game.reset();
									std::string winnerText;
									if (winner == Piece::X) {
										winnerText = "X wins!";
									} else if (winner == Piece::O) {
										winnerText = "O wins!";
									} else {
										winnerText = "Tie!";
									}

									SDL_Surface* winText = TTF_RenderText_Solid(winFont, winnerText.c_str(), { 255, 153, 0 });
									SDL_Rect dstRect = { WINDOW_WIDTH / 2 - winText->w / 2, WINDOW_HEIGHT / 2 - winText->h / 2, winText->w, winText->h };
									SDL_BlitSurface(winText, NULL, windowSurface, &dstRect);

									SDL_UpdateWindowSurface(window);
									SDL_Delay(2000);

									SDL_FillRect(windowSurface, NULL, SDL_MapRGB(windowSurface->format, 0, 153, 255));
									for (int i = 0; i < 3; i++) {
										for (int j = 0; j < 3; j++) {
											SDL_Rect rect = { i * 220, j * 220, 200, 200 };
											SDL_FillRect(windowSurface, &rect, SDL_MapRGB(windowSurface->format, 200, 200, 200));
										}
									}

									currentPlayer = Piece::X;
								}

								SDL_UpdateWindowSurface(window);
							}
						}
					}
					TTF_Quit();
				}


				IMG_Quit();
			}

			SDL_FreeSurface(windowSurface);

			SDL_DestroyWindow(window);
		}
		SDL_Quit();
	}

	return 0;
}

bool checkInput(Board* board, SDL_Event* e, Piece p) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int x = e->button.x;
			int y = e->button.y;
			// {i * 220, j * 220, 200, 200}
			if (x > i * 220 && y > j * 220 && x < i * 220 + 200 && y < j * 220 + 200) {
				board->move(p, i, j);
				return true;
			}
		}
	}
	return false;
}
