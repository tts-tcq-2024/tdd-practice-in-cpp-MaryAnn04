int Add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    std::string delimiter = ",";
    std::string numbersPart = numbers;

    if (numbers.substr(0, 2) == "//") {
        size_t endDelim = numbers.find("\n");
        std::string delimPart = numbers.substr(2, endDelim - 2);
        
        if (delimPart[0] == '[' && delimPart.back() == ']') {
            delimiter = delimPart.substr(1, delimPart.size() - 2);
        } else {
            delimiter = delimPart;
        }
        
        numbersPart = numbers.substr(endDelim + 1);
    }

    size_t pos;
    while ((pos = numbersPart.find("\n")) != std::string::npos) {
        numbersPart.replace(pos, 1, delimiter);
    }

    std::vector<int> nums = split(numbersPart, delimiter);
    std::vector<int> negatives;
    int sum = 0;

    for (int num : nums) {
        if (num < 0) {
            negatives.push_back(num);
        } else if (num <= 1000) {
            sum += num;
        }
    }

    if (!negatives.empty()) {
        std::string neg

