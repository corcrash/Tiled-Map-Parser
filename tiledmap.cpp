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

TiledMap::TiledMap(string source)
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

bool TiledMap::loadMap(string source)
{
    XMLDocument map;
    map.LoadFile(source.data());

    XMLElement* map_info =  map.FirstChildElement("map");

    this->version = map_info->Attribute("version");
    this->orientation = map_info->Attribute("orientation");

    this->width = this->stringToInt(map_info->Attribute("width"));
    this->height = this->stringToInt(map_info->Attribute("height"));
    this->tilewidth = this->stringToInt(map_info->Attribute("tilewidth"));
    this->tileheight = this->stringToInt(map_info->Attribute("tileheight"));

    this->loadTilesets(&map);
    this->loadLayers(&map);
    this->loadObjectGroups(&map);
}

bool TiledMap::loadTilesets(XMLDocument *map)
{
    XMLElement* tileset;
    if((tileset = map->FirstChildElement("map")->FirstChildElement("tileset")) != NULL)
    {
        TiledMapTileset* temp = new TiledMapTileset();
        temp->setFirstgid(this->stringToInt(tileset->Attribute("firstgid")));
        temp->setName(tileset->Attribute("name"));
        temp->setTilewidth(this->stringToInt(tileset->Attribute("tilewidth")));
        temp->setTileheight(this->stringToInt(tileset->Attribute("tileheight")));
        temp->setImageSource(tileset->FirstChildElement("image")->Attribute("source"));
        temp->setImageTrans(tileset->FirstChildElement("image")->Attribute("trans"));
        temp->setImageWidth(this->stringToInt(tileset->FirstChildElement("image")->Attribute("width")));
        temp->setImageHeight(this->stringToInt(tileset->FirstChildElement("image")->Attribute("height")));

        this->insertTileset(temp);
    }

    while(tileset != NULL && (tileset = tileset->NextSiblingElement("tileset")) != NULL)
    {
        TiledMapTileset* temp = new TiledMapTileset();
        temp->setFirstgid(this->stringToInt(tileset->Attribute("firstgid")));
        temp->setName(tileset->Attribute("name"));
        temp->setTilewidth(this->stringToInt(tileset->Attribute("tilewidth")));
        temp->setTileheight(this->stringToInt(tileset->Attribute("tileheight")));
        temp->setImageSource(tileset->FirstChildElement("image")->Attribute("source"));
        temp->setImageTrans(tileset->FirstChildElement("image")->Attribute("trans"));
        temp->setImageWidth(this->stringToInt(tileset->FirstChildElement("image")->Attribute("width")));
        temp->setImageHeight(this->stringToInt(tileset->FirstChildElement("image")->Attribute("height")));

        this->insertTileset(temp);
    }
}

bool TiledMap::loadLayers(XMLDocument *map)
{
    XMLElement* layer;
    XMLElement* tile;
    if((layer = map->FirstChildElement("map")->FirstChildElement("layer")) != NULL)
    {
        TiledMapLayer* temp = new TiledMapLayer();
        temp->setName(layer->Attribute("name"));
        temp->setWidth(this->stringToInt(layer->Attribute("width")));
        temp->setHeight(this->stringToInt(layer->Attribute("height")));

        if((tile = layer->FirstChildElement("data")->FirstChildElement("tile")) != NULL)
        {
            temp->insertData(this->stringToInt(tile->Attribute("gid")));
        }

        while((tile = tile->NextSiblingElement("tile")) != NULL)
        {
            temp->insertData(this->stringToInt(tile->Attribute("gid")));
        }

        this->insertLayer(temp);
    }

    while(layer != NULL && (layer = layer->NextSiblingElement("layer")) != NULL)
    {
        TiledMapLayer* temp = new TiledMapLayer();
        temp->setName(layer->Attribute("name"));
        temp->setWidth(this->stringToInt(layer->Attribute("width")));
        temp->setHeight(this->stringToInt(layer->Attribute("height")));

        if((tile = layer->FirstChildElement("data")->FirstChildElement("tile")) != NULL)
        {
            temp->insertData(this->stringToInt(tile->Attribute("gid")));
        }

        while((tile = tile->NextSiblingElement("tile")) != NULL)
        {
            temp->insertData(this->stringToInt(tile->Attribute("gid")));
        }

        this->insertLayer(temp);
    }
}

