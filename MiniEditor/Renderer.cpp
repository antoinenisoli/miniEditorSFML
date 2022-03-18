#include "Renderer.h"
#include "GameObject.h"

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

void Renderer::Initialize(sf::Sprite spr)
{
	sprite = spr;
}

void Renderer::Update(sf::RenderWindow* window)
{
	sprite.setPosition(gameObject->position);
	sprite.setScale(gameObject->scale);
	window->draw(sprite);
}

Renderer::Renderer(std::shared_ptr<GameObject> obj)
{
	gameObject = obj;
}
