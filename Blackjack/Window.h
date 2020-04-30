#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Window {
public:
	// Con/De-structor
	Window(const char* title,
		int x, int y, int w,
		int h, Uint32 flags);
	~Window();

	// Checks if construction was successful
	bool successful();

	// Rendering functions
	void clear();
	void copy(SDL_Texture* texture,
		const SDL_Rect* srcrect,
		const SDL_Rect* dstrect);
	void copy(SDL_Texture* texture,
		const SDL_Rect* srcrect,
		int x, int y, int w, int h);
	void update();

	// Renderer-specfic functions
	SDL_Texture* loadTexture(const char* path);
	SDL_Texture* convertToTexture(SDL_Surface* surface);

	void setIcon(const char* iconPath);

	SDL_Surface* getWindowSurface();
	SDL_Renderer* getWindowRenderer();
private:
	SDL_Window* m_window;
	SDL_Surface* m_windowSurface;
	SDL_Renderer* m_renderer;
};
