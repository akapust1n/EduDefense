#pragma once
#include <exception>

// Базовый класс исключений
class my_base_exception : public std::exception {
};

// Класс ошибки памяти
class memory_alloc_error : public my_base_exception {
public:
    memory_alloc_error();
    virtual const char* what() const throw();
};

// Класс ошибки загрузки статического файла
class file_load_error : public my_base_exception {
public:
    file_load_error();
    virtual const char* what() const throw();
};







