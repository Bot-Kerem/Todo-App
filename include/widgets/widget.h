#pragma once

#include "graphics.h"
#include "node.h"

class Widget: public Node, protected Graphics::VertexArray, Graphics::VertexBuffer{
    public:
        virtual void draw();
};
