#version 330 core

layout (location=0) in vec3 aPos;
layout (location=1) in vec2 aTexCoord; 
layout (location=2) in vec4 aOffset;
out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
//uniform int spriteLoc[2];
//uniform vec2 offsets[100];

void main(){
    //vec2 offset = offsets[gl_InstanceID];
    //gl_Position = vec4(aPos.x+aOffset.x, aPos.y+aOffset.y, aPos.z, 1.0);
    vec4 temp = vec4(aPos, 1.0);
    gl_Position = model*vec4(temp.x+aOffset.x, temp.y+aOffset.y, 0.0, 1.0);
    //TexCoord = vec2(aTexCoord.x*16/512+16.0f/512*spriteLoc[0], aTexCoord.y*16/512+16.0f/512*spriteLoc[1]);
    //TexCoord = vec2(0, 0);
    TexCoord = vec2(aTexCoord.x*16/512+16.0f/512*aOffset.z, aTexCoord.y*16/512+16.0f/512*aOffset.w);
}