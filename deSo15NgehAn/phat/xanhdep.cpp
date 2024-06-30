#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1e9+7
#define inf 1e18
using namespace std;

int n,ans;
string a[N];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("xanhdep.inp","r",stdin);
    freopen("xanhdep.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        string s=a[i];
        int l=0,r;
        for(r=0;r<s.size();r++){
            if(s[l]!=s[r])l=r;
            if(s[l] == s[r]){
                ans=max(ans,r-l+1);
            }
        }
        if(l < s.size())ans=max(ans,r-l);
    }
    cout<<ans;
}
