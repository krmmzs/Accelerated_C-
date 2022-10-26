#include "template_string_as_parameter.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;


int main(void) {
    vector<double> v;
    v.push_back(1.0);
    v.push_back(2.0);
    v.push_back(3.0);
    v.push_back(4.0);
    v.push_back(5.0);
    v.push_back(6.0);
    v.push_back(7.0);
    v.push_back(8.0);
    v.push_back(9.0);
    v.push_back(10.0);
    v.push_back(11.0);
    v.push_back(12.0);
    v.push_back(13.0);
    v.push_back(14.0);
    v.push_back(15.0);
    v.push_back(16.0);
    v.push_back(17.0);
    v.push_back(18.0);
    v.push_back(19.0);
    v.push_back(20.0);
    v.push_back(21.0);
    v.push_back(22.0);
    v.push_back(23.0);
    v.push_back(24.0);
    v.push_back(25.0);
    v.push_back(26.0);
    v.push_back(27.0);
    v.push_back(28.0);
    v.push_back(29.0);
    v.push_back(30.0);
    v.push_back(31.0);
    v.push_back(32.0);
    v.push_back(33.0);
    v.push_back(34.0);
    v.push_back(35.0);
    v.push_back(36.0);
    v.push_back(37.0);
    v.push_back(38.0);
    v.push_back(39.0);
    v.push_back(40.0);
    v.push_back(41.0);
    v.push_back(42.0);
    v.push_back(43.0);
    v.push_back(44.0);
    v.push_back(45.0);
    v.push_back(46.0);
    v.push_back(47.0);
    v.push_back(48.0);
    v.push_back(49.0);
    v.push_back(50.0);
    v.push_back(51.0);
    v.push_back(52.0);
    v.push_back(53.0);
    v.push_back(54.0);

    double m = median(v);

    cout << "median(double) = " << m << endl;

    vector<string> v2;
    v2.push_back("1");
    v2.push_back("2");
    v2.push_back("3");
    v2.push_back("4");
    v2.push_back("5");

    string m2 = median(v2);

    cout << "median(string) = " << m2 << endl;

    return 0;
}
