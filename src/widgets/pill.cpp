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
    return this;;
}