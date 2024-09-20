#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>
#include <stdexcept>

class StringCalculator {
public:
    int add(const std::string& numbers);

private:
    std::string ExtractDelimiter(std::string& numbers);
    std::string ReplaceNewlines(const std::string& numbers, const std::string& delimiter);
    std::vector<int> ExtractingNumbers(const std::string& input, const std::string& delimiter);
    void Negatives(const std::vector<int>& numbers);
    int SumValidNumbers(const std::vector<int>& numbers);
    bool isGreaterThanLimit(int number, int limit);
};

#endif // STRINGCALCULATOR_H
