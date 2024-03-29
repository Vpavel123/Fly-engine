#version 330 core
layout(location = 0) in vec3 pos;
layout(location = 1) in vec4 col;
layout(location = 2) in vec2 uv;
out vec4 pass_color;
uniform mat4 Model;

void main()
{
	gl_Position = Model * vec4(pos.x, pos.y, pos.z, 1.0f);
	pass_color = col;
};