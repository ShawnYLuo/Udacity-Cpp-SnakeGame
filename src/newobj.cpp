#include "newobj.h"
#include "SDL.h"

void Newobj::Appear(int x, int y){
  _last = SDL_GetTicks();
  _exist = true;
  int dtype = random_type(engine);
  switch (dtype)
  {
    case 0:
      _type = ObjType::shrink;
      break;
    case 1:
      _type = ObjType::slow;
      break;
    case 2:
      _type = ObjType::acc;
      break;
  }
  _x = x;
  _y = y;
}
  
void Newobj::Activate(std::shared_ptr<Snake> snake){
  switch (_type)
  {
    case ObjType::shrink:
      snake->ShrinkBody();
      break;
    case ObjType::slow:
      snake->speed = snake->speed>0.2?snake->speed-0.2:0.1;
      break;
     case ObjType::acc:
      snake->speed += 0.1;
      break;
  }
  Vanish();
}