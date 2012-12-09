#include "tiledmaptileset.h"

TiledMapTileset::TiledMapTileset()
{
    this->firstgid = 0;
    this->name = "";
    this->tilewidth = 0;
    this->tileheight = 0;
    this->image_source = "";
    this->image_trans = "";
    this->image_width = 0;
    this->image_height = 0;
}

TiledMapTileset::TiledMapTileset(int firstgid, string name, int tilewidth, int tileheight, string image_source, string image_trans, int image_width, int image_height)
{
    this->firstgid = firstgid;
    this->name = name;
    this->tilewidth = tilewidth;
    this->tileheight = tileheight;
    this->image_source = image_source;
    this->image_trans = image_trans;
    this->image_height = image_height;
    this->image_width = image_width;
}

TiledMapTileset::~TiledMapTileset()
{

}
