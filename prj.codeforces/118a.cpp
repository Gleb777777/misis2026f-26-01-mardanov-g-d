#include <iostream>
#include <string>
#include <algorithm>
int main() {
	std::string s;
	std::cin >> s;

	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		if (c == 'a' || c == 'o') {

		}
		else {
			std::cout << '.' << c;
		}
		
	}

	return 0;
}