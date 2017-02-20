#ifndef QUICK_HPP_
# define QUICK_HPP_

#include <cstdlib>
#include <iterator>
#include <algorithm>
#include "ASort.hpp"

namespace Sort
{
  template <typename T>
  class Quick : public ASort<T>
  {
  private:
    void quickSort(T &container, typename T::iterator begin, typename T::iterator end,
                   typename ASort<T>::Compare comp) const;
    void pickPivot(typename T::iterator &begin, typename T::iterator &end) const;
    typename T::iterator partition(typename T::iterator &begin, typename T::iterator &end,
                                   typename ASort<T>::Compare comp) const;

  public:
    Quick();
    ~Quick();

    void sort(T &container, typename ASort<T>::Compare comp) const;
  };

  template <typename T>
  Quick<T>::Quick() { }

  template <typename T>
  Quick<T>::~Quick() { }

  template <typename T>
  void Quick<T>::sort(T &container, typename ASort<T>::Compare comp) const
  {
    quickSort(container, container.begin(), container.end(), comp);
  }

  template <typename T>
  void Quick<T>::quickSort(T &container, typename T::iterator begin, typename T::iterator end,
                           typename ASort<T>::Compare comp) const
    {
      if (std::distance(begin, end) > 1)
      {
        pickPivot(begin, end);
        typename T::iterator pivot = partition(begin, end, comp);
        quickSort(container, begin, pivot, comp);
        quickSort(container, std::next(pivot), end, comp);
      }
    }

  template <typename T>
  void Quick<T>::pickPivot(typename T::iterator &begin, typename T::iterator &end) const
  {
    int random = rand() % std::distance(begin, end);
    typename T::iterator pivot = std::next(begin, random);
    std::swap(*pivot, *begin);
  }

  template <typename T>
  typename T::iterator Quick<T>::partition(typename T::iterator &begin, typename T::iterator &end,
                                  typename ASort<T>::Compare comp) const
  {
    typename T::iterator pivot = begin;
    typename T::iterator leftmost = std::next(pivot);
    for (typename T::iterator it = leftmost; it != end; it++)
    {
      if (comp(*it, *pivot))
      {
        std::swap(*it, *leftmost);
        leftmost++;
      }
    }
    std::swap(*pivot, *std::prev(leftmost));
    return std::prev(leftmost);
  }
}

#endif /* !QUICK_HPP_ */
