#include "Game.h"
#include "Actor.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
bool Game::Initialize() {
  IMG_Init(IMG_INIT_PNG);
  return false;
}
// // //Inserts the sprite;
// //Checks the draw order of each sprite
// //if the elements draw order is Greater insert before.
void Game::AddSprite(CSprite *sprite) {
  int currDrawOrder = sprite->GetDrawOrder();
  auto iter = mSprites.begin();
  for (; iter != mSprites.end(); ++iter) {
    if (currDrawOrder < (*iter)->GetDrawOrder()) {
      break;
    }
  }
  mSprites.insert(iter, sprite);
}
void Game::AddActor(Actor *actor) {
  if (actor != nullptr) {
    if (mUpdatingActors) {
      mActorQueue.push(actor);
    } else {
      mActors.emplace_back(actor);
    }
  }
}
void Game::Shutdown() {
  while (!mActors.empty()) {
    delete mActors.back();
  }
}
void Game::UpdateGame() {
  float deltaTime;
  mUpdatingActors = true;
  for (auto actor : mActors) {
    actor->Update(deltaTime);
  }

  while (!mActorQueue.empty()) {
    mActors.emplace_back(mActorQueue.front());
    mActorQueue.pop();
  }
  std::vector<Actor *> deadActors;
  for (auto actor : mActors) {
    if (actor->GetState() == Actor::EDead) {
      deadActors.emplace_back(actor);
    }
  }
  for (auto actor : deadActors) {
    delete actor;
  }
}
