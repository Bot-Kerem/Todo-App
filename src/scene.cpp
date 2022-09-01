#include "scene.h"
#include "graphics.h"

Scene* Scene::CurrentScene = nullptr;

void Scene::draw(){
    CurrentScene = this;
    Graphics::Clear(theme.Background);
}
