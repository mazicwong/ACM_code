//1.cpp
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>
using namespace std;
const int maxn = 1005;
char str[1005];

int main()
{
    scanf("%s",str);
    int len = strlen(str);
    for (int i=0;i<len;i++)
    {
        printf("%c",str[i]);
    }
    for (int i=len-1;i>=0;i--)
    {
        printf("%c",str[i]);
    }
    
    return 0;
}
