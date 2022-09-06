#version 460 core
layout (location = 0) in vec2 inPosition;
layout (location = 1) in vec2 inTexPosition;

uniform vec2 Size;
uniform vec2 Position;
uniform vec2 ScreenResolution;

out vec2 TexCoord;
out vec2 FragPos;

void main(){
    gl_Position = vec4((inPosition*(Size / ScreenResolution)) + (Position / ScreenResolution), 0.0f, 1.0f);
    TexCoord = inTexPosition;
    FragPos = inPosition;
}