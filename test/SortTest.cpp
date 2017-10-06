#include "SortTest.hpp"
#include "../src/Bubble.hpp"
#include "../src/Selection.hpp"
#include "../src/Insertion.hpp"
#include "../src/Merge.hpp"
#include "../src/Quick.hpp"

namespace Test
{
  CPPUNIT_TEST_SUITE_REGISTRATION(SortTest);

  void SortTest::setUp()
  {
    lunsorted = std::list<int> { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    lsorted = std::list<int> { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  }

  void SortTest::tearDown() { }

  void SortTest::testBubbleSort()
  {
    Sort::ASort<std::list<int>> *sorter = new Sort::Bubble<std::list<int>>();
    sorter->sort(lunsorted);
    delete sorter;
    CPPUNIT_ASSERT(lunsorted == lsorted);
  }

  void SortTest::testSelectionSort()
  {
    Sort::ASort<std::list<int>> *sorter = new Sort::Selection<std::list<int>>();
    sorter->sort(lunsorted);
    delete sorter;
    CPPUNIT_ASSERT(lunsorted == lsorted);
  }

  void SortTest::testInsertionSort()
  {
    Sort::ASort<std::list<int>> *sorter = new Sort::Insertion<std::list<int>>();
    sorter->sort(lunsorted);
    delete sorter;
    CPPUNIT_ASSERT(lunsorted == lsorted);
  }

  void SortTest::testMergeSort()
  {
    Sort::ASort<std::list<int>> *sorter = new Sort::Merge<std::list<int>>();
    sorter->sort(lunsorted);
    delete sorter;
    CPPUNIT_ASSERT(lunsorted == lsorted);
  }

  void SortTest::testQuickSort()
  {
    Sort::ASort<std::list<int>> *sorter = new Sort::Quick<std::list<int>>();
    sorter->sort(lunsorted);
    delete sorter;
    CPPUNIT_ASSERT(lunsorted == lsorted);
  }
}
