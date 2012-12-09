#ifndef TILEDMAPOBJECTPROPERTY_H
#define TILEDMAPOBJECTPROPERTY_H

#include <iostream>
#include <sstream>

using namespace std;

class TiledMapObjectProperty
{
private:
    string name;
    string value;

public:
    TiledMapObjectProperty();
    TiledMapObjectProperty(string name, string value);
    ~TiledMapObjectProperty();

    string getValueString(){ return this->value; }
    int getValueInt(){ stringstream daString(this->value); int value; daString >> value; return value; }
    string getName(){ return this->name; }

    void setName(string name){ this->name = name; }
    void setName(char* name){ this->name = name; }
    void setValue(string value){ this->value = value; }
    void setValue(char* value){ this->value = value; }
};

#endif // TILEDMAPOBJECTPROPERTY_H
