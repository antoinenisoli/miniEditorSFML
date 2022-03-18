#include "PlayerController.h"
#include "GameEngine.h"
#include <iostream>
using namespace std;
float PLAYER_SPEED = 100;

void PlayerController::Awake(sf::Sprite spr)
{
	auto gameObject = _gameObject.lock();
	gameObject = std::make_shared<GameObject>();
	gameObject->scale = sf::Vector2f(1, 1);
	gameObject->position = sf::Vector2f(300, 400);
	std::shared_ptr<Renderer> renderer(new Renderer(gameObject));
	renderer->Initialize(spr);
	gameObject->AddComponent(renderer);
}

void PlayerController::Update(float elapsedTime)
{
	auto go = _gameObject.lock();
	//go->Update();

	if (GameEngine::IsKeyDown(sf::Keyboard::Left))
		go->position += sf::Vector2f(elapsedTime * -PLAYER_SPEED, 0);
	else if (GameEngine::IsKeyDown(sf::Keyboard::Right))
		go->position += sf::Vector2f(elapsedTime * PLAYER_SPEED, 0);

	if (GameEngine::IsKeyDown(sf::Keyboard::Up))
		go->position += sf::Vector2f(elapsedTime * -PLAYER_SPEED, 0);
	else if (GameEngine::IsKeyDown(sf::Keyboard::Down))
		go->position += sf::Vector2f(elapsedTime * PLAYER_SPEED, 0);
}
