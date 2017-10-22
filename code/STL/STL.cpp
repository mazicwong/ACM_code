http://www.cnblogs.com/shanyr/p/5745807.html

http://blog.csdn.net/qiweigo/article/details/43566227
本文结合小紫书总结STL在ACM竞赛中的使用


std::ios::sync_with_stdio(false);cin.tie(0);//不能用cout<<endl;
扩栈:
//C++
#pragma comment(linker, "/STACK:102400000,102400000")
//G++
int size = 256 << 20; // 256MB  
char *p = (char*)malloc(size) + size;  
__asm__("movl %0, %%esp\n" :: "r"(p));



1.string类型:
//string优点:可以直接用四则运算符和关系运算符
string str1="22",str2="11";  
str1+=str2;                 //类似于strcat
int len=str1.length();      //类似于strlen,也可以用string.size();
bool flag=str1>str2;        //类似于strcmp
while(getline(cin,str)){    //输入一行,然后用stringstream创建字符串流(很慢!慎用)
    stringstream ss(str);
    while(ss>>x) sum+=x;
}
/***string与char str[]转化***/
string ss; char str1[],str2[];
const char* pp=ss.c_str(); //string转到char
strcpy(str2,str1);         //char[]转到char[]
/***string与char str[]转化***/
//读取
string s;
scanf("%s",s.c_str);
printf("%s",s.c_str);



2.模板template:
模板是为了，使类或者函数具有通用性，不仅限于一种数据类型或者一种成员结构。
现定义一个可以任意交换类型的模板（注意模板只能在全局或者命名空间内定义，不可以在main函数或者自定义函数内定义。）

template<class &T>    //class为固定关键字,也可以用等效的typename.(紫书P106)
void swap1(T &a,T &b){
    T tmp;
    tmp=a;
    a=b;
    b=tmp;
}



3. 容器vector:
创建:
vector<int> v;
vector<int> v(10);			           //创建一个前十个元素为int的容器
vector<string> v(10,string("mazic"));  //使容器的前10个元素都为string型，并且都初始化为mazic
vector<string> v1(v2);		           //对于已经存在的v2创建一个v1副本  
vector<int> G[maxn];                   //建图,邻接表

基本操作:
sort(vec.begin(),vec.end());
v.push_back(a);         //压入元素a到末端
v.pop_back();           //弹出最后一个元素
v.begin();              //容器的起始位置
v.end();                //容器最后一个位置
v.empty();              //返回是否容器为空
v.clear();              //清空容器
v.erase(it);            //删除迭代器it处的数据，并返回下一个数据的地址(注意'循环'中最好用it=vec.erase(it))
v.erase(m,n);           //删除m到n之间的数据，并返回下一个数据的地址
v.front();v.back();     //返回第一个|最后一个元素(但不判断是否存在)一般用v[0],v[n-1]
v2.assign(8,1);         //重新给vec2赋值，8个成员的初始值都为1 
v.resize(n);            //用于改变大小,v只保留[0~n)的元素
v.reserve(100);         //reserve只是预留空间并没有真正创建，v.push_back();只是在第1位  
v.resize(101);          //resize已经创建空间如果再v.push_back();空间就会到101
v.size();               //已经创建的空间大小 OR 元素个数
v.capacity();           //容器容量，是预留空间并没有实际创建  
swap(a,b);              //交换两个元素的位置如:swap(v[0],v[1]);  
v.insert(place,element);  
v.insert(place,n,element);   //在place（迭代器）位插入n个元素  
v[0];     //访问
v.at[0];  //访问,越界时更安全
vec.erase(remove(vec.begin(),vec.end(),val), vec.end());  //删除某个特定值val,remove是将其移到最后
vec.erase(it);                                            //*it=val,删除某个迭代器


4.集合set(没有重复元素)://主要用于查询元素
创建:
set<int> s;             //创建整型集合s,默认升序
set<int,less<int> > st1;      //降序排列
set<int,greater<int> > st2;   //升序排列

