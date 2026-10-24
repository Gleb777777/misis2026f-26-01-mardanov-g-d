#include <iostream>
#include <sstream>

struct Complex {
    Complex() {}
    explicit Complex(const double real);
    Complex(const double real, const double imaginary);

    bool operator==(const Complex& rhs) const { return (re == rhs.re) && (im == rhs.im); }
    bool operator!=(const Complex& rhs) const { return !operator==(rhs); }

    Complex& operator+=(const Complex& rhs);
    Complex& operator+=(const double rhs) { return operator+=(Complex(rhs)); }

    Complex& operator-=(const Complex& rhs);
    Complex& operator-=(const double rhs) { return operator-=(Complex(rhs)); }

    Complex& operator*=(const Complex& rhs);
    Complex& operator*=(const double rhs);

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

    double re{ 0.0 };
    double im{ 0.0 };

    static const char leftBrace{ '{' };
    static const char separator{ ',' };
    static const char rightBrace{ '}' };
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
    return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs)
{
    return rhs.readFrom(istrm);
}

bool testParse(const std::string& str)
{
    using namespace std;
    istringstream istrm(str);
    Complex z;
    istrm >> z;
    if (istrm.good()) {
        cout << "Read success: " << str << " -> " << z << endl;
    }
    else {
        cout << "Read error  : " << str << " -> " << z << endl;
    }
    return istrm.good();
}

int main()
{
    using namespace std;

    Complex z;
    z += Complex(8.0);

    // Тесты парсинга из оригинального кода
    testParse("{8.9,9}");
    testParse("{8.9, 9}");
    testParse("{8.9,9");

    // Тесты для новых операторов
    Complex a(5.0, 3.0); // 5 + 3i
    Complex b(2.0, 1.0); // 2 + 1i

    a -= b; // (5-2) + (3-1)i = 3 + 2i
    cout << "a -= b: " << a << endl;

    a -= 1.0; // (3-1) + 2i = 2 + 2i
    cout << "a -= 1.0: " << a << endl;

    Complex c(1.0, 2.0); // 1 + 2i
    Complex d(3.0, 4.0); // 3 + 4i
    c *= d; // (1*3 - 2*4) + (1*4 + 2*3)i = -5 + 10i
    cout << "c *= d: " << c << endl;

    c *= 2.0; // Умножение на скаляр
    cout << "c *= 2.0: " << c << endl;

    return 0;
}

// --- РЕАЛИЗАЦИЯ МЕТОДОВ И ОПЕРАТОРОВ ---

Complex::Complex(const double real)
    : Complex(real, 0.0)
{
}

Complex::Complex(const double real, const double imaginary)
    : re(real)
    , im(imaginary)
{
}

Complex& Complex::operator+=(const Complex& rhs)
{
    re += rhs.re;
    im += rhs.im;
    return *this;
}

Complex& Complex::operator-=(const Complex& rhs)
{
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}

Complex& Complex::operator*=(const Complex& rhs)
{
    // (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
    double new_re = re * rhs.re - im * rhs.im;
    double new_im = re * rhs.im + im * rhs.re;
    re = new_re;
    im = new_im;
    return *this;
}

Complex& Complex::operator*=(const double rhs)
{
    re *= rhs;
    im *= rhs;
    return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
    Complex sum(lhs);
    sum += rhs;
    return sum;
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace << re << separator << im << rightBrace;
    return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm)
{
    char leftBrace(0);
    double real(0.0);
    char comma(0);
    double imaginary(0.0); // Исправлена опечатка imaganary -> imaginary
    char rightBrace(0);

    istrm >> leftBrace >> real >> comma >> imaginary >> rightBrace;

    if (istrm.good()) {
        if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
            && (Complex::rightBrace == rightBrace)) {
            re = real;
            im = imaginary;
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}