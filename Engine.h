#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

constexpr static int WINDOW_WIDTH = 1280;
constexpr static int WINDOW_HEIGHT = 720;

class Engine
{
public:
	bool init();
	void shutdown();
	inline static Engine& get()
	{
		if (s_instance == nullptr)
		{
			s_instance = new Engine();
		}
		return *s_instance;
	}
	bool isRunning() { return m_running; }
	
private:
	bool m_running;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	static Engine* s_instance;
};

