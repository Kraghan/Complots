//
// Created by Kraghan on 02/12/2016.
//

#include "../../include/GraphicEngine/GraphicEngine.hpp"

GraphicEngine::GraphicEngine()
: m_pWindow(nullptr)
, m_LayerCount(0)
, m_aLayersSize(nullptr)
, m_Framerate(60.0)
{

}

GraphicEngine::~GraphicEngine()
{
    // Delete window
    delete m_pWindow;

    // Delete layers
    delete [] m_aLayers;

    // Delete layersSize
    delete [] m_aLayersSize;
}

void GraphicEngine::Init(std::string name, unsigned width, unsigned height, unsigned spriteCount, unsigned layerCount,
                         unsigned *layersSize)
{
    // Initialize window
    m_pWindow = new sf::RenderWindow(sf::VideoMode(width,height), name, sf::Style::Close);

    // Initialize layers
    m_LayerCount = layerCount;
    m_aLayersSize = layersSize;
    initLayers();
}

Sprite *GraphicEngine::GetSprite()
{
    return nullptr;
}

void GraphicEngine::Render(double factor)
{

}

sf::RenderWindow *GraphicEngine::GetWindow() const
{
    return m_pWindow;
}

void GraphicEngine::SetFramerate(double framerate)
{
    m_Framerate = framerate;
}

void GraphicEngine::draw()
{
    // Clear buffer
    //m_pWindow->clear();

    // Draw layers
    for(unsigned index = 0; index < m_LayerCount; ++index)
    {
        // Checking size of the layer
        // Skipping if there's nothing to draw
        if(m_aLayers[index].getSize() == 0) continue;

        // Drawing the content of the current layer
        m_pWindow->draw(m_aLayers[index].getVertices(),
                       m_aLayers[index].getSize(),
                       m_aLayers[index].getPrimitive(),
                       m_aLayers[index].getState());
    }

    // Swapping buffer
    m_pWindow->display();
}

void GraphicEngine::initLayers()
{
    m_aLayers = new Layer[m_LayerCount];
    for(unsigned i = 0; i < m_LayerCount; ++i)
    {
        m_aLayers[i].init(m_aLayersSize[i]);
    }
}

void GraphicEngine::constructLayers(double factor)
{

}

void GraphicEngine::prepareLayers()
{
    for(unsigned index = 0; index < m_LayerCount; ++index)
    {
        // Prepare the layer
        m_aLayers[index].prepare();
    }
}
