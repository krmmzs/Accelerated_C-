#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using std::cin;                  using std::setprecision;
using std::cout;                 using std::string;
using std::endl;                 using std::streamsize;

int main(void) {
    streamsize prec = cout.precision();
    cout << "fasdfas" << setprecision(3)
        << 0.2 << setprecision(prec);
}
