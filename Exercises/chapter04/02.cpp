#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

int main(void) {
    for (int i = 1; i <= 100; i ++) {
        cout << setw(3) << i << " "
            << setw(5) << i * i << endl;
    }

    return 0;
}
