#include <iostream>
#include "array.hpp"


using std::cout, std::endl;


int main()
{
    cocobolo::array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


    for (cocobolo::array<int, 10>::iterator i = arr.begin(); i != arr.end(); ++i)
    {
        cout << *i << "  ";
    }
    cout << endl;


    // for (int i )
}