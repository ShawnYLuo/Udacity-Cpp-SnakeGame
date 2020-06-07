#ifndef NEWOBJ_H
#define NEWOBJ_H

#include <random>
#include <memory>
#include "SDL.h"
#include "snake.h"

class Newobj {
  public:
      enum class ObjType {shrink, slow, acc};
      // constructor
      Newobj() : engine(dev()), random_type(0, 2) {}
      // setters / getters
      int GetX(){return _x;}
      int GetY(){return _y;}
      ObjType GetType(){ return _type;}
      bool isExist(){return _exist;}
      void SetX(int x){_x = x;}
      void SetY(int y){_y = y;}
      void SetType(ObjType type){_type = type;}
      // behavior functions
      void Vanish(){ _x = -1; _y = -1; _exist = false; _last = 0;}
      void Appear(int x, int y);
      void Activate(std::shared_ptr<Snake> snake);
  
      Uint32 _last;
  
  private:
      std::random_device dev;
      std::mt19937 engine;
      std::uniform_int_distribution<int> random_type;
      
      ObjType _type;
      int _x;
      int _y;
      bool _exist;
};

#endif