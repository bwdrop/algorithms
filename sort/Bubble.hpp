#ifndef BUBBLE_HPP_
# define BUBBLE_HPP_

#include <iterator>
#include <algorithm>
#include "ASort.hpp"

namespace Sort
{
  template <typename T>
  class Bubble : public ASort<T>
  {
  public:
    Bubble();
    virtual ~Bubble();

    virtual void sort(T &container, typename ASort<T>::Compare comp) const;
  };

  template <typename T>
  Bubble<T>::Bubble() { }

  template <typename T>
  Bubble<T>::~Bubble() { }

  template <typename T>
  void Bubble<T>::sort(T &container, typename ASort<T>::Compare comp) const
  {
    typename T::const_reverse_iterator crit;
    for (crit = std::next(container.crbegin()); crit != container.crend(); crit++)
    {
      bool sorted = true;
      for (typename T::iterator it = container.begin(); it != crit.base(); it++)
      {
        typename T::iterator next = std::next(it);
        if (comp(*next, *it))
        {
          std::swap(*next, *it);
          sorted = false;
        }
      }
      if (sorted)
        return;
    }
  }
}

#endif /* !BUBBLE_HPP_ */
