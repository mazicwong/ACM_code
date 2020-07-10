

/*********************KMP ģʽ��ƥ��**************************/
//http://www.cnblogs.com/zhangtianq/p/5839909.html
// O(n+m)
// O(m)Ԥ����,O(n)ƥ��
T[]: ĸ��
P[]: ģʽ��
next[]: ����ǰ�ַ�������ͬǰ׺��׺(λ��Ҫ��P[]��һλ,next[0]=-1)
next[j]=k: j֮ǰ���ַ���������󳤶�Ϊk����ͬǰ׺��׺

kmp˼��: ��ģʽ��PԤ��������next[]����;����ʱ,iֻɨһ��,��T[i]��P[j]ʧ��ʱ,P�����ƶ�j-next[j],��j=next[j]
* ���j=-1,���ߵ�ǰ�ַ�ƥ��ɹ�(��S[i]==P[j]),����i++,j++,����ƥ����һ���ַ�;
* ���j!=-1,�ҵ�ǰ�ַ�ƥ��ʧ��(��S[i] != P[j]),����i����,j=next[j]��
�˾���ζ��ʧ��ʱ��ģʽ��P������ı���S�����ƶ���j-next[j]λ��

Ӧ��:
1.����һ��P����һȺ��ͬ��T��,��P������Щ�����Ӵ�(��)
2.�Ӵ���ĸ���г��ּ���(kmp_count())
3.��ѭ����(hdu 3746)

ע��:��������ģ���ǿ��Ի���,һ�����Լ��ܽ��(�������),һ����kuangbin�����(������������)
�����1��.

char T[1000];//ĸ��
char P[100];//ģ�崮
int next[101];//[1..m]
void getNext()
{//next��1��ʼ,�ַ�����0��ʼ
    int pp = strlen(P);
    next[0]=-1;
    int k=-1,j=0;
    while(j<pp)
    {
        if (k==-1 || P[k]==P[j]) //P[k]ǰ׺,P[j]��׺
        {
            j++;k++;
            /*
             * //�Ż���,����P[j]=P[nxt[j]]ʱ���еݹ�,k=nxt[k]=nxt[nxt[k]]
             * if (P[j]!=P[k]) nextval[j]=k;
             * else next[j]=nextval[k];
             */
            next[j]=k;
        }
        else k=next[k];//����,��߾��Լ�����,(������kmp˼����)
    }
}

//����P��T���״γ��ֵ�λ��,��0��ʼ
int kmp()
{
    int tt=strlen(T),pp=strlen(P);
    int i=0,j=0;
    while(i<tt && j<pp)
    {
        //���j=-1�����ߵ�ǰ�ַ�ƥ��ɹ�����T[i] == P[j]��,����i++,j++
        if (j==-1 || T[i]==P[j]) i++,j++;
        //���j!=-1���ҵ�ǰ�ַ�ƥ��ʧ�ܣ���T[i] != P[j]��,����i����,j=next[j]
        else j=next[j];
    }
    if (j==pp) return i-j;
    else return -1;
}
//����ģʽ��P������T�г��ֵĴ���(���ص�)(��1:����)
int kmp_count()
{
    int tt=strlen(T),pp=strlen(P);
    int i=0,j=0;
    int ans=0;
    while(i<tt)
    {
        if (j==-1 || T[i]==P[j]) i++,j++;
        else j=nxt[j];
        if (j>=pp)
        {
            ans++;
            j=nxt[j];//�����ص��Ļ��Ͱ������Ϊj=0;
        }
    }
    return ans;
}

/******************************KMP**************************/

/*************************kuangbin KMPģ��****************************/
char T[1000];//ĸ��
char P[100];//ģ�崮  
int next[101];//ʧ�䴮(λ����ģ�崮��1)
void getNext()
{//next��1��ʼ,�ַ�����0��ʼ
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
void kmp() //�������ƥ���λ��
{
	int tt=strlen(T),pp=strlen(P);
	int j=-1;
	for (int i=0;i<tt;i++)
	{
		while (j!=-1 && T[i]!=P[j]) j=next[j];
		if (T[i]==P[j]) j++;
		if (j==pp) printf("%d\n", i-pp+1);//����j��pp�ˣ�Ҳ��next[pp]����ƥ��  
	}
}
int kmp_count()
{//����ģʽ��������T�г��ֵĴ���(��2,����,kuangbinģ��)
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
/*************************kuangbin KMPģ��****************************/




/*************************��չKMP****************************/
s[i]: �������Ե�i��λ��Ϊ��ʼ�ĺ�׺,(KMP:��s[i]=ģʽ������ �����)
next[i]:"ģʽ���ĺ�׺"��"ģʽ��P"�������ǰ׺
extend[i]:"s[i]"��"ģʽ��P"�������ǰ׺(��next[i]��)




��չKMP˼��: ����ģ�崮T���Ӵ�B�����ȷֱ�ΪlenT��lenB��Ҫ��������ʱ���ڣ�����ÿ��T[i]��0<=i<lenT)�����T[i..lenT-1]��B�������ǰ׺���ȣ���Ϊex[i]������˵��ex[i]Ϊ����T[i..i+z-1]==T[0..z-1]������zֵ����


����:
1.��һ���ַ�����������Ӵ�����ظ��Ӵ�
2.��'������ÿһ����׺' �� 'ģʽ��' �������ǰ׺
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
/*************************��չKMP****************************/



