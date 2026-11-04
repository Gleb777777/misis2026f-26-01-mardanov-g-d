#include <rational/rational.hpp>

#include <iostream>
#include <numeric>
#include <stdexcept>

Rational::Rational(const std::int32_t num, const std::int32_t den)
    : num_(num), den_(den) {
    if (0 == den_) {
        throw std::invalid_argument("Zero denominator in Rational ctor");
    }
    normalize();
}

void Rational::normalize() noexcept {
    if (den_ < 0) {
        num_ = -num_;
        den_ = -den_;
    }
    const std::int32_t g = std::gcd(num_, den_);
    if (g > 1) {
        num_ /= g;
        den_ /= g;
    }
}

bool Rational::operator==(const Rational& rhs) const noexcept {
    return num_ == rhs.num_ && den_ == rhs.den_;
}
bool Rational::operator!=(const Rational& rhs) const noexcept { return !operator==(rhs); }
bool Rational::operator<(const Rational& rhs) const noexcept {
    return static_cast<std::int64_t>(num_) * rhs.den_ < static_cast<std::int64_t>(rhs.num_) * den_;
}
bool Rational::operator<=(const Rational& rhs) const noexcept { return !(rhs < *this); }
bool Rational::operator>(const Rational& rhs) const noexcept { return rhs < *this; }
bool Rational::operator>=(const Rational& rhs) const noexcept { return !(*this < rhs); }

Rational& Rational::operator+=(const Rational& rhs) noexcept {
    num_ = num_ * rhs.den_ + rhs.num_ * den_;
    den_ *= rhs.den_;
    normalize();
    return *this;
}
Rational& Rational::operator-=(const Rational& rhs) noexcept {
    num_ = num_ * rhs.den_ - rhs.num_ * den_;
    den_ *= rhs.den_;
    normalize();
    return *this;
}
Rational& Rational::operator*=(const Rational& rhs) noexcept {
    num_ *= rhs.num_;
    den_ *= rhs.den_;
    normalize();
    return *this;
}
Rational& Rational::operator/=(const Rational& rhs) {
    if (0 == rhs.num_) {
        throw std::invalid_argument("Division by zero in Rational::operator/=");
    }
    num_ *= rhs.den_;
    den_ *= rhs.num_;  // знак может стать отрицательным, normalize это исправит
    normalize();
    return *this;
}

Rational& Rational::operator+=(const std::int32_t rhs) noexcept { return operator+=(Rational(rhs)); }
Rational& Rational::operator-=(const std::int32_t rhs) noexcept { return operator-=(Rational(rhs)); }
Rational& Rational::operator*=(const std::int32_t rhs) noexcept { return operator*=(Rational(rhs)); }
Rational& Rational::operator/=(const std::int32_t rhs) { return operator/=(Rational(rhs)); }

Rational operator+(const Rational& lhs, const Rational& rhs) noexcept { return Rational{ lhs } += rhs; }
Rational operator-(const Rational& lhs, const Rational& rhs) noexcept { return Rational{ lhs } -= rhs; }
Rational operator*(const Rational& lhs, const Rational& rhs) noexcept { return Rational{ lhs } *= rhs; }
Rational operator/(const Rational& lhs, const Rational& rhs) { return Rational{ lhs } /= rhs; }

Rational operator+(const Rational& lhs, const std::int32_t rhs) noexcept { return Rational{ lhs } += rhs; }
Rational operator-(const Rational& lhs, const std::int32_t rhs) noexcept { return Rational{ lhs } -= rhs; }
Rational operator*(const Rational& lhs, const std::int32_t rhs) noexcept { return Rational{ lhs } *= rhs; }
Rational operator/(const Rational& lhs, const std::int32_t rhs) { return Rational{ lhs } /= rhs; }

Rational operator+(const std::int32_t lhs, const Rational& rhs) noexcept { return Rational{ lhs } += rhs; }
Rational operator-(const std::int32_t lhs, const Rational& rhs) noexcept { return Rational{ lhs } -= rhs; }
Rational operator*(const std::int32_t lhs, const Rational& rhs) noexcept { return Rational{ lhs } *= rhs; }
Rational operator/(const std::int32_t lhs, const Rational& rhs) { return Rational{ lhs } /= rhs; }

std::ostream& Rational::write_to(std::ostream& ostrm) const noexcept {
    ostrm << num_ << '/' << den_;
    return ostrm;
}

std::istream& Rational::read_from(std::istream& istrm) noexcept {
    std::int32_t num = 0, den = 1;
    char slash = 0;
    istrm >> num >> slash >> den;
    if (!istrm.fail()) {
        if ('/' == slash && 0 != den) {
            num_ = num;
            den_ = den;
            normalize();
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept { return rhs.write_to(ostrm); }
std::istream& operator>>(std::istream& istrm, Rational& rhs) noexcept { return rhs.read_from(istrm); }