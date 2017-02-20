#ifndef MERGE_HPP_
# define MERGE_HPP_

#include <iterator>

namespace Sort
{
  template <typename T>
  class Merge : public ASort<T>
  {
  private:
    T merge(T const &left, T const &right, typename ASort<T>::Compare comp) const;

  public:
    Merge();
    virtual ~Merge();

    virtual void sort(T &container, typename ASort<T>::Compare comp) const;
  };

  template <typename T>
  Merge<T>::Merge() { }

  template <typename T>
  Merge<T>::~Merge() { }

  template <typename T>
  void Merge<T>::sort(T &container, typename ASort<T>::Compare comp) const
  {
    if (container.size() > 1)
    {
      int middle = container.size() / 2;
      T left(container.cbegin(), std::next(container.cbegin(), middle));
      T right(std::next(container.cbegin(), middle), container.cend());
      sort(left, comp);
      sort(right, comp);
      container = merge(left, right, comp);
    }
  }

  template <typename T>
  T Merge<T>::merge(T const &left, T const &right, typename ASort<T>::Compare comp) const
  {
    T result;
    if (left.empty())
      return right;
    else if (right.empty())
      return left;
    else if (comp(*left.cbegin(), *right.cbegin()))
    {
      result.insert(result.cend(), *left.cbegin());
      T tmp(std::next(left.cbegin()), left.cend());
      T fusion = merge(tmp, right, comp);
      result.insert(result.cend(), fusion.cbegin(), fusion.cend());
    }
    else
    {
      result.insert(result.cend(), *right.cbegin());
      T tmp(std::next(right.cbegin()), right.cend());
      T fusion = merge(left, tmp, comp);
      result.insert(result.cend(), fusion.cbegin(), fusion.cend());
    }
    return result;
  }
}

#endif /* !MERGE_HPP_ */
