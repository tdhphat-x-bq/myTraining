#include<bits/stdc++.h>
#define int long long
using namespace std;

main() {
    freopen("tdoan.inp","r",stdin);
    freopen("tdoan.out","w",stdout);

    int n,k;
    cin>>n>>k;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int sum = 0,d=1e18,len=1e18;
    int l=0,r;
    for(r = 0; r < n; r ++){
        sum += a[r];

        while(sum >= k){
            if(sum == k){
                if(len > r-l+1){
                    len = r-l+1;
                    d = l + 1;
                }
               // cout<<l+1<<" "<<r-l+1<<endl;
            }
            sum -=a[l];
            l++;
        }
    }
    if(len == 1e18)cout<<0;
    else {
        cout<<d<<" "<<len;
    }
}
