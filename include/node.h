#pragma once

#include <memory>
#include <vector>

#include "types.h"

class Node{
    public:
        Node* Parent = nullptr;
        std::unique_ptr<std::vector<Node>> Childs;
        Position getPosition();
    protected:
        Position m_Position{0.0f};
};
