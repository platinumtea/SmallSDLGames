#include "Window.h"

Window::Window(const char* title, int x, int y, int w, int h, Uint32 flags) {
	m_window = SDL_CreateWindow(title, x, y, w, h, flags);
	if (m_window != NULL) {
		m_windowSurface = SDL_GetWindowSurface(m_window);
	}
}

Window::~Window() {
	SDL_DestroyWindow(m_window);
	SDL_FreeSurface(m_windowSurface);
}

bool Window::successful() {
	if (m_window == NULL || m_windowSurface == NULL) {
		return false;
	}
	return true;
}

void Window::blit(SDL_Surface* src, const SDL_Rect* srcrect, SDL_Surface* dst, SDL_Rect* dstrect) {
	SDL_BlitSurface(src, srcrect, dst, dstrect);
}
