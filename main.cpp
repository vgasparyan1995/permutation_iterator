#include <iostream>
#include "permutation_iterator.h"

void print(const std::vector<int>& permutation)
{
    std::cout << "{ ";
    for (const auto& item : permutation) {
        std::cout << item << " ";
    }
    std::cout << "}\n";
}

int main()
{
    std::permutation_iterator<int> iter { 1, 2, 3, 4};
    while (!iter.is_end()) {
        const auto p = *iter;
        print(p);
        ++iter;
    }
}
