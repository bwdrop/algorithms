#ifndef SORT_TEST_HPP_
# define SORT_TEST_HPP_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <list>

namespace Test
{
  class SortTest : public CppUnit::TestFixture
  {
    CPPUNIT_TEST_SUITE(SortTest);
    CPPUNIT_TEST(testBubbleSort);
    CPPUNIT_TEST(testSelectionSort);
    CPPUNIT_TEST(testInsertionSort);
    CPPUNIT_TEST(testMergeSort);
    CPPUNIT_TEST(testQuickSort);
    CPPUNIT_TEST_SUITE_END();

  private:
    std::list<int> lunsorted;
    std::list<int> lsorted;

  public:
    void setUp();
    void tearDown();

    void testBubbleSort();
    void testSelectionSort();
    void testInsertionSort();
    void testMergeSort();
    void testQuickSort();
  };
}

#endif /* !SORT_TEST_HPP_ */
