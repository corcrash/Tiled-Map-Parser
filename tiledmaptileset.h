#ifndef TILEDMAPTILESET_H
#define TILEDMAPTILESET_H
#include <iostream>

using namespace std;

class TiledMapTileset
{
private:
    int firstgid;
    string name;
    int tilewidth;
    int tileheight;
    string image_source;
    string image_trans;
    int image_width;
    int image_height;

public:
    TiledMapTileset();
    TiledMapTileset(int firstgid, string name, int tilewidth, int tileheight, string image_source, string image_trans, int image_width, int image_height);
    ~TiledMapTileset();

    int getFirstgid(){ return this->firstgid; }
    string getName(){ return this->name; }
    int getTilewidth(){ return this->tilewidth; }
    int getTileheight(){ return this->tileheight; }
    string getImageSource(){ return this->image_source; }
    string getImageTrans(){ return this->image_trans; }
    int getImageWidth(){ return this->image_width; }
    int getImageHeight(){ return this->image_height; }

    void setFirstgid(int gid){ this->firstgid = gid; }
    void setName(string name){ this->name = name; }
    void setName(char* name){ this->name = name; }
    void setTilewidth(int width){ this->tilewidth = width; }
    void setTileheight(int height){ this->tileheight = height; }
    void setImageSource(string source){ this->image_source = source; }
    void setImageSource(char* source){ this->image_source = source; }
    void setImageTrans(string trans){ this->image_trans = trans; }
    void setImageTrans(char* trans){ this->image_trans = trans; }
    void setImageWidth(int width){ this->image_width = width; }
    void setImageHeight(int height){ this->image_height = height; }
};

#endif // TILEDMAPTILESET_H
