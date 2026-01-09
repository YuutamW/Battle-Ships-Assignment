#pragma once
#include "Ship.hpp"

class BattleShip : public Ship
{
public:
  BattleShip(const string &Name = "BattleShip") : Ship(Name, 4) {}
  ~BattleShip() {}
};
