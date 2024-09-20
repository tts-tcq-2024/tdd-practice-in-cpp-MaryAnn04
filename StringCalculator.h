#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>

class StringCalculator {
public:
    int addNumbers(const std::string& input); // Main function to add numbers

private:
    std::string findDelimiter(const std::string& input); // No conditionals here
    std::string replaceNewlines(const std::string& input, const std::string& delimiter); // No conditionals here
    std::vector<int> splitIntoNumbers(const std::string& input, char delimiter); // No conditionals here
    void checkForNegativeNumbers(const std::vector<int>& numbers); // No conditionals here
    int sumValidNumbers(const std::vector<int>& numbers); // No conditionals here
};

#endif // STRINGCALCULATOR_H
