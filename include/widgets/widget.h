#pragma once

#include "graphics.h"
#include "node.h"

class Widget: public Node{
    public:
        virtual void draw() = 0;
};
