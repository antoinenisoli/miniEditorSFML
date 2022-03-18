#include "GameEngine.h"

std::shared_ptr<GameEngine> GameEngine::Instance(nullptr);


void GameEngine::AddGameobject(std::shared_ptr<GameObject> obj)
{
	gameObjects.push_back(obj);
}

void GameEngine::Update(sf::RenderWindow* window)
{
	for (auto& gameObject : gameObjects) 
		gameObject->Update(window);
}

std::shared_ptr<GameEngine> GameEngine::getInstance()
{
	if (GameEngine::Instance == nullptr)
		GameEngine::Instance = std::make_shared<GameEngine>();

	return GameEngine::Instance;
}

bool GameEngine::IsKeyDown(sf::Keyboard::Key key)
{
	return sf::Keyboard::isKeyPressed(key);
}
