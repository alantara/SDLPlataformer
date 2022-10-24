
#pragma once

#include "Scene.hpp"

class ScenesM
{
    public:

        void Create(std::string name, Scene* sc);
        void Render();
        void Update();
        void SetActive();

        void Clean();

        static ScenesM* GetInstance() 
        {
            return Instance = (Instance != nullptr) ? Instance : new ScenesM();
        }

    private:
        ScenesM();
        ~ScenesM();

        Scene* activeScene;
        std::map<std::string, Scene*> scenesMap;
        static ScenesM* Instance;
};