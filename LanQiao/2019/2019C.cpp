#include <iostream>
using namespace std;
int a[5];
int main() {
	a[3] = a[1] = a[2] = 1;
	for (int i = 4; i <= 20190324; i++) {
		a[i % 5] = (a[(i - 1) % 5] + a[(i -2 ) % 5] + a[(i - 3) % 5]) % 10000;
	}
	cout << a[20190324 % 5];
	return 0;
} 
