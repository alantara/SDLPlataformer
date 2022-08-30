#include "src/core/Engine.h"
#include "src/timer/Timer.h"

int main(int argsc, char** argv)
{
    Engine::GetInstance()->Init();

    while(Engine::GetInstance()->IsRunning())
    {
        Engine::GetInstance()->Events();
        Engine::GetInstance()->Update();
        Engine::GetInstance()->Render();
        Timer::GetInstance()->Tick();
    }

    Engine::GetInstance()->Clean();

    return 0;
}
