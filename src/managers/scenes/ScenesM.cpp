
#include "ScenesM.hpp"

#include <iostream>


ScenesM* ScenesM::Instance = nullptr;

ScenesM::ScenesM()
{
    activeScene = nullptr;
}

ScenesM::~ScenesM()
{

}

void ScenesM::CreateScene(std::string id, Scene* sc)
{
    if(sc == nullptr)
    {
        std::cout << "Scene can not be nullptr!" << std::endl;
        return;
    }

    scenesMap.insert(make_pair(id, sc));
}

void ScenesM::Clean()
{
    std::map<std::string, Scene*>::iterator it;

    for(it = scenesMap.begin(); it != scenesMap.end(); it++)
    {
        delete it->second;
    }
    scenesMap.clear();
}


void ScenesM::RenderScene()
{
    activeScene->Render();
}

void ScenesM::UpdateScene()
{
    activeScene->Update();
}


void ScenesM::SetActiveScene(std::string id)
{
    if(scenesMap[id] == nullptr)
    {
        std::cout << "Scene ID not found!" << std::endl;
        return;
    }
    activeScene = scenesMap[id];
}
