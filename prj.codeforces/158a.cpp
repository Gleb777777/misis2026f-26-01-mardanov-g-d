#include <iostream>
#include <vector>
int main() {
	int n;
	int k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int border = a[k - 1];
	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] >= border && a[i] > 0) {
			answer++;
		}
	}
	std::cout << answer;
	return 0;
}