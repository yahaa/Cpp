/*************************************************************************
	> File Name: huanon_1009.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> QQ:1477765176 
	> Wechat:w1477765176 
	> Created Time: 2016年05月15日 星期日 10时18分36秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <set>
#include <bitset>
#include <fstream>
#include <functional>
#include <iomanip>
#include <cstdlib>
#define FOR(x,y) for(int x=0;x<y;x++)
#define MS(a,x) memset(a,x,sizeof(a))
#define ROF(x,y) for(int x=y;x>=0;x--)
#define LFOR(i,x,y) for(int i=x;i<=y;i++)
#define ll long long
#define INF 0X3FFFF
using namespace std;

int main(){
	//freopen("xxxxin.txt","r",stdin);
	//freopen("xxxxout.txt","w",stdout);
	int n,k;
	while(cin>>n>>k){

		int tn=n;
		while(1){
			int f=tn;
			if(tn%2==0)tn/=2;
			else tn=tn-(tn/2+1);
			tn+=k;
			if(f==tn)break;
		}
		cout<<tn<<endl;
	}

	return 0;
}

