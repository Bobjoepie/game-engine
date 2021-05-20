#include "Engine.h"

Engine* Engine::s_instance;

bool Engine::init()
{
	bool success = true;
	SDL_Init(SDL_INIT_VIDEO);
	m_window = SDL_CreateWindow(
		"Temp Title",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		NULL
	);

	if (!m_window)
	{
		std::cout << "Could not create window: " << SDL_GetError() << std::endl;
		success = false;
	}

	m_renderer = SDL_CreateRenderer(
		m_window,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);

	if (!m_renderer)
	{
		std::cout << "Could not create renderer: " << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		SDL_RenderSetLogicalSize(m_renderer, 1280, 720);
		SDL_RenderSetIntegerScale(m_renderer, SDL_TRUE);
	}
	if (success) { m_running = true; }
	return success;
}

void Engine::shutdown()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	if (s_instance) { delete s_instance; }
}
