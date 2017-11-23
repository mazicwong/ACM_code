/*************************************************************************
    > File Name: 4.cpp
    > Author: mazicwong
    > Mail: mazicwong@gmail.com
    > Created Time: 2017年08月28日 星期一 19时47分50秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <time.h>
using namespace std;
typedef long long ll;
int S=5;//测试次数，越大精度越高
ll mod_mul(ll a, ll b, ll n)  //快速乘
{
    ll res = 0;
    while(b)
    {
        if(b&1)    res = (res + a) % n;
        a = (a + a) % n;
        b >>= 1;
    }
    return res;
}
ll mod_exp(ll a, ll b, ll n)  //快速幂
{
    ll res = 1;
    while(b)
    {
        if(b&1)    res = mod_mul(res, a, n);
        a = mod_mul(a, a, n);
        b >>= 1;
    }
    return res;
}
bool miller_rabin(ll n)  //复杂度很小
{
    if(n == 2 || n == 3 || n == 5 || n == 7 || n == 11)    return true;
    if(n == 1 || !(n%2) || !(n%3) || !(n%5) || !(n%7) || !(n%11))    return false;

    ll x, pre, u;
    int i, j, k = 0;
    u = n - 1;    //要求x^u % n

    while(!(u&1))      //如果u为偶数则u右移，用k记录移位数
    {
        k++;
        u >>= 1;
    }

    srand((ll)time(0));
    for(i = 0; i < S; ++i)      //进行S次测试
    {
        x = rand()%(n-2) + 2;    //在[2, n)中取随机数
        if((x%n) == 0)    continue;

        x = mod_exp(x, u, n);    //先计算(x^u) % n，
        pre = x;
        for(j = 0; j < k; ++j)      //把移位减掉的量补上，并在这地方加上二次探测
        {
            x = mod_mul(x, x, n);
            if(x == 1 && pre != 1 && pre != n-1)    return false;    //二次探测定理，这里如果x = 1则pre 必须等于 1，或则 n-1否则可以判断不是素数
            pre = x;
        }
        if(x != 1)    return false;    //费马小定理
    }
    return true;
}
int main()
{
    //freopen("in","r",stdin);
    //*/test miller_rabin
    int n;
    cin>>n;

    if(miller_rabin(n))
        cout << "1";
    else if(miller_rabin(n-2))
        cout << "2";
    else
    {
        if(n%2==0)
            printf("2\n");
        else
            printf("3\n");

    }
    return 0;
}
