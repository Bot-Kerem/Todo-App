#pragma once

#include "widgets/widget.h"
#include "theme.h"

class Scene: public Widget{
    public:
        Scene(Size size);
        Theme theme = getDefaultTheme();
        
        void _draw() override;

};