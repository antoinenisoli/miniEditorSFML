#pragma once
#include "GameObject.h"

class PlayerController
{
public:
	std::weak_ptr<GameObject> _gameObject;
	void Awake(sf::Sprite spr);
	void Update(float elapsedTime);
};

