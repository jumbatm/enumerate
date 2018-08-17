#include <iostream>
#include <vector>

#include "enumerate.hh"

namespace
{
template <typename T>
inline void print(T&& container)
{
  std::cout << "{ ";
  auto it = container.begin();
  for (; it != container.end() - 1; ++it)
  {
    std::cout << *it << ", ";
  }
  std::cout << *it << " };\n";
}
constexpr inline size_t VECTOR_SIZE = 100;
}  // namespace

int main()
{
  std::cout << "Vectors\n";

  std::vector<int> v(VECTOR_SIZE, 0);  // Twenty values.

  std::cout << "Enumerate over glvalue vector.\n";

  for (auto&& [index, item] : jon::enumerate(v))
  {
    std::cout << index << ": " << item << "\n";
  }

  std::cout << "Set it to a count from 0 -> " << VECTOR_SIZE - 1 << "\n";
  for (auto&& [index, item] : jon::enumerate(v))
  {
    item = index;
  }
  print(v);

  std::cout << "Assign 3 to all values.\n";
  for (auto&& [index, item] : jon::enumerate(v))
  {
    item = 3;
    std::cout << index << ": " << item << "\n";
  }
  print(v);

  return 0;
}
