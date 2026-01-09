#pragma once 
#include "Ship.hpp"

class Submarine : public Ship
{
private:
  /* data */
public:
  Submarine(string &Name) : Ship(Name, 3) {}
  ~Submarine() {}
};
