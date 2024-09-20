#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>
#include <stdexcept>

class StringCalculator {
public:
    int add(const std::string& numbers);

private:
    std::string extractDelimiter(std::string& numbers);
    std::string replaceNewlines(const std::string& numbers, const std::string& delimiter);
    std::vector<int> parseNumbers(const std::string& input, const std::string& delimiter);
    void handleNegatives(const std::vector<int>& numbers);
    int sumValidNumbers(const std::vector<int>& numbers);
    bool isGreaterThanLimit(int number, int limit);
};

#endif // STRINGCALCULATOR_H
