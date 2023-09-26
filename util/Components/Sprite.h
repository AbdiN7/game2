#ifndef UTIL_SPRITE_H_
#define UTIL_SPRITE_H_
#include "../Actor.h"
#include "Component.h"
#include "SDL2/SDL.h"
class CSprite : public Component {
public:
  CSprite(class Actor *owner, int drawOrder = 100);
  ~CSprite();
  virtual void Draw(SDL_Renderer *renderer);
  virtual void SetTexture(SDL_Texture *texture);
  int GetDrawOrder() const { return mDrawOrder; }
  int GetTextHeight() const { return mTexHeight; }
  int GetTextWidth() const { return mTexWidth; }

protected:
  class Actor *mOwner;
  SDL_Texture *mTexture;
  int mDrawOrder;
  int mTexWidth;
  int mTexHeight;
};

#endif
