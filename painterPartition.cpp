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



bool isValid(int a,int b,vector<int> v,int mid)
{
    int painter=1;
    int temp=v[0]*b;
    for(int i=1;i<v.size();i++)
    {
        temp+=(v[i]*b);
        if(temp>=mid)
        {
            painter++;
            temp=v[i]*b;
        }
        if(painter>a)
        return false;
    }
    return true;
}

void solve2(int a,int b,vector<int> &v)
{
    int start=INT_MIN,end=0,n=v.size();
    for(int i=0;i<n;i++)
    {
        start=max(start,v[i]);
        end+=v[i];
    }
    start*=b;end*=b;int ans;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(isValid(a,b,v,mid))
        {
            ans=mid;
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    cout<<ans<<endl;
}

void solve(ll k1){
    
    int a,b;
    cin>>a>>b;
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    solve2(a,b,v);
    return ;
}

int main()
{
    //hr();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    for(ll k1=0;k1<t;k1++)
    {
        solve(k1);
    }
}