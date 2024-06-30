#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1e9+7
#define inf 1e18
using namespace std;

inr n,t,ans;
inr a[N];
deque<inr>demax,demin;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("fgarden.inp","r",stdin);
    freopen("fgarden.out","w",stdout);

    cin>>n>>t;
    for(int i=1;i<=n;i++)cin>>a[i];
    int j=1;
    for(int i=1;i<=n;i++){
        while(!demax.empty() and a[demax.back()] < a[i])demax.pop_back();
        while(!demin.empty() and a[demin.back()] > a[i]) demin.pop_back();
        demax.push_back(i);
        demin.push_back(i);

        while(!demin.empty() and !demax.empty() and a[demax.front()] - a[demin.front()] > t){
            if(demax.front() == j)demax.pop_front();
            else if(demin.front() == j)demin.pop_front();
            j++;
        }
        ans=max(ans,(inr)i-j+1);
    }
    cout<<ans;
}
