#version 460 core

out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D Image;

void main(){
    FragColor = vec4(texture(Image, TexCoord).rgb, 1.0f);
}