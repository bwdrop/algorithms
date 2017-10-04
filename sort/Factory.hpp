#ifndef FACTORY_HPP_
# define FACTORY_HPP_

#include <map>
#include <string>

template <typename T, typename Key=std::string>
class Factory
{
private:
  using CreateFn = T *(*)();
  std::map<Key, CreateFn> _map;

public:
  Factory();
  virtual ~Factory();
  void record(Key const &key, CreateFn fn);
  T* create(Key const &key) const;
};

template <typename T, typename Key>
Factory<T, Key>::Factory() { }

template <typename T, typename Key>
Factory<T, Key>::~Factory() { }

template <typename T, typename Key>
void Factory<T, Key>::record(Key const &key, CreateFn fn)
{
  _map[key] = fn;
}

template <typename T, typename Key>
T *Factory<T, Key>::create(Key const &key) const
{
  typename std::map<Key, CreateFn>::const_iterator it = _map.find(key);
  if (it != _map.cend())
    return (it->second)();
  return NULL;
}

#endif /* !FACTORY_HPP_ */