基本操作:
s.insert(a);            //插入元素a,并会自动排序,默认升序
s.size();               //返回元素个数
s.empty();
s.find(a);              //返回元素的下标，没找到的话返回s.end()
s.erase(s.find(a));     //删除元素a
s.count(a);             //元素个数
s.lower_bound();        //lower_bound,upper_bound都可以用
copy(s.begin(), s.end(), ostream_iterator<string>(cout, "\n"));
//#include<iterator>中的函数：输出全部集合中的元素，并在每个元素后面接换行符

逻辑操作:
//获得两个set的并集,s1,s2的并存入s3
set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),insert_iterator<set<int> >(s3,s3.begin()));
copy(s3.begin(),s3.end(),ostream_iterator<int>(cout," "));//输出也可以用这种形式
//获得两个set的交集,s1,s2的交存入s3,注意s3先clear()
s3.clear();
set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),insert_iterator<set<int> >(s3.s3.begin()));
copy(s3.begin(),s3.end(),ostream_iterator<int>(cout," "));
//获得两个set的差
s3.clear();
set_difference(s1.begin(),s1.end(),s2.begin(),s2.end(),insert_iterator<set<int> >(s3,s3.begin()));
cout<<"Difference:";
copy(s3.begin(),s3.end(),ostream_iterator<int>(cout," "));
//获得两个set的对称差，也就是假设两个集合分别为A和B那么对称差为AUB-A∩B
eg3.clear();
set_symmetric_difference(s1.begin(),s1.end(),s2.begin(),s2.end(),insert_iterator<set<int> >(s3,s3.begin()));
copy(s3.begin(),s3.end(),ostream_iterator<int>(cout," "));


//////multiset应用: hdu6168(可以重复元素)
multiset<int> st;
*st.begin()             //取出最小的数
st.find(a)              //返回数a处的迭代器
st.erase(st.find(a))    //从st中删除数a



5.映射map:
创建:
map<string,int> mp; //const char* pp = it->first.c_str();
map<string,int>::iterator it = mp.begin();


基本操作:
mp.insert(pair<string,int>("month",1)); //插入一个元素
mp["month"]=1;							//插入一个元素
it = mp.find("month");                  //返回一个迭代器指向键值为key的元素，找不到则返回最后一位元素后面的迭代器(map尾部)
mp.erase(it);                           //删除一个元素,注意用find后it不能是mp.end()
mp.count("month");                      //返回指定元素出现的次数,效率:logn
for(it=mp.begin();it!=mp.end();it++) {it->begin;  it->second;}

常用技巧:
map<int,vector<int> >mp;

