#include <exceptions.h>
#include <fstream>
#include <gameobjectcreator.h>

void ObjectsCreator::readfile() {
    int num_string = 0;
    int string_len = 0;
    ifstream fin(file); // (ВВЕЛИ НЕ КОРРЕКТНОЕ ИМЯ ФАЙЛА)

    if (!fin.is_open()) // если файл не открыт
        throw(file_load_error());
    fin>>string_len;
    fin>>num_string;
}
