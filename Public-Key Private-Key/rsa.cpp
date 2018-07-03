#include <iostream>
#include <time.h>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//double e=4;

ll p,q,e,n,d;

string convertToString(ll num)
{
    string s;
    int temp=num%100;
    temp=temp+'a'-1;
    num=num/100;
    s=temp;
    while(num>0)
    {
        temp=num%100;
        num=num/100;
        temp=temp+'a'-1;
        s.insert(0,1,temp);
    }

    return s;

}

ll getNumber(string s)
{
    //cout<<s;
    ll sum=0;
    for (int i = 0; i<s.length(); i++)
    {
        sum=sum*100+(s[i]-'a'+1);
        //cout<<"sum="<<sum<<", s[i]="<<s[i]<<endl;
    }
    //cout<<sum;
    return sum;
}

bool checkPrime(ll num)
{
    for (int i = 2; i <=sqrt(num); ++i)
    {
        if(num%i==0) return false;
    }
    return true;
}

ll getPrime(int num)
{
    srand(time(0));

    if(num<50) num=59;
    for (int i = num; i >1; i--)
    {
        if(checkPrime(i)) return i;
    }

}

ll modulo(ll a, ll b, ll n){
    long long x=1, y=a;
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % n; // multiplying with base
        }
        y = (y*y) % n; // squaring the base
        b /= 2;
    }
    return x % n;
}

pair<ll,ll> getPublicKey()
{
    return make_pair(n,e);
}

ll getPrivateKey()
{
    return d;
}
ll encrypt(string s)
{
    srand(time(0));
    ll num=getNumber(s);
    //num=89;
    p = getPrime(rand()%10+pow(10,s.length()));
    q = getPrime(rand()%9+pow(10,s.length()));
    //cout<<num;
    //p=53;
    //q=59;
    n=p*q;


    while(true)
    {
        e=getPrime(rand()%8);
        if((p-1)%e!=0 || (q-1)%e!=0)  break;
    }
    //e=3;
    //cout<<"p="<<p<<" q="<<q<<" e="<<e<<endl;


    // ll ans=1;
    // for (int i = 1; i <= e; i++)
    // {
    //     ans=(ans*num)%n;
    // }


    ll ans=modulo(num,e,n);
    return ans;
}

int modInverse(int a, int m)
{
    a = a%m;
    for (int x=1; x<m; x++)
       if ((a*x) % m == 1)
          return x;
}

string decrypt(ll num)
{
    //ll fhi=(p-1)*(q-1);
    //ll d=(2*fhi+1)/e;
    //num=1394;
    d=modInverse(e,(p-1)*(q-1));

    ll ans=modulo(num,d,n);
    //cout<<"ans="<<ans<<endl;
    return convertToString(ans);

}
