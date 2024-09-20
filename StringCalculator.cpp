#include "StringCalculator.h"
#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>

int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    std::string delimiter = ",";
    std::string input = numbers;
    
    // Custom delimiter case
    if (numbers.substr(0, 2) == "//") {
        size_t delimiterEnd = numbers.find("\n");
        delimiter = numbers.substr(2, delimiterEnd - 2);
        input = numbers.substr(delimiterEnd + 1);
    }
    
    // Replace newline with the delimiter
    for (char& ch : input) {
        if (ch == '\n') {
            ch = delimiter[0];
        }
    }

    // Split input based on delimiter and sum the numbers
    std::vector<int> nums;
    std::stringstream ss(input);
    std::string temp;
    int sum = 0;
    std::vector<int> negatives;
    
    while (std::getline(ss, temp, delimiter[0])) {
        int num = std::stoi(temp);
        if (num < 0) {
            negatives.push_back(num);
        } else if (num <= 1000) {
            sum += num;
        }
    }

    if (!negatives.empty()) {
        std::string errorMsg = "Negatives not allowed: ";
        for (int neg : negatives) {
            errorMsg += std::to_string(neg) + " ";
        }
        throw std::runtime_error(errorMsg);
    }

    return sum;
}
