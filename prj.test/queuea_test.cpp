#include <queuea/queuea.h>
#include <iostream>

int main() {
    QueueA q;

    q.push(10);
    q.push(20);
    std::cout << q.top() << '\n';

    q.pop();
    std::cout << q.top() << '\n';

    q.pop();
    std::cout << std::boolalpha << q.isempty() << '\n';
}