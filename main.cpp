#include "Engine.h"
#include "SceneManager.h"
#include "Transform.h"
#include <iostream>

int main(int argc, char* argv[])
{
	Engine engine = Engine::get();
	if (engine.init())
	{
		SceneManager sceneManager = SceneManager::get();
		sceneManager.createScene("Main Menu");
		sceneManager.getEntityManager("Main Menu").createEntity();
		sceneManager.activateScene("Main Menu");
		sceneManager.run();
		sceneManager.deactivateScene("Main Menu");
		sceneManager.run();
	}
	engine.shutdown();
	return 0;
}