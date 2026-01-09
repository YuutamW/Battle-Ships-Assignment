#pragma once
#include "Ship.hpp"

class Carrier :  public Ship
{ 
public:
  Carrier(string &Name) : Ship(Name,5) {}
  ~Carrier();
};

