#include <iostream>
#include <vector>

int main(int argc, char** argv) {
    // test code. Replaced with your code
    std::cout << "Called with " << argc << " arguments\n";
    for (unsigned i = 0; i < argc; ++i) {
        std::cout << "Arg " << i << " is " << argv[i] << "\n";
    }
    std::cout << "Enter a numbers separated by comma: ";

    std::vector<unsigned> nums;
    char c = ',';

    while (c == ',' && !std::cin.fail() && !std::cin.eof()) {
        c = 0;
        unsigned num;
        std::cin >> num;
        if (std::cin.fail() || std::cin.eof()) break;
        nums.push_back(num);
        std::cin >> c;
        std::cerr << "got char: " << c << "\n";
    }

    if (std::cin.fail()) {
        std::cout << "Error parsing input\n";
    }

    if (!nums.empty()) {
        std::cout << "You have entered " << nums.size() << " numbers\n";
        for (std::vector<unsigned>::iterator it = nums.begin(), end = nums.end();
             it != end; ++it) {
            std::cout << *it;
            if (it+1 != end)
                std::cout << ",";
        }
    }
    std::cout << "\n";
}
