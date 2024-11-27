#include <iostream>
#include "array.hpp"
#include <algorithm>
#include <numeric>
#include <ranges>
#include <vector>

using std::cout, std::endl;


int main()
{
    cocobolo::array<int, 10> arr = {};


    std::iota(arr.begin(), arr.end(), 1);

    for (cocobolo::array<int, 10>::reverse_iterator i = arr.rbegin(); i != arr.rend(); ++i)
    {
        cout << *i << "  ";
    }
    cout << endl;

    // cout << std::accumulate(arr.begin(), arr.end(), 1, std::multiplies<decltype(arr)::value_type>{}) << endl;

}