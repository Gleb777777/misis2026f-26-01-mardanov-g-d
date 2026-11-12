#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
int main() {
	std::string s;
	std::cin >> s;

	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		if (c == 'a' || c == 'o' || c == 'e' || c == 'y' || c == 'i' || c == 'u' || c == 'A' || c == 'O' || c == 'E' || c == 'I' || c == 'U') {

		}
		else {
			std::cout << '.' << std::tolower(c);
		}
		
	}

	return 0;
}