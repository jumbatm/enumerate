#include <forward_list>
#include <iostream>
#include <map>
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

#if HAS_CPP17
  std::cout << "\nUsing C++17 syntax, assign 3 to all values:\n";
  for (auto &&[index, element] : jon::enumerate(v))
  {
    element = 3;
    std::cout << index << ": " << element << "\n";
  }
  print(v);
#endif

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
  std::cout << "\nInsert random values into a map as keys, as well as the Nth "
               "number that was to be stored.\n";
  std::map<size_t, size_t> map;

  // Insert into a map in reverse order. Map the value to the Nth number added
  // it was.
  size_t nth_number_added = 0;
  for (size_t i = SIZE; i--;)
  {
    map[rand()] = ++nth_number_added;
  }

  for (auto &&[index, pair] : jon::enumerate(map))
  {
    std::cout << index << ": "
              << "{ " << pair.first << ", " << pair.second << " }\n";
  }
#endif

  return 0;
}
