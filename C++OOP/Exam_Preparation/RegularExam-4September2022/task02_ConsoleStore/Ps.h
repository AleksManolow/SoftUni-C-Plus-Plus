#ifndef __PS_H
#define __PS_H
#include"Console.h"

class Ps:public Console
{
private:
    int _generation;
public:
    Ps(int price, int quality, int generation) : Console(price,quality), _generation(generation) {
  }
  void print() const
  {
    std::cout << "PS with generation " << _generation << ", ";
    Console::print();
  }
};

#endif