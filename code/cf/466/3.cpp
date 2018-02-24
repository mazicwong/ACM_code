#include <bits/stdc++.h>
using namespace std;
pair<char,int> pii[30];
int num=0;
string str;
int n,k; 
char getNext(char c)
{
    int idx=0;
    char ans='*';
    //if not exist?
    while(++idx && idx<=num)
    {
        if (pii[idx].first>c)
        {
            ans = pii[idx].first;
            break;
        }
    }
    return ans;
}

int main()
{
    cin>>n>>k;
    cin>>str;
    //find string t of length k, and the 
    //- letter is subset of str;
    //- >str; (smallest)
    set<char> st;
    for (int i=0;i<str.size();i++)
        st.insert(str[i]);
    //cout << st.size() << endl;
    for (set<char>::iterator it=st.begin();it!=st.end();it++)
    {
        num++;
        pii[num].first = *it;
        pii[num].second = num;
    }
    char ans[100005];
    //for (int i=1;i<=num;i++)cout << pii[i].first << "  " << pii[i].second << endl;
    if (n < k)
    {
        cout << str;
        int tmp = k-n;
        while(tmp--)
            cout << pii[1].first;
    }
    else if (n > k)
    {
        //for (int i=0;i<k-1;i++)
        //    cout << str[i];
        int idx = k-1;
        while(getNext(str[idx])=='*')
        {
            idx--;
        }
        char minn = pii[1].first;
        for (int i=0;i<idx;i++)
            cout << str[i];
        cout << getNext(str[idx]);
        for (int i=idx+1;i<k;i++)
            cout << minn;
    }
    else if (n == k)
    {
        int idx = n-1;
        while(getNext(str[idx])=='*')
        {
            idx--;
        }
        char minn = pii[1].first;
        for (int i=0;i<idx;i++)
            cout << str[i];
        cout << getNext(str[idx]);
        for (int i=idx+1;i<n;i++)
            cout << minn;
    }
    return 0;
}
