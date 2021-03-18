#include <iostream>
#include <algorithm>
using namespace std;
int a[100002];

int gongyue(int x, int y){
	if ( x % y == 0 ) {
		return y;
	}
	return gongyue(x, x%y);
}
int main(){
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	sort(a, a + N);
	int x , y;
	x = gongyue(a[1] - a [0], a[2] - a[1]);
	for (int i = 3; i < N; i++) {
		y = a[i] - a[i - 1];
		x = gongyue(x, y);
	}
	cout << (a[N - 1] - a[0]) / x + 1 << endl;
	return 0;
}
