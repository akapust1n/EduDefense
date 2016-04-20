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
    int num_string = 0;
    int string_len = 0;
    char temp;
    std::ifstream fin(file); // (ВВЕЛИ НЕ КОРРЕКТНОЕ ИМЯ ФАЙЛА)

    if (!fin.is_open()) // если файл не открыт
        throw(file_load_error());
    fin >> string_len;
    fin >> num_string;

    for (int i = 0; i < num_string; i++)
        for (int j = 0; j < string_len; j++) {
            fin >> temp;
            Area u = getAreaByChar(temp);
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
