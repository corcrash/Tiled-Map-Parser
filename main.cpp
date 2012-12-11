#include <iostream>
#include "tiledmap.h"

using namespace std;

int main()
{
    TiledMap map;

    map.loadMap("map.tmx");

    cout << map.getVersion() << " : " << map.getOrientation() << " : " << map.getWidth() << endl;

    cout << map.getTileset("Tileset2")->getFirstgid() << map.getTileset("Tileset2")->getName() <<  map.getTileset("Tileset2")->getTilewidth() << map.getTileset("Tileset2")->getTileheight() <<  map.getTileset("Tileset2")->getImageSource() << map.getTileset("Tileset2")->getImageTrans() << map.getTileset("Tileset2")->getImageWidth() << map.getTileset("Tileset2")->getImageHeight() << endl;

    TiledMapLayer* temp = map.getLayer("Back");

    cout << temp->getName() << " : " << temp->getHeight() << " : " << temp->getWidth() << " : " << temp->getDataSize() << endl;
    cout << "Data:" << endl;

    for(int i=0; i<temp->getDataSize(); i++)
    {
        cout << temp->getData(i);
    }

    cout << endl;

    temp = map.getLayer("Front");

    cout << temp->getName() << " : " << temp->getHeight() << " : " << temp->getWidth() << " : " << temp->getDataSize() << endl;
    cout << "Data:" << endl;

    for(int i=0; i<temp->getDataSize(); i++)
    {
        cout << temp->getData(i);
    }

    cout << endl;

    cout << map.getObjectGroup("Objects")->getObject("Hero")->getProperty("health")->getValueInt() << endl;

    return 0;
}
