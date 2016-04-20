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
        path.push_back(MapObject(0, 0, ROAD));
        path.push_back(MapObject(200, 200, ROAD));
        it = path.begin();
    }

    std::vector<MapObject> path;
    std::vector<MapObject>::iterator it;
};

#endif // PATH_H