bool TiledMap::loadObjectGroups(XMLDocument *map)
{
    XMLElement* objectgroup;
    XMLElement* object;
    XMLElement* property;

    if((objectgroup = map->FirstChildElement("map")->FirstChildElement("objectgroup")) != NULL)
    {
        TiledMapObjectGroup* temp = new TiledMapObjectGroup();
        temp->setName(objectgroup->Attribute("name"));
        temp->setWidth(this->stringToInt(objectgroup->Attribute("width")));
        temp->setHeight(this->stringToInt(objectgroup->Attribute("height")));

        if((object = objectgroup->FirstChildElement("object")) != NULL)
        {
            TiledMapObject* obj = new TiledMapObject();

            obj->setName(object->Attribute("name"));
            obj->setType(object->Attribute("type"));
            obj->setX(this->stringToInt(object->Attribute("x")));
            obj->setY(this->stringToInt(object->Attribute("y")));
            obj->setWidth(this->stringToInt(object->Attribute("width")));
            obj->setHeight(this->stringToInt(object->Attribute("height")));

            if((property = object->FirstChildElement("properties")->FirstChildElement("property")) != NULL)
            {
                TiledMapObjectProperty* prop = new TiledMapObjectProperty();

                prop->setName(property->Attribute("name"));
                prop->setValue(property->Attribute("value"));

                obj->insertProperty(prop);
            }

            while((property = object->NextSiblingElement("property")) != NULL)
            {
                TiledMapObjectProperty* prop = new TiledMapObjectProperty();

                prop->setName(property->Attribute("name"));
                prop->setValue(property->Attribute("value"));

                obj->insertProperty(prop);
            }

            temp->insertObject(obj);
        }

        while((object = object->NextSiblingElement("object")) != NULL)
        {
            TiledMapObject* obj = new TiledMapObject();

            obj->setName(object->Attribute("name"));
            obj->setType(object->Attribute("type"));
            obj->setX(this->stringToInt(object->Attribute("x")));
            obj->setY(this->stringToInt(object->Attribute("y")));
            obj->setWidth(this->stringToInt(object->Attribute("width")));
            obj->setHeight(this->stringToInt(object->Attribute("height")));

            if((property = object->FirstChildElement("properties")->FirstChildElement("property")) != NULL)
            {
                TiledMapObjectProperty* prop = new TiledMapObjectProperty();

                prop->setName(property->Attribute("name"));
                prop->setValue(property->Attribute("value"));

                obj->insertProperty(prop);
            }

            while((property = object->NextSiblingElement("property")) != NULL)
            {
                TiledMapObjectProperty* prop = new TiledMapObjectProperty();

                prop->setName(property->Attribute("name"));
                prop->setValue(property->Attribute("value"));

                obj->insertProperty(prop);
            }

            temp->insertObject(obj);
        }

        this->insertObjectGroup(temp);
    }

    while((objectgroup = objectgroup->NextSiblingElement("objectgroup")) != NULL)
    {
        TiledMapObjectGroup* temp = new TiledMapObjectGroup();
        temp->setName(objectgroup->Attribute("name"));
        temp->setWidth(this->stringToInt(objectgroup->Attribute("width")));
        temp->setHeight(this->stringToInt(objectgroup->Attribute("height")));

        if((object = objectgroup->FirstChildElement("object")) != NULL)
        {
            TiledMapObject* obj = new TiledMapObject();

            obj->setName(object->Attribute("name"));
            obj->setType(object->Attribute("type"));
            obj->setX(this->stringToInt(object->Attribute("x")));
            obj->setY(this->stringToInt(object->Attribute("y")));
            obj->setWidth(this->stringToInt(object->Attribute("width")));
            obj->setHeight(this->stringToInt(object->Attribute("height")));

            if((property = object->FirstChildElement("properties")->FirstChildElement("property")) != NULL)
            {
                TiledMapObjectProperty* prop = new TiledMapObjectProperty();

                prop->setName(property->Attribute("name"));
                prop->setValue(property->Attribute("value"));

                obj->insertProperty(prop);
            }

            while((property = object->NextSiblingElement("property")) != NULL)
            {
                TiledMapObjectProperty* prop = new TiledMapObjectProperty();

                prop->setName(property->Attribute("name"));
                prop->setValue(property->Attribute("value"));

                obj->insertProperty(prop);
            }

            temp->insertObject(obj);
        }

        while(object != NULL && (object = object->NextSiblingElement("object")) != NULL)
        {
            TiledMapObject* obj = new TiledMapObject();

            obj->setName(object->Attribute("name"));
            obj->setType(object->Attribute("type"));
            obj->setX(this->stringToInt(object->Attribute("x")));
            obj->setY(this->stringToInt(object->Attribute("y")));
            obj->setWidth(this->stringToInt(object->Attribute("width")));
            obj->setHeight(this->stringToInt(object->Attribute("height")));

            if((property = object->FirstChildElement("properties")->FirstChildElement("property")) != NULL)
            {
                TiledMapObjectProperty* prop = new TiledMapObjectProperty();

                prop->setName(property->Attribute("name"));
                prop->setValue(property->Attribute("value"));

                obj->insertProperty(prop);
            }

            while((property = object->NextSiblingElement("property")) != NULL)
            {
                TiledMapObjectProperty* prop = new TiledMapObjectProperty();

                prop->setName(property->Attribute("name"));
                prop->setValue(property->Attribute("value"));

                obj->insertProperty(prop);
            }

            temp->insertObject(obj);
        }

        this->insertObjectGroup(temp);
    }
}
