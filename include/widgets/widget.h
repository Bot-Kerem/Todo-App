#pragma once

#include "graphics.h"
#include "node.h"

#include <memory>

class Widget: public Node{
    public:
        Widget();
        void draw();

        Size size{0.2f};
        
    protected:
        virtual void _draw() = 0;
        std::unique_ptr<Graphics::FrameBuffer> m_FrameBuffer;
};
