#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

int n, ans[500000 + 5];
char str[55][500000 + 5];

struct AcAutomaton{
  static const int N = 500000 + 10;
  static const int C = 26;

  int size;
  int ch[N][C], fail[N], num[N], end[N];

  AcAutomaton(){
    size = 1;
  }

  int idx(char c){
    return c - 'a';
  }
  
  void insert(char *buf, int k){
    int cur = 0, len = strlen(buf);

    for(int i = 0; i < len; ++ i){
      int x = idx(buf[i]);

      if(!ch[cur][x])
        ch[cur][x] = size ++;
      cur = ch[cur][x];
    }

    end[cur] ++; num[cur] = k;
  }

  void build(){
    queue <int> q;
    fail[0] = 0;

    for(int i = 0; i < C; ++ i){
      if(!ch[0][i]) ch[0][i] = 0;
      else{
        fail[ch[0][i]] = 0;
        q.push(ch[0][i]);
      }
    }

    while(!q.empty()){
      int x = q.front(); q.pop();

      for(int i = 0; i < 26; ++ i){
        if(!ch[x][i]) ch[x][i] = ch[fail[x]][i];
        else{
          fail[ch[x][i]] = ch[fail[x]][i];
          q.push(ch[x][i]);
        }
      }
    }
  }

  void find(char* buf){
    int cur = 0, len = strlen(buf);

    for(int i = 0; i < len; ++ i){
      int x = idx(buf[i]);
      
      cur = ch[cur][x];

      int tmp = cur;
      while(tmp){
        if(end[tmp])
          ans[num[tmp]] += end[tmp];
        tmp = fail[tmp];
      }
    }
  }
}ac;


int main(){
  freopen("in", "r", stdin);

  scanf("%d", &n);
  for(int i = 1; i <= n; ++ i){
    scanf("%s", str[i]);
    ac.insert(str[i], i);
  }
  ac.build();
  scanf("%s", str[n+1]);
  ac.find(str[n+1]);

  for(int i = 1; i <= n; ++ i){
    int tp = strlen(str[i]);
    for(int j = 0; j < tp; ++ j)
      printf("%c", str[i][j]);
    printf(" %d\n", ans[i]);
  }
  return 0;
}

AcAutomaton
