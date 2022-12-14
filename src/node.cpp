#include "node.h"
#include "widgets/widget.h"

Position Node::getPosition(){
    return m_Position + (Parent ? Parent->getPosition() : Position(0.0f));
}

void Node::setPosition(Position position){
    m_Position = position;
}

void Node::Append(Node* node){
    Childs.push_back(node);
    node->Parent = this;
    node->m_Position = Position(500, 500); // ((Widget*)node)->m_Size;
    ((Widget*)node)->update();
}
