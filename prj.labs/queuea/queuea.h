#pragma once

#include <cstddef>
#include <cstdint>

class QueueA {
public:
    QueueA();
    QueueA(const QueueA& other);
    QueueA& operator=(const QueueA& other);
    ~QueueA();

    void push(std::int64_t value);
    void pop();
    std::int64_t& top();
    const std::int64_t& top() const;
    bool isempty() const noexcept;

private:
    std::size_t capacity_ = 16;
    std::size_t head_ = 0;
    std::size_t tail_ = 0;
    std::size_t size_ = 0;
    std::int64_t* data_ = nullptr;
};