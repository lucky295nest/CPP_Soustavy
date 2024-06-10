#ifndef CONVERSION_H
#define CONVERSION_H

#include <string>

class Conversion {
private:
    std::string number;
    int base;

    int toDecimal() const;
    std::string fromDecimal(int value, int base) const;

public:
    Conversion();
    Conversion(const std::string& num, int base);

    std::string toBinary() const;
    std::string toDecimalString() const;
    std::string toOctal() const;
    std::string toHexadecimal() const;

    friend std::ostream& operator<<(std::ostream& os, const Conversion& conv);
};

#endif // CONVERSION_H