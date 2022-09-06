#pragma once

#include "widgets/widget.h"

class Pill: public Widget{
    public:
        void _draw() override;

        Pill(Size size);
};