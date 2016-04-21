#pragma once
#include <exception>

// Базовый класс исключений
class my_base_exception : public std::exception {
};

// Класс ошибки памяти
class memoryAllocError : public my_base_exception {
public:
    memoryAllocError();
    virtual const char* what() const throw();
};

// Класс ошибки загрузки статического файла
class fileLoadError : public my_base_exception {
public:
    fileLoadError();
    virtual const char* what() const throw();
};








