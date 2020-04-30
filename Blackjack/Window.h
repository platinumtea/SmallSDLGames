#pragma once
#include <SDL.h>

class Window {
public:
	Window(const char* title,
		int x, int y, int w,
		int h, Uint32 flags);
	~Window();

	bool successful();

	void blit(SDL_Surface* src, const SDL_Rect* srcrect,
		SDL_Surface* dst, SDL_Rect* dstrect);
private:
	SDL_Window* m_window;
	SDL_Surface* m_windowSurface;
};
