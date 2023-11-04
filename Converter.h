#include "iostream"
#include "memory"
#include "string"

class Converter{
public:
    virtual  ~Converter() = default;
    virtual void converter() = 0;
};