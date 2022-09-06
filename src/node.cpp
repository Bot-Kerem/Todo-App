#include "node.h"
#include "widgets/widget.h"

#include <iostream>

Position Node::getPosition(){
    return m_Position + (Parent ? Parent->getPosition() : Position(0.0f));
}

void Node::Append(Node* node){
    Childs.push_back(node);
    node->Parent = this;
    node->m_Position = ((Widget*)node)->m_Size;
    ((Widget*)node)->update();
    ((Widget*)this)->update();
}