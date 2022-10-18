#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::endl;
using std::setw;

int get_length(int n) {
    return log10(n) + 1;
}

int main(void) {
    int max_number = 999;
    int max_len = get_length(max_number);
    int max_sq = get_length(max_number * max_number);

    for (int i = 1; i <= max_number; i ++) {
        cout << setw(max_len) << i << " "
            << setw(max_sq) << i * i << endl;
    }

    return 0;
}
