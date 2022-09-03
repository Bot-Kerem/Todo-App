#include "widgets/pill.h"

Pill::Pill(){
    
}

void Pill::_draw(){
    Graphics::Draw::Circle(Position(0.0f), Size(1.0f), Color(0.0f, 0.0f, 1.0f));
}