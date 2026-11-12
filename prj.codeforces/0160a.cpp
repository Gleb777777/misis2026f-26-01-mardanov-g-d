#include <iostream>
#include <vector>
#include <algorithm>
int main() {
	int n;
	int sum = 0;
	std::cin >> n;
	vector<int> a(n)
	for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			sum += a[i];
	}
	sort(a.begin(), a.end(), greater<int>());
	return 0;
}