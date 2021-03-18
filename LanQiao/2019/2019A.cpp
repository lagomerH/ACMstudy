#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
int a[21][5];


int main() {
	freopen("D:\\ZTlanqiao\\2019A.txt", "r",stdin);
	for (int i =0; i < 20; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	int i1, i2, i3, i4, i5;
	for (i1 = 0; i1 < 20; i1++) {
		for(i2 = 0; i2 < 20; i2++) {
			if(i2 == i1){
				continue;
			}
			for(i3 = 0; i3 < 20; i3++) {
				if(i3 == i2 || i3 == i1){
					continue;
				}
				for(i4 = 0; i4 < 20; i4 ++) {
					if(i4 == i3 || i4 == i2 || i4 == i1){
						continue;
					}
					for(i5 = 0; i5 < 20; i5++) {
						if(i5==i4 || i5 == i3 || i5 == i2 || i5 == i1){
							continue;
						}
						/*if(i1 == i2 || i1 == i3 || i1 == i4 || i1 == i5 || i2 == i3 || i2 == i4 || i2 == i5 || i3 ==i4 || i3 == i5 || i4 == i5) {
							continue;
						}*/
						if((a[i1][0] + a[i2][1] + a[i3][2] + a[i4][3] + a[i5][4]) > ans) {
							ans = (a[i1][0] + a[i2][1] + a[i3][2] + a[i4][3] + a[i5][4]);
						} 
					}
				} 
			}
		} 
	}
	cout << ans;
	return 0;
} 
