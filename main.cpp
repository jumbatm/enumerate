#include <iostream>
#include <vector>

#include "enumerate.hh"

int main()
{
    std::vector<int> v{ 1, 2, 3, 4 };

    std::cout << "Enumerate over glvalue vector.\n";

    for (auto&& [index, item] : jon::enumerate(v))
    {
        std::cout << index << " " << item << "\n";
    }

    std::cout << "Assign 3 to all values.\n";

    for (auto&& [index, item] : jon::enumerate(v))
    {
        item = 3;
        std::cout << index << " " << item << "\n";
    }
}
