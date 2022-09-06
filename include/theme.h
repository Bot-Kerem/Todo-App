#pragma once

#include "types.h"

struct Theme{
    Color Background;
    Color PillCircle;
    Color PillSquare;
    Color EditModeHover;
    Color Main;
};


Theme getDefaultTheme();