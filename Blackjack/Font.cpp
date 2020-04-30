#include "Font.h"

Font::Font(const char* path, int size) {
	m_font = TTF_OpenFont(path, size);
	m_path = path;
	m_size = size;
}

SDL_Surface* Font::renderFontSolid(const char* text, SDL_Color color) {
	return TTF_RenderText_Solid(m_font, text, color);
}

int Font::getWidth(const char* text) {
	int width;
	TTF_SizeText(m_font, text, &width, NULL);
	return width;
}
