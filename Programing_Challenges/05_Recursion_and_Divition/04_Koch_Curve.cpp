#include<iostream>
#include<cmath>
using  namespace std;

const double PI=acos(-1);

pair<double,double> point;

void  koch(int n,pair<double,double> a,pair<double,double> b)
{
    if(n==0) return;
    pair<double,double> s,t,u;
    double th=PI*60.0/180.0;
    s.first=(2.0*a.first+1.0*b.first)/3.0;
    s.second=(2.0*a.second+1.0*b.second)/3.0;
    t.first=(1.0*a.first+2.0*b.first)/3.0;
    t.second=(1.0*a.second+2.0*b.second)/3.0;
    u.first=(t.first-s.first)*cos(th)-(t.second-s.second)*sin(th)+s.first;
    u.second=(t.first-s.first)*sin(th)+(t.second-s.second)*cos(th)+s.second;

    koch(n-1,a,s);
    printf("%.8f %.8f\n",s.first,s.second);
    koch(n-1,s,u);
    printf("%.8f %.8f\n",u.first,u.second);
    koch(n-1,u,t);
    printf("%.8f  %.8f\n",t.first,t.second);
    koch(n-1,t,b);
}

int read()
{
    char  c=getchar();
    int n=0;
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9')
    {
        n=(n<<1)+(n<<3)+(c&15);
        c=getchar();
    }
    return n;
}

int main(void)
{
    pair<double,double> a,b;
    int n;
    n=read();
    a.first=0;
    a.second=0;
    b.first=100;
    b.second=0;

    printf("%.8f %.8f\n",a.first,a.second);
    koch(n,a,b);
    printf("%.8f %.8f\n",b.first,b.second);

    return 0;
}

