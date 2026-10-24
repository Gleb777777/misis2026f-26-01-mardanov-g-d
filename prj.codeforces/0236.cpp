#include <iostream>
#include <string>

int main() {
	std::string s;
	std::cin >> s;
	int unique = 0;
	
	for (int i = 0; i < s.size(); i++) {
		bool anew = true;
		for (int j = 0; j < i; j++) {
			if (s[i] == s[j]) {
				anew = false;
				break;
			}
		}
		if (anew) {
			unique++;
		}
	} 
	
	if (unique % 2 == 0) {
		std::cout << "CHAT WITH HER!";
	}
	else {
		std::cout << "IGNORE HIM!";
	}

	
	return 0;
}