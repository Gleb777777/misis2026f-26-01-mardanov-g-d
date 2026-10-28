#include <iostream>
#include <string>
#include <cctype>
int main() {
	std::string s;
	std::cin >> s;
	
	int upper = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			upper++;
		}
	}
		if (upper == s.size()) {
			for (int i = 0; i < s.size(); i++) {
				s[i] = tolower(s[i]);
			}
		}
		else if (s[0] >= 'a' && s[0] <= 'z' && upper == s.size() - 1) {
			for (int i = 0; i < s.size(); i++) {
				if (i == 0){
					s[i] = toupper(s[i]);
				}
				else {
					s[i] = tolower(s[i]);
				}
				}
			
			}
		}

		std::cout << s;
	return 0;
}