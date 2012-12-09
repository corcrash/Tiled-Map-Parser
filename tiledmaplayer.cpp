#include "tiledmaplayer.h"

TiledMapLayer::TiledMapLayer()
{
    this->name = "";
    this->height = 0;
    this->width = 0;
}

TiledMapLayer::TiledMapLayer(string name, int width, int height)
{
    this->name = name;
    this->width = width;
    this->height = height;
}

TiledMapLayer::~TiledMapLayer()
{

}
