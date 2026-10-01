#include <iostream>
#include <string>

int main() {
	int t;
	std::cin >> t;
	while (t--) {
		int sum = 0;
		for (int i = 0; i < 10; i++) {
			std::string row;
			std::cin >> row;
			for (int j = 0; j < 10; j++) {
				if (row[j] == 'X') {
					int d = i;
					if (j < d) {
						d = j;
					}
					if (9 - i < d) {
						d = 9 - i;
					}
					if (9 - j < d) {
						d = 9 - j;
					}
					sum += d + 1;
				}
			}
		}
		std::cout << sum << "\n";
	}
	return 0;
}