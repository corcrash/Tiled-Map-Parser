#ifndef TILEDMAPOBJECTGROUP_H
#define TILEDMAPOBJECTGROUP_H

#include <iostream>
#include "tiledmapobject.h"

using namespace std;

class TiledMapObjectGroup
{
private:
    string name;
    int width;
    int height;
    vector<TiledMapObject*> objects;

public:
    TiledMapObjectGroup();
    TiledMapObjectGroup(string name, int width, int height);
    ~TiledMapObjectGroup();

    void setName(string name){ this->name = name; }
    void setName(char* name){ this->name = name; }
    void setWidth(int width){ this->width = width; }
    void setHeight(int height){ this->height = height; }
    void insertObject(string name, string type, int width, int height, int x, int y)
    {
        TiledMapObject* temp = new TiledMapObject(name, type, width, height, x, y);

        this->objects.push_back(temp);
    }
    void insertObject(TiledMapObject* object)
    {
        this->objects.push_back(object);
    }

    string getName(){ return this->name; }
    int getWidth(){ return this->width; }
    int getHeight(){ return this->height; }
    TiledMapObject* getObject(int index){ return this->objects[index]; }
    TiledMapObject* getObject(string name)
    {
        for(int i=0; i<this->objects.size(); i++)
        {
            string temp = this->objects[i]->getName();

            if(temp == name)
                return this->objects[i];
        }
    }
};

#endif // TILEDMAPOBJECTGROUP_H
