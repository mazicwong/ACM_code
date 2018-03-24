#include <bits/stdc++.h>
using namespace std;

int main()
{
    int hh,mm;
    cin>>hh>>mm;

    int h,d,c,n;
    cin>>h>>d>>c>>n;
    if(hh>=20)
    {
        double num = h/n + (h%n!=0);
        double ans = num*0.8*c;
        printf("%.4lf",ans);
        return 0;
    }

    double num1 = h/n+(h%n!=0);
    double ans1=num1*c;
    //cout << ans1 << endl;

    int qaq2 = ((20-hh)*60-mm)*d+h;
    //cout << qaq2<<endl;
    double num2 = qaq2/n + (qaq2%n!=0);
    //cout << num2 << endl;
    double ans2 = num2*0.8*c;
    //cout << ans2 << endl;
    printf("%.4lf",min(ans1,ans2));
    return 0;
}
