#ifndef TILEDMAPOBJECT_H
#define TILEDMAPOBJECT_H

#include <iostream>
#include <vector>
#include "tiledmapobjectproperty.h"

using namespace std;

class TiledMapObject
{
private:
    string name;
    string type;
    int width;
    int height;
    int x;
    int y;
    vector<TiledMapObjectProperty*> properties;

public:
    TiledMapObject();
    TiledMapObject(string name, string type, int width, int height, int x, int y);
    ~TiledMapObject();

    string getName(){ return this->name; }
    string getType(){ return this->type; }
    int getWidth(){ return this->width; }
    int getHeight(){ return this->height; }
    int getX(){ return this->x; }
    int getY(){ return this->y; }
    TiledMapObjectProperty* getProperty(int index){ return this->properties[index]; }
    TiledMapObjectProperty* getProperty(string name)
    {
        for(int i=0; i<this->properties.size(); i++)
        {
            string temp = this->properties[i]->getName();
            if(temp == name)
                return this->properties[i];
        }
    }

    void setName(string name){ this->name = name; }
    void setName(char* name){ this->name = name; }
    void setType(string type){ this->type = type; }
    void setType(char* type ){ this->type = type; }
    void setWidth(int width){ this->width = width; }
    void setHeight(int height){ this->height = height; }
    void setX(int x){ this->x = x; }
    void setY(int y){ this->y = y; }
    void insertProperty(string property, string value)
    {
        TiledMapObjectProperty* temp = new TiledMapObjectProperty(property, value);
        this->properties.push_back(temp);
    }
    void insertProperty(TiledMapObjectProperty* property)
    {
        this->properties.push_back(property);
    }

};

#endif // TILEDMAPOBJECT_H
