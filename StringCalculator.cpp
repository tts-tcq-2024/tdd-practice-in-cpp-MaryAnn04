#include "StringCalculator.h"
#include <algorithm>
#include <numeric>
#include <sstream>
#include <functional>

int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    std::string input = numbers;
    std::string delimiter = extractDelimiter(input);

    std::string normalizedInput = replaceNewlines(input, delimiter);
    std::vector<int> nums;

    // Directly parse numbers in add function
    std::istringstream ss(normalizedInput);
    std::string token;

    while (std::getline(ss, token, delimiter[0])) {
        if (!token.empty()) {
            nums.push_back(std::stoi(token));
        }
    }

    handleNegatives(nums);
    
    return sumValidNumbers(nums);
}

std::string StringCalculator::extractDelimiter(std::string& numbers) {
    if (numbers.substr(0, 2) == "//") {
        size_t delimiterEndPos = numbers.find("\n");
        std::string delimiter = numbers.substr(2, delimiterEndPos - 2);  // Extract delimiter
        numbers = numbers.substr(delimiterEndPos + 1);  // Update input to remove delimiter declaration
        return delimiter;
    }
    return ",";  // Default delimiter
}

std::string StringCalculator::replaceNewlines(const std::string& numbers, const std::string& delimiter) {
    std::string result = numbers;
    std::replace(result.begin(), result.end(), '\n', delimiter[0]);
    return result;
}

void StringCalculator::handleNegatives(const std::vector<int>& numbers) {
    std::vector<int> negatives;
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(negatives), [](int num) { return num < 0; });

    if (!negatives.empty()) {
        std::string errorMessage = "negatives not allowed: ";
        for (int neg : negatives) {
            errorMessage += std::to_string(neg) + " ";
        }
        throw std::runtime_error(errorMessage);
    }
}

int StringCalculator::sumValidNumbers(const std::vector<int>& numbers) {
    int sum = 0;

    std::for_each(numbers.begin(), numbers.end(), [&sum, this](int num) {
        if (!isGreaterThanLimit(num, 1000)) {
            sum += num;
        }
    });

    return sum;
}

bool StringCalculator::isGreaterThanLimit(int number, int limit) {
    return number > limit;
}
