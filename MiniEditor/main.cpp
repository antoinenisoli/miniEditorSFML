#include<iostream>
#include<fstream>
using namespace std;

#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include "GameObject.h"
#include "Renderer.h"
#include "GameEngine.h"
#include "PlayerController.h"

void Update()
{
    sf::RenderWindow window(sf::VideoMode(600, 800), "SFML works!");
    std::shared_ptr<GameEngine> game = GameEngine::getInstance();

    sf::Texture texture;
    if (!texture.loadFromFile("PNG/playerShip3_blue.png"))
        cout << "error !" << endl;

    sf::Sprite textureShip;
    textureShip.setTexture(texture);

    std::shared_ptr<PlayerController> player = std::make_shared<PlayerController>();
    player->Awake(textureShip);
    game->AddGameobject(player->_gameObject.lock());

    sf::Clock deltaClock;

    while (window.isOpen())
    {
        float time = deltaClock.sf::Clock::restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        player->Update(time);
        game->Update(&window);
        window.display();
    }
}

int main()
{
    Update();
    return 0;
}