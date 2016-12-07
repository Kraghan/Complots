//
// Created by Kraghan on 02/12/2016.
//

#ifndef COMPLOTS_LAYER_HPP
#define COMPLOTS_LAYER_HPP


#include "Sprite.hpp"

class Layer
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:

    /// Enum to set the type of datas contained in the layer
    enum LAYER_TYPE
    {
        NONE,
        SPRITE,
        TEXT
    };

    /// Default constructor
    explicit                Layer                   ();

    /// Default destructor
    virtual                 ~Layer                  ();

    /// Reset the layer for the next frame
    void                    prepare                 ();

    /// Append the vertices of a sprite at the end of the layer
    void                    append                  (Sprite * sprite, double offset);

    /// Initialize the layer
    void                    init                    (unsigned layerSize);

    ///

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
};


#endif //COMPLOTS_LAYER_HPP
