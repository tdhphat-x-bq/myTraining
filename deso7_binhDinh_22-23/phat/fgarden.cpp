#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 103
using namespace std;

inr n,k;
inr a[3*N];
deque<inr>amax,amin;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("fgarden.inp","r",stdin);
    freopen("fgarden.out","w",stdout);

    cin>>n>>k;
    for(inr i=1;i<=n;i++)cin>>a[i];

    amax.push_back(1);amin.push_back(1);

    int l=1,r=1;
    int res=1;

    while(l<=n and r<=n){
        if(a[amax.front()] - a[amin.front()] <= k){
            res= max(res,r-l+1);
            r++;
            while(!amin.empty() and a[r] < a[amin.front()]) amin.pop_front();
            while(!amin.empty() and a[r] < a[amin.back()]) amin.pop_back();
            amin.push_back(r);
            while(!amax.empty() and a[r] > a[amax.front()]) amax.pop_front();
            while(!amax.empty() and a[r] > a[amax.back()]) amax.pop_back();
            amax.push_back(r);
        }else{
            l++;
            while(amin.front() < l)amin.pop_front();
            while(amax.front() < l)amax.pop_front();
        }
    }
    cout<<res;

}


