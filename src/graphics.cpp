#include "graphics.h"


namespace Graphics
{
    #include <glad/glad.h>

    void LoadGraphics(){
        gladLoadGL();
    }

    void Clear(glm::vec3 color){
        glClearColor(color.r, color.g, color.b, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

}
