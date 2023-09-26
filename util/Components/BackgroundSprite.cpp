#include "BackgroundSprite.h"

void CBackgroundSprite::SetBackgroundTextures(
    const std::vector<SDL_Texture *> &textures) {
  int count = 0;
  for (auto tex : textures) {
    BackgroundTexture temp;
    temp.mTexture = tex;
    temp.mOffset.x = count * mScreenSize.x;
    temp.mOffset.y = 0;
    mBGTextures.emplace_back(temp);
    count++;
  }
}
