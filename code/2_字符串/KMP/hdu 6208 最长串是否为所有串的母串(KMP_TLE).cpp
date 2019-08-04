/*************************************************************************
    > File Name: q.cpp
    > Author: mazicwong
    > Mail: mazicwong@gmail.com
    > Created Time: 2017年09月17日 星期日 12时38分32秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
using namespace std;
const int N = 1e5+5;
/*************************kuangbin KMP模板****************************/
char T[N];//母串
char P[N];//模板串  
int Next[N+1];//失配串(位数比模板串多1)
void getNext(const char *P)
{//Next从1开始,字符串从0开始
    int pp = strlen(P);
    Next[0]=-1;
    int k=-1,j=0;
    while(j<pp)
    {
        while(-1!=k && P[j]!=P[k])k=Next[k];
        j++;k++;
        Next[j]=k;
    }
}
int kmp(const char *T,const char *P)
{//返回模式串P在主串T中首次出现的位置,从0开始
    int tt=strlen(T),pp=strlen(P);
    int i=0,j=0;
    while(i<tt && j<pp)
    {
        //如果j=-1，或者当前字符匹配成功（即T[i] == P[j]）,都令i++,j++
        if (j==-1 || T[i]==P[j])
        {
            i++;
            j++;
        }
        //如果j!=-1，且当前字符匹配失败（即T[i] != P[j]）,则令i不变,j=Next[j]
        else
        {
            j=Next[j];
        }
    }
    if (j==pp) return i-j;
    else return -1;
}

void kmp1(const char *T,const char *P) //(未验证)
{
    int tt = strlen(T), pp = strlen(P);
    int j = -1;
    for (int i = 0; i < tt; i++)
    {
        while (j!=-1 && T[i] != P[j]) j = Next[j];
        if (T[i] == P[j]) j++;
        if (j == pp) printf("%d\n", i - pp + 1);//就算j到pp了，也用f[pp]继续匹配  
    }
}
/*************************kuangbin KMP模板****************************/

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
map<string,int> mp;
map<int,int> maa;

int main()
{
    //freopen("in","r",stdin);
    std::ios::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    while(t--)
    {
        mp.clear();
        maa.clear();
        int n;
        cin>>n;
        int maxlen=0;
        string str;
        string maxstr;
        for (int i=0;i<n;i++)
        {
            cin>>str;
            if (str.size()>maxlen)
            {
                maxlen = str.size();
                maxstr = str;
                maa[maxlen]=1;
            }
            else if (str.size()==maxlen)
            {
                if (str!=maxstr)
                    maa[maxlen]++;
            }
            mp[str]=1;
        }

        const char *pp=maxstr.c_str();
        //getNext(pp);
        bool flag=true;
  
        if (maa[maxlen]==1)
        {
            for (map<string,int>::iterator it=mp.begin();it!=mp.end();it++)
            {
                if (it->second==0) continue;
                const char *qq=it->first.c_str();
                memset(Next,0,sizeof(Next));
                getNext(qq);
                if (kmp(pp,qq)==-1)
                {
                    cout << "No\n";
                    flag=false;
                    break;
                }
            }
            if (flag)
            {
                cout << maxstr <<endl;
            }
        }
        else
            cout << "No\n";
    }
    return 0;
}
