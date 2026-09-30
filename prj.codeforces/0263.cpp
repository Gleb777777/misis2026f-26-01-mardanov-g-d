#include <iostream>
#include <cstdlib> 
int main() {
	int answer = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int x;
			std::cin >> x;
			if (x == 1) {
				std::cout << std::abs(i - 2) + std::abs(j - 2) << "\n";
			}
		}
	}
	return 0;
}