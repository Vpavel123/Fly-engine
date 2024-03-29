#version 330 core 
out vec4 glFragColor; 
in vec3 Normal;
in vec4 pass_color; 
in vec2 TexCoord; 
in vec3 vs_position;

uniform sampler2D ourTexture;

uniform vec3 lightPos;

void main() 
{ 
    // ambient
    vec3 ambientLight = vec3(0.1f, 0.1f, 0.1f);
    //diffuse
    vec3 posToLightDir = normalize(vs_position - lightPos);
    vec3 diffuseColor = vec3(1.0f,1.0f,1.0f);
    float diffuse = clamp(dot(posToLightDir, Normal), 0, 1);
    vec3 diffuseFinal = diffuseColor * diffuse;

    glFragColor = texture(ourTexture, TexCoord) * pass_color * (vec4(ambientLight, 1.0f) + vec4(diffuseFinal, 1.0f));
};

//Просто добавив это, как никто другой не предлагал, вы уверены, что ваши координаты текстуры верны? Обычно sampler2Dони должны находиться в диапазоне от 0 до 1.
//Изменить: быстрый способ проверить - FragColor = vec4(texCoord, 0, 1);увидеть некоторые градиенты.