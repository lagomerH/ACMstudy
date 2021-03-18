#include <iostream>
#include <string>
using namespace std;
static string s = "";
void convert(int n) {

	if(n == 0) return;
	convert(n / 26);
	s += (n-1) % 26 + 'A';
	
}
int main() {
	convert();
	cout << s <<endl;
	return 0;
}
