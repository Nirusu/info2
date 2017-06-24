#ifndef __BINARY_HEAP_HPP__
#define __BINARY_HEAP_HPP__

#include<vector>
#include "Apple.hpp"

class Binary_heap
 {
 private:
  std::vector<Apple> content;
  int N;

 public:
  Binary_heap();
  bool is_empty();
  void insert(Apple a);
  Apple del_max();

 private:
  void swim(int k);
  void sink(int k);
  void exch(int i, int j);
 };

#endif

