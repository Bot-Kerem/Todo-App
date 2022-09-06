#include "scene.h"
#include "graphics.h"
#include "widgets/widget.h"

void Scene::_draw(){
    Widget::theme = &theme;
    Graphics::Clear(theme.Background);
}

Widget* Scene::collide(float xpos, float ypos){
    if(xpos < (m_Position.x + abs(m_Size.x)) && ypos <  (m_Position.y + abs(m_Size.y))){
        for(int i = Childs.size() - 1; i >= 0; i--){
            Widget* yes = static_cast<Widget*>(Childs[i])->collide(xpos, ypos);
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