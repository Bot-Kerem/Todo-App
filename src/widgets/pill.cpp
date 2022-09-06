#include "widgets/pill.h"
#include "scene.h"

Pill::Pill(Size size): Widget(size){
    
}

void Pill::_draw(){
    Graphics::Draw::Circle(Position(-m_Size.x + m_Size.y, 0.0f), Size(m_Size.y), theme->PillCircle, Size(m_Size));
    Graphics::Draw::Circle(Position(m_Size.x - m_Size.y, 0.0f), Size(m_Size.y), theme->PillCircle, Size(m_Size));
    Graphics::Draw::Square(Position(0.0f), Size(m_Size.x-m_Size.y, m_Size.y), theme->PillSquare, Size(m_Size));
}

Widget* Pill::collide(float xpos, float ypos){
    if(xpos >= ((getPosition().x - m_Size.x + m_Size.y) / 2) && xpos <= ((getPosition().x + m_Size.x - m_Size.y) / 2) && ypos <= ((getPosition().y + m_Size.y) / 2) && ypos >= ((getPosition().y - m_Size.y) / 2)){
        return this;
    }
    if(m_Size.y / 2 >= glm::distance(glm::vec2(((getPosition().x - m_Size.x + m_Size.y) / 2), getPosition().y / 2), glm::vec2(xpos, ypos))){
        return this;
    }
    if(m_Size.y / 2 >= glm::distance(glm::vec2(((getPosition().x + m_Size.x - m_Size.y) / 2), getPosition().y / 2), glm::vec2(xpos, ypos))){
        return this;
    }
    return nullptr;
}