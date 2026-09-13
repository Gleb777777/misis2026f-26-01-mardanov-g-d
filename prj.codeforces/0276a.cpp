#include <iostream>
int main() {
	int n;
	int k;
	std::cin >> n >> k;
	int answer = 0;
	for (int i = 0; i < n; i++) {
		int f_i;
		int t_i;
		std::cin >> f_i >> t_i;
		int udovoletvorenie;
		if (t_i > k) {
			udovoletvorenie = f_i - (t_i - k);
		}
		else {
			udovoletvorenie = f_i;
		}
		if (udovoletvorenie > answer) {
			answer = udovoletvorenie;
		}
	}
	std::cout << answer;
	return 0;
}	
