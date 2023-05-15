#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <iostream>

class exceptions: public std::exception
{
private:
    char *message;
public:
    explicit exceptions(const char *msg) : std::exception(){message = (char *)msg;}
    const char *what() const noexcept{return message;}
};

#endif // EXCEPTIONS_H
