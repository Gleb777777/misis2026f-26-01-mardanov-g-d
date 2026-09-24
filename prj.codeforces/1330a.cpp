#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t > 0) {
        t--;

        int n;
        int x;
        std::cin >> n >> x;

        std::vector<int> a(n);

        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        int answer = 0;
        int limit = n + x;

        for (int mesto = 1; mesto <= limit; mesto++) {

            bool found = false;

            for (int i = 0; i < n; i++) {

                if (mesto == a[i]) {
                    found = true;
                    break;
                }
            }

            if (found) {
                answer = mesto;
            }
            else if (x > 0) {
                x--;
                answer = mesto;
            }
            else {
                break;
            }
        }

        std::cout << answer << "\n";
    }

    return 0;
}