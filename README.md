Ranged-for loops are beautiful, but there's some cases where you want to keep track of the index, too. For example - let's say for some inexplicable reason, you want to set a vector of size 100 to the values 1...100. Right now, you can't use a ranged for loop - instead, you have to do an old-fashioned for-loop:

```cpp
#include <vector>

std::vector<int> v(100);

for (size_t i = 0; i < v.size(); ++i)
{
  v[i] = i+1;
}
```
If you were REALLY set on using a ranged-for, say if you really don't like to use raw indexing, you could do this:
```cpp
#include <vector>

std::vector<int> v(100);
size_t i = 0; // ... Create a counter variable, I guess?
for (auto& elem : v)
{
  elem = i++; // Hmm.
}

```
But we can do better. That's what `enumerate.hh` does.

```cpp
#include "enumerate.hh"
#include <vector>

std::vector<int> v(100);

for (auto &&[index, elem] : jon::enumerate(v)) 
{
  elem = index+1;
}

```
This works not only with vectors, but with any type that supports iterators - it does nothing but wrap any normal iterator. See `demo.c` for some examples.
