#include "stairs.hpp"

int ways_to_top(int n) {
	if (n <= 2)
		return n;
	if (n == 3)
		return 4;
	return ways_to_top(n - 1) + ways_to_top(n - 2) + ways_to_top(n - 3);
}
