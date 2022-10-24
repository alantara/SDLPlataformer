
#include "ScenesM.hpp"

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
    scenesMap.insert(make_pair(id, sc));
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
    activeScene = scenesMap[id];
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