#include <iostream>
int main() {
	int n;
	int answer = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		int b;
		int c;
		std::cin >> a >> b >> c;
		if (a + b + c >= 2) {
			answer++;
		}
	}
	std::cout << answer << "\n";
	return 0;
}