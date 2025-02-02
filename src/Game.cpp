//
// Created by JustAPie on 2/2/2025.
//

#include "Game.hpp"
#include <SDL2/SDL.h>

Game::Game() {
    this->is_running = false;
}

Game::~Game() {
    this->is_running = NULL;
    this->window = nullptr;
    this->renderer = nullptr;
}

void Game::init(const char *title, const int w, const int h) {
    SDL_Log("Engine initializing");
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        SDL_Log("Engine initialized");
        SDL_Log("Drawing window");
        this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_HIDDEN);
        if (this->window) {
            SDL_Log("Window drawn");
        }

        SDL_Log("Renderer initializing");
        SDL_Log("Scanning for render device");
        SDL_RendererInfo info;
        for (int i = 0; i < SDL_GetNumRenderDrivers(); i++) {
            if (SDL_GetRenderDriverInfo(i, &info) == 0) {
                if (strstr(info.name, "opengl") || strstr(info.name, "vulkan")) {
                    this->renderer = SDL_CreateRenderer(this->window, i, 0);
                    SDL_Log("Using detected dGPU as the render device");
                    break;
                }
            }
        }

        if (!this->renderer) {
            this->renderer = SDL_CreateRenderer(this->window, -1, 0);
            SDL_Log("No dGPU detected. Using iGPU as the render device");
        }

        if (this->renderer) {
            SDL_Log("Renderer initialized");
        }

        SDL_ShowWindow(this->window);

        this->is_running = true;
    } else {
        SDL_Log("Engine initialization failed");
        this->is_running = false;
    }
}

void Game::handle_events() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            SDL_Log("Game exited");
            this->is_running = false;
            break;
        default:
            break;
    }
}


void Game::update() {

}


void Game::render() const {
    SDL_RenderClear(this->renderer);
    SDL_RenderPresent(this->renderer);
}

void Game::clean() const {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
    SDL_Log("Game cleaned");
}
