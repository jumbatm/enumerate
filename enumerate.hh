#ifndef ENUMERATE_H_INCLUDED
#define ENUMERATE_H_INCLUDED

#include <tuple>
#include <utility>

namespace jon
{
template <typename T>
struct enumeratedIterator
{
    size_t index = 0;

    T& m_container;

    enumeratedIterator(T& container) : m_container(container) {}

    size_t internalIndex = 0;

    auto& begin()
    {
        return *this;
    }

    size_t end()
    {
        return m_container.size();
    }

    enumeratedIterator<T>& operator++()
    {
        ++index;
        return *this;
    }

    bool operator!=(size_t endValue)
    {
        return index != endValue;
    }

    auto operator*()
    {
        return std::tie(index, *(m_container.begin() + index));
    }
};

template <typename T>
auto enumerate(T&& container)
{
    return enumeratedIterator<T>(std::forward<T>(container));
}

}  // namespace jon

#endif
