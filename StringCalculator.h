#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>

class StringCalculator {
public:
    int add(const std::string& numbers); // Main function to add numbers

private:
    std::vector<int> extractNumbers(const std::string& input, const std::string& delimiter);
    std::string getDelimiter(const std::string& numbers, std::string& input);
    void checkForNegatives(const std::vector<int>& numbers);
};

#endif // STRINGCALCULATOR_H
