#pragma once  
#include "Ship.hpp"

class Destroyer : public Ship
{
private:
  /* data */
public:
  Destroyer(string &Name) : Ship(Name, 2) {}
  ~Destroyer() {}
};
