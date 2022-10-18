#include <iostream>
#include <algorithm>
#include "Student_info.h"

using std::max;

int main(void) {
    size_t maxlen;
    Student_info s;
    max(s.name.size(), maxlen);

    return 0;
}
