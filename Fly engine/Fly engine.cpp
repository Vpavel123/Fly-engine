#define _CRT_SECURE_NO_WARNINGS
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "../../Fly engine/Engine/Graphics/Geometry/Mesh.h"
#include "Engine/Scenes/SceneManager.h"
#include "Engine/Scenes/MainScene.h"
#include "Engine/Graphics/Screen.h"
#include "Engine/Inputs/Input.h"'
#include "Engine/Debugging/Logger.h"
#include <format>

Screen screen = Screen();

int main(void)
{
    Logger* log = Logger::getInstance();
    screen.width(1920);
    screen.height(1080);
    int frameBufferWidth = Screen::width();
    int frameBufferHeight = Screen::height();

    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(1920, 1080, "Fly engine", NULL, NULL);

    glfwGetFramebufferSize(window, &frameBufferWidth, &frameBufferHeight);

    screen.window = window;

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
    {
        log->Error("Error!");
    }
    log->Information(std::format("OpenGL Version: {}", reinterpret_cast<const char*>(glGetString(GL_VERSION))));

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_CONSTANT_ALPHA);

    SceneManager scene = SceneManager();
    scene.Load(new MainScene());
    
    //
    // 
    // 
    //Не передавайте размер окна в glViewport или другие пиксельные вызовы OpenGL.Размер окна указывается в координатах экрана, а не в пикселях.
    //Кроме того, не забудьте вызвать glViewport() при изменении размера окна.

    glViewport(0, 0, Screen::width(), Screen::height());

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_ALWAYS);


    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        scene.Current->InitSystems();
        scene.Current->DrawSystems();

        //////////////////////////////////////// Debug ////////////////////////////////////////
        GLenum errorCode;
        while ((errorCode = glGetError()) != GL_NO_ERROR)
        {
            std::string error;
            switch (errorCode)
            {
            case GL_INVALID_ENUM:                  error = "INVALID_ENUM"; break;
            case GL_INVALID_VALUE:                 error = "INVALID_VALUE"; break;
            case GL_INVALID_OPERATION:             error = "INVALID_OPERATION"; break;
            case GL_STACK_OVERFLOW:                error = "STACK_OVERFLOW"; break;
            case GL_STACK_UNDERFLOW:               error = "STACK_UNDERFLOW"; break;
            case GL_OUT_OF_MEMORY:                 error = "OUT_OF_MEMORY"; break;
            case GL_INVALID_FRAMEBUFFER_OPERATION: error = "INVALID_FRAMEBUFFER_OPERATION"; break;
            }
            std::cout << error << " | " << std::endl;
        }
        //return errorCode;

        GLenum err = glGetError();
        if (err != GL_NO_ERROR)
        {
            log->Error(std::format("OpenGL error {},", err));
            abort();
        }

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glDisable(GL_DEPTH_TEST);
    glfwTerminate();
    return 0;
}