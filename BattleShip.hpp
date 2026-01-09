#pragma once
#include "Ship.hpp"

class BattleShip : public Ship
{
public:
  BattleShip(string &Name) : Ship(Name, 4) {}
  ~BattleShip() {}
};
