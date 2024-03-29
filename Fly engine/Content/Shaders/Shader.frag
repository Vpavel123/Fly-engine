#version 330 core 
out vec4 glFragColor; 
in vec3 Normal;
in vec4 pass_color; 
in vec2 TexCoord; 
in vec3 crntPos;

uniform sampler2D ourTexture;

void main() 
{ 
    glFragColor = texture(ourTexture, TexCoord) * pass_color;
};