#ifndef MATH_ACTOR_H_
#define MATH_ACTOR_H_
#include "../Components/Component.h"
#include "../Math/Math.h"
#include <vector>
class Actor {
public:
  enum State { EActive, EPaused, EDead };
  Actor(class Game *game);
  virtual ~Actor();
  virtual void UpdateActor(float deltaTime);
  State GetState();
  float GetScale();
  float GetRotation();
  Vector2 GetPosition();
  void SetPosition(int x, int y);
  void SetScale(int s);
  void SetRotation(int r);
  void SetState(State s);
  void Update(float deltaTime);
  void UpdateComponents(float deltaTime);
  void AddComponent(class Component *comp);
  void RemoveComponent(class Component *comp);

private:
  State mState;
  Vector2 mPosition;
  float mScale;
  float mRotation;
  std::vector<class Component *> mComponents;
  class Game *mGame;
};

#endif
