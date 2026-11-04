#include <complex/complex.hpp>

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

void check_contracts() {
    try {
        std::cout << "try divide by zero -> ";
        Complex z;
        z /= 0;
        std::cout << "nothing happens (trouble)";
    }
    catch (const std::invalid_argument& ex) {
        std::cout << "exception caught, msg - " << ex.what();
    }
    std::cout << "\n";
}

bool testParse(const std::string& str) {
    std::istringstream istrm(str);
    Complex z;
    istrm >> z;
    if (!istrm.fail()) {
        std::cout << "Read success: " << str << " -> " << z << std::endl;
    }
    else {
        std::cout << "Read error  : " << str << " -> " << z << std::endl;
    }
    return !istrm.fail();
}

int main() {
    check_contracts();

    Complex a(1, 2), b(3, -1);
    std::cout << a << " + " << b << " = " << a + b << "\n";
    std::cout << a << " - " << b << " = " << a - b << "\n";
    std::cout << a << " * " << b << " = " << a * b << "\n";
    std::cout << a << " / " << b << " = " << a / b << "\n";

    testParse("{8.9,9}");
    testParse("{8.9, 9}");
    testParse("{8.9,9");
    return 0;
}