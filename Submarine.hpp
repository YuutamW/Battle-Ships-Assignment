#pragma once 
#include "Ship.hpp"
using std::string;
class Submarine : public Ship
{
private:
  /* data */
public:
  Submarine(const string &Name = "Sumbarine") : Ship(Name, 3) {}
  ~Submarine() {}
};
