#include "graphics.h"

#include <stdexcept>
#include <iostream>

namespace Graphics{
    Shader* Draw::m_SquareShader = nullptr;
    Shader* Draw::m_ImageSquareShader = nullptr;
    Shader* Draw::m_CircleShader = nullptr;

    VertexArray* Draw::m_SquareVAO = nullptr;
    VertexBuffer* Draw::m_SquareVBO = nullptr;
    #include <glad/glad.h>
    void LoadGraphics(){
        gladLoadGL();
    }

    void Clear(glm::vec3 color, float Alpha){
        glClearColor(color.r, color.g, color.b, Alpha);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    //----------Vertex Array----------//
    VertexArray::VertexArray(){
        glGenVertexArrays(1, &m_VertexArray);
    }

    VertexArray::~VertexArray(){
        glDeleteVertexArrays(1, &m_VertexArray);
    }

    void VertexArray::bindVertexArray() const{
        glBindVertexArray(m_VertexArray);
    }

    void VertexArray::vertexAttrib(unsigned int index, int size, int stride, const void* pointer) const{
        glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride, pointer);
        glEnableVertexAttribArray(index);
    }
    //----------Vertex Array----------//
    
    //----------Vertex Buffer---------//
    VertexBuffer::VertexBuffer(){
        glGenBuffers(1, &m_VertexBuffer);
    }

    VertexBuffer::~VertexBuffer(){
        glDeleteBuffers(1, &m_VertexBuffer);
    }

    void VertexBuffer::bindVertexBuffer() const{
        glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
    }

    void VertexBuffer::bufferData(void* data, signed long int size){
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    }
    //----------Vertex Buffer---------//

    //----------Frame Buffer----------//
    FrameBuffer::FrameBuffer(int width, int height){
        glGenFramebuffers(1, &m_FrameBuffer);
        glBindFramebuffer(GL_FRAMEBUFFER, m_FrameBuffer);

        glGenTextures(1, &m_Image);
        glBindTexture(GL_TEXTURE_2D, m_Image);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_Image, 0);

        glGenRenderbuffers(1, &m_RenderBuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, m_RenderBuffer);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_RenderBuffer);

        if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE){
            throw std::runtime_error("ERROR::FRAMEBUFFER:: Framebuffer is not complete!");
        }
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }
    unsigned int FrameBuffer::getImage(){
        return m_Image;
    }

    void FrameBuffer::start() const{
        glBindFramebuffer(GL_FRAMEBUFFER, m_FrameBuffer);
    }

    void FrameBuffer::end() const{
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    FrameBuffer::~FrameBuffer(){
        glDeleteFramebuffers(1, &m_FrameBuffer);
        glDeleteRenderbuffers(1, &m_RenderBuffer);
        glDeleteTextures(1, &m_Image);
    }
    //----------Frame Buffer----------//

    //--------------Draw--------------//
    void Draw::InitDraw(){
        std::cout << "TODO: COMPILING SHADERS..." << std::endl;
        m_SquareShader = new Shader{"./../shaders/square.vs", "./../shaders/square.fs"};
        m_CircleShader = new Shader{"./../shaders/square.vs", "./../shaders/circle.fs"};
        m_ImageSquareShader = new Shader{"./../shaders/square.vs", "./../shaders/image.fs"};
        m_ImageSquareShader->use();
        m_ImageSquareShader->setInt("Image", 0);
        
        std::cout << "TODO: CREATING BUFFERS..." << std::endl;

        m_SquareVAO = new VertexArray{};
        m_SquareVBO = new VertexBuffer{};

        std::cout << "TODO: GENERATING SHAPES..." << std::endl;

        float SquareVertices[] = {
            1.0f, -1.0f, 1.0f, 0.0f,
            -1.0f, -1.0f, 0.0f, 0.0f,
            1.0f, 1.0f, 1.0f, 1.0f,
            -1.0f, 1.0f, 0.0f, 1.0f,
        };
        m_SquareVBO->bindVertexBuffer();
        m_SquareVBO->bufferData(SquareVertices, sizeof(SquareVertices));

        m_SquareVAO->bindVertexArray();
        m_SquareVAO->vertexAttrib(0, 2, sizeof(float) * 4, nullptr);
        m_SquareVAO->vertexAttrib(1, 2, sizeof(float) * 4, (void*)(sizeof(float) * 2));

        std::cout << "TODO: READY TO DRAW" << std::endl;

    }

    void Draw::Square(Position position, Size size, Color color){
        m_SquareShader->use();
        m_SquareShader->setVec2("Position", position);
        m_SquareShader->setVec2("Size", size);
        m_SquareShader->setVec3("Color", color);
        m_SquareVAO->bindVertexArray();
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }

    void Draw::ImageSquare(Position position, Size size, unsigned int Image){
        m_ImageSquareShader->use();
        m_ImageSquareShader->setVec2("Position", position);
        m_ImageSquareShader->setVec2("Size", size);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, Image);
        m_SquareVAO->bindVertexArray();
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }

    void Draw::Circle(Position position, Size size, Color color){
        m_CircleShader->use();
        m_CircleShader->setVec2("Position", position);
        m_CircleShader->setVec2("Size", size);
        m_CircleShader->setVec3("Color", color);
        m_SquareVAO->bindVertexArray();
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }
    //--------------Draw--------------//
}
