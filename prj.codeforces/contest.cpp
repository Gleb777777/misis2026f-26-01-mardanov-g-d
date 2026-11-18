#include <iostream>
#include <cstdlib>

int n, v;
int a[1005][1005];
char col[1000005];

int main() {
    std::cin >> n >> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
        }
    }

    while (1) {
        for (int i = 1; i <= v; i++) {
            if (rand() % 2) col[i] = 'R';
            else col[i] = 'B';
        }

        bool good = true;
        for (int i = 0; i < n; i++) {
            bool hasR = false, hasB = false;
            for (int j = 0; j < n; j++) {
                if (col[a[i][j]] == 'R') hasR = true;
                else hasB = true;
            }
            if (!hasR || !hasB) {
                good = false;
                break;
            }
        }

        if (good) break;
    }

    for (int i = 1; i <= v; i++) {
        std::cout << col[i]
    }
    std::cout << "\n";
    return 0;
}