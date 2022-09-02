#version 460 core
layout (location = 0) in vec2 inPosition;

uniform vec2 Size;
uniform vec2 Position;

void main(){
    gl_Position = vec4((inPosition*Size) + Position, 0.0f, 1.0f);
}