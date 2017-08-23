http://www.cnblogs.com/shanyr/p/5745807.html

http://blog.csdn.net/qiweigo/article/details/43566227
本文结合小紫书总结STL在ACM竞赛中的使用

manacher
splay
kdtree    hdu 5992



1.stringstream字符流，和string类型:
//string类具有的优点：可以直接用四则运算符和关系运算符，简化了字符串类型的操作。

string str1="22",str2="11";  
str1+=str2;                 //类似于strcat
int length=str1.length();   //类似于strlen,也可以用string.size();
bool judge=str1>str2;       //类类似于strcmp



2.模板：
模板是为了，使类或者函数具有通用性，不仅限于一种数据类型或者一种成员结构。
现定义一个可以任意交换类型的模板（注意模板只能在全局或者命名空间内定义，不可以在main函数或者自定义函数内定义。）

template<class &T>    //class为固定关键字，也可以用等效的typename.  
void swap1(T &a,T &b){
    T tmp;
    tmp=a;
    a=b;
    b=tmp;
}



3. 容器vector：
创建:
vector<int> v;
vector<int> v(10);			           //创建一个前十个元素为int的容器
vector<string> v(10,string("mazic"));  //使容器的前10个元素都为string型，并且都初始化为mazic
vector<string> v1(v2);		           //对于已经存在的v2创建一个v1副本  
vector<int> G[maxn];                   //建图,邻接表

基本操作:
v.push_back(a);         //压入元素a到末端
v.pop_back();           //弹出最后一个元素
v.begin();              //容器的起始位置
v.end();                //容器最后一个位置
v.front();v.back();     //返回第一个元素(最后一个元素,但不判断是否存在)
v.empty();              //返回是否容器为空
v.clear();              //清空容器
v.erase(m);             //删除m位置的数据，并返回下一个数据的地址(m是迭代器)
v.erase(m,n);           //删除m到n之间的数据，并返回下一个数据的地址
v2.assign(8,1);         // 重新给vec2赋值，8个成员的初始值都为1 
v.reserve(100);v.resize(101);    //resize已经创建空间如果再v.push_back();空间就会到101，而reserve只是预留空间并没有真正创建，v.push_back();只是在第1位  
v.size();v.capacity();       //size表示的是已经创建的空间大小也可以表示元素个数可用v[]的形式直接访问，capacity容器容量，是预留空间并没有实际创建  
swap(a,b);					//交换两个元素的位置如:swap(v[0],v[1]);  
v.insert(place,element);  
v.insert(place,n,element);	//在place（迭代器）位插入n个元素  
v[0];     //访问
v.at[0];  //访问,越界时更安全


4.集合set(没有重复元素)://主要用于查询元素
创建:
set<int> s;				      //创建整型集合:s  
set<int,less<int> > st1;      //降序排列
set<int,greater<int> > st2;   //升序排列

基本操作:
s.insert(a);		    //插入元素a,并会自动排序,默认升序
s.size();				//返回元素个数
s.find(a);              //返回元素的下标，没找到的话返回s.end()
s.erase(s.find(a))      //删除元素a
copy(s.begin(), s.end(), ostream_iterator<string>(cout, "\n"));//#include<iterator>中的函数：输出全部集合中的元素，并在每个元素后面接换行符

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
map<string,int> mp;
it = map<string,int>::iterator it;

基本操作:
mp.insert(pair<string,int>("month",1)); //插入一个元素
mp["month"]=1;							//插入一个元素
it = mp.find("month");                  //返回一个迭代器指向键值为key的元素，找不到则返回最后一位元素后面的迭代器(map尾部)
mp.erase(it);                           //删除一个元素,注意用find后it不能是mp.end()
mp.count("month");                      //返回指定元素出现的次数,效率:logn


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
st.empty();		//是否为空  
st.size();		//元素个数  
st.top();		//判断是否为栈顶元素  


7.队列queue:
创建:
queue<int> que;

基本操作:
que.push(x);	//加入队列顶部  
que.pop();		//弹出队列里第一个元素  
que.back();		//队列最后一个元素  
que.front();	//队列第一个元素  
que.size();		//队列元素个数  
que.empty();	//队列是否为空



8.优先队列priority_queue:
priority_queue<int,vector<int>,less<int>> pque;		//默认容器为vector,其中less算子，表示小的先出队  
priority_queue<int,vector<int>,greater<int>> pque;	//大的先出队  
//优先队列与队列相比，只是按照指定的算子将队列内部排序，让后在操作排序后的栈顶元素


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
bitset<n> b;            //b有n位，每位都为0  
bitset<n> b(u);             //b是unsigned long型u的一个副本  
bitset<n> b(s);             //b是string对象s中含有的位串的副本  
bitset<n> b(s, pos, n);     //b是s中从位置pos开始的n个位的副本  
bitset<32> bitvec; //32位，全为0。  


11.permutation  hdu1027
//输出str的下一个全排列
string str;
next_permutation(str.begin(),str.end());
//输出a[0..n-1]的第m次全排列
int a[maxn];
while(m--)
    next_permutation(a,a+n);



12.unique:从序列中删除所有相邻的重复元素
数组去重:
int mp[N];
sort(mp,mp+n);
int len = unique(mp,mp+n)-mp;


//下面归入位运算
13.lowbit hdu1196
lowbit: 返回2^t  (t为从右往左第一次出现1的位置)
int lowbit(int x)
{
	return x&(-x);
}
