#include "tiledmapobjectgroup.h"

TiledMapObjectGroup::TiledMapObjectGroup()
{
    this->name = "";
    this->width = 0;
    this->height = 0;
}

TiledMapObjectGroup::TiledMapObjectGroup(string name, int width, int height)
{
    this->name = name;
    this->width = width;
    this->height = height;
}

TiledMapObjectGroup::~TiledMapObjectGroup()
{

}
