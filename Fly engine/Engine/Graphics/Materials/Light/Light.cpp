#include "Light.h"

Light::Light()
{
}

Light::~Light()
{
}

glm::vec3 Light::GetDiffuse(MeshRenderer* meshRenderer)
{
    //glm::vec3 norm;
    //glm::vec3 pos;

    //for (int i = 0; i < meshRenderer->mesh.Normaly.size(); i = i + 3)
    //{
    //    norm = glm::vec3(meshRenderer->mesh.Normaly[i], meshRenderer->mesh.Normaly[i + 1], meshRenderer->mesh.Normaly[i + 2]);
    //    vecLightNormal.push_back(norm);
    //}
    //
    //for (int i = 0; i < meshRenderer->mesh.Position.size(); i = i + 3)
    //{
    //    pos = glm::vec3(meshRenderer->mesh.Position[i], meshRenderer->mesh.Position[i + 1], meshRenderer->mesh.Position[i + 2]);
    //    vecLightPos.push_back(pos);
    //}
    // 
    //for (int i = 0; i < vecLightPos.size(); i)
    //{
    //    for (int b = 0; b < vecLightNormal.size(); b++)
    //    {
    //        normal = glm::normalize((glm::vec3)vecLightNormal[b]);
    //        lightDir = glm::normalize(lightPos - vecLightPos[i]);
    //        diff = glm::max(glm::dot(normal, lightDir), 0.0f);
    //        glm::vec3 diffuse = diff * lightColor;
    //    }
    //}
    ///*vec3 lightDir = normalize(lightPos - FragPos);
    //float diff = max(dot(norm, lightDir), 0.0);
    //vec3 diffuse = diff * lightColor;*/

    ////vec3 lightDir = normalize(lightPos - FragPos);
    ////float diff = std::max(dot(norm, lightDir), 0.0);
    ////vec3 diffuse = diff * lightColor;
    return glm::vec3(1.0f, 1.0f, 1.0f);



}

glm::vec3 Light::GetAmbient()
{
    return ambientStrength * lightColor;
}

glm::vec3 Light::GetSpecular()
{
    return glm::vec3();
}

glm::vec3 Light::GetLight()
{
    return glm::vec3();
}
