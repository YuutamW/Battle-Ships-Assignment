#pragma once
#include "Ship.hpp"
class Cruiser : public Ship
{
private:
  /* data */
public:
  Cruiser(const string &Name = "Cruiser") : Ship(Name, 3) {}
  ~Cruiser() {}
};
