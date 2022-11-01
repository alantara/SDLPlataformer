#pragma once

#include <SDL2/SDL.h>

namespace Components
{
    class CharacterInput
    {
    private:
        SDL_Scancode left;
        SDL_Scancode right;
        SDL_Scancode jump;

    public:
        CharacterInput(SDL_Scancode l, SDL_Scancode r, SDL_Scancode j) : left(l), right(r), jump(j){};
        ~CharacterInput(){};

        const SDL_Scancode getLeft() const { return left; }
        const SDL_Scancode getRight() const { return right; }
        const SDL_Scancode getJump() const { return jump; }

        SDL_Scancode setLeft(SDL_Scancode l) { return left = l; }
        SDL_Scancode setRight(SDL_Scancode r) { return right = r; }
        SDL_Scancode setJump(SDL_Scancode j) { return jump = j; }
    };
}