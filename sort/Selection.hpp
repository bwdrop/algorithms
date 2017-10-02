#ifndef SELECTION_HPP_
# define SELECTION_HPP_

#include <iterator>
#include <algorithm>
#include "ASort.hpp"

namespace Sort
{
  template <typename T>
  class Selection : public ASort<T>
  {
  public:
    Selection();
    virtual ~Selection();

    virtual void sort(T &container, typename ASort<T>::Compare &comp) const;
  };

  template <typename T>
  Selection<T>::Selection() { }

  template <typename T>
  Selection<T>::~Selection() { }

  template <typename T>
  void Selection<T>::sort(T &container, typename ASort<T>::Compare &comp) const
  {
    typename T::iterator it;
    for (it = container.begin(); it != std::prev(container.end()); ++it)
    {
      typename T::iterator min = it;
      for (typename T::iterator jt = std::next(it); jt != container.end(); ++jt)
      {
        if (comp(*jt, *min))
          min = jt;
      }
      if (min != it)
        std::swap(*min, *it);
    }
  }
}

#endif /* !SELECTION_HPP_ */
