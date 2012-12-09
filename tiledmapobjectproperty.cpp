#include "tiledmapobjectproperty.h"

TiledMapObjectProperty::TiledMapObjectProperty()
{
    this->name = "";
    this->value = "";
}

TiledMapObjectProperty::TiledMapObjectProperty(string name, string value)
{
    this->name = name;
    this->value = value;
}

TiledMapObjectProperty::~TiledMapObjectProperty()
{

}
