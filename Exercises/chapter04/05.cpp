#include "stdafx.h"
#include <algorithm>
#include <exception>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::vector;
using std::string;
using std::istream;
using std::ostream;
using std::sort;
using std::domain_error;

istream& read(istream& in, vector<string>& words) {
    if (in) {
        words.clear();
        string word;
        while (in >> word) {
            words.push_back(word);
        }
        in.clear();
    }

    return in;
}

unsigned count_distinct(vector<string> words) {
    if (words.size() < 2) {
        return words.size();
    }

    sort(words.begin(), words.end());

    unsigned count = 1;

    for (vector<string>::size_type i = 1; i < words.size(); i ++) {
        if (words[i] != words[i - 1]) {
            count ++;
        }
    }

    return count;
}

ostream& count_occurence(ostream& out, vector<string> words) {
    if (words.size() < 2) {
        throw domain_error("Vector should have atleast two elements.");
    }

    sort(words.begin(), words.end());

    for (vector<string>::size_type i = 0, counter = 0; i < words.size(); i ++) {
        counter ++;
        if (i + 1 == words.size() || words[i] != words[i + 1]) {
            out << words[i] << ": " << counter << endl;
            counter = 0;
        }
    }

    return out;
}

int main(void) {
    vector<string> words;
    read(cin, words);
    cout << "Number of distinct words: " << count_distinct(words) << endl;
    count_occurence(cout, words);

    return 0;
}
