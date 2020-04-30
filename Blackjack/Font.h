#pragma once
#include <SDL.h>
#include <SDL_ttf.h>

class Font {
public:
	Font(const char* path, int size);

	SDL_Surface* renderFontSolid(const char* text, SDL_Color color);

	int getWidth(const char* text);

private:
	const char* m_path;
	int m_size;

	TTF_Font* m_font;
};

