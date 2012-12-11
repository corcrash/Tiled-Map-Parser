#ifndef TILEDMAPDATA_H
#define TILEDMAPDATA_H

#include <iostream>
#include <vector>
#include "tinyxml2.h"
#include "tiledmaptileset.h"
#include "tiledmaplayer.h"
#include "tiledmapobjectgroup.h"

using namespace std;
using namespace tinyxml2;

class TiledMap
{
private:
    string version;
    string orientation;
    int width;
    int height;
    int tilewidth;
    int tileheight;
    vector<TiledMapTileset*> tilesets;
    vector<TiledMapLayer*> layers;
    vector<TiledMapObjectGroup*> objectgroups;

public:
    TiledMap();
    TiledMap(string source);
    ~TiledMap();

    bool loadMap(string source);
    bool loadTilesets(XMLDocument *map);
    bool loadLayers(XMLDocument *map);
    bool loadObjectGroups(XMLDocument *map);

    int stringToInt(string str)
    {
        istringstream temp(str);
        int ret;
        temp >> ret;

        return ret;
    }

    void setVersion(string version){ this->version = version; }
    void setVersion(char* version){ this->version = version; }
    void setOrientation(string orientation){ this->orientation = orientation; }
    void setOrientation(char* orientation){ this->orientation = orientation; }
    void setWidth(int width){ this->width = width; }
    void setHeight(int height){ this->height = height; }
    void setTileWidth(int tilewidth){ this->tilewidth = tilewidth; }
    void setTileHeight(int tileheight){ this->tileheight = tileheight; }
    void insertTileset(int firstgid, string name, int tilewidth, int tileheight, string image_source, string image_trans, int image_width, int image_height)
    {
        TiledMapTileset* temp = new TiledMapTileset(firstgid, name, tilewidth, tileheight, image_source, image_trans, image_width, image_height);

        this->tilesets.push_back(temp);
    }
    void insertTileset(TiledMapTileset* tileset)
    {
        this->tilesets.push_back(tileset);
    }
    void insertLayer(string name, int width, int height)
    {
        TiledMapLayer* temp = new TiledMapLayer(name, width, height);

        this->layers.push_back(temp);
    }
    void insertLayer(TiledMapLayer* layer)
    {
        this->layers.push_back(layer);
    }
    void insertObjectGroup(string name, int width, int height)
    {
        TiledMapObjectGroup* temp = new TiledMapObjectGroup(name, width, height);

        this->objectgroups.push_back(temp);
    }
    void insertObjectGroup(TiledMapObjectGroup* group)
    {
        this->objectgroups.push_back(group);
    }

    string getVersion(){ return this->version; }
    string getOrientation(){ return this->orientation; }
    int getWidth(){ return this->width; }
    int getHeight(){ return this->height; }
    int getTileWidth(){ return this->tilewidth; }
    int getTileHeight(){ return this->tileheight; }
    TiledMapTileset* getTileset(int index){ if(this->tilesets.size() < index) return NULL; return this->tilesets[index]; }
    TiledMapTileset* getTileset(string name)
    {
        if(this->tilesets.empty())
            return NULL;
        for(int i=0; i<this->tilesets.size(); i++)
        {
            string temp = this->tilesets[i]->getName();

            if(temp == name)
                return this->tilesets[i];
        }
    }
    TiledMapLayer* getLayer(int index){ if(this->layers.size() < index) return NULL; return this->layers[index]; }
    TiledMapLayer* getLayer(string name)
    {
        if(this->layers.empty())
            return NULL;
        for(int i=0; i<this->layers.size(); i++)
        {
            string temp = this->layers[i]->getName();

            if(temp == name)
                return this->layers[i];
        }
    }
    TiledMapObjectGroup* getObjectGroup(int index){ if(this->objectgroups.size() < index) return NULL; return this->objectgroups[index]; }
    TiledMapObjectGroup* getObjectGroup(string name)
    {
        if(this->objectgroups.empty())
            return NULL;

        for(int i=0; i<this->objectgroups.size(); i++)
        {
            string temp = this->objectgroups[i]->getName();

            if(temp == name)
                return this->objectgroups[i];
        }
    }
};

#endif // TILEDMAPDATA_H
