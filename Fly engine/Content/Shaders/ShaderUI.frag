#version 330 core 
out vec4 glFragColor; 
in vec4 pass_color; 

void main() 
{ 
    glFragColor = pass_color;
};