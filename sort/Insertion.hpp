#ifndef INSERTION_HPP_
# define INSERTION_HPP_

#include <iterator>

namespace Sort{
  template <typename T>
  class Insertion : public ASort<T>
  {
  public:
    Insertion();
    virtual ~Insertion();

    virtual void sort(T &container, typename ASort<T>::Compare &comp) const;
    static ASort<T> *clone();
  };

  template <typename T>
  Insertion<T>::Insertion() { }

  template <typename T>
  Insertion<T>::~Insertion() { }

  template <typename T>
  void Insertion<T>::sort(T &container, typename ASort<T>::Compare &comp) const
  {
    typename T::iterator it;
    for (it = std::next(container.begin()); it != container.end(); ++it)
    {
      typename T::value_type value = *it;
      typename T::iterator curr = it;
      while (curr != container.begin() && comp(value, *std::prev(curr)))
      {
        *curr = *std::prev(curr);
        --curr;
      }
      *curr = value;
    }
  }

  template <typename T>
  ASort<T> *Insertion<T>::clone()
  {
    return new Insertion<T>();
  }
}

#endif /* !INSERTION_HPP_ */
