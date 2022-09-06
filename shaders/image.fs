#version 460 core

out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D Image;
uniform vec3 Main;

void main(){
    
    vec4 tex = texture(Image, TexCoord);
    if(tex.a == 0.0f){
        discard;
    }
    FragColor = vec4(Main, 1.0f) * tex;
}