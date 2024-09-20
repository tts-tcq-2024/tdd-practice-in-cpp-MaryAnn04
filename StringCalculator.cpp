#include "StringCalculator.h"
#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>

// Main function to add numbers
int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    std::string input = numbers;
    std::string delimiter = getDelimiter(numbers, input);
    std::vector<int> nums = extractNumbers(input, delimiter);
    checkForNegatives(nums);

    int sum = 0;
    for (int num : nums) {
        if (num <= 1000) {
            sum += num;
        }
    }

    return sum;
}

// Get the delimiter and modify the input if necessary
std::string StringCalculator::getDelimiter(const std::string& numbers, std::string& input) {
    if (numbers.substr(0, 2) == "//") {
        size_t delimiterEnd = numbers.find("\n");
        std::string delimiter = numbers.substr(2, delimiterEnd - 2);
        input = numbers.substr(delimiterEnd + 1);  // Skip the delimiter part
        return delimiter;
    }
    return ",";
}

// Split string into numbers and convert them
std::vector<int> StringCalculator::extractNumbers(const std::string& input, const std::string& delimiter) {
    std::vector<int> numbers;
    std::string modifiedInput = input;
    
    // Replace newlines with the delimiter
    for (char& ch : modifiedInput) {
        if (ch == '\n') {
            ch = delimiter[0];
        }
    }

    std::stringstream ss(modifiedInput);
    std::string temp;

    while (std::getline(ss, temp, delimiter[0])) {
        numbers.push_back(std::stoi(temp));
    }

    return numbers;
}

// Check if any negative numbers exist
void StringCalculator::checkForNegatives(const std::vector<int>& numbers) {
    std::vector<int> negatives;
    for (int num : numbers) {
        if (num < 0) {
            negatives.push_back(num);
        }
    }

    if (!negatives.empty()) {
        std::string errorMsg = "Negatives not allowed: ";
        for (int neg : negatives) {
            errorMsg += std::to_string(neg) + " ";
        }
        throw std::runtime_error(errorMsg);
    }
}
