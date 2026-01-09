#pragma once
#include <iostream>
using std::string;

class Ship
{
private:
  string name;
  int size;
  int hitsTaken;

public:
  Ship(string &Name, int shipSize) : name(Name), size(shipSize), hitsTaken(0) {}
  virtual ~Ship() = 0;
  virtual void takeHit() { hitsTaken++; };
  inline bool isSunk() const { return hitsTaken >= size; }

  inline int getSize() { return size; };
  inline string getName() { return name; }
};
