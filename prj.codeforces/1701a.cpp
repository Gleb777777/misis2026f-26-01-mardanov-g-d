#include <iostream>
int main() {
	int t;
	std::cin >> t;
	while (t > 0) {
		t--;
		int count = 0;
		int x;
		for (int i = 0; i < 4; i++) {
			std::cin >> x;
			if (x == 1) {
				count++;
			}
		}

		int answer = 0;
		if (count == 0) {
			answer = 0;
		}
		else if (1 <= count && count <= 3) {
			answer = 1;
		}
		else if (count == 4) {
			answer = 2;
		}
		std::cout << answer << "\n";
	}

	return 0;
}