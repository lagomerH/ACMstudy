# ACM

## 基本算法

### 递归

#### 汉诺塔问题

******



## 动态规划

### 习题

#### 数字游戏

1. 首先以b为索引降序排序a,b。

#### 厉害了我的杯

有一种玻璃杯质量确定但未知，需要检测。

有一100层大楼，该种玻璃杯从某一层楼扔下，刚好会碎。

先给你两个杯子，问怎样检测出个杯子的质量，即找到那一层杯子会碎。

1. f(i)(j):i个杯子j层的最优值
2. 状态方程:f(i)(j)=1+min( max( f(i-1)(x-1), f(i)(k-x) ) ); 1为必试的一次。



```c++
int f[100][100];
f[0][0]=0;
f[0][100]=0;
for(int j=1;j<=100;j++){
	f[2][j]= 1+ min
}
```

#### Phone Number

From: codeforces

#### Long Path

from: codeforces407B

~~记忆化搜索(备忘录方法):保证每一个子问题只解决一次~~

f(x):从第一个门第一次到第x 个房间时的步数 

状态方程：f(x) = f(i-1) + 1 + p(i-1)到 i-1 --> f(x) = f(i-1) +1 + f(i-1) - f( p(i-1) ) +1

初始条件：f(0) = 0;

#### 滑雪

记忆化搜索(备忘录方法)

​	

#### 数塔（数字三角形）

******

思路：

* 确定状态：(x,y)---当前所在的位置看成一个状态
* 指标函数：f(x,y)---从(x,y)出发所能取得的最大值
* 确定状态转移方程：f(x,y)=a(x,y)+max(f(x+1,y),f(x+1,y+1))

******

最优子结构：如果连从 (x+1,y)出发的走到底部这部分都不是最大的，加上a(x,y)肯定也不是最大的。这种性质被称为最优子结构，即全局最优解包含局部最优解。

******

算法实现：

1. 记忆化搜索(备忘录方法)与递归

2. 递归(重复计算时间效率较低)

3. 递推

```c++
#include<iostream>
#include<string.h>
using namespace std;

int dp[101][101];
int a[101][101];
int C, N;

int f( int, int );
int max( int, int );
int main(){
	cin >> C;
	while(C--){
		cin >> N;
		for( int i = 1; i <= N; i++ ){
			for(int j = 1; j <= i; j++ ){
				cin >> a[i][j];
			}
		}	
		memset( dp, -1, sizeof(dp) );
		
		cout << f( 1, 1 ) << endl;	
	}
	return 0;
} 

int f( int x, int y ){
	if(  0 <= dp[x][y] )
		return dp[x][y];
	
	if( N < x )
		return 0;
		
	return dp[x][y] = a[x][y] + max( f( x+1, y), f( x+1, y+1 ) );
	
}

int max( int x, int y ){
	return x > y ? x : y;
}
```

******



#### 免费馅饼

思路：

* 状态：(x,t)---表示t秒时所在的位置
* 指示函数：f(x,t)---t秒时在x处所能获得的最大馅饼数
* 状态转移方程：f(x,t)=a(x,t)+max( f(x-1,t+1) , f(x,t+1), f(x+1,t+1))
* 确定初始状态：f(5,0)

算法实现：

1. 记忆化搜索
2. 递归

```c++
//内存溢出
#include<iostream>
#include<string.h>
using namespace std;

int dp[11][1000000];
int a[11][1000000];
int n;
int T;
int max( int, int, int );
int f( int, int );
int main(){
	while(cin >> n && n){
		memset( a, 0, sizeof(a) );
		memset( dp, 0, sizeof(dp) );
		int x;
		for( int i=1; n >= i; i++ ){
			cin >> x;
			cin >> T;
			a[x][T]++;
		}
		
		cout << f( 5, 0) << endl;	
	}	
	return 0;
}
int f( int x, int t ){
	if( t == n )
		return a[x][t];
	
	else{
		return a[x][t] + max( f( x-1, t+1 ), f( x, t+1 ), f( x+1, t+1 ) );
	}
}
int max( int a, int b, int c ){
	int y = a;
	if( b>y )
		y = b;
	if( c>y )
		y = c;
	return c;
}
```

```C++
#include<iostream>
#include<string.h>
using namespace std;

int dp[11][3];
int a[11][100001];
int n;
int T;
int Tmax;
int max( int, int, int );
int f( int, int );
int main(){
	while(cin >> n && n){
		memset( a, 0, sizeof(a) );
		memset( dp, 0, sizeof(dp) );
		int x;
		Tmax = 0;
		for( int i=1; n >= i; i++ ){
			cin >> x;
			cin >> T;
			if( T>Tmax )
				Tmax = T;
			a[x][T]++;
		}
		for( int i = Tmax; 0 <= i; i-- ){
			for( int j = 1; j < 11; j ++ ){
				dp[j][i%2] = a[j][i] + max( dp[j-1][(i+1)%2], dp[j][(i+1)%2], dp[j+1][(i+1)%2] );
			}
		}
		cout << dp[5][0] << endl;
	}	
	return 0;
}

int max( int a, int b, int c ){
	int y = a;
	if( b>y )
		y = b;
	if( c>y )
		y = c;
	return y;
}
```



