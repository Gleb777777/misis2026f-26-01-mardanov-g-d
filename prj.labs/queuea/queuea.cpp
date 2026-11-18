#include <queuea/queuea.h>

#include <stdexcept>

QueueA::QueueA() : data_(new std::int64_t[capacity_]) {}

QueueA::~QueueA() {
    delete[] data_;
}

bool QueueA::isempty() const noexcept {
    return size_ == 0;
}
void QueueA::push(std::int64_t value) {
    if (size_ == capacity_) {
        std::size_t new_capacity = capacity_ * 2;
        std::int64_t* new_data = new std::int64_t[new_capacity];

        for (std::size_t i = 0; i < size_; ++i) {
            new_data[i] = data_[(head_ + i) % capacity_];
        }

        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
        head_ = 0;
        tail_ = size_;
    }

    data_[tail_] = value;
    tail_ = (tail_ + 1) % capacity_;
    ++size_;
}

void QueueA::pop() {
    if (isempty()) return;

    head_ = (head_ + 1) % capacity_;
    --size_;
}
std::int64_t& QueueA::top() {
    if (isempty()) {
        throw std::out_of_range("Queue is empty");
    }
    return data_[head_];
}

const std::int64_t& QueueA::top() const {
    if (isempty()) {
        throw std::out_of_range("Queue is empty");
    }
    return data_[head_];
}
QueueA::QueueA(const QueueA& other)
    : capacity_(other.capacity_), size_(other.size_),
    data_(new std::int64_t[capacity_]) {
    for (std::size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[(other.head_ + i) % capacity_];
    }
    tail_ = size_ % capacity_;
}

QueueA& QueueA::operator=(const QueueA& other) {
    if (this == &other) return *this;

    std::int64_t* new_data = new std::int64_t[other.capacity_];
    for (std::size_t i = 0; i < other.size_; ++i) {
        new_data[i] = other.data_[(other.head_ + i) % other.capacity_];
    }

    delete[] data_;
    data_ = new_data;
    capacity_ = other.capacity_;
    size_ = other.size_;
    head_ = 0;
    tail_ = size_ % capacity_;
    return *this;
}