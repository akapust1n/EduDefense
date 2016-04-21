#include <exceptions.h>

// Реализация класса ошибки памяти
memoryAllocError::memoryAllocError() {
}

const char* memoryAllocError::what() const throw() {
     return "memory alloc error \n";
}

// Реализация класса ошибки загрузки статического файла
fileLoadError::fileLoadError() {
}

const char* fileLoadError::what() const throw() {
     return "file load error \n";
}
