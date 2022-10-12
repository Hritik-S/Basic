#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;



/* sort(courses.begin(),courses.end(),
            [](vector<int> a, vector<int> b){return a.back()<b.back();});*/



void hr(){
	
	#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif 
}



bool isValid(vector<ll> v,ll n,ll k,ll mid)
{
    int cows=1;
    ll temp=v[0];
    for(ll i=1;i<n;i++)
    {
        if(v[i]-temp>=mid)
        {
            cows++;
            temp=v[i];
        }
        if(cows>=k)
        return true;
    }
    return false;
}


void solve(ll k1){
    
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    for(ll i=0;i<n;i++)
    cin>>v[i];
    sort(v.begin(),v.end());
    int start=v[1]-v[0],end=v[n-1],ans;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(isValid(v,n,k,mid))
        {
            ans=mid;
            start=mid+1;
        }
        else
        end=mid-1;
    }
    cout<<ans<<endl;
    return ;
}

int main()
{
    //hr();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t=1;
    //cin>>t;
    for(ll k1=0;k1<t;k1++)
    {
        solve(k1);
    }
}