#pragma once
#include "Ship.hpp"
class Cruiser : public Ship
{
private:
  /* data */
public:
  Cruiser(string &Name) : Ship(Name, 3) {}
  ~Cruiser();
};
