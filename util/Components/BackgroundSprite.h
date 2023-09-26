#ifndef COMPONENTS_BACKGROUNDSPRITE_H_
#define COMPONENTS_BACKGROUNDSPRITE_H_
#include "../Math/Math.h"
#include "Sprite.h"
#include <SDL2/SDL.h>
#include <vector>
class CBackgroundSprite : public CSprite {
public:
  CBackgroundSprite(class Actor *owner, int drawOrder = 10);
  void Update(float deltaTime);
  void Draw(SDL_Renderer *renderer);
  void SetBackgroundTextures(const std::vector<SDL_Texture *> &textures);
  void SetScreenSize(const Vector2 &size) { mScreenSize = size; };
  void SetScrollSpeed(const float speed) { mScrollSpeed = speed; };
  float GetScrollSpeed() const { return mScrollSpeed; }

private:
  struct BackgroundTexture {
    SDL_Texture *mTexture;
    Vector2 mOffset;
  };
  std::vector<BackgroundTexture> mBGTextures;
  Vector2 mScreenSize;
  float mScrollSpeed;
};

#endif
