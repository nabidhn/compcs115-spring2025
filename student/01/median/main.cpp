#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstdlib>  // for EXIT_SUCCESS and EXIT_FAILURE

int main() {
    std::cout << "Enter numbers: ";

    std::string line;
    if (!std::getline(std::cin, line)) {
        std::cout << "No input" << std::endl;
        return EXIT_FAILURE;
    }

    std::istringstream iss(line);
    std::vector<double> numbers;
    double num;

    while (iss >> num) {
        numbers.push_back(num);
    }

    // If there is still stuff left after trying to read doubles, it's invalid input
    if (!iss.eof()) {
        std::cout << "Not a double" << std::endl;
        return EXIT_FAILURE;
    }

    if (numbers.empty()) {
        std::cout << "No input" << std::endl;
        return EXIT_FAILURE;
    }

    std::sort(numbers.begin(), numbers.end());

    double median;
    std::size_t n = numbers.size();
    if (n % 2 == 1) {
        median = numbers[n / 2];
    } else {
        median = (numbers[n / 2 - 1] + numbers[n / 2]) / 2.0;
    }

    std::cout << "Median: " << median << std::endl;

    return EXIT_SUCCESS;
}
