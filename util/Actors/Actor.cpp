#include "Actor.h"
#include "../Components/Component.h"
#include "../Game.h"
#include "../Math/Math.h"
Actor::Actor(Game *game)
    : mState(EActive), mPosition(Vector2::Zero), mScale(1.0f), mRotation(0.0f),
      mGame(game) {

  mGame->AddActor(this);
}

Actor::~Actor() {

  mGame->RemoveActor(this);
  while (!mComponents.empty()) {
    delete mComponents.back();
  }
}
