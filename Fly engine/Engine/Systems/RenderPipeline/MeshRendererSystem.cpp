#include "MeshRendererSystem.h"
#include "../../Graphics/Screen.h"
#include "../../Graphics/Materials/Light/Light.h"
#include <windows.h>

MeshRendererSystem::MeshRendererSystem(Scene *scene)
{
	_scene = scene;
	main = static_cast<MainScene*>(_scene);
}

void MeshRendererSystem::Init()
{
	for (size_t i = 0; i < main->entityList.List.size(); i++)
	{
		main->entityList.List[i].getComponent<MeshRenderer>().mesh.Upload();
	}
}

void MeshRendererSystem::Run()
{
	// Light attributes
	glm::vec3 lightPos = glm::vec3(1.2f, 1.0f, 2.0f);
	//input = new Input();
	////camera = CameraSystem();
	//input->GetDevice(new MoveSystem());
	//input->GetDevice(new CameraViewSystem());

	for (size_t i = 0; i < main->entityList.List.size(); i++)
	{
		if (dynamic_cast<CameraSystem*>(&main->entityList.List[i].getComponent<CameraSystem>()) != nullptr)
		{
			main->entityList.List[i].getComponent<CameraSystem>().transform->Model = main->entityList.List[i].getComponent<CameraSystem>().transform->UpdateModel();
			main->entityList.List[i].getComponent<CameraSystem>().Run();
		}

		//for (int b = 0; b < input->device.size(); b++)
		//{
		//	input->device[b]->Run(Screen::window, &main->entityList.List[i].getComponent<CameraSystem>(), main->entityList.List[i].getComponent<CameraSystem>().transform);
		//};

		glm::mat4 MVP = main->entityList.List[i].getComponent<CameraSystem>().cam->Projection * main->entityList.List[i].getComponent<CameraSystem>().cam->View * main->entityList.List[i].getComponent<CameraSystem>().transform->Model;
		
		// Check value in mat4

		//const float* pSource = (const float*)glm::value_ptr(MVP);
		//for (int i = 0; i < 16; ++i) {
		//	dArray[i] = pSource[i];
		//	std::cout << "NEW Value in View:" << i << " Value " << dArray[i] << std::endl;
		//	Sleep(500);
		//}

		Light light = Light();
		light.GetDiffuse(&main->entityList.List[i].getComponent<MeshRenderer>());
		

		main->entityList.List[i].getComponent<MeshRenderer>().material->shader.Use();
		main->entityList.List[i].getComponent<MeshRenderer>().material->shader.SetMatrix4("MVP", MVP);
		main->entityList.List[i].getComponent<MeshRenderer>().material->shader.SetMatrix4("model", main->entityList.List[i].getComponent<CameraSystem>().transform->Model);
		main->entityList.List[i].getComponent<MeshRenderer>().material->LoadParams();
		main->entityList.List[i].getComponent<MeshRenderer>().material->shader.SetUniform3fv("lightPos", 1, glm::value_ptr(lightPos));
		main->entityList.List[i].getComponent<MeshRenderer>().material->shader.SetUniform1i("ourTexture", 0);

		main->entityList.List[i].getComponent<MeshRenderer>().mesh.vao.Bind();
		glDrawElements(GL_TRIANGLES, main->entityList.List[i].getComponent<MeshRenderer>().mesh.Indices.size(), GL_UNSIGNED_INT, nullptr);
		main->entityList.List[i].getComponent<MeshRenderer>().mesh.vao.UnBind();
		main->entityList.List[i].getComponent<MeshRenderer>().material->shader.Reset();
	}
}