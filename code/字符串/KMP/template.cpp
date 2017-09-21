

/*********************KMP 模式串匹配**************************/
//http://www.cnblogs.com/zhangtianq/p/5839909.html
// O(n+m)
// O(m)预处理,O(n)匹配
T[]: 母串
P[]: 模式串
next[]: 除当前字符外的最长相同前缀后缀(位数要比P[]多一位,next[0]=-1)
next[j]=k: j之前的字符串中有最大长度为k的相同前缀后缀

kmp思想: 对模式串P预处理计算出next[]数组;查找时,i只扫一遍,当T[i]与P[j]失配时,P向右移动j-next[j],即j=next[j]
* 如果j=-1,或者当前字符匹配成功(即S[i]==P[j]),都令i++,j++,继续匹配下一个字符;
* 如果j!=-1,且当前字符匹配失败(即S[i] != P[j]),则令i不变,j=next[j]。
此举意味着失配时，模式串P相对于文本串S向右移动了j-next[j]位。

应用:
1.给定一个P串和一群不同的T串,问P串是那些串的子串(裸)
2.子串在母串中出现几次(kmp_count())
3.求循环节(hdu 3746)

注意:下面两套模板是可以混搭的,一套是自己总结的(容易理解),一套是kuangbin大神的(比赛敲起来块)
最好用1的.


int next[maxm];
void getNext(char *P)
{//next从1开始,字符串从0开始
    int pp = strlen(P);
    next[0]=-1;
    int k=-1,j=0;
    while(j<pp)
    {
        if (k==-1 || P[k]==P[j]) //P[k]前缀,P[j]后缀
        {
            j++;k++;
            /*
             * //优化版,出现P[j]=P[nxt[j]]时进行递归,k=nxt[k]=nxt[nxt[k]]
             * if (P[j]!=P[k]) nextval[j]=k;
             * else next[j]=nextval[k];
             */
            next[j]=k;
        }
        else k=next[k];//不等,左边就自己返回,(运用了kmp思想了)
    }
}

int kmp(char *T,char *P)
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
        //如果j!=-1，且当前字符匹配失败（即T[i] != P[j]）,则令i不变,j=next[j]
        else
        {
            j=next[j];
        }
    }
    if (j==pp) return i-j;
    else return -1;
}
int kmp_count()
{//返回模式串在主串T中出现的次数(可重叠)(法1:较慢)
    int tt=strlen(T),pp=strlen(P);
    int i=0,j=0;
    int ans=0;
    while(i<tt)
    {
        if (j==-1 || T[i]==P[j])
        {
            i++;
            j++;
        }
        else
        {
            j=nxt[j];
        }
        if (j>=pp)
        {
            ans++;
            j=nxt[j];//不可重叠的话就把这里改为j=0;
        }
    }
    return ans;
}

/******************************KMP**************************/



/*************************kuangbin KMP模板****************************/
char T[1000];//母串
char P[100];//模板串  
int next[101];//失配串(位数比模板串多1)
void getNext(char *P)
{//next从1开始,字符串从0开始
    int pp = strlen(P);
    next[0]=-1;
    int k=-1,j=0;
    while(j<pp)
    {
        while(-1!=k && P[j]!=P[k])k=next[k];
        j++;k++;
        next[j]=k;
    }
}
void kmp(char *T, char *P) //(未验证)
{
	int tt=strlen(T),pp=strlen(P);
	int j=-1;
	for (int i = 0; i < tt; i++)
	{
		while (j!=-1 && T[i]!=P[j]) j=next[j];
		if (T[i]==P[j]) j++;
		if (j==pp) printf("%d\n", i-pp+1);//就算j到pp了，也用next[pp]继续匹配  
	}
}
int kmp_count()
{//返回模式串在主串T中出现的次数(法2,更块,kuangbin模板)
    int tt=strlen(T),pp=strlen(P);
    int i=0,j=0;
    int ans=0;
    while(i<tt)
    {
        while(j!=-1 && T[i]!=P[j]) j=next[j];
        i++;j++;
        if (j>=pp)
        {
            ans++;
            j=next[j];
        }
    }
    return ans;
}
/*************************kuangbin KMP模板****************************/




/*************************扩展KMP****************************/
s[i]: 主串中以第i个位置为起始的后缀,(KMP:求s[i]=模式串长度 的情况)
next[i]:"模式串的后缀"和"模式串P"的最长公共前缀
extend[i]:"s[i]"与"模式串P"的最长公共前缀(用next[i]求)




扩展KMP思想: 给出模板串T和子串B，长度分别为lenT和lenB，要求在线性时间内，对于每个T[i]（0<=i<lenT)，求出T[i..lenT-1]与B的最长公共前缀长度，记为ex[i]（或者说，ex[i]为满足T[i..i+z-1]==T[0..z-1]的最大的z值）。


题型:
1.求一个字符串的最长回文子串和最长重复子串
2.求'主串的每一个后缀' 和 '模式串' 的最长公共前缀
void getNext(char *P)
{
    int a=0;
    int pp=strlen(P);
    next[0]=pp;
    while(a<pp-1 && P[a]==P[a+1]) a++;
    next[1]=a;
    a=1;
    for(int k=2;k<pp;k++)
    {
        int p=a+next[a]-1,L=next[k-a];
        if((k-1)+L>=p)
        {
            int j=(p-k+1)>0? p-k+1:0;
            while(k+j<pp && T[k+j]==T[j]) j++;
            next[k]=j;
            a=k;
        }
        else next[k]=L;
    }
}

void GetExtend(char *S,char *T)  
{  
    int a=0;
    getNext(T);
    int Slen=strlen(S);
    int Tlen=strlen(T);
    int MinLen=Slen<Tlen? Slen:Tlen;
    while(a<MinLen && S[a]==T[a]) a++;
    extend[0]=a;
    a=0;
    for(int k=1;k<Slen;k++) 
    {
        int p=a+extend[a]-1,L=next[k-a];
        if((k-1)+L>=p)
        {
            int j=(p-k+1)>0? p-k+1:0;
            while(k+j<Slen&&j<Tlen&&S[k+j]==T[j]) j++;
            extend[k]=j;
            a=k;
        }
        else extend[k]=L;
    }
}
/*************************扩展KMP****************************/



