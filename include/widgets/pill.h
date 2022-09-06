#pragma once

#include "widgets/widget.h"

class Pill: public Widget{
    public:
        void _draw() override;
        Widget* collide(float xpos, float ypos) override;

        Pill(Size size);
};