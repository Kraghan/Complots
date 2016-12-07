//
// Created by Kraghan on 02/12/2016.
//

#ifndef COMPLOTS_GRAPHICENGINE_HPP
#define COMPLOTS_GRAPHICENGINE_HPP


#include <string>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Sprite.hpp"
#include "Layer.hpp"

class GraphicEngine
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    /// Default constructor
    explicit            GraphicEngine               ();

    /// Default destructor
    virtual             ~GraphicEngine              ();

    /// Initialize the graphic engine
    /// Name        : The name of the window
    /// Width       : The width of the window
    /// Height      : The height of the window
    /// SpriteCount : The number of available sprite
    /// LayerCount  : The number of available layer
    /// LayersSize   : The size of each layer
    void                Init                        (std::string name, unsigned width, unsigned height,
                                                     unsigned spriteCount, unsigned layerCount,
                                                     unsigned* layersSize);

    /// Return a free sprite
    Sprite *            GetSprite                   ();

    /// Render all graphic object referenced in the game
    void                Render                      (double factor);

    /// Return a pointer on the window
    sf::RenderWindow *  GetWindow                   () const;

    /// Set the engine framerate
    void                SetFramerate                (double framerate);

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    /// The render window to display layers
    sf::RenderWindow *  m_pWindow;

    /// Number of layers
    unsigned            m_LayerCount;

    /// Numbers of elements by layers
    unsigned *          m_aLayersSize;

    /// Array of layers
    Layer *             m_aLayers;

    /// Render display framerate
    double              m_Framerate;

    /// Internal clock
    sf::Clock           m_clock;

    /// Draw all layers
    void                draw                        ();

    /// Initialize layers
    void                initLayers                  ();

    /// Construct layers for the next frame
    void                constructLayers             (double factor);

    /// Prepare all layers for the next frame
    void                prepareLayers               ();
};


#endif //COMPLOTS_GRAPHICENGINE_HPP
