#ifndef TILEDMAPLAYER_H
#define TILEDMAPLAYER_H

#include <iostream>
#include <vector>

using namespace std;

class TiledMapLayer
{
private:
    string name;
    int width;
    int height;
    vector<int> data;

public:
    TiledMapLayer();
    TiledMapLayer(string name, int width, int height);
    ~TiledMapLayer();

    string getName(){ return this->name; }
    int getWidth(){ return this->width; }
    int getHeight(){ return this->height; }
    int getData(int index){ return this->data[index]; }

    void setName(string name){ this->name = name; }
    void setName(char* name){ this->name = name; }
    void setWidth(int width){ this->width = width; }
    void setHeight(int height){ this->height = height; }
    void insertData(int data){ this->data.push_back(data); }
};

#endif // TILEDMAPLAYER_H
