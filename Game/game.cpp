#include "game.hpp"

Game::Game() : mWindowSize(1000, 800), mWindow(sf::VideoMode(mWindowSize.x, mWindowSize.y), "Flappy-Bird") {}
Game::~Game() {}
void Game::run()
{
    sf::Clock clock;
    while (mWindow.isOpen())
    {
        processEvents();
        sf::Time dt = clock.restart();
        update(dt.asSeconds());
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            mWindow.close();
    }
}
void Game::update(float dt) {}
void Game::render()
{
    mWindow.clear(sf::Color::Cyan);
    // mWindow.draw();
    mWindow.display();
}