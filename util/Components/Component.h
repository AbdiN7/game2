#ifndef COMPONENTS_COMPONENT_H_
#define COMPONENTS_COMPONENT_H_
class Component {
public:
  int num;
  Component(class Actor *owner, int updateOrder = 100);
  virtual ~Component();
  virtual void Update(float deltaTime);
  int GetUpdateOrder() const { return mUpdateOrder; }

protected:
  class Actor *mOwner;
  int mUpdateOrder;
};

#endif
