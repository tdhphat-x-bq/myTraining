#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1e9+7
using namespace std;

string s,st;
unordered_map<string,inr>mp;
pair<inr,inr>x[N];
int dp[N];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("bai3.inp","r",stdin);
    freopen("bai3.out","w",stdout);
    cin>>s;
    int q=8,n=0;
    while(cin>>st){

        n++;
        mp[st]=n;

    }
    n=s.size();
    for(int i=1;i<=n;i++){
        string t="";
        dp[i]=n;
        for(int j=i;j>max(0,i-16);j--){
            t=s[j-1]+t;
            if(mp[t] != 0 and dp[i] > dp[j-1]+1){
                dp[i]=dp[j-1]+1;
                x[i] = {mp[t],t.size()};
            }
        }
    }
    //for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
    //cout<<endl;
    if(dp[n] ==n)cout<<0;
    else{
        cout<<dp[n]<<endl;
        vector<inr>ans;
        for(int i=n;i>0;i-=x[i].second)ans.push_back(x[i].first);
        reverse(ans.begin(),ans.end());
        for(int x:ans)cout<<x<<" ";
    }
}
