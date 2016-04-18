#include <exceptions.h>
#include <fstream>
#include <gameobjectcreator.h>

ObjectsCreator::ObjectsCreator(std::string filename) : file(filename) {
    mapStates.append(" "); //пустое пространство
    mapStates.append("0"); //дорога
    mapStates.append("s"); //камень
}

void ObjectsCreator::readfile() {
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
            map_state u = charToMapState(temp);
            if (u != not_map_element) {
                MapObject *mapObject = new MapObject(texture_size * j, texture_size, u);
                switch (u) {
                case freearea:
                    freeAreas.push_back(mapObject);
                    break;
                case stone:
                    stones.push_back(mapObject);
                    break;
                case road:
                    roads.push_back(mapObject);
                    break;
                default:
                    break;
                }
            }
        }
}

map_state ObjectsCreator::charToMapState(char c) {
    if (c == mapStates[0])
        return freearea;
    if (c == mapStates[1])
        return road;
    if (c == mapStates[2])
        return stone;
    return not_map_element; // этого не должно происходить
}
