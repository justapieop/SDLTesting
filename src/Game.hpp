//
// Created by JustAPie on 2/2/2025.
//

#ifndef GAME_HPP
#define GAME_HPP
#include <SDL2/SDL.h>

class Game {
public:
    Game();
    ~Game();

    void init(const char* title, int w, int h);
    void handle_events();
    void update();
    void render() const;
    void clean() const;

    [[nodiscard]] bool running() const { return this->is_running; }

private:
    bool is_running;
    SDL_Window* window{};
    SDL_Renderer* renderer{};
};



#endif //GAME_HPP
