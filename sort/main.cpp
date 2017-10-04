#include <vector>
#include <string>
#include <random>
#include <iostream>
#include <algorithm>
#include "Bubble.hpp"
#include "Selection.hpp"
#include "Insertion.hpp"
#include "Merge.hpp"
#include "Quick.hpp"
#include "Factory.hpp"

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

Factory<Sort::ASort<std::vector<int>>> *initFactory()
{
  Factory<Sort::ASort<std::vector<int>>> *factory;
  factory = new Factory<Sort::ASort<std::vector<int>>>();

  factory->record("bubble", &Sort::Bubble<std::vector<int>>::clone);
  factory->record("selection", &Sort::Selection<std::vector<int>>::clone);
  factory->record("insertion", &Sort::Insertion<std::vector<int>>::clone);
  factory->record("merge", &Sort::Merge<std::vector<int>>::clone);
  factory->record("quick", &Sort::Quick<std::vector<int>>::clone);
  return factory;
}

void run(std::string algorithm, int count) {
  Factory<Sort::ASort<std::vector<int>>> *factory = initFactory();
  Sort::ASort<std::vector<int>> *sorter = factory->create(algorithm);
  std::vector<int> *container = randomizeArray<std::vector<int>>(count);

  printList<std::vector<int>>(*container);
  sorter->sort(*container);
  delete sorter;
  printList<std::vector<int>>(*container);
  container->clear();
  delete container;
  delete factory;
}

int main()
{
  run("quick", 100);
  return 0;
}
