#ifndef UTIL_GAMEOBJECT_H_
#define UTIL_GAMEOBJECT_H_
#include "Components/Component.h"
#include "Components/Sprite.h"
#include <queue>
#include <unordered_set>
#include <vector>
class Game {
public:
  bool Initialize();
  static void RunLoop();
  void Shutdown();
  void AddSprite(CSprite *sprite);
  void AddActor(Actor *actor);
  void RemoveActors(Actor *actor);
  ~Game() {}
  void AddComponent(Component *comp);
  void RemoveComponent(Component *comp);

private:
  void ProccessInput();
  void UpdateGame();
  void RenderOutput();
  std::queue<Actor *> mActorQueue;
  static bool mUpdatingActors;
  std::vector<Actor *> mActors;
  std::vector<CSprite *> mSprites;
  std::unordered_set<Component *> mComponent;
};

#endif
