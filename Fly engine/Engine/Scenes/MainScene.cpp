#include "MainScene.h"
#include <iostream>
#include "SceneManager.h"
#include "../Graphics/Geometry/Mesh.h"
#include "../Systems/Components/MeshRenderer.h"
#include "../Systems/RenderPipeline/MeshRendererSystem.h"
#include "../Graphics/Materials/StandartMaterial.h"
#include "../Graphics/Screen.h"
#include "../Systems/MoveSystem.h"
#include "../Systems/CameraViewSystem.h"
#include "../Systems/ECS/ecsEntityManager.h"

MainScene::MainScene()
{
    rend = new (MeshRenderer);
    transform = new (Transform);
    entityList = ecsEntityList();
}

void MainScene::OnLoadContent()
{
    content.shader.Load("Shader");
    content.shader.Load("TestShader");
    content.shader.Load("TextureShader");
    content.texture.Load("cover.jpg");
    content.texture.Load("cat.png");
    content.texture.Load("car.png");
    content.texture.Load("House.bmp");
}

void MainScene::BuildEntitis()
{
    ecsEntity& pyramid = (manager.addEntity());
    pyramid.addComponent<MeshRenderer>().mesh = Mesh(GL_STATIC_DRAW);
    pyramid.getComponent<MeshRenderer>().material = new StandartMaterial("TextureShader", "cover.jpg");

    pyramid.addComponent<Transform>();
    pyramid.getComponent<Transform>().position = glm::vec3(0.0f, 0.0f, 0.0f);
    pyramid.getComponent<Transform>().rotation = glm::vec3(0.0f, 1.0f, 0.1f);
    pyramid.getComponent<Transform>().scale = glm::vec3(1.0f, 1.0f, 1.0f);
    transform = &pyramid.getComponent<Transform>();

    pyramid.addComponent<CameraSystem>() = CameraSystem();
    pyramid.getComponent<CameraSystem>().cam->FOV = 45.0f;
    pyramid.getComponent<CameraSystem>().cam->Near = 0.1f;
    pyramid.getComponent<CameraSystem>().cam->Far = 1000.0f;
    pyramid.getComponent<CameraSystem>().transform = this->transform;

    ecsEntity& square = (manager.addEntity());
    square.addComponent<MeshRenderer>().mesh = Mesh(GL_STATIC_DRAW);
    square.getComponent<MeshRenderer>().material = new StandartMaterial("TextureShader", "House.bmp");

    square.addComponent<Transform>();
    square.getComponent<Transform>().position = glm::vec3(-0.5f, 0.0f, 1.0f);
    square.getComponent<Transform>().rotation = glm::vec3(0.6f, 0.1f, 0.1f);
    square.getComponent<Transform>().scale = glm::vec3(0.5f, 0.5f, 0.5f);
    transform = &square.getComponent<Transform>();

    square.addComponent<CameraSystem>() = CameraSystem();
    square.getComponent<CameraSystem>().cam->FOV = 45.0f;
    square.getComponent<CameraSystem>().cam->Near = 0.1f;
    square.getComponent<CameraSystem>().cam->Far = 1000.0f;
    square.getComponent<CameraSystem>().transform = this->transform;

    square.getComponent<MeshRenderer>().mesh.Position.insert(square.getComponent<MeshRenderer>().mesh.Position.end(),
    { 
        -0.5f, -0.5f, -0.5f, 
        0.5f, -0.5f, -0.5f, 
        0.5f,  0.5f, -0.5f, 
        -0.5f,  0.5f, -0.5f,

        -0.5f, -0.5f,  0.5f,
        0.5f, -0.5f,  0.5f, 
        0.5f,  0.5f,  0.5f, 
        -0.5f,  0.5f,  0.5f
    });

    square.getComponent<MeshRenderer>().mesh.Color.insert(square.getComponent<MeshRenderer>().mesh.Color.end(),
    {
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,

        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f
    });

    square.getComponent<MeshRenderer>().mesh.Normaly.insert(square.getComponent<MeshRenderer>().mesh.Normaly.end(),
       {
           0.0f, 0.0f, -1.0f,
           0.0f, 0.0f, 1.0f,
           -1.0f, 0.0f, 0.0f,
           1.0f, 0.0f, 0.0f,
           0.0f, -1.0f, 0.0f
       });

    square.getComponent<MeshRenderer>().mesh.UV.insert(square.getComponent<MeshRenderer>().mesh.UV.end(),
       {
           0.0f, 0.0f,  // down left start x, y
           0.0f, 1.0f, // up left
           1.0f, 1.0f, // up right
           1.0f, 0.0f,  // down right
       });

    square.getComponent<MeshRenderer>().mesh.Indices.insert(square.getComponent<MeshRenderer>().mesh.Indices.end(),
    {
        0, 1, 2,
        2, 3, 0,
        4, 5, 6,
        6, 7, 4,
        3, 2, 6,
        6, 7, 3,
        7, 6, 5,
        5, 4, 7,
        4, 0, 3,
        3, 7, 4,
        1, 5, 2,
        2, 6, 1
    });

    ecsEntity& trigle = (manager.addEntity());
    trigle.addComponent<MeshRenderer>().mesh = Mesh(GL_STATIC_DRAW);
    trigle.getComponent<MeshRenderer>().material = new StandartMaterial("TextureShader", "cat.png");

    trigle.addComponent<Transform>();
    trigle.getComponent<Transform>().position = glm::vec3(0.0f, 0.0f, 0.0f);
    trigle.getComponent<Transform>().rotation = glm::vec3(-0.5f, 0.5f, 1.0f);
    trigle.getComponent<Transform>().scale = glm::vec3(1.0f, 1.0f, 1.0f);
    transform = &trigle.getComponent<Transform>();

    trigle.addComponent<CameraSystem>() = CameraSystem();
    trigle.getComponent<CameraSystem>().cam->FOV = 45.0f;
    trigle.getComponent<CameraSystem>().cam->Near = 0.1f;
    trigle.getComponent<CameraSystem>().cam->Far = 100.0f;
    trigle.getComponent<CameraSystem>().transform = this->transform;

    trigle.getComponent<MeshRenderer>().mesh.Position.insert(trigle.getComponent<MeshRenderer>().mesh.Position.end(),
        { 
            -0.3f, 0.0f, 0.0f, 
            -0.5f, 0.0f, -0.0f, 
            0.5f, 0.0f, -0.0f,  
            0.5f, 0.0f, 0.0f, 
            0.0f, 0.8f, 0.0f
        });

    trigle.getComponent<MeshRenderer>().mesh.Color.insert(trigle.getComponent<MeshRenderer>().mesh.Color.end(),
        {
            1.0f, 0.2f, 1.0f, 1.0f,
            0.1f, 0.5f, 0.9f, 1.0f,
            0.1f, 0.4f, 0.6f, 1.0f,
            0.2f, 1.0f, 0.1f, 1.0f,
            0.4f, 0.2f, 0.1f, 1.0f
        });

    trigle.getComponent<MeshRenderer>().mesh.Normaly.insert(trigle.getComponent<MeshRenderer>().mesh.Normaly.end(),
        {
            0.0f, 0.0f, -1.0f,
            0.0f, 0.0f, 1.0f,
            -1.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            0.0f, -1.0f, 0.0f
        });

    trigle.getComponent<MeshRenderer>().mesh.UV.insert(trigle.getComponent<MeshRenderer>().mesh.UV.end(),
        {
            0.0f, 0.0f,  // ������ ����� ����
            5.0f, 0.0f, // ������ ������ ����
            0.0f, 0.0f, // ������� ������ ����
            5.0f, 0.0f,  // ������� ����� ���� 
            2.5f, 5.0f
        });

    trigle.getComponent<MeshRenderer>().mesh.Indices.insert(trigle.getComponent<MeshRenderer>().mesh.Indices.end(),
        {
            0, 1, 2,   // ������ �����������
            0, 2, 3,    // ������ �����������
            0, 1, 4,
            1, 2, 4,
            2, 3, 4,
            3, 0, 4
        });

    pyramid.getComponent<MeshRenderer>().mesh.Position.insert(pyramid.getComponent<MeshRenderer>().mesh.Position.end(),
    {   
        -0.5f, 0.0f, 0.5f, // ������� ������ ���� 
        -0.5f, 0.0f, -0.5f,  // ������ ������ ����
        0.5f, 0.0f, -0.5f,  // ������ ����� ����
        0.5f, 0.0f, 0.5f, // ������� ����� ����
        0.0f, 0.8f, 0.0f 
    });

    pyramid.getComponent<MeshRenderer>().mesh.Color.insert(pyramid.getComponent<MeshRenderer>().mesh.Color.end(),
    {
        1.0f, 0.5f, 1.0f, 1.0f,
        0.3f, 0.5f, 0.9f, 1.0f,
        0.1f, 0.4f, 0.2f, 1.0f,
        1.0f, 0.2f, 0.1f, 1.0f,
        1.0f, 0.2f, 0.1f, 1.0f
    });
    
    pyramid.getComponent<MeshRenderer>().mesh.Normaly.insert(pyramid.getComponent<MeshRenderer>().mesh.Normaly.end(),
    {
        0.0f, 0.0f, -1.0f,
        0.0f, 0.0f, 1.0f,
        -1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        0.0f, -1.0f, 0.0f
    });

    pyramid.getComponent<MeshRenderer>().mesh.UV.insert(pyramid.getComponent<MeshRenderer>().mesh.UV.end(),
    {
        0.0f, 0.0f,
        5.0f, 0.0f, 
        0.0f, 0.0f, 
        5.0f, 0.0f,  
        2.5f, 5.0f
    });

    pyramid.getComponent<MeshRenderer>().mesh.Indices.insert(pyramid.getComponent<MeshRenderer>().mesh.Indices.end(),
    {
        0, 1, 2,   
        0, 2, 3,    
        0, 1, 4,
        1, 2, 4,
        2, 3, 4,
        3, 0, 4
    });

    entityList.add(std::move(pyramid));
    entityList.add(std::move(trigle));
    entityList.add(std::move(square));
}

void MainScene::OnConfigureUpdate(ecsSystems systems)
{
    systems.Add(new MoveSystem());
    systems.Add(new CameraViewSystem());
}

void MainScene::ConfigureRenderPipeline(ecsSystems pipeline)
{
    pipeline.Add(new MeshRendererSystem(this));
    Scene::renderPipeline = pipeline;
    systems = Scene::renderPipeline;
}