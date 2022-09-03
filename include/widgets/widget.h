#pragma once

#include "graphics.h"
#include "node.h"
#include "theme.h"

#include <memory>

class Widget: public Node{
    public:
        Widget();
        void draw();

        Size size{0.5f};
        
        static Theme* theme;
    protected:
        virtual void _draw() = 0;
        std::unique_ptr<Graphics::FrameBuffer> m_FrameBuffer;
};
