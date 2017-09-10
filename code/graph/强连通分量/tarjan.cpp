/*强连通分量分解 tarjan算法 (hdu 1269) 
  题意： 
  给出一个有n个点m条边的有向图，判断该图是否只有一个强连通分量。 
  限制： 
  0 <= N <= 10000 
  0 <= M <= 100000 
 */  
#include<iostream>  
#include<cstdio>  
#include<stack>  
#include<vector>  
#include<cstring>  
using namespace std;  
const int MAX_V = 1e5+5;  
  
vector<int> G[MAX_V];  
stack<int> tarjan_stack;  
int DFN[MAX_V], LOW[MAX_V];  
int tarjan_set[MAX_V];  
bool in_stack[MAX_V];  
int scc_cnt, tarjan_cnt;  
void tarjan(int u){  
    DFN[u] = LOW[u] = ++tarjan_cnt;  
    tarjan_stack.push(u);  
    in_stack[u] = true;  
  
    for(int i = 0; i < G[u].size(); ++i){  
        int ch = G[u][i];  
        if(!DFN[ch]){  
            tarjan(ch);  
            LOW[u] = min(LOW[u], LOW[ch]);  
        } else if(in_stack[ch]){  
            LOW[u] = min(LOW[u], DFN[ch]);  
        }  
    }  
  
    if(DFN[u] == LOW[u]){  
        int tmp;  
        ++scc_cnt;  
        do{  
            tmp = tarjan_stack.top(); tarjan_stack.pop();  
            in_stack[tmp] = false;  
            tarjan_set[tmp] = scc_cnt;  
        }  
        while(tmp != u);  
    }  
}  
void add_edge(int u,int v){  
    G[u].push_back(v);  
}  
void init_tarjan(int n){  
    scc_cnt = tarjan_cnt = 0;  
    memset(DFN, 0, sizeof(DFN));  
    memset(LOW, 0, sizeof(LOW));  
    memset(in_stack, 0, sizeof(in_stack));  
    memset(tarjan_set, 0, sizeof(tarjan_set));  
    for(int i = 0; i <= n; ++i)  
        G[i].clear();  
}  
//点的序号从0开始  
void gao(int n){  
    for(int i = 0; i < n; ++i){  
        if(!DFN[i]) tarjan(i);  
    }  
    for(int i = 1; i < n; ++i){  
        if(tarjan_set[i] != tarjan_set[i-1]){  
            puts("No");  
            return ;  
        }  
    }  
    puts("Yes");  
}  
int main(){  
    int n, m;  
    while(scanf("%d%d", &n, &m) && (n || m)){  
        init_tarjan(n);  
        for(int i = 0; i < m; ++i){  
            int u, v;  
            scanf("%d%d", &u, &v);  
            add_edge(u-1, v-1);  
        }  
        gao(n);  
    }  
    return 0;  
} 





//////////////////////////////////////////////////////////////////////
//另一份模板
//https://www.byvoid.com/zhs/blog/scc-tarjan
//https://www.byvoid.com/zhs/blog/biconnect
//
void tarjan(int i)
{
    int j;
    DFN[i]=LOW[i]=++Dindex;
    instack[i]=true;
    Stap[++Stop]=i;
    for (edge *e=V[i];e;e=e->next)
    {
        j=e->t;
        if (!DFN[j])
        {
            tarjan(j);
            if (LOW[j]<LOW[i])
                LOW[i]=LOW[j];
        }
        else if (instack[j] && DFN[j]<LOW[i])
            LOW[i]=DFN[j];
    }
    if (DFN[i]==LOW[i])
    {
        Bcnt++;
        do
        {
            j=Stap[Stop--];
            instack[j]=false;
            Belong[j]=Bcnt;
        }
        while (j!=i);
    }
}
void solve()
{
    int i;
    Stop=Bcnt=Dindex=0;
    memset(DFN,0,sizeof(DFN));
    for (i=1;i<=N;i++)
        if (!DFN[i])
            tarjan(i);
}
