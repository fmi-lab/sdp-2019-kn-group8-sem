#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Source.h"



void read_numbers_from_file(std::string& numbers_file_name)
{
    std::vector<int> numbers;
    std::ifstream file_in;
    file_in.open(numbers_file_name);
    while (!file_in.eof()) {
        int n;
        file_in >> n;
        if (!file_in.eof()) {
            std::cout << n << std::endl;
            numbers.push_back(n);
        }
    }
}

void write_numbers_to_file(int n, std::string& numbers_file_name)
{
    std::ofstream file_out;

    file_out.open(numbers_file_name);

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; j = j*2) {
            //file_out.operator<<(i);
            file_out << i << std::endl;
        }
    }
    //file_out.flush();
    file_out.close();
}



int main() {
    std::string numbers_file_name = "numbers.txt";
    write_numbers_to_file(numbers_file_name);
    read_numbers_from_file(numbers_file_name);

    return 0;
}
