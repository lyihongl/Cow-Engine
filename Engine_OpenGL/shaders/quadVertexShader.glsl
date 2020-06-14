#version 330 core

layout (location=0) in vec3 aPos;
layout(location=1) in vec2 aTexCoord; 
out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform int spriteLoc[2];

void main(){
    gl_Position = view*model*vec4(aPos, 1.0);
    TexCoord = vec2(aTexCoord.x*16/512+16.0f/512*spriteLoc[0], aTexCoord.y*16/512+16.0f/512*spriteLoc[1]);
}