#include <exceptions.h>
#include <fstream>
#include <gameobjectcreator.h>

ObjectsCreator::ObjectsCreator(std::string filename) : file(filename) {
    map_states.append(" "); //пустое пространство
    map_states.append("0"); //дорога
    map_states.append("s"); //камень
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
            map_state u = case_map_state(temp);
            if (u != not_map_element) {
                MapObject z(texture_size * j, texture_size, u);
                switch (u) {
                case freearea:
                    freeareas.push_back(z);
                    break;
                case stone:
                    stones.push_back(z);
                    break;
                case road:
                    roads.push_back(z);
                    break;
                default:
                    break;
                }
            }
        }
}

map_state ObjectsCreator::case_map_state(char temp) {
    if (temp == map_states[0])
        return freearea;
    if (temp == map_states[1])
        return road;
    if (temp == map_states[2])
        return stone;
    return not_map_element; // этого не должно происходить
}
