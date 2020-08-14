#pragma once
#include <iostream>
#include <SDL.h>

class Window
{
public:
    Window();
    void Update();
    ~Window();
private:
    SDL_Window* _window;
    SDL_GLContext _context;
};

