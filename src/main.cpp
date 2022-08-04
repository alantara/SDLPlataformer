#include <SDL_image.h>
#include <stdio.h>

#include <core/core.hpp>
#include <sprite/sprite.hpp>

#define SCREEN_WIDTH 1280 
#define SCREEN_HEIGHT 720

int main(int argc, char** argv){

    Core Instance;
    Instance.CreateWindow("Hello World!", SCREEN_WIDTH, SCREEN_HEIGHT);

    Sprite img;
    img.LoadTexture(Instance, "a.jpg");

    bool running = true;
    while(running){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT)
                running = false;
        }

        SDL_RenderClear(Instance.renderer);

        
        img.RenderTexture(Instance, img.texture);

        SDL_RenderPresent(Instance.renderer);
    }

    return 0;
}