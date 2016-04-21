#include <exceptions.h>
#include <fstream>
#include <gameobjectcreator.h>

UsualMapCreator::UsualMapCreator(std::string filename)
    : ObjectsCreator(filename) {
    mapStates.append("+"); //пустое пространство
    mapStates.append("0"); //дорога
    mapStates.append("s"); //камень
}

void UsualMapCreator::readfile() {
    int numString = 0;
    int stringLen = 0;
    char c;
    std::ifstream fin(file); // (ВВЕЛИ НЕ КОРРЕКТНОЕ ИМЯ ФАЙЛА)

    if (!fin.is_open()) // если файл не открыт
        throw(fileLoadError());
    fin >> stringLen;
    fin >> numString;

    for (int i = 0; i < numString; i++)
        for (int j = 0; j < stringLen; j++) {
            fin >> c;
            Area u = getAreaByChar(c);
            if (u != ERROR) {
                MapObject mapObject(texture_size * j, texture_size, u);
                switch (u) {
                case FREE:
                    usualmap.freeAreas.push_back(mapObject);
                    break;
                case STONE:
                    usualmap.stones.push_back(mapObject);
                    break;
                case ROAD:
                    usualmap.roads.push_back(mapObject);
                    break;
                default:
                    break;
                }
            }
        }
}

Area UsualMapCreator::getAreaByChar(char c) {
    if (c == mapStates[0])
        return FREE;
    if (c == mapStates[1])
        return ROAD;
    if (c == mapStates[2])
        return STONE;
    return ERROR; // этого не должно происходить
}
