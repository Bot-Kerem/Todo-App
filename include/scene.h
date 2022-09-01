#pragma once

#include "node.h"
#include "theme.h"

class Scene: public Node{
    public:
        Theme theme = getDefaultTheme();
        static Scene* CurrentScene;

        void draw();
};