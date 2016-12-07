//
// Created by Kraghan on 02/12/2016.
//

#ifndef COMPLOTS_GAMEENGINE_HPP
#define COMPLOTS_GAMEENGINE_HPP

#include <StateMachine/StateMachine.hpp>
#include <GraphicEngine/GraphicEngine.hpp>
#include <Tools/Updatable.hpp>

class GameEngine : public Updatable
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    /// Default constructor
    explicit        GameEngine      ();

    /// Default destructor
    virtual         ~GameEngine     ();

    /// Initialize the game engine
    void            init            ();

    /// Start the game
    void            start           ();

    /// Stop the game
    void            stop            ();

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    /// True if the game engine is running
    bool                m_isRunning;

    /// Number of update each second
    const double        SECONDS_PER_UPDATE = 1.0/120.0;

    /// The client window
    sf::RenderWindow*   m_window;

    /// The graphic engine
    GraphicEngine       m_graphicEngine;

    /// Main class
    Game                m_game;

    /// Start the game loop
    void                gameLoop            ();

    /// Update the game
    void                update              (double dt);

};


#endif //COMPLOTS_GAMEENGINE_HPP
