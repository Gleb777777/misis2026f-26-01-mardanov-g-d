#pragma once
#ifndef STACKA_STACKA_HPP
#define STACKA_STACKA_HPP

#include <cstddef>

class StackA {
public:
	using Value = int;

	StackA() = default;
	StackA(const StackA& rhs);
	StackA(StackA&& rhs) noexcept;
	~StackA();
	StackA& operator=(const StackA& rhs);
	StackA& operator=(StackA&& rhs) noexcept;

	void push(Value v);
	void pop();
	[[nodiscard]] Value& top();
	[[nodiscard]] const Value& top() const;
	[[nodiscard]] bool empty() const noexcept { return 0 == size_; }
	[[nodiscard]] std::size_t size() const noexcept { return size_; }
	void clear() noexcept { size_ = 0; }

private:
	void swap(StackA& rhs) noexcept;
	void reserve(std::size_t new_capacity);

	Value* data_ = nullptr;
	std::size_t size_ = 0;
	std::size_t capacity_ = 0;
};

#endif