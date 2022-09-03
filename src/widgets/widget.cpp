#include "widgets/widget.h"

Theme* Widget::theme = nullptr;

void Widget::draw(){
    m_FrameBuffer->start();
    Graphics::Clear(Color(0.0f, 1.0f, 0.0f), 0.0);
    _draw();
    m_FrameBuffer->end();
    Graphics::Draw::ImageSquare(getPosition(), size, m_FrameBuffer->getImage());
}

Widget::Widget(){
    m_FrameBuffer = std::make_unique<Graphics::FrameBuffer>(800, 600); // It will be updated later
}