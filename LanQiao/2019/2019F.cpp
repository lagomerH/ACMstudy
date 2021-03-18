#include <iostream>
using namespace std;
bool is(int x) {
	int y;
	while(x) {
		y = x % 10;
		if ( y == 2 || y == 0 || y  == 1 || y ==9) {
			return true;
		} 
		x /= 10;
	}
	return false;
}
int main(){
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if ( is(i) ){
			sum += i;
		}
	} 
	cout << sum <<endl;
	return 0;
}
