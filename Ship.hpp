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
  Ship(const string &Name, int shipSize) : name(Name), size(shipSize) ,hitsTaken(0) {}  
  virtual ~Ship() = 0;
  virtual void takeHit() {std::cout<<"<"<<name<<">"<<" got hit!"<<std::endl; hitsTaken++;}
  inline bool isSunk() const {return  hitsTaken >= size;}
};
