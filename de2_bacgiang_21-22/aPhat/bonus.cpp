#include<bits/stdc++.h>
#define inr long long
#define inf 1e9
#define N 1000001
using namespace std;

inr n,res;
inr a[N], minl[N], minr[N], maxl[N], maxr[N];
stack<inr>sl,sr;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("bonus.inp","r",stdin);
    // freopen("bonus.out","w",stdout);

    cin>>n;
    for(inr i=1;i<=n;i++){
        cin>>a[i];
    }
    a[0] = a[n+1] = 1e9;
    sl.push(0);sr.push(n+1);
    minl[0] = 0;minr[n+1] = n+1;
    for(inr i=1;i<=n;i++){
        while(a[i] > a[sl.top()]) sl.pop();
        maxl[i] = sl.top();
        sl.push(i);
    }
    for(inr i=n;i>0;i--){
        while(a[i] >= a[sr.top()])sr.pop();
        maxr[i] =sr.top();
        sr.push(i);
    }
    while(!sr.empty())sr.pop();
    while(!sl.empty())sl.pop();
    a[0]= a[n+1] = 0;
    sl.push(0);sr.push(n+1);
    for(inr i=1;i<=n;i++){
        while(a[i] < a[sl.top()]) sl.pop();
        minl[i] = sl.top();
        sl.push(i);
    }
    for(inr i=n;i>0;i--){
        while(a[i] <= a[sr.top()])sr.pop();
        minr[i] =sr.top();
        sr.push(i);
    }
    for(inr i=1;i<=n;i++){
       // cout<<maxl[i]<<" "<<maxr[i]<<" "<<minl[i]<<" "<<minr[i]<<endl;
        res += (i - maxl[i]) * (maxr[i] - i) * a[i];
        res -= (i - minl[i]) * (minr[i] - i) * a[i];
    }
    cout<<res;
}

