#include <vector>
#include <random>
#include <iostream>
#include <algorithm>
#include "Bubble.hpp"
#include "Selection.hpp"
#include "Insertion.hpp"
#include "Merge.hpp"
#include "Quick.hpp"

template <typename T>
void printList(T const list)
{
  for (typename T::const_iterator it = list.cbegin(); it != list.cend(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;
}

template <typename T>
T* randomizeArray(typename T::value_type count) {
  T* array = new T();
  std::random_device rd;
  std::mt19937 g(rd());

  for (typename T::value_type i = 1; i < count + 1; ++i)
    array->insert(array->cend(), i);
  std::shuffle(array->begin(), array->end(), g);
  return array;
}

int main()
{
  Sort::ASort<std::vector<int>> *sorter = new Sort::Quick<std::vector<int>>();
  std::vector<int> *container = randomizeArray<std::vector<int>>(100);

  printList<std::vector<int>>(*container);
  sorter->sort(*container);
  delete sorter;
  printList<std::vector<int>>(*container);
  container->clear();
  delete container;
}
