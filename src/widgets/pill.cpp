#include "widgets/pill.h"
#include "scene.h"
Pill::Pill(){
    
}

void Pill::_draw(){
    Graphics::Draw::Circle(Position(size.x, 0.0f), Size(size.y, size.y), theme->PillCircle);
    Graphics::Draw::Circle(Position(-size.x, 0.0f), Size(size.y, size.y), theme->PillCircle);
    Graphics::Draw::Square(Position(0.0f), size, theme->PillSquare);
}