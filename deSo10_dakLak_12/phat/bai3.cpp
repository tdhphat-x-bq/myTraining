#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
using namespace std;

string s;
unordered_map<string,inr>mp;
inr n,dp[N];
pair<inr,inr>x[N];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("bai3.inp","r",stdin);
    freopen("bai3.out","w",stdout);

    cin>>s;
    int q=8;
    string st;
    while(cin>>st){

        n++;
        mp[st] = n;

    }
    n=s.size();
    //fill(dp+1,dp+n+1,n);
    for(int i=1;i<=n;i++){
        string t="";
        dp[i] = n;
        for(int j=i;j>max(i-16,0);j--){
            t=s[j-1]+t;
            if(mp[t] != 0 and dp[i] > dp[j-1]+1){
                dp[i]=dp[j-1]+1;
                x[i]= {mp[t],t.size()};
            }
        }

    }


    if(dp[n] == n)cout<<0;
    else{
        cout<<dp[n]<<endl;
        vector<inr>ans;
        //for(int i=1;i<=n;i+=x[i].second)ans.push_back(x[i].first);
        // for(int i=n;i>0;i--){
        //     cout<<x[i].first<<" "<<x[i].second<<endl;
        // }
        for(int i=n;i>0;i-=x[i].second)ans.push_back(x[i].first);
        reverse(ans.begin(),ans.end());
        for(int x:ans)cout<<x<<" ";
    }
}
