#pragma once

#include "graphics.h"
#include "node.h"
#include "theme.h"

#include <memory>

class Widget: public Node{
    public:
        Widget(Size size);
        void draw();

        Size m_Size;

        void update();
        
        static Theme* theme;

        virtual Widget* collide(float xpos, float ypos) = 0;

        bool Hover = false;
        static bool EditMode;
    protected:
        virtual void _draw() = 0;
        std::unique_ptr<Graphics::FrameBuffer> m_FrameBuffer;
};
