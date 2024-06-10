#include <iostream>
#include "Conversion.h"

int main() {
    // Test cases
    Conversion conv1("AB11", 16);
    Conversion conv2("10110", 2);
    Conversion conv3("6", 8);

    std::cout << conv1 << std::endl;
    std::cout << conv2 << std::endl;
    std::cout << conv3 << std::endl;

    return 0;
}
