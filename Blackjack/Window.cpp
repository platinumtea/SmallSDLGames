#include "Window.h"
#include <iostream>

Window::Window(const char* title, int x, int y, int w, int h, Uint32 flags) {
	m_windowSurface = NULL;
	m_renderer = NULL;

	m_window = SDL_CreateWindow(title, x, y, w, h, flags);
	if (m_window != NULL) {
		m_windowSurface = SDL_GetWindowSurface(m_window);

		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
		SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	}
}

Window::~Window() {
	SDL_DestroyRenderer(m_renderer);
	SDL_FreeSurface(m_windowSurface);
	SDL_DestroyWindow(m_window);

	m_renderer = NULL;
	m_windowSurface = NULL;
	m_window = NULL;
}

bool Window::successful() {
	if (m_window == NULL || m_windowSurface == NULL || m_renderer == NULL) {
		return false;
	}
	return true;
}

// RENDERING

void Window::clear() {
	SDL_RenderClear(m_renderer);
}

void Window::copy(SDL_Texture* texture,
	const SDL_Rect* srcrect,
	const SDL_Rect* dstrect) {
	SDL_RenderCopy(m_renderer, texture, srcrect, dstrect);
}

void Window::copy(SDL_Texture* texture, const SDL_Rect* srcrect, int x, int y, int w, int h) {
	SDL_Rect dstrect = { x, y, w, h };
	SDL_RenderCopy(m_renderer, texture, srcrect, &dstrect);
}

void Window::update() {
	SDL_RenderPresent(m_renderer);
}

SDL_Texture* Window::loadTexture(const char* path) {
	SDL_Texture* loadedTexture = NULL;
	SDL_Surface* loadedSurface = NULL;

	loadedSurface = IMG_Load(path);
	if (loadedSurface == NULL) {
		return NULL;
	} else {
		loadedTexture = SDL_CreateTextureFromSurface(m_renderer, loadedSurface);
	}

	SDL_FreeSurface(loadedSurface);
	return loadedTexture;
}

SDL_Texture* Window::convertToTexture(SDL_Surface* surface) {
	SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, surface);
	SDL_FreeSurface(surface);
	return texture;
}

void Window::setIcon(const char* iconPath) {
	SDL_Surface* icon = IMG_Load(iconPath);
	if (icon == NULL) {
		std::cout << "IMG_Load" << ": " << SDL_GetError();
	}

	SDL_SetWindowIcon(m_window, icon);

	SDL_FreeSurface(icon);
}

SDL_Surface* Window::getWindowSurface() {
	return m_windowSurface;
}

SDL_Renderer* Window::getWindowRenderer() {
	return m_renderer;
}
