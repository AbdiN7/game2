#include "Game.h"
#include "./Actors/Actor.h"
#include "./Actors/Ship.h"
#include "./Components/BackgroundSprite.h"
#include "./Components/Sprite.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <algorithm>
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
void Game::RemoveSprite(CSprite *sprite) {
  auto iter = std::find(mSprites.begin(), mSprites.end(), sprite);
  mSprites.erase(iter);
}

// Actors
void Game::AddActor(Actor *actor) {
  if (actor != nullptr) {
    if (mUpdatingActors) {
      mActorQueue.push_back(actor);
    } else {
      mActors.emplace_back(actor);
    }
  }
}

void Game::RemoveActor(Actor *actor) {
  auto iter = std::find(mActorQueue.begin(), mActorQueue.end(), actor);
  if (iter != mActorQueue.end()) {
    // std::iter_swap(iter, mActorQueue.end() - 1);
    iter = mActorQueue.erase(iter);
  }
  auto viter = std::find(mActors.begin(), mActors.end(), actor);
  if (viter != mActors.end()) {
    std::iter_swap(iter, mActors.end() - 1);
    mActors.pop_back();
  }
}

// Game Conditions
bool Game::Initialize() {
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
    SDL_Log("unable to initialize SDL: %s", SDL_GetError());
    return false;
  }
  mWindow = SDL_CreateWindow("Game 2", 100, 100, 1024, 768, 0);
  if (!mWindow) {
    SDL_Log("Could not create window: %s", SDL_GetError());
    return false;
  }
  mRenderer = SDL_CreateRenderer(
      mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!mRenderer) {
    SDL_Log("Cloud not create the renderer: %s", SDL_GetError());
    return false;
  }
  if (IMG_Init(IMG_INIT_PNG) == 0) {
    SDL_Log("Could not initialize SDL_image: %s", SDL_GetError());
    return false;
  }
  LoadData();
  mTicksCount = SDL_GetTicks();
  return true;
}
void Game::RunLoop() {
  while (mIsRunning) {
    ProccessInput();
    UpdateGame();
    RenderOutput();
  }
}

void Game::ProccessInput() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT:
      mIsRunning = false;
      break;
    }
  }

  const Uint8 *state = SDL_GetKeyboardState(NULL);
  if (state[SDL_SCANCODE_ESCAPE]) {
    mIsRunning = false;
  }
  // TODO: add ProccessKeyboard to Ship actor
  mShip->ProccessKeyboard(state);
}

//  // TODO:
void Game::LoadData() {
  //  // 1) create ship
  //  // 2) create background
  //  //     bg: close
  //  //     bg: far
}
// // TODO:
void Game::UnloadData() {
  // // 1) delete actors
  // // 2) delete textures
}

// // TODO: Add GetTexture
SDL_Texture *Game::GetTexture(const std::string &fName) {
  SDL_Texture *tex = nullptr;
  return tex;
}

void Game::Shutdown() {
  while (!mActors.empty()) {
    delete mActors.back();
  }
  while (!mActorQueue.empty()) {
    mActorQueue.pop_front();
  }
  IMG_Quit();
  SDL_DestroyRenderer(mRenderer);
  SDL_DestroyWindow(mWindow);
  SDL_Quit();
}

// // TODO: expand
void Game::UpdateGame() {
  float deltaTime;
  // TODO: deltatime using ticks
  mUpdatingActors = true;
  for (auto actor : mActors) {
    actor->Update(deltaTime);
  }
  while (!mActorQueue.empty()) {
    mActors.emplace_back(mActorQueue.front());
    mActorQueue.pop_front();
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
