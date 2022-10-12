#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;



void hr(){
	
	#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif 
}


bool bs(ll n)
{
    ll start=1,end=cbrt(n);
    while(start<=end)
    {
        ll mid=start+(end-start)/2;
        ll check=pow(mid,3);
        if(check<0)
        {
            end=mid-1;
            continue;
        }
        if(check==n)
        return true;
        else if(check<n)
        start=mid+1;
        else
        end=mid-1;
    }
    return false;
}

void solve(){
    
    ll n;
    cin>>n;
    for(ll i=1;i<=cbrt(n);i++)
    {
        ll temp=n-(i*i*i);
        if(temp==0)
        {
            cout<<"NO"<<endl;
            return ;
        }
        if(bs(temp))
        {
            cout<<"YES"<<endl;
            return ;
        }
    }
    cout<<"NO"<<endl;
    return;
}

int main()
{
    //hr();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    for(ll k1=0;k1<t;k1++)
    {
        solve();
    }
}