begin()          返回指向map头部的迭代器
end()            返回指向map末尾的迭代器
clear(）         删除所有元素
count()          返回指定元素出现的次数
empty()          如果map为空则返回true
equal_range()    返回特殊条目的迭代器对
erase()          删除一个元素
find()           查找一个元素
get_allocator()  返回map的配置器
insert()         插入元素
key_comp()       返回比较元素key的函数
lower_bound()    返回键值>=给定元素的第一个位置
upper_bound()    返回键值>给定元素的第一个位置
max_size()       返回可以容纳的最大元素个数
rbegin()         返回一个指向map尾部的逆向迭代器
rend()           返回一个指向map头部的逆向迭代器
size()           返回map中元素的个数
swap()           交换两个map
value_comp()     返回比较元素value的函数



6.栈stack：
创建:
stack<int> st;	//在是默认以deque为容器的  

基础操作:
st.push(x);
st.pop(); 
st.top();		//取栈顶
st.empty();		//是否为空
st.size();		//元素个数


7.队列queue:
创建:
queue<int> que;

基本操作:
que.push(x);	//加入队列顶部  
que.pop();		//弹出队列里第一个元素  
que.front();	//队列第一个元素  
que.back();		//队列最后一个元素  
que.size();		//队列元素个数  
que.empty();	//队列是否为空



8.priority_queue://解决多路归并问题(紫书P119,蓝书P188)
(!其实priority_queue跟multiset大部分功能很像,都是自动排序,区别在于set支持随机操作;都可以时,用priority_queue好些,cf865D)
priority_queue<int,vector<int>,less<int> > pque;    //less,表示大的先出队(默认less)
priority_queue<int,vector<int>,greater<int> > pque;	//小的先出队  
pque.top(); pque.pop();   //不用front

struct cmp{
    bool operator() (const int a, const int b) const{
        return a%10 > b%10;
    }
};
priority_queue<int,vector<int>, cmp> pq;

struct item{
    int num,period,time;
    bool operator < (const item& a) const{
        return time>a.time || (time==a.time && num>a.num)
    }
};
priority_queue<item> pq;


9.deque双端队列
#include<queue>
deque <int> deq;			//初始化对象为空
deque <int> deq1(10,6);		//对象初始化有10个值为6的元素
deque <int>:: iterator it;
for(it = deq.begin(); it!=deq.end(); it++)
	cout<<*it<<endl;
deq.push_back(ele);			//从队列尾部插入
deq.push_front(ele);		//从队列头部插入
deq.insert(deq.begin()+1,3,9);	//从队列中间插入三个9
deq[n];						//访问
deq.at(n);					//访问n下标处的值
deq1.pop_front();			//从deq1序列的前面移去一个元素
deq1.pop_back();			//从deq1序列的前面移去一个元素
deq.erase(deq.begin()+1);	//清除deq的第二个元素
deq2.assign(8,1);			//对deq2赋值并显示
cout<<"deq2.assign(8,1):"<<endl;
put_deque(deq2,"deq2");


10.bitset
#include <bitset>  
bitset<n> b;                //b有n位，每位都为0  
bitset<n> b(u);             //b是unsigned long型u的一个副本  
bitset<n> b(s);             //b是string对象s中含有的位串的副本  
bitset<n> b(s, pos, n);     //b是s中从位置pos开始的n个位的副本  
bitset<32> bitvec;          //32位，全为0。  


11.permutation  hdu1027
//输出str的下一个全排列
string str;
next_permutation(str.begin(),str.end());
//输出a[0..n-1]的第m次全排列
int a[maxn];
while(m--)
    next_permutation(a,a+n);



12.unique:从序列中删除所有相邻的重复元素
//数组去重:
int arr[N];
sort(arr,arr+n);
int len = unique(arr,arr+n)-arr;
for (int i=0;i<len;i++)  cout<<arr[i];
//向量去重:
vector<int> v{1,2,2,3,2,1,1};
vector<int>::iterator it = unique(v.begin(),v.end());//去重
v.erase(it,v.end());
for (int *t=v.begin();t!=v.end();t++)  cout << *t;


//下面归入位运算
13. lowbit hdu1196(find the lowest bit)
lowbit: 返回2^t  (t为从右边开始第一次出现1的位置/0的个数)
int lowbit(int x) {
    return x&(-x);
}


14. struct
构造函数:
struct point{
    int x,y;
    point(int x=0,int y=0):x(x),y(y){};
}

重载:
point operator + (const point& A,const point& B){
    return point(A.x+B.x,A.y+B.y);
}


15. pair
vector<pair<int,int> > vec;
vec[2]=make_pair(2,3);
/*
 * 给出a[]和b[],现在固定b[],对a[]重排列,使得b[]中的最小到最大分别对应a[]中的最大到最小,
 * 输出排列后的a[]
 *
 * 思路:a存数组,b存pair<num,index>
 * a从大到小排,b按first从小到大排
 * 然后直接ans[b[i].second] = a[i]
 *
 * 适用于排序后还要记住原来的下标的
 */
const int maxn = 2e5+5;
int a[maxn];
int ans[maxn];
bool cmp(int a,int b) {return a>b;}
typedef pair<int,int> pii;
pii b[maxn];
int main()
{
    int n;cin >> n;
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&b[i].first);
        b[i].second=i;
    }
    sort(a,a+n,cmp);
    sort(b,b+n);//按first从小到大排序,使用于排序后还要记住原来下表的
    for (int i=0;i<n;i++)
        ans[b[i].second] = a[i];
    for (int i=0;i<n;i++)
        printf("%d ",ans[i]);
    return 0;
}


