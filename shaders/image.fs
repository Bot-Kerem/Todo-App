#version 460 core

out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D Image;

void main(){
    
    vec4 tex = texture(Image, TexCoord);
    if(tex.a == 0.0f){
        discard;
    }
    FragColor = tex;
}