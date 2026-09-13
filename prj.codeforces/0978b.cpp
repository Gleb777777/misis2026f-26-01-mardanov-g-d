#include <iostream>
#include <string>
int main() {
	int n;
	std::string s;
	std::cin >> n;
	std::cin >> s;

	int count = 0;
	int udali = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] == 'x') {
			count+=1;
			if (count > 2) {
				udali += 1;
			}
		}
		else {
			count = 0;
		}
	}
	std::cout << udali;

	return 0;
}
