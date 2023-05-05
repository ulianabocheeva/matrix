#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <iostream>

class exceptions: public std::exception // public, как наследуется - protected & public идет для всех
{
private:
    char *message;
public:
    // параметртизированный конструктор - тут частично
    explicit exceptions(const char *msg) : std::exception(){message = (char *)msg;} // explicit - запрещает неявный вызов, используется только на конструкторах
    const char *what() const noexcept{return message;} // noexcept - показывает, что никаких исключений не выдаст
    // два const, первый показывает что вернет константый тип, второый показывает, что внутренний this метода будеи константый
};

#endif // EXCEPTIONS_H
