#include "scene.h"
#include "graphics.h"
#include "widgets/widget.h"

void Scene::_draw(){
    Widget::theme = &theme;
    Graphics::Clear(theme.Background);
}

Scene::Scene(Size size): Widget(size){

}