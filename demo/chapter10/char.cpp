#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
    std::string filename = "in";
    std::ifstream infile(filename);
    std::ofstream outfile("out");

    std::string s;

    while (getline(infile, s)) {
        outfile << s << std::endl;
    }

    return 0;
}
