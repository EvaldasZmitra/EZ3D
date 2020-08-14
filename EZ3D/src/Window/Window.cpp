#include "Window.h"
#include <GL\glew.h>

Window::Window()
{
    SDL_Init(SDL_INIT_VIDEO);   
    _window = SDL_CreateWindow(
        "An SDL2 window",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        SDL_WINDOW_OPENGL
    );
    _context = SDL_GL_CreateContext(_window);
    glewInit();
}

void Window::Update()
{
    SDL_GL_SwapWindow(_window);
}

Window::~Window()
{
    SDL_DestroyWindow(_window);
    SDL_Quit();
}
