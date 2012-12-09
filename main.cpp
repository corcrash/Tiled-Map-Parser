#include <iostream>
#include "tiledmap.h"

using namespace std;

int main()
{
    XMLDocument doc;
    doc.LoadFile("map.tmx");
    cout << doc.FirstChildElement("map")->FirstChildElement("tileset")->FirstChildElement("image")->Attribute("source") << endl;

    return 0;
}

