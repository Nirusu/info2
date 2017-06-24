#ifndef __ORANGE_HPP__
#define __ORANGE_HPP__

class Orange
 {
 public:
 int sweetness;
 int juicyness;
   Orange(int sweetness, int juicyness);
   bool operator<(Orange other);
 };

#endif

