#include <exceptions.h>

//------------------------------Реализация класса ошибки памяти---------------------------
memory_alloc_error::memory_alloc_error() {
}

const char* memory_alloc_error::what() const throw() {
     return "memory alloc error \n";
}

//------------------------------Реализация класса ошибки загрузки статического файла ---------------------------
file_load_error::file_load_error() {
}

const char* file_load_error::what() const throw() {
     return "file load error  \n";
}

