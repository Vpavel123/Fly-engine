#version 330 core
layout(location = 0) in vec3 pos;
layout(location = 1) in vec4 col;
layout(location = 2) in vec3 aNormal;
layout(location = 3) in vec2 uv;

out vec3 Normal;
out vec3 vs_position;

out vec4 pass_color;
out vec2 TexCoord;

uniform mat4 MVP;
uniform mat4 model;

void main()
{
	gl_Position = MVP * vec4(pos, 1.0f);
	pass_color = col;
	TexCoord = uv;
        vs_position = pos;
	Normal = mat3(model) * aNormal;
};