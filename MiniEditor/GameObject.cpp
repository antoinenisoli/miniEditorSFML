#include "GameObject.h"
#include "Component.h"

void GameObject::AddComponent(std::shared_ptr<Renderer> comp)
{
	components.push_back(comp);
}

void GameObject::Update(sf::RenderWindow* window)
{
	for (auto& component : components)
		component->Update(window);
}