#pragma once
#include "GameObject.h"

class GameEngine
{
public:
	std::vector<std::shared_ptr<GameObject>> gameObjects;
	void AddGameobject(std::shared_ptr<GameObject> obj);
	void Update(sf::RenderWindow* window);

	static std::shared_ptr<GameEngine> getInstance();
	static std::shared_ptr<GameEngine> Instance;

	static bool IsKeyDown(sf::Keyboard::Key key);
};

