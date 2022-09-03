#include "scene.h"
#include "graphics.h"
#include "widgets/widget.h"

void Scene::draw(){
    Widget::theme = &theme;
    Graphics::Clear(theme.Background);
}
