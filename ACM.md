# ACM

## 基本算法

### 递归

#### 汉诺塔问题

******



## 动态规划

问题中有大量重复子问题







#### 习题

##### 数字游戏

1. 首先以b为索引降序排序a,b。

##### 厉害了我的杯

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

##### Phone Number

From: codeforces

Long Path

from: codeforces407B

~~记忆化搜索(备忘录方法):保证每一个子问题只解决一次~~

f(x):从第一个门第一次到第x 个房间时的步数 

状态方程：f(x) = f(i-1) + 1 + p(i-1)到 i-1 --> f(x) = f(i-1) +1 + f(i-1) - f( p(i-1) ) +1

初始条件：f(0) = 0;

##### 滑雪

记忆化搜索(备忘录方法)

​	

##### 数塔（数字三角形）

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



##### [免费馅饼](http://acm.hdu.edu.cn/diy/contest_showproblem.php?pid=1002&cid=37175)

思路：

* 状态：(x,t)---表示t秒时所在的位置
* 指示函数：f(x,t)---t秒时在x处所能获得的最大馅饼数
* 状态转移方程：f(x,t)=a(x,t)+max( f(x-1,t+1) , f(x,t+1), f(x+1,t+1))
* 确定初始状态：f(5,0)

算法实现：

1. ~~记忆化搜索~~ 数据过大采用滚动式记忆化搜索进行空间优化
2. ~~递归~~ 数据过大导致内存溢出
3. 采用递推+数组滚动应用

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
			dp[0][i%2] = a[0][i] + max( 0, dp[0][(i+1)%2], dp[1][(i+1)%2] );
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

******



##### [Monkey and Banana](http://acm.hdu.edu.cn/diy/contest_showproblem.php?pid=1003&cid=37175)

思路：

* 状态：(x,y)---目前的底的尺寸
* 指示函数：f(x,y)---

******

****



### 状态压缩---复杂状态的动态规划



#### 二进制表示状态

二进制的很多应用离不开**集合**这个概念。如果我们把int的32位bit看成是一个集合，那么**每一个数都应该对应集合的一种状态**，并且每个数的状态都是不同的。

*****



#### 状态转移

整数的二进制表示可以代表一个二元集合的状态，既然是状态就可以转移。在此基础上，我们可以得出另一个非常重要的结论——**我们可以用整数的加减表示状态之间的转移**。

我们用二进制的0和1表示一个二元集合的状态。可以简单认为某个物品存在或者不存在的状态。由于二进制的0和1可以转化成一个int整数，也就是说我们用整数代表了一个集合的状态。这样一来，我们可以**用整数的加减计算来代表集合状态的变化**。

所谓的压缩，其实就是将一个**集合压缩成了一个整数**的意思，因为整数可以作为数组的下标，这样操作会方便我们的编码。

****

#### 习题

##### 子集和问题

解决方案1：

回溯法剪纸



解决方案2：

思路：

* 状态：(x,y)---前x个数的和为y
* 指示函数： f(x,y)---前x个数的和能否为y
* 状态转移方程：f(x,y)=f(x-1,y) || f(x-1,y-a[x])
* 初始状态：



解决方案3：

状态压缩：

假设有6个元素，a6~~a1:0 1 1 0 1 0

{a2,a4,a5}---表示为11010 ==26(十进制)

按为与操作

```c++
#incude<iostream>
using namespace std;
#define N 102
int n, a[N];
int main(){
	int i, j, sum;
    cin >> n >> s;
    for( i=0; i<n; i++ )
        cin >> a[i];
    for( i=0; i<(1<<n)-1; i++ ){
        sum = 0;
        for( j=0; j<n; j++ ){
            if( (i&(1<<j) != 0 ){
               sum+=a[j];
               if(sum == s){
                   cout << "YES" <<endl;
                   return 0;
               }
            }
        }
    }
    
	cout << "NO" << endl;
    return 0;
}

```



##### unmerge

******



##### H and V

from: atCoder-abc173-C

解题方案1---暴力枚举

*****



##### 点集配对问题

from: 9.4.3

