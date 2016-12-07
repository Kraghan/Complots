//
// Created by Kraghan on 02/12/2016.
//

#include "GameEngine/GameEngine.hpp"

/* Explicit */ GameEngine::GameEngine()
: m_isRunning(false)
, m_window(nullptr)
, m_graphicEngine()
, m_game()
{

}

/* Virtual */ GameEngine::~GameEngine()
{

}

void GameEngine::init()
{
    // Initialize graphic engine
    m_graphicEngine.init();

    // Initialize the window
    m_window = m_graphicEngine.getWindow();

    // Set the framerate
    m_graphicEngine.setFramerate(60.0);
}

void GameEngine::start()
{
    // Game already run
    if(m_isRunning)
        return;

    // Launch the game
    m_game.init();

    // Start gameloop
    m_isRunning = true;
    gameLoop();
}

void GameEngine::stop()
{
    // Game already stoped
    if(!m_isRunning)
        return;

    // Stop gameloop
    m_isRunning = false;
}

void GameEngine::gameLoop()
{
    sf::Clock clock;
    double lag = 0.0;
    double previous = clock.getElapsedTime().asSeconds();

    while(m_isRunning)
    {
        double current = clock.getElapsedTime().asSeconds();
        double elapsed = current - previous;
        previous = current;

        lag += elapsed;

        // Processing inputs


        while(lag >= SECONDS_PER_UPDATE)
        {
            // Updating
            update(SECONDS_PER_UPDATE * TimeManager::TimeScale);

            // Retrieve elapsed time
            lag -= SECONDS_PER_UPDATE;
        }

        // Rendering
        m_graphicEngine.render(lag / SECONDS_PER_UPDATE);
    }
}

void GameEngine::update(double dt)
{
    // Update game
    m_game.update(dt);
}

