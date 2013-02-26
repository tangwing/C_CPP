#ifndef STL_H
#define STL_H

#include <iostream>
#include <vector>
#include <deque>
#include "common.cpp"
#include <algorithm>
#include <iterator>
#include <sstream>
#include <tuple>
template <class T>
void parcourir(T begin,T end)
{
  for(T it = begin; it < end; it++)
  {
      std::cout<<*it<<"\t";
  }
  std::cout<<std::endl;
}

void tryVector();
void tryCopy();
void tryStringFind();
//void tryTuple();
void tryFoncteur();
#endif
