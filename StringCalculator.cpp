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
    std::vector<int> nums = parseNumbers(normalizedInput, delimiter);

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

std::vector<int> StringCalculator::parseNumbers(const std::string& input, const std::string& delimiter) {
    std::vector<int> tokens;
    size_t start = 0;
    size_t end = input.find(delimiter);

    auto addToken = [&tokens, &input](size_t start, size_t length) {
        tokens.push_back(std::stoi(input.substr(start, length)));
    };

    while (end != std::string::npos) {
        addToken(start, end - start);
        start = end + delimiter.length();
        end = input.find(delimiter, start);
    }

    addToken(start, end);  // Add the last token
    return tokens;
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
