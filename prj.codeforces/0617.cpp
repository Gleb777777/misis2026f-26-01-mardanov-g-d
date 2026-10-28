#include <iostream>
int main() {
	int x;
	std::cin >> x;
	int answer = 0;
	if (x % 5 == 0) {
		answer = x / 5;
	}
	else {
		answer = x / 5 + 1;
		
	}
	std::cout << answer << std::endl;


	return 0;
}