#include <iostream>
using namespace std;
bool f(int  x) {
	while(x != 0) {
		if(x%10 == 2 || x%10 == 4) {
			return true;
		}
		x /= 10;
	}
	return false;
}
int main() {
	int ans = 0;
	int i, j, k;
	for (i = 1; i < 2019; i++){
		if(f(i))
			continue;
		for (j = i + 1; j < 2019; j++) {
			if(f(j))
				continue;
			k = 2019 - i - j;
			if(k > j && !f(k)){
				ans++;
			}
		}
	} 
	cout << ans;
	return 0;
}
