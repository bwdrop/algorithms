#include <vector>

#include <list>
#include <iostream>
#include "Bubble.hpp"
#include "Selection.hpp"
#include "Insertion.hpp"
#include "Merge.hpp"
#include "Quick.hpp"

template <typename T>
void printList(T const list)
{
  for (typename T::const_iterator it = list.cbegin(); it != list.cend(); it++)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

int main()
{
  Sort::ASort<std::vector<int>> *sorter = new Sort::Quick<std::vector<int>>();
  std::vector<int> container = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };

  printList<std::vector<int>>(container);
  sorter->sort(container);
  delete sorter;
  printList<std::vector<int>>(container);
  container.clear();
}
