#pragma once

#include <memory>
#include <vector>

#include "types.h"

class Node{
    public:
        Node* Parent = nullptr;
        Position getPosition();
        void Append(Node* node);
    protected:
        std::unique_ptr<std::vector<Node*>> Childs;
        Position m_Position{0.0f};
};
