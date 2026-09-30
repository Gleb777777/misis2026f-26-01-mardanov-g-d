#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
int main() {
	int t;
	std::cin >> t;

	while (t > 0) {
		t--;

		int n;
		std::cin >> n;

		std::string s;
		std::cin >> s;

		int k;
		std::cin >> k;

		std::vector <bool> a(26, false);
		for (int i = 0; i < k; i++) {
			char c;
			std::cin >> c;
			a[c - 'a'] = true;
		}
		int answer = 0;
		int last = 0;
		for (int i = 0; i < n; i++) {
			if (a[s[i] - 'a']) {
				answer = std::max(answer, i - last);
				last = i;
			}
		}
		std::cout << answer << "\n";
	}
	return 0;
}