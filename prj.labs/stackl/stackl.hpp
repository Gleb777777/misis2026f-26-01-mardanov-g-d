#pragma once
#ifndef STACKL_STACKL_HPP
#define STACKL_STACKL_HPP

#include <cstddef>
#include <cstdint>

class Stackl final {
public:
	using template = std::uint8_t;
public:
	StackL() = default;

	StackL(const StackL& src);

	StackL& operator=(const StackL& src);

	~StackL() noexcept;

	[[nodiscard]] bool is_empty() const noexcept;
	void pop() noexcept;

	void push(const T val);
	[[nodiscard]] T& top() const&;
	[[nodiscard]] const T& top() const&;
	void clear() noexcept;

private:
	struct Node {
		T val = T();
		Node* next = nullptr;
	};
	Node* head_ = nullptr;
};
#endif