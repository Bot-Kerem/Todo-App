#pragma once

#include <memory>
#include <vector>

class Node{
    public:
        Node* Parent;
        std::unique_ptr<std::vector<Node>> Childs;
};
