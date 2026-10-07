#include <iostream>
#include <string>
int main() {
	int x = 0;
	std::string s;
	std::cin >> s;
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		if (s == "++X" || s == "X++") {
			x++;
		}
		else {
			x--;
		}
	}
	std::cout >> x;

	return 0;
}