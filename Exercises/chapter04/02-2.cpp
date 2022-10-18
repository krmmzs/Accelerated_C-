/**
Accelerated C++, Exercise 4-3, 4_3.cpp

What happens if we rewrite the previous program to allow values up to but not
including 1000 but neglect to change the arguments to setw? Rewrite the program to
be more robust in the face of changes that allow i to grow without adjusting the setw
arguments.
*/

#include "stdafx.h"
#include <cmath>
#include <stdexcept>

#include <vector>
using std::vector;

#include <iostream>
using std::ostream;
using std::streamsize;
using std::cout;
using std::endl;
using std::domain_error;

#include <iomanip>
using std::setw;

unsigned GetNumberOfDigits(unsigned i)
{
    return i > 0 ? (int)log10((double)i) + 1 : 1;
}

vector<int> square(const unsigned int range) 
{
    vector<int> squares;
    if (range > squares.max_size())
        throw domain_error("Range argument exceeds vector limit.");

    for (unsigned int i = 0; i < range; i++)
        squares.push_back(i * i);

    return squares;
}

ostream& print_squares_robust(ostream& os, const vector<int>& v)
{
    if (os)
    {
        unsigned digits_i = GetNumberOfDigits(v.size());
        unsigned digits_v = GetNumberOfDigits(v.back());

        for (vector<int>::size_type i = 0; i < v.size(); i++)
            {
                streamsize s_size = os.width();
                os << setw(digits_i) << i << " " << setw(digits_v) << v[i] << endl;
                os.width(s_size);
            }
    }

    return os;
}

int main(void)
{
    vector<int> v = square(1000);
    print_squares_robust(cout, v);

    return 0;
}
