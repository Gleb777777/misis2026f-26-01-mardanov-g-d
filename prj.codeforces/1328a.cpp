#include <iostream>
int main() {
	int a;
	int b;
	int t;
	std::cin >> t;
	while (t > 0) {
		t--;
		std::cin >> a >> b;
		int answer = 0;
		if (a % b == 0) {
			std::cout << 0 << std::endl;
		}
		else {
			std::cout << b - (a % b) << std::endl;
		
		}
	}



	return 0;
}