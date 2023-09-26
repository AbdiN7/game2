#ifndef UTIL_GAMEOBJECT_H_
#define UTIL_GAMEOBJECT_H_
// #include "Components/Component.h"
// #include "Components/Sprite.h"
#include <SDL2/SDL.h>
#include <deque>
#include <string>
#include <unordered_map>
// #include <unordered_set>
#include <vector>

class Game {
public:
  bool Initialize();
  void RunLoop();
  void Shutdown();
  void AddSprite(class CSprite *sprite);
  void AddActor(class Actor *actor);
  void RemoveActor(class Actor *actor);
  void RemoveSprite(class CSprite *sprite);
  ~Game() {}
  void AddComponent(class Component *comp);
  void RemoveComponent(class Component *comp);

private:
  void ProccessInput();
  void UpdateGame();
  void RenderOutput();
  void LoadData();
  void UnloadData();
  std::deque<Actor *> mActorQueue;
  std::vector<Actor *> mActors;
  std::vector<CSprite *> mSprites;
  // std::unordered_set<Component *> mComponent;
  std::unordered_map<std::string, SDL_Texture *> mTextures;
  SDL_Window *mWindow;
  SDL_Renderer *mRenderer;
  Uint32 mTicksCount;
  bool mIsRunning;
  bool mUpdatingActors;
  class Ship *mShip;
};

#endif
