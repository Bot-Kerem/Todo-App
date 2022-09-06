#pragma once

#include "types.h"
#include "shader.h"

namespace Graphics{
    
    void Clear(Color color, float Alpha = 1.0f);

    void setViewport(Size size);

    class VertexArray{
        public:
            VertexArray();
            ~VertexArray();
            void bindVertexArray() const;
            void vertexAttrib(unsigned int index, int size, int stride, const void* pointer) const;
        private:
            unsigned int m_VertexArray{0};
    };

    class VertexBuffer{
        public:
            VertexBuffer();
            ~VertexBuffer();
            void bindVertexBuffer() const;
            void bufferData(void* data, signed long int size);
        private:
            unsigned int m_VertexBuffer{0};
    };

    class FrameBuffer{
        public:
            FrameBuffer(int width, int height);
            ~FrameBuffer();

            void start() const;
            void end() const;

            unsigned int getImage();

        protected:
            unsigned int m_FrameBuffer;
            unsigned int m_Image;
            unsigned int m_RenderBuffer;
    };

    struct Draw
    {
        public:
            static void Square(Position position, Size size, Color color, Size resolution = Size(800, 600));
            static void ImageSquare(Position position, Size size, unsigned int Image, Size resolution = Size(800, 600));
            static void Circle(Position position, Size size, Color color, Size resolution = Size(800, 600));

            static void InitDraw();
        private:
            static Shader* m_SquareShader;
            static Shader* m_ImageSquareShader;
            static Shader* m_CircleShader;
            static VertexArray* m_SquareVAO;
            static VertexBuffer* m_SquareVBO;
    };
    
}