16. rand (紫书P121)
#include <time.h>
srand(time(NULL));   //在程序开头只用一次,初始化随机数种子

//int型
srand(time(NULL));
printf("%d\n",rand());
//获取n以内整数
int t=100;
srand(time(NULL));
printf("%d\n",rand()%t);
//double型
srand(time(NULL));
printf("%.6lf\n",rand()*1.0/100);
//字符串
int len=100;
srand(time(NULL));
while(len--) printf("%c\n",'A'+rand()%26);




17. 技巧
传引用,不要用返回
void fill(vector<int>& v,int cnt)

二分(非递归,紫书P228)
//返回大于等于v的第一个,不存在则返回应该插入的位置(即lower_bound)
int bs(int l,int r,int v){
    while(l<r){
        int mid = l+(r-l)/2;
        if (v<=a[mid]) r=mid; //v<=a[mid]
        else l=mid+1;         //v>a[mid],则不可能取到刚好mid那里了
    }
    return l;
}


template<class Type> 
int bs(Type a[], const Type& x, int l, int r)
{
    while (l<=r){ 
        int mid = (l+r)/2;
        if (x==a[mid]) return m;
        if (x<a[mid]) r = m-1;
        else l = m+1;
    }
    return -1;
} 


18. 输入挂
测试: hdu6208 青岛网络赛第三题的AC自动机,3000ms
- AC自动机:
- 1.用`string+sync`            各种TLE
- 2.改用`char ss[]`            刚好卡过去..2800ms
- 3.加了个`fastIO`输入挂...    2400ms就过了

namespace fastIO  
{
    #define BUF_SIZE 100000  
    //fread -> read
    bool IOerror = 0;  
    inline char nc() {  
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;  
        if(p1 == pend) {  
            p1 = buf;  
            pend = buf + fread(buf, 1, BUF_SIZE, stdin);  
            if(pend == p1) {  
                IOerror = 1;return -1;  
            }  
        }  
        return *p1++;  
    }  
    inline bool blank(char ch) {  
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';  
    }  
    inline int read(char x[]) {  
        char ch;  
        while(blank(ch = nc()));  
        if(IOerror)  
            return 0;  
        int k = 0;  
        for(x[k++] = ch; (ch = nc())&&(!blank(ch))&&(ch != EOF); x[k++] = ch);  
        x[k]='\0';  
        return k;  
    }
    inline void readint(int &x) {  
        char ch;  
        while(blank(ch = nc()));  
        if(IOerror)return;  
        for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');  
    }  
#undef BUF_SIZE  
};  
using namespace fastIO;  


//how to use
while(read(n),!fastIO::IOerror)
{
    readint(T);
    for (int i=1;i<=n;i++)
        readint(a[i]);
    char str[maxn];
    read(str);
}


/**********kuangbin***********/
//适用于正负整数
template <class T>
inline bool scan_d(T &ret) {
    char c; int sgn;
    if(c=getchar(),c==EOF) return 0; //EOF
    while(c!='-'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
    ret*=sgn;
    return 1;
}
inline void out(int x) {
    if(x>9) out(x/10);
    putchar(x%10+'0');
}

/**********another***********/
std::ios::sync_with_stdio(false);
cin.tie(0);

/**********test***********/
#include <ctime>
int main()
{
    double start = clock();
    // do sth;
    printf("%.3lf\n",double(clock()-start)/CLOCKS_PRE_SEC);
}


int maxn = 1e7+5;
//1.406s
while(maxn--) cin>>i;

//0.552
while(maxn--) scanf("%d",&i);

//0.521
std::ios::sync_with_stdio(false);
while(maxn--) cin>>i;

//0.427
std::ios::sync_with_stdio(false); cin.tie(0);
while(maxn--) cin>>i;

//0.229 (kuangbin)
while(maxn--) scan_d()i;

//0.165 (神奇FastIO挂)
while(maxn--) readint(i)

