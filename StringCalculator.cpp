#include "StringCalculator.h"
#include <algorithm>
#include <numeric>
#include <sstream>

int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    std::string input = numbers;
    std::string delimiter = getDelimiter(input);

    std::string normalizedInput = normalizeInput(input, delimiter);
    std::vector<int> nums = splitAndConvert(normalizedInput, delimiter);

    checkForNegatives(nums);
    
    return sumNumbers(nums);
}

std::string StringCalculator::getDelimiter(std::string& numbers) {
    std::string delimiter = ",";

    // Check for custom delimiter format
    if (numbers.substr(0, 2) == "//") {
        size_t delimiterEndPos = numbers.find("\n");
        delimiter = numbers.substr(2, delimiterEndPos - 2);  // Extract delimiter
        numbers = numbers.substr(delimiterEndPos + 1);  // Update string without delimiter declaration
    }

    return delimiter;
}

std::string StringCalculator::normalizeInput(const std::string& numbers, const std::string& delimiter) {
    std::string result = numbers;
    
    // Replace all newline characters with the delimiter
    std::replace(result.begin(), result.end(), '\n', delimiter[0]);
    
    return result;
}

std::vector<int> StringCalculator::splitAndConvert(const std::string& input, const std::string& delimiter) {
    std::vector<int> tokens;
    size_t start = 0;
    size_t end = input.find(delimiter);

    while (end != std::string::npos) {
        tokens.push_back(std::stoi(input.substr(start, end - start)));
        start = end + delimiter.length();
        end = input.find(delimiter, start);
    }

    // Last token
    tokens.push_back(std::stoi(input.substr(start, end)));
    return tokens;
}

void StringCalculator::checkForNegatives(const std::vector<int>& numbers) {
    std::vector<int> negatives;
    for (int num : numbers) {
        if (num < 0) {
            negatives.push_back(num);
        }
    }

    if (!negatives.empty()) {
        std::string errorMessage = "negatives not allowed: ";
        for (int neg : negatives) {
            errorMessage += std::to_string(neg) + " ";
        }
        throw std::runtime_error(errorMessage);
    }
}

int StringCalculator::sumNumbers(const std::vector<int>& numbers) {
    int sum = 0;

    for (int num : numbers) {
        if (num <= 1000) {
            sum += num;
        }
    }

    return sum;
}
