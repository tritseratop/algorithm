#include <iostream>

int main() {
	int breaks[3];
	int hole[2];
	for (auto& b : breaks) {
		std::cin >> b;
	}
	for (auto& b : hole) {
		std::cin >> b;
	}
	
	bool result = false;
	int buf = 0;
	for (int i = 0; i < 3; ++i) {
		if (breaks[i] <= hole[0]) {
			for (int j = 0; j < 3; ++j) {
				if (j != i && breaks[j] <= hole[1]) {
					buf = i;
					std::cout << "YES" << std::endl;
					return 0;
				}
			}
		}
	}

	std::cout << "NO" << std::endl;

	return 0;
}