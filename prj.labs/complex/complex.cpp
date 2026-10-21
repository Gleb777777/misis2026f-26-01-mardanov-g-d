#include <iostream> 1 
#include <sstream> 2 
 3 
struct Complex { 4 
    Complex() {} 5 
    explicit Complex(const double real); 6 
    Complex(const double real, const double imaginary); 7 
    bool operator==(const Complex& rhs) const { return (re == rhs.re) && (im == rhs.im); } 8 
    bool operator!=(const Complex& rhs) const { return !operator==(rhs); } 9 
    Complex& operator+=(const Complex& rhs); 10 
    Complex& operator+=(const double rhs) { return operator+=(Complex(rhs)); } 11 
    //Complex& operator-=(const Complex& rhs); 12 
    //Complex& operator-=(const double rhs) { return operator-=(Complex(rhs)); } 13 
    //Complex& operator*=(const Complex& rhs); 14 
    Complex& operator*=(const double rhs); 15 
    std::ostream& writeTo(std::ostream& ostrm) const; 16 
    std::istream& readFrom(std::istream& istrm); 17 
 18 
    double re{ 0.0 }; 19 
    double im{ 0.0 }; 20 
 21 
    static const char leftBrace{ '{' }; 22 
    static const char separator{ ',' }; 23 
    static const char rightBrace{ '}' }; 24 
}; 25 
 26 
Complex operator+(const Complex& lhs, const Complex& rhs); 27 
Complex operator-(const Complex& lhs, const Complex& rhs); 28 
 29 
inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) 30 
{ 31 
    return rhs.writeTo(ostrm); 32 
} 33 
 34 
inline std::istream& operator>>(std::istream& istrm, Complex& rhs) 35 
{ 36 
    return rhs.readFrom(istrm); 37 
} 38 
 39 
bool testParse(const std::string& str) 40 
{ 41 
    using namespace std; 42 
    istringstream istrm(str); 43 
    Complex z; 44 
    istrm >> z; 45 
    if (istrm.good()) { 46 
        cout << "Read success: " << str << " -> " << z << endl; 47 
    } else { 48 
        cout << "Read error  : " << str << " -> " << z << endl; 49 
    } 50 
    return istrm.good(); 51 
} 52 
 53 
int main() 54 
{ 55 
    using namespace std; 56 
 57 
    Complex z; 58 
    z += Complex(8.0); 59 
    testParse("{8.9,9}"); 60 
    testParse("{8.9, 9}"); 61 
    testParse("{8.9,9"); 62 
    return 0; 63 
} 64 
 65 
Complex::Complex(const double real) 66 
    : Complex(real, 0.0) 67 
{ 68 
} 69 
 70 
Complex::Complex(const double real, const double imaginary) 71 
    : re(real) 72 
    , im(imaginary) 73 
{ 74 
} 75 
 76 
Complex& Complex::operator+=(const Complex& rhs) 77 
{ 78 
    re += rhs.re; 79 
    im += rhs.im; 80 
    return *this; 81 
} 82 
 83 
Complex operator+(const Complex& lhs, const Complex& rhs) 84 
{ 85 
    Complex sum(lhs); 86 
    sum += rhs; 87 
    return sum; 88 
} 89 
 90 
Complex operator-(const Complex& lhs, const Complex& rhs) 91 
{ 92 
    return Complex(lhs.re - rhs.re, lhs.im - rhs.im); 93 
} 94 
 95 
Complex& Complex::operator*=(const double rhs) 96 
{ 97 
    re *= rhs; 98 
    im *= rhs; 99 
    return *this; 100 
} 101 
 102 
std::ostream& Complex::writeTo(std::ostream& ostrm) const 103 
{ 104 
    ostrm << leftBrace << re << separator << im << rightBrace; 105 
    return ostrm; 106 
} 107 
 108 
std::istream& Complex::readFrom(std::istream& istrm) 109 
{ 110 
    char leftBrace(0); 111 
    double real(0.0); 112 
    char comma(0); 113 
    double imaganary(0.0); 114 
    char rightBrace(0); 115 
    istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace; 116 
    if (istrm.good()) { 117 
        if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma) 118 
            && (Complex::rightBrace == rightBrace)) { 119 
            re = real; 120 
            im = imaganary; 121 
        } else { 122 
            istrm.setstate(std::ios_base::failbit); 123 
        } 124 
    } 125 
    return istrm; 126 
} 127 
