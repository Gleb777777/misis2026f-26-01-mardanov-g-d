#include <iostream>
#include <vector>
int main() {
	int t;
	std::cin >> t;
	while (t > 0) {
		t--;
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		std::vector<int> b(n);
		std::vector<int> tm(n);
		for (int i = 0; i < n; i++) {
			std::cin >> a[i] >> b[i];
		}
		for (int i = 0; i < n; i++) {
			std::cin >> tm[i];
		}

		int dep = 0;
		int prosh = 0;
		int ariive = 0;
		int stay = 0;
		for (int i = 0; i < n; i++) {
			ariive = dep + a[i] - prosh + tm[i];
			stay = (b[i] - a[i]) / 2;
			prosh = b[i];
		}
	}
	std::cout << ariive << "\n";

	return 0;
}