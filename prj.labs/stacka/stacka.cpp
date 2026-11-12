#include <stacka/stacka.hpp>

#include <algorithm>
#include <stdexcept>
#include <utility>

StackA::StackA(const StackA& rhs) {
    if (rhs.size_ > 0) {
        data_ = new Value[rhs.size_];
        capacity_ = rhs.size_;
        size_ = rhs.size_;
        std::copy(rhs.data_, rhs.data_ + rhs.size_, data_);
    }
}

StackA::StackA(StackA&& rhs) noexcept
    : data_(std::exchange(rhs.data_, nullptr)),
    size_(std::exchange(rhs.size_, 0)),
    capacity_(std::exchange(rhs.capacity_, 0)) {
}

StackA::~StackA() { delete[] data_; }

StackA& StackA::operator=(const StackA& rhs) {
    if (this != &rhs) {
        StackA tmp(rhs);
        swap(tmp);
    }
    return *this;
}

StackA& StackA::operator=(StackA&& rhs) noexcept {
    if (this != &rhs) {
        StackA tmp(std::move(rhs));
        swap(tmp);
    }
    return *this;
}

void StackA::push(const Value v) {
    if (size_ == capacity_) {
        reserve(0 == capacity_ ? 4 : capacity_ * 2);
    }
    data_[size_++] = v;
}

void StackA::pop() {
    if (0 == size_) {
        throw std::out_of_range("pop from empty StackA");
    }
    --size_;
}

StackA::Value& StackA::top() {
    if (0 == size_) {
        throw std::out_of_range("top of empty StackA");
    }
    return data_[size_ - 1];
}

const StackA::Value& StackA::top() const {
    if (0 == size_) {
        throw std::out_of_range("top of empty StackA");
    }
    return data_[size_ - 1];
}

void StackA::swap(StackA& rhs) noexcept {
    std::swap(data_, rhs.data_);
    std::swap(size_, rhs.size_);
    std::swap(capacity_, rhs.capacity_);
}

void StackA::reserve(const std::size_t new_capacity) {
    Value* new_data = new Value[new_capacity];
    std::copy(data_, data_ + size_, new_data);
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
}