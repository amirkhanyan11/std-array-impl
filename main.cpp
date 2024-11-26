#include <iostream>
#include "array.hpp"
#include <algorithm>
#include <numeric>

using std::cout, std::endl;


int main()
{
    cocobolo::array<int, 10> arr;

    for (cocobolo::array<int, 10>::reverse_iterator i = arr.rbegin(); i != arr.rend(); ++i)
    {
        cout << *i << "  ";
    }
    cout << endl;

}