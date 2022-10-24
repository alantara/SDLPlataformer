
#include "ScenesM.hpp"

ScenesM* ScenesM::Instance = nullptr;

ScenesM::ScenesM()
{
    activeScene = nullptr;
}

ScenesM::~ScenesM()
{

}

void ScenesM::Create(std::string name, Scene* sc)
{
    scenesMap.push_back(make_pair(id, sc));
}

void ScenesM::Render()
{
    activeScene->Render();
}

void ScenesM::Update()
{
    activeScene->Update();
}

void ScenesM::SetActive(Scenes* sc)
{
    activeScene = sc;
}

void ScenesM::Clean()
{
    std::map<std::string, Scene*>::iterator it;

    for(it = scenesMap.begin(); it != scenesMap.end(); it++)
    {
        delete *it;
    }
    scenesMap.clear();
}