#include<bits/stdc++.h>
#define int long long
using namespace std;

main() {
    freopen("chiamang.inp","r",stdin);
    freopen("chiamang.out","w",stdout);

    int n,sum=0,ans=0;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum == 0){
        cout<<1;
    }else{
        int res=0;
        for(int i=0;i<n;i++){
            ans+=a[i];
            sum-=a[i];
            if(ans == sum){
                res=i+1;
                break;
            }
        }
        cout<<res;
    }

}
