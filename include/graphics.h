#pragma once

#include "types.h"

namespace Graphics{
    void LoadGraphics();
    
    void Clear(Color color);

    class VertexArray{
        public:
            VertexArray();
            void bindVertexArray() const;
            void vertexAttrib(unsigned int index, int size, int stride, const void* pointer);
        private:
            unsigned int m_VertexArray{0};
    };

    class VertexBuffer{
        public:
            VertexBuffer();
            void bindVertexBuffer() const;
            void bufferData(void* data, signed long int size);
        private:
            unsigned int m_VertexBuffer{0};
    };

    class FrameBuffer{
        public:
            FrameBuffer();
            void bindFrameBuffer() const;
        private:
            unsigned int m_FrameBuffer{0};
            unsigned int m_RenderBuffer{0};
            unsigned int m_Image{0};
    };

    struct Draw
    {
        public:
            static void Square(Position position, Size size);
            static void Circle(Position position, Size size);

            static void InitDraw();
        private:
            static VertexArray* SquareVAO;
    };
    
}