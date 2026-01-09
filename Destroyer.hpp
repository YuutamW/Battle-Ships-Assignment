#pragma once  
#include "Ship.hpp"

class Destroyer : public Ship
{
private:
  /* data */
public:
  Destroyer(const string &Name = "Destroyer") : Ship(Name, 2) {}
  ~Destroyer() {}
};
