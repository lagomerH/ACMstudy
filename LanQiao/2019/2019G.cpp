#include <iostream> 
using namespace std;
int a[100002];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	} 
	int sum = 0;
	int retd;
	int max = 0;
	int d = 1;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
		if ( i == (2<<d - 1)) {
			if ( sum > max ) {
				max = sum;
				retd = d;
			}
			d++;
			sum = 0;
		}
	}
	cout << retd << endl;
	return 0;
}
