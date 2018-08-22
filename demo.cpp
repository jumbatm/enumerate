#include <forward_list>
#include <iostream>
#include <queue>
#include <random>
#include <vector>

#include "enumerate.hh"

#define HAS_CPP17 (__cplusplus >= 201703L)

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

constexpr size_t SIZE = 20;
}  // namespace

int main()
{
  // Vectors.
  std::vector<int> v(SIZE, 0);

  std::cout << "Enumerate over a vector:\n";

  for (auto &&pair : jon::enumerate(v))
  {
    std::cout << pair.first << ": " << pair.second << "\n";
  }

  std::cout << "\nSet it to a count from 1 -> " << SIZE << "\n";
  for (auto &&pair : jon::enumerate(v))
  {
    pair.second = pair.first + 1;
  }
  print(v);

  std::cout << "\nAssign 3 to all values:\n";
  for (auto &&pair : jon::enumerate(v))
  {
    pair.second = 3;
    std::cout << pair.first << ": " << pair.second << "\n";
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
  for (auto &&pair : jon::enumerate(f))
  {
    if (pair.first % 5 == 0)
    {
      std::cout << "Found " << pair.first << " at index " << pair.second
                << "\n";
    }
  }

#if HAS_CPP17
  std::priority_queue<std::string> queue;
  for (size_t i = 0; i < SIZE; ++i)
  {
    queue.push();
  }

  for (auto &&[index, pair] : jon::enumerate(map))
  {
    std::cout << index << ": "
              << "{ " << pair.first << ", " << pair.second << " }\n";
  }

#else
  std::cout << "Skipping C++17 demo of map.\n";
#endif

  return 0;
}
