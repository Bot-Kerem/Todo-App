#include "widgets/widget.h"

Theme* Widget::theme = nullptr;
#include <iostream>

void Widget::draw(){

    m_FrameBuffer->start();
    Graphics::setViewport(m_Size);
    Graphics::Clear(Color(0.0f, 1.0f, 0.0f), 0.0);
    _draw();
    for(auto widget: Childs){
        ((Widget*)widget)->draw();
    }
    m_FrameBuffer->end();
    Graphics::setViewport(Parent ? ((Widget*)Parent)->m_Size : m_Size);
    std::cout << (Parent ? ((Widget*)Parent)->m_Size.x : m_Size.x) << std::endl;
    Graphics::Draw::ImageSquare(getPosition(), m_Size, m_FrameBuffer->getImage());
}

Widget::Widget(Size size): m_Size(size){
    m_FrameBuffer = std::make_unique<Graphics::FrameBuffer>(m_Size.x, m_Size.y);
}