#ifndef ENUMERATE_H_INCLUDED
#define ENUMERATE_H_INCLUDED

#include <tuple>
#include <type_traits>
#include <utility>

namespace jon
{
template <typename T>
class enumeratedIterator
{
  size_t m_index = 0;

  using iterator = typename std::remove_reference<T>::type::iterator;
  iterator m_iterator;
  iterator m_end;

  using value_type =
      typename std::remove_reference<decltype(*m_iterator)>::type;

public:
  enumeratedIterator(T &container)
    : m_iterator(container.begin()), m_end(container.end())
  {
  }

  enumeratedIterator(
      const typename std::remove_reference<T>::type::iterator &iterator)
    : m_iterator(iterator)
  {
  }

  enumeratedIterator<T> begin()
  {
    return *this;
  }

  enumeratedIterator<T> end()
  {
    return m_end;
  }

  enumeratedIterator<T> &operator++()
  {
    ++m_iterator;
    ++m_index;
    return *this;
  }

  bool operator!=(const iterator &it)
  {
    return m_iterator != it;
  }

  operator iterator()
  {
    return m_iterator;
  }

  std::pair<const size_t, value_type &> operator*()
  {
    return { m_index, *m_iterator };
  }
};

template <typename T>
enumeratedIterator<T> enumerate(T &&container)
{
  return enumeratedIterator<T>(std::forward<T>(container));
}

}  // namespace jon

#endif
