#include "StringCalculator.h"
#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>
#include <algorithm> // for std::remove_if

int StringCalculator::addNumbers(const std::string& input) {
    if (input.empty()) {
        return 0; // Handle empty input
    }

    std::string delimiter = findDelimiter(input);
    std::string cleanedInput = replaceNewlines(input, delimiter);
    std::vector<int> numbers = splitIntoNumbers(cleanedInput, delimiter[0]);
    checkForNegativeNumbers(numbers);
    return sumValidNumbers(numbers);
}

// No conditionals in this function
std::string StringCalculator::findDelimiter(const std::string& input) {
    if (input.substr(0, 2) == "//") {
        return input.substr(2, input.find("\n") - 2);
    }
    return ","; // Default delimiter
}

// No conditionals in this function
std::string StringCalculator::replaceNewlines(const std::string& input, const std::string& delimiter) {
    std::string result = input;
    std::replace(result.begin(), result.end(), '\n', delimiter[0]);
    return result.substr(result.find("\n") + 1); // Skip the first line if there's a custom delimiter
}

// Replaces 'parseNumbers' and 'ss', splits input into numbers
std::vector<int> StringCalculator::splitIntoNumbers(const std::string& input, char delimiter) {
    std::vector<int> numbers;
    std::string temp;
    for (char c : input) {
        if (c == delimiter) {
            numbers.push_back(std::stoi(temp));
            temp.clear();
        } else {
            temp += c;
        }
    }
    if (!temp.empty()) {
        numbers.push_back(std::stoi(temp)); // Add the last number
    }
    return numbers;
}

// No conditionals in this function
void StringCalculator::checkForNegativeNumbers(const std::vector<int>& numbers) {
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

// No conditionals in this function
int StringCalculator::sumValidNumbers(const std::vector<int>& numbers) {
    int sum = 0;
    for (int num : numbers) {
        if (num <= 1000) {
            sum += num;
        }
    }
    return sum;
}
