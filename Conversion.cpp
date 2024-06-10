#include "Conversion.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>

// Empty constructor
Conversion::Conversion() : number("0"), base(10) {}

// Regular constructor
Conversion::Conversion(const std::string& num, int base) : number(num), base(base) {}

// Convert the current number to decimal
int Conversion::toDecimal() const {
    int result = 0;
    int power = 0;
    for (auto it = number.rbegin(); it != number.rend(); ++it, ++power) {
        char digit = *it;
        if (digit >= '0' && digit <= '9') {
            result += (digit - '0') * std::pow(base, power);
        }
        else if (digit >= 'A' && digit <= 'F') {
            result += (digit - 'A' + 10) * std::pow(base, power);
        }
        else if (digit >= 'a' && digit <= 'f') {
            result += (digit - 'a' + 10) * std::pow(base, power);
        }
    }
    return result;
}

// Convert a decimal number to a specified base
std::string Conversion::fromDecimal(int value, int base) const {
    std::string result;
    while (value > 0) {
        int remainder = value % base;
        if (remainder < 10) {
            result += (remainder + '0');
        }
        else {
            result += (remainder - 10 + 'A');
        }
        value /= base;
    }
    std::reverse(result.begin(), result.end());
    return result.empty() ? "0" : result;
}

std::string Conversion::toBinary() const {
    return fromDecimal(toDecimal(), 2);
}

std::string Conversion::toDecimalString() const {
    return std::to_string(toDecimal());
}

std::string Conversion::toOctal() const {
    return fromDecimal(toDecimal(), 8);
}

std::string Conversion::toHexadecimal() const {
    return fromDecimal(toDecimal(), 16);
}

std::ostream& operator<<(std::ostream& os, const Conversion& conv) {
    os << "Original: " << conv.number << " (base " << conv.base << ")\n";
    os << "Binary: " << conv.toBinary() << "\n";
    os << "Decimal: " << conv.toDecimalString() << "\n";
    os << "Octal: " << conv.toOctal() << "\n";
    os << "Hexadecimal: " << conv.toHexadecimal() << "\n";
    return os;
}