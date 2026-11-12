#include <stacka/stacka.hpp>

#include <stdexcept>
#include <utility>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("[stacka] - default is empty") {
	StackA s;
	CHECK(s.empty());
	CHECK(0 == s.size());
}

TEST_CASE("[stacka] - push, top, pop") {
	StackA s;
	s.push(1);
	s.push(2);
	s.push(3);
	CHECK(3 == s.size());
	CHECK(3 == s.top());
	s.pop();
	CHECK(2 == s.top());
	s.pop();
	CHECK(1 == s.top());
	s.pop();
	CHECK(s.empty());
}

TEST_CASE("[stacka] - growth") {
	StackA s;
	for (int i = 0; i < 1000; ++i) {
		s.push(i);
	}
	CHECK(1000 == s.size());
	for (int i = 999; i >= 0; --i) {
		CHECK(i == s.top());
		s.pop();
	}
	CHECK(s.empty());
}

TEST_CASE("[stacka] - contracts") {
	StackA s;
	CHECK_THROWS_AS(s.top(), std::out_of_range);
	CHECK_THROWS_AS(s.pop(), std::out_of_range);
}

TEST_CASE("[stacka] - clear") {
	StackA s;
	s.push(1);
	s.push(2);
	s.clear();
	CHECK(s.empty());
	s.push(5);
	CHECK(5 == s.top());
}

TEST_CASE("[stacka] - copy is independent") {
	StackA a;
	a.push(1);
	a.push(2);
	StackA b(a);
	b.push(3);
	CHECK(2 == a.size());
	CHECK(3 == b.size());

	StackA c;
	c.push(9);
	c = a;
	CHECK(2 == c.size());
	CHECK(2 == c.top());
}

TEST_CASE("[stacka] - move") {
	StackA a;
	a.push(1);
	a.push(2);
	StackA b(std::move(a));
	CHECK(2 == b.size());
	CHECK(2 == b.top());
	CHECK(a.empty());

	StackA c;
	c = std::move(b);
	CHECK(2 == c.size());
	CHECK(b.empty());
}