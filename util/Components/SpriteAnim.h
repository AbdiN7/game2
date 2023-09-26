#ifndef COMPONENTS_SPRITEANIM_H_
#define COMPONENTS_SPRITEANIM_H_
#include "Sprite.h"
class CSpriteAnim : public CSprite {
public:
  CSpriteAnim(class Actor *owner, int drawOrder = 100);
  void Update(float deltaTime);
  void SetAnimTextures(const std::vector<SDL_Texture *> &texutres);
  float GetAnimFPS() const { return mAnimFPS; }

private:
  std::vector<SDL_Texture *> mAnimTextures;
  float mAnimFPS;
  float mCurrFrame;
};
#endif
