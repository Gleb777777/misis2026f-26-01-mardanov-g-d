#include <iostream>
#include <string>
int main() {
	int n;
	std::cin >> n;
	std::string s;
	for (int i = 0; i < n; i++) {
		std::cin >> s;
		if (s.length() > 10) {
			std::cout << s[0] << s.length() - 2 << s[s.length() - 1] << "\n";
		}
		else {
			std::cout << s << "\n";
		}
	}

	return 0;
}