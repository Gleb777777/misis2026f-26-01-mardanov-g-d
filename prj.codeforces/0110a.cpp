#include <iostream>
#include <string>
int main() {
	std::string n;
	std::cin >> n;
	int happy = 0;
	for (int i = 0; i < n.size(); i++) {
		if (n[i] == '4' || n[i] == '7') {
			happy++;
		}
	}
	if (happy == 7 || happy == 4) {

		std::cout << "YES"<< std::endl;
	}
	else {
		std::cout << "NO"<< std::endl;
	}


	return 0;
}