#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

double average(const vector<double>& nums) {
    double sum = 0;

    for (vector<double>::size_type i = 0; i < nums.size(); i ++) {
        sum += nums[i];
    }

    return sum / nums.size();
}

int main()
{
    vector<double> numbers;

    // ask the for double input
    cout << "Enter doubles, followed by end-of-file: " << endl;

    double d;
    while (cin >> d)
        numbers.push_back(d);
    
    cout << "The average is: " << average(numbers) << endl;
}
