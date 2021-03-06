// #include <iostream>
// #include <cstring>
// #include <cstdio>

// using namespace std;
// typedef long long ll;
// const int N =2005;
// const int mod = 29;

// bool prime[N];
// int p[N];
// int cnt;

// void isprime(){
//     cnt = 0;
//     memset(prime,true,sizeof(prime));
//     for(int i=2; i<=sqrt(N); i++){
//         if(prime[i]){
//             p[cnt++] = i;
//             for(int j=i+i; j<N; j+=i)
//                 prime[j] = false;
//         }
//     }
// }

// ll power(ll a,ll b){
//     ll ans = 1;
//     a %= mod;
//     while(b){
//         if(b & 1){
//             ans = ans * a % mod;
//             b--;
//         }
//         b >>= 1;
//         a = a * a % mod;
//     }
//     return ans;
// }

// ll sum(ll a,ll n){
//     if(n == 0) return 1;
//     ll t = sum(a,(n-1)/2);
//     if(n & 1){
//         ll cur = power(a,(n+1)/2);
//         t = (t + t % mod * cur % mod) % mod;
//     }
//     else{
//         ll cur = power(a,(n+1)/2);
//         t = (t + t % mod * cur % mod) % mod;
//         t = (t + power(a,n)) % mod;
//     }
//     return t;
// }

// void Solve(ll A,ll B){	
//     ll ans = 1;
//     for(int i=0; p[i]*p[i]<= A; i++){
//         if(A % p[i] == 0){
//             int num = 0;
//             while(A % p[i] == 0){
//                 num++;
//                 A /= p[i];
//             }
//             ans *= sum(p[i],num*B) % mod;
//             ans %= mod;
//         }
//     }

//     if(A>1){
//     	ans*=sum(A,B);
//     	ans%=mod;
//     }
   
//     cout<<ans<<endl;
// }

// int main(){
//     int x;
//     isprime();
//     while(cin>>x){
//     	if(x==0)break;
//         Solve(2004,x);
    	
//     }
//     return 0;
// }



#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
typedef long long LL;
const int N =10005;
const int MOD = 9901;

bool prime[N];
int p[N];
int cnt;

void isprime()
{
    cnt = 0;
    memset(prime,true,sizeof(prime));
    for(int i=2; i<N; i++)
    {
        if(prime[i])
        {
            p[cnt++] = i;
            for(int j=i+i; j<N; j+=i)
                prime[j] = false;
        }
    }
}

LL power(LL a,LL b)
{
    LL ans = 1;
    a %= MOD;
    while(b)
    {
        if(b & 1)
        {
            ans = ans * a % MOD;
            b--;
        }
        b >>= 1;
        a = a * a % MOD;
    }
    return ans;
}

LL sum(LL a,LL n)
{
    if(n == 0) return 1;
    LL t = sum(a,(n-1)/2);
    if(n & 1)
    {
        LL cur = power(a,(n+1)/2);
        t = (t + t % MOD * cur % MOD) % MOD;
    }
    else
    {
        LL cur = power(a,(n+1)/2);
        t = (t + t % MOD * cur % MOD) % MOD;
        t = (t + power(a,n)) % MOD;
    }
    return t;
}

void Solve(LL A,LL B)
{   
    LL ans = 1;
    for(int i=0; p[i]*p[i]<= A; i++)
    {
        if(A % p[i] == 0)
        {
            int num = 0;
            while(A % p[i] == 0)
            {
                num++;
                A /= p[i];
            }
            ans *= sum(p[i],num*B) % MOD;
            ans %= MOD;
        }
    }

    if(A>1){
        ans*=sum(A,B);
        ans%=MOD;
    }
   
    cout<<ans<<endl;
}

int main()
{
    LL A,B;
    isprime();
    while(cin>>A>>B)
        Solve(A,B);
    return 0;
}
