#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    int n;
    for (int i = 0; i < t; i++) {
        std::cin >> n;
        std::vector<int> answer;
        int place = 1;

        while (n > 0) {
            int digit = n % 10;
            if (digit != 0) {
                answer.push_back(digit * place);
            }
            n = n / 10;
            place = place * 10;
        }
        std::cout << answer.size() << "\n";

        for (int x:answer) {
            std::cout << x << " ";
        }
    }
    return 0;
}
