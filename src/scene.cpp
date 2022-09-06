#include "scene.h"
#include "graphics.h"
#include "widgets/widget.h"
#include <iostream>

void Scene::_draw(){
    Widget::theme = &theme;
    Graphics::Clear(theme.Background);
}

Widget* Scene::collide(float xpos, float ypos){
    if(xpos < (m_Position.x + abs(m_Size.x)) && ypos <  (m_Position.y + abs(m_Size.y))){
        for(auto widget: Childs){
            Widget* yes = static_cast<Widget*>(widget)->collide(xpos, ypos);
            if(yes){
                return yes;
            }
        }

        return this;
    }
    return nullptr;
}

Scene::Scene(Size size): Widget(size){
    
}