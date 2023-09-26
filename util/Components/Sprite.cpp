#include "Sprite.h"
#include "../Math.h"
void CSprite::SetTexture(SDL_Texture *texture) {
  mTexture = texture;
  SDL_QueryTexture(texture, nullptr, nullptr, &mTexWidth, &mTexHeight);
}

void CSprite::Draw(SDL_Renderer *renderer) {
  if (mTexture) {
    SDL_Rect r;
    r.w = static_cast<float>(mTexWidth * mOwner->GetScale());
    r.h = static_cast<float>(mTexHeight * mOwner->GetScale());
    r.x = static_cast<float>(mOwner->GetPosition().x - r.w / 2);
    r.y = static_cast<float>(mOwner->GetPosition().y - r.h / 2);
    SDL_RenderCopyEx(renderer, mTexture, nullptr, &r,
                     -Math::ToDegrees(mOwner->GetRotation()), nullptr,
                     SDL_FLIP_NONE);
  }
}
