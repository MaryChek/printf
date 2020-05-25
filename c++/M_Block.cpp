#include <iostream>
#include <limits>

using namespace std;

int     main() {
	int N;
	__uint64_t sum_M;
	__uint16_t density;
	sum_M = 0;
	cin >> N >> density;
	for (int i = 0; i < N; i++) {
		__uint16_t h, w, l;
		cin >> h >> w >> l;
		__uint64_t M;
		M = h;
		M *= w;
		M *= l;
		M *= density;
		sum_M += M;
	}
	cout << sum_M << endl;
	return 0;
}
