#ifndef __APPLE_HPP__
#define __APPLE_HPP__

class Apple
 {
 public:
 int sweetness;
 int juicyness;
   Apple(int sweetness, int juicyness);
   bool operator<(Apple other);
 };

#endif

