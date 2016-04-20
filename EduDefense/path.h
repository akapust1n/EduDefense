#ifndef PATH_H
#define PATH_H

#include <vector>
#include "mapobject.h"

class Path
{
public:
    /*
     * !!!!!!!!!!!!!!!!!!HARD CODE
     */
    Path() {
        path.push_back(MapObject(-60, 60, ROAD));
        path.push_back(MapObject(540, 60, ROAD));
        path.push_back(MapObject(540, 180, ROAD));
        path.push_back(MapObject(300, 180, ROAD));
        path.push_back(MapObject(300, 300, ROAD));
        path.push_back(MapObject(660, 300, ROAD));
        path.push_back(MapObject(660, 480, ROAD));
        path.push_back(MapObject(180, 480, ROAD));
        path.push_back(MapObject(180, 300, ROAD));
        path.push_back(MapObject(60, 300, ROAD));
        path.push_back(MapObject(60, 540, ROAD));
        path.push_back(MapObject(-60, 540, ROAD));
        it = path.begin();
    }

    std::vector<MapObject> path;
    std::vector<MapObject>::iterator it;
};

#endif // PATH_H
