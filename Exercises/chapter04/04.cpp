#include "stdafx.h"

using std::cout;
using std::endl;
using std::setw;
using std::streamsize;
using std::setprecision;
using std::fixed;

int get_length(double number, const streamsize& decimal_potints) {
    int length = 1;
    while (number / 10 > 1.0) {
        number /= 10;
        length++;
    }

    return length + decimal_potints + 1;
}

int main(void) {
    const double max_number = 1000.0;
    const streamsize decimal_potints = 2;

    int max_len = get_length(max_number, decimal_potints);
    int  max_sq = get_length(max_number * max_number, decimal_potints);

    for (double i = 1.0; i < max_number; i ++) {
        streamsize prec = cout.precision();
        cout << fixed << setprecision(decimal_potints)
            << setw(max_len) << i << " " << setw(max_sq) << i * i
            << setprecision(prec) << endl;
    }

    return 0;
}
