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
        path.push_back(MapObject(0, 60, ROAD));
        path.push_back(MapObject(560, 60, ROAD));
        path.push_back(MapObject(560, 180, ROAD));
        it = path.begin();
    }

    std::vector<MapObject> path;
    std::vector<MapObject>::iterator it;
};

#endif // PATH_H
