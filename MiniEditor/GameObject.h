#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"
#include "Renderer.h"

class GameObject
{
public:
	sf::Vector2f position;
	sf::Vector2f scale;
	std::vector<std::shared_ptr<Renderer>> components;
	void AddComponent(std::shared_ptr<Renderer> comp);
	void Update(sf::RenderWindow* window);
};

