#ifndef UTIL_VECTOR2D_H_
#define UTIL_VECTOR2D_H_
struct Vector2D {
  int x;
  int y;
  Vector2D() : x(0.0f), y(0.0f) {}
  Vector2D(int a, int b) {
    x = a;
    y = b;
  }
};
#endif
