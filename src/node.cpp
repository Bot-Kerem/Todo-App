#include "node.h"

Position Node::getPosition(){
    return m_Position + (Parent ? Parent->getPosition() : Position(0.0f));
}