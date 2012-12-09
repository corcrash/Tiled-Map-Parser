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
    TiledMap(string version, string orientation, int width, int height, int tilewidth, int tileheight);
    ~TiledMap();

    string getVersion(){ return this->version; }
    string getOrientation(){ return this->orientation; }
    int getWidth(){ return this->width; }
    int getHeight(){ return this->height; }
    int getTileWidth(){ return this->tilewidth; }
    int getTileHeight(){ return this->tileheight; }
    TiledMapTileset* getTileset(int index){ return this->tilesets[index]; }
    TiledMapTileset* getTileset(string name)
    {
        for(int i=0; i<this->tilesets.size(); i++)
        {
            string temp = this->tilesets[i]->getName();

            if(temp == name)
                return this->tilesets[i];
        }
    }
    TiledMapLayer* getLayer(int index){ return this->layers[index]; }
    TiledMapLayer* getLayer(string name)
    {
        for(int i=0; i<this->layers.size(); i++)
        {
            string temp = this->layers[i]->getName();

            if(temp == name)
                return this->layers[i];
        }
    }
    TiledMapObjectGroup* getObjectGroup(int index){ return this->objectgroups[index]; }
    TiledMapObjectGroup* getObjectGroup(string name)
    {
        for(int i=0; i<this->objectgroups.size(); i++)
        {
            string temp = this->objectgroups[i]->getName();

            if(temp == name)
                return this->objectgroups[i];
        }
    }

};

#endif // TILEDMAPDATA_H
