#include "widgets/widget.h"

Theme* Widget::theme = nullptr;
bool Widget::EditMode = false;

void Widget::draw(){
    Graphics::setViewport(Parent ? ((Widget*)Parent)->m_Size : m_Size);
    Graphics::Draw::ImageSquare(Position(getPosition().x - (Parent ? (((Widget*)Parent)->m_Size).x : 0), (Parent ? (((Widget*)Parent)->m_Size).y - m_Size.y : 0) - getPosition().y), m_Size, m_FrameBuffer->getImage(), {1920,1080}, (EditMode && Hover) ? theme->EditModeHover : theme->Main);
}

Widget::Widget(Size size): m_Size(size){
    m_FrameBuffer = std::make_unique<Graphics::FrameBuffer>(m_Size.x, m_Size.y);
}

void Widget::update(){
    m_FrameBuffer->start();
    Graphics::setViewport(m_Size);
    Graphics::Clear(Color(0.0f, 1.0f, 0.0f), 0.0f);
    _draw();
    for(auto widget: Childs){
        ((Widget*)widget)->draw();
    }
    m_FrameBuffer->end();
    if(Parent){
        ((Widget*)Parent)->update();
    }
}
