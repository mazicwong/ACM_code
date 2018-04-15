#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
struct Task{
    char all[100];
    char name[15];
    char day[15];
    char time[20];
    char hou[15];
    int f0;
    int f1;
    int f2;
    int f3;
    int f4;
}task[maxn];

bool cmp(const Task a, const Task b)
{
    if(strcmp(a.hou,b.hou)==0)
    {
        if(strcmp(a.day,b.day)==0)
            return strcmp(a.time,b.time)<0;
        return strcmp(a.day,b.day)<0;
    }
    return strcmp(a.hou,b.hou)<0;
}

int main()
{
    ios::sync_with_stdio(false);
    int cnt=0;
    char ch;
    while(cin.getline(task[cnt].all,100))
    {
        int tmp=0;
        int idx=0;
        int now=0;
        int len = strlen(task[cnt].all);
        while(task[cnt].all[idx++] == ' ')tmp++; task[cnt].f0=tmp; tmp=0; now=0;
        while(task[cnt].all[idx] != ' ')task[cnt].name[now++]=task[cnt].all[idx++]; task[cnt].name[now]='\0';
        while(task[cnt].all[idx++] == ' ')tmp++; task[cnt].f1=tmp; tmp=0; now=0;
        while(task[cnt].all[idx] != ' ')task[cnt].day[now++]=task[cnt].all[idx++]; task[cnt].day[now]='\0';
        while(task[cnt].all[idx++] == ' ')tmp++; task[cnt].f2=tmp; tmp=0; now=0;
        while(task[cnt].all[idx] != ' ')task[cnt].name[now++]=task[cnt].all[idx++]; task[cnt].time[now]='\0';
        while(task[cnt].all[idx++] == ' ')tmp++; task[cnt].f3=tmp; tmp=0; now=0;
        while(task[cnt].all[idx] != '\n' && task[cnt].all[idx]!=' ' && idx<len)task[cnt].hou[now++]=task[cnt].all[idx++]; task[cnt].hou[now]='\0';
        if(task[cnt].all[idx]==' ')
            while(task[cnt].all[idx++] == ' ')tmp++; task[cnt].f4=tmp;
    }
    sort(task,task+cnt,cmp);
    for(int i=0;i<cnt;i++)
    {
        while(task[i].f0--) cout << ' ';
        cout << task[i].name;
        while(task[i].f1--) cout << ' ';
        cout << task[i].day;
        while(task[i].f2--) cout << ' ';
        cout << task[i].time;
        while(task[i].f3--) cout << ' ';
        cout << task[i].hou;
        while(task[i].f4--) cout << ' ';
        cout << endl;
    }
    return 0;
}
