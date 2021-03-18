#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
using namespace std;
string maz[31];
string d = "DLRU";
int dir[4][2] = {1, 0, 0, -1, 0, 1, -1, 0};
int vis[31][51];
struct node{
	int x, y, step;
	string path;
	node():step(0), path(""){
	}
};
bool iscan(int x, int y){
	if(x < 0 || x > 29){
		return false;
	}
	if(y < 0 || y > 49) {
		return false;
	}
	if(vis[x][y] == 1){
		return false;
	}
	if(maz[x][y] == '1') {
		return false;
	}
	return true;
}
void bfs(){
	int dx, dy;
	int i; 
	node t, tt;
	queue<node> qu;
	t.x = 0;
	t.y = 0;
	qu.push(t);
	while(!qu.empty()){
		tt = qu.front();
		qu.pop();
		for (i = 0; i < 4; i++) {
			dx = tt.x + dir[i][0];
			dy = tt.y + dir[i][1];
			if(iscan(dx, dy)){
				vis[dx][dy] = 1;
				t.x = dx;
				t.y = dy;
				t.step = tt.step + 1;
				t.path = tt.path + d[i];
				if(dx==29 && dy == 49) {
					cout << t.path << endl;
					return;
				}
				qu.push(t);
			}
		}
	}
}
int main(){
	freopen("D:\\ZTlanqiao\\2019E.txt","r",stdin);
	for (int i = 0; i < 30; i++) {
		cin >> maz[i];
	}
	bfs();
	return 0;
}
