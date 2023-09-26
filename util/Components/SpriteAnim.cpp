#include "SpriteAnim.h"

void CSpriteAnim::Update(float deltaTime) {
  CSprite::Update(deltaTime);
  if (mAnimTextures.size() > 0) {
    mCurrFrame += mAnimFPS * deltaTime;
    while (mCurrFrame >= mAnimTextures.size()) {
      mCurrFrame -= mAnimTextures.size();
    }
    SetTexture(mAnimTextures[static_cast<int>(mCurrFrame)]);
  }
}
