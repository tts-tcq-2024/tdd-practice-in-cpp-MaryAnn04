#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>
#include <stdexcept>

class StringCalculator {
public:
    int add(const std::string& numbers);

private:
    std::string getDelimiter(std::string& numbers);
    std::string normalizeInput(const std::string& numbers, const std::string& delimiter);
    std::vector<int> splitAndConvert(const std::string& input, const std::string& delimiter);
    void checkForNegatives(const std::vector<int>& numbers);
    int sumNumbers(const std::vector<int>& numbers);
};

#endif // STRINGCALCULATOR_H

