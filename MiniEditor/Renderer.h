#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"


class GameObject;

class Renderer : Component
{
public:
	std::shared_ptr<GameObject> gameObject;
	sf::Sprite sprite;

	void Initialize(sf::Sprite spr);
	void Update(sf::RenderWindow* window);
	Renderer(std::shared_ptr<GameObject> obj);
};

