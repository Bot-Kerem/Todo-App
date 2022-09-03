#version 460 core

out vec4 FragColor;

in vec2 FragPos;

uniform vec3 Color;

void main(){
    if(sqrt(pow(FragPos.x, 2) + pow(FragPos.y, 2)) > 1){
        discard;
    }
    FragColor = vec4(Color, 1.0f);
}