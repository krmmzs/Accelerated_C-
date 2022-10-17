#include <algorithm>
#include <iomanip>
#ifndef __GNUC__
#include <ios>
#endif
#include <iostream>
#include <string>
#include <vector>

using std::cin;             using std::sort;
using std::cout;            using std::streamsize;
using std::endl;            using std::string;
using std::setprecision;    using std::vector;

int main() {
    vector<double> vec;
    vec.push_back(3.0);
    if (vec.size() - 100 >= 0) {
        cout << "hhh" << endl;
    } else {
        cout << "fuck" << endl;
    }

    return 0;
}
