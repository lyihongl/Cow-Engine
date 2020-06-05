#version 330

out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;

void main(){
    FragColor = texture(ourTexture2, TexCoord);
}