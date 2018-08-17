#include <forward_list>
#include <iostream>
#include <random>
#include <vector>

#include "enumerate.hh"

namespace
{
template <typename T>
inline void print(T &&container, const char *separator = ",")
{
  std::cout << "{ ";
  auto it = container.begin();
  for (; it != container.end() - 1; ++it)
  {
    std::cout << *it << separator << " ";
  }
  std::cout << *it << " };\n";
}
constexpr inline size_t SIZE = 20;
}  // namespace

int main()
{
  // Vectors.
  std::vector<int> v(SIZE, 0);

  std::cout << "Enumerate over a vector:\n";

  for (auto &&[index, item] : jon::enumerate(v))
  {
    std::cout << index << ": " << item << "\n";
  }
  std::cout << "\nSet it to a count from 1 -> " << SIZE << "\n";
  for (auto &&[index, item] : jon::enumerate(v))
  {
    item = index + 1;
  }
  print(v);

  std::cout << "\nAssign 3 to all values:\n";
  for (auto &&[index, item] : jon::enumerate(v))
  {
    item = 3;
    std::cout << index << ": " << item << "\n";
  }
  print(v);

  std::cout << "\n";

  // Forward list.
  std::forward_list<int> f;
  std::random_device rd;

  for (size_t i = 0; i < SIZE; ++i)
  {
    f.push_front(rd());
  }

  std::cout << "Assign forward list randomly:\n";
  // Print all elements.
  for (auto &elem : f)
  {
    std::cout << elem << " ";
  }

  std::cout << "\n\nPrint all elements divisible by 5 and what position:\n";
  for (auto &&[index, elem] : jon::enumerate(f))
  {
    if (elem % 5 == 0)
    {
      std::cout << "Found " << elem << " at index " << index << "\n";
    }
  }

  return 0;
}
