#include <rational/rational.hpp>

#include <sstream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("[rational] - ctor default") {
	Rational r0;
	CHECK(0 == r0.num());
	CHECK(1 == r0.den());
}

TEST_CASE("[rational] - ctor") {
	Rational r1(3);
	CHECK(3 == r1.num());
	CHECK(1 == r1.den());
	Rational r2(-6, 2);
	CHECK(-3 == r2.num());
	CHECK(1 == r2.den());
	Rational r3(2, -6);
	CHECK(-1 == r3.num());
	CHECK(3 == r3.den());

	CHECK_THROWS(Rational(1, 0));
}

TEST_CASE("[rational] - compare") {
	CHECK(Rational(1, 2) == Rational(2, 4));
	CHECK(Rational(1, 3) != Rational(1, 2));
	CHECK(Rational(1, 3) < Rational(1, 2));
	CHECK(Rational(1, 2) <= Rational(1, 2));
	CHECK(Rational(2, 3) > Rational(1, 2));
	CHECK(Rational(2, 3) >= Rational(2, 3));
}

TEST_CASE("[rational] - arithmetic") {
	CHECK(Rational(1, 2) + Rational(1, 3) == Rational(5, 6));
	CHECK(Rational(1, 2) - Rational(1, 3) == Rational(1, 6));
	CHECK(Rational(2, 3) * Rational(3, 4) == Rational(1, 2));
	CHECK(Rational(1, 2) / Rational(1, 4) == Rational(2));
	CHECK(Rational(1, 2) + 1 == Rational(3, 2));
	CHECK(1 - Rational(1, 4) == Rational(3, 4));
	CHECK(2 * Rational(1, 4) == Rational(1, 2));
	CHECK(1 / Rational(2, 3) == Rational(3, 2));
	CHECK(-Rational(1, 2) == Rational(-1, 2));
	CHECK_THROWS(Rational(1, 2) / Rational(0));
}

TEST_CASE("[rational] - io") {
	std::stringstream s;
	s << Rational(6, -4);
	CHECK(s.str() == "-3/2");

	Rational r;
	std::istringstream in("4/-6");
	in >> r;
	CHECK(r == Rational(-2, 3));
}