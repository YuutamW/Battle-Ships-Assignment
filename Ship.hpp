#pragma once
#include <iostream>
using std::string;

class Ship
{
private:
  string name;
  int size;
  int hitsTaken;
  int row_start;
  int col_start;
  bool horizontal;
public:
  Ship(const string &Name, int shipSize) : name(Name), size(shipSize), hitsTaken(0) {}
  
  virtual ~Ship() {}
  virtual void takeHit()
  {
    std::cout << "\t____<" << name << ">" << "___got hit!___" << std::endl;
    hitsTaken++;
  }
  inline bool isSunk() const { return hitsTaken >= size; }

  inline int getSize() { return size; };
  inline string getName() { return name; }
  inline int getRowStart() {return row_start;}
  inline int getColStart() {return col_start;}
  inline bool isHorizontal() const {return horizontal;}
  inline void setRoStart(int r) {this->row_start = r;}
  inline void setColStart(int c) {this->col_start = c;}
  inline void setHor(bool horizon) {this->horizontal = horizon;}
  inline void setPos(int r, int c , bool h) 
  {
    setRoStart(r);
    setColStart(c);
    setHor(h);
  }
  inline bool covers(int r , int c) const {
    if(horizontal)
      return ((r == row_start) && (c >= col_start) && (c < col_start + size));
    else
      return ((c == col_start) && (r>=row_start) && (r < row_start + size));
  }

};
