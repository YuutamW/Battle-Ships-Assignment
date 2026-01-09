#pragma once
#include "Ship.hpp"

class Carrier :  public Ship
{ 
public:
  Carrier(const string &Name = "Carrier") : Ship(Name,5) {}
  ~Carrier() {}
};

