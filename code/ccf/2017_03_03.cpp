#include <bits/stdc++.h>
using namespace std;
char str[105];

int cout_title(int idx)
{
    while(str[idx]==' ')idx++;
    return idx;
}


void cout_strong_superlink(int idx)
{
    int len = strlen(str);
    int strong=0;
    //for(int i=idx;i<len;i++)
    while(idx<len)
    {
        if(str[idx]=='_')
        {
            if(strong==0)
            {
                strong=1;
                cout << "<em>";
            }
            else 
            {
                strong=0;
                cout << "</em>";
            }
            idx++;
        }
        else if (str[idx]=='[')
        {
            char tmp[105]; int cur=0;
            while(str[idx]!=']')
            {
                tmp[cur++]=str[idx];
                idx++;
            }

            cout << "<a href=" << '"';  //<a href="

            idx++;idx++;              //Link">
            int strong2=0;
            while(str[idx]!=')')
            {
                if(str[idx]=='_')
                {
                    cout<<(strong2==0?"<em>":"</em>");
                    strong2&=1;
                }
                else cout << str[idx];
                idx++;
            }
            cout << '"' << ">";

            //_em_
            int strong1=0;
            for(int k=1;k<cur;k++)
            {
                if(tmp[k]=='_')
                {
                    cout<< (strong1==0?"<em>":"</em>");
                    strong1&=1;
                }
                else cout << tmp[k]; //Text</a>
            }
            cout << "</a>";
        }
        else cout << str[idx++];
    }
}

int main()
{
    //char ss[100]; cin.getline(ss,1000);
    int para=1;
    int unlist=1;
    while(cin.getline(str,105))
    {
        int len = strlen(str);
        if(len==0)
        {
            if(unlist==2)
            {
                cout<<"</ul>"<<endl;
                unlist=1;
                continue;
            }
            if(para==0 || para==1)
            {
                para=1;
            }
            else if (para==2)
            {
                para=1;
                cout << "</p>";
                cout << endl;
            }
            continue;
        }
        if(str[0]=='*')
        {
            if(unlist==1)
            {
                cout << "<ul>" << endl;
                unlist=2;
            }
            cout<<"<li>";
            int idd = cout_title(1);
            for(int i=idd;i<len;i++) cout << str[i];
            cout<<"</li>"<<endl;
            continue;
        }
        else if(str[0]=='#')
        {
            if(str[1]=='#')
            {
                if(str[2]=='#')
                {
                    if(str[3]=='#')
                    {
                        if(str[4]=='#')
                        {
                            if(str[5]=='#')
                            {
                                cout<<"<h6>";
                                cout_strong_superlink(cout_title(6));
                                cout<<"</h6>"<<endl;
                            }
                            else 
                            {
                                cout<<"<h5>";
                                cout_strong_superlink(cout_title(5));
                                cout<<"</h5>"<<endl;
                            }
                        }
                        else
                        {
                            cout<<"<h4>";
                            cout_strong_superlink(cout_title(4));
                            cout<<"</h4>"<<endl;
                        }
                    }
                    else
                    {
                        cout<<"<h3>";
                        cout_strong_superlink(cout_title(3));
                        cout<<"</h3>"<<endl;
                    }
                }
                else
                {
                    cout<<"<h2>";
                    cout_strong_superlink(cout_title(2));
                    cout<<"</h2>"<<endl;
                }
            }
            else
            {
                cout<<"<h1>";
                cout_strong_superlink(cout_title(1));
                cout<<"</h1>"<<endl;
            }
        }
        else
        {
            if(para==1) //第一次出现
            {
                cout << "<p>";
                cout_strong_superlink(0);
                para=2;
            }
            else if (para==2)
            {
                cout << endl;
                cout_strong_superlink(0);
            }
        }
    }
    if(para==2)
    {
        cout<<"</p>";
    }
    return 0;
}
