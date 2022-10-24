
#pragma once

#include "Scene.hpp"
#include <string>
#include <map>

class ScenesM
{
    public:

        void CreateScene(std::string id, Scene* sc);
        void RenderScene();
        void UpdateScene();
        void SetActiveScene(std::string id);

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