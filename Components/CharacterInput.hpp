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
        SDL_Scancode fire;

    public:
        CharacterInput() : left(SDL_SCANCODE_A), right(SDL_SCANCODE_D), jump(SDL_SCANCODE_W), fire(SDL_SCANCODE_Q){};
        ~CharacterInput(){};

        void setCharacterInput(SDL_Scancode l, SDL_Scancode r, SDL_Scancode j, SDL_Scancode f)
        {
            setLeft(l);
            setRight(r);
            setJump(j);
            setFire(f);
        }

        const SDL_Scancode getLeft() const {return left;}
        const SDL_Scancode getRight() const { return right; }
        const SDL_Scancode getJump() const { return jump; }
        const SDL_Scancode getFire() const { return fire; }

        void setLeft(SDL_Scancode l) { left = l; }
        void setRight(SDL_Scancode r) { right = r; }
        void setJump(SDL_Scancode j) { jump = j; }
        void setFire(SDL_Scancode f) { fire = f; }
    };
}