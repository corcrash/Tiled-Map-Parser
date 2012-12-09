#include "tiledmapobject.h"

TiledMapObject::TiledMapObject()
{
    this->name = "";
    this->type = "";
    this->width = 0;
    this->height = 0;
    this->x = 0;
    this->y = 0;
}

TiledMapObject::TiledMapObject(string name, string type, int width, int height, int x, int y)
{
    this->name = name;
    this->type = type;
    this->width = width;
    this->height = height;
    this->x = x;
    this->y = y;
}

TiledMapObject::~TiledMapObject()
{

}
