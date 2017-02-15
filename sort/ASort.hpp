#ifndef ASORT_HPP_
# define ASORT_HPP_

#include <functional>

namespace Sort
{
  template <typename T>
  class ASort
  {
  protected:
    using Value = typename T::value_type;
    using Compare = std::function<bool(Value, Value)>;

    static bool defaultCompare(Value lhs, Value rhs);

  private:
    ASort(ASort const &);
    ASort &operator=(ASort const &);

  public:
    ASort();
    virtual ~ASort();

    void sort(T &container) const;
    virtual void sort(T &container, Compare comp) const = 0;
  };

  template <typename T>
  ASort<T>::ASort() { }

  template <typename T>
  ASort<T>::~ASort() { }

  template <typename T>
  bool ASort<T>::defaultCompare(Value lhs, Value rhs)
  {
    return lhs < rhs;
  }

  template <typename T>
  void ASort<T>::sort(T &container) const
  {
    sort(container, defaultCompare);
  }
}

#endif /* !ASORT_HPP_ */
