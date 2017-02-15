#include <vector>

#include <list>
#include <iostream>
#include "Bubble.hpp"

void printList(std::list<int> const list)
{
  for (std::list<int>::const_iterator it = list.begin(); it != list.end(); it++)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
  (void)argc;
  (void)argv;
  Sort::ASort<std::list<int>> *sorter = new Sort::Bubble<std::list<int>>();
  std::list<int> container = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };

  printList(container);
  sorter->sort(container);
  delete sorter;
  printList(container);
}
