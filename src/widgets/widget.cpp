#include "widgets/widget.h"

void Widget::draw(){
    m_FrameBuffer->start();
    Graphics::Clear(Color(1.0f, 0.0f, 1.0f));
    _draw();
    m_FrameBuffer->end();
    Graphics::Draw::ImageSquare(getPosition(), size, m_FrameBuffer->getImage());
}

Widget::Widget(){
    m_FrameBuffer = std::make_unique<Graphics::FrameBuffer>(size.x * 800, size.y * 600); // It will be updated later
}