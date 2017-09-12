// Compile with c++ ece650-a2cpp -std=c++11 -o ece650-a2
#include <iostream>
#include <sstream>
#include <vector>

int main(int argc, char** argv) {
    // Test code. Replaced with your code
    std::cout << "Called with " << argc << " arguments\n";
    for (int i = 0; i < argc; ++i)
        std::cout << "Arg " << i << " is " << argv[i] << "\n";

    const char comma = ',';

    while (!std::cin.eof()) {
        std::cout << "Enter numbers separated by comma: ";

        std::string line;
        std::getline(std::cin, line);
        std::istringstream input(line);
        std::vector<unsigned> nums;

        while (!input.eof()) {
            unsigned num;
            if (!(input >> num))
                std::cerr << "Error parsing number\n";
            else
                nums.push_back(num);

            if (input.eof())
                break;

            char separator;
            if (!(input >> separator) || separator != comma) {
                std::cerr << "Error parsing separator\n";
                break;
            }
        }

        if (!nums.empty()) {
            std::cout << "\nYou have entered " << nums.size() << " numbers: ";
            size_t i = 0;
            for (unsigned& x : nums) {
                std::cout << x;
                if (++i < nums.size()) std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
}
