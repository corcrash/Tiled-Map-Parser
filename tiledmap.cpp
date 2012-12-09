#include "tiledmap.h"

TiledMap::TiledMap()
{
    this->version = "";
    this->orientation = "";
    this->width = 0;
    this->height = 0;
    this->tilewidth = 0;
    this->tileheight = 0;
}

TiledMap::TiledMap(string version, string orientation, int width, int height, int tilewidth, int tileheight)
{
    this->version = version;
    this->orientation = orientation;
    this->width = width;
    this->height = height;
    this->tilewidth = tilewidth;
    this->tileheight = tileheight;
}

TiledMap::~TiledMap()
{

}
