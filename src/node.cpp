#include "node.h"

Position Node::getPosition(){
    return m_Position + (Parent ? Parent->getPosition() : Position(0.0f));
}

void Node::Append(Node* node){
    Childs->push_back(node);
    node->Parent = this;
}