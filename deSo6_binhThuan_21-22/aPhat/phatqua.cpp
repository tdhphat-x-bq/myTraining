#include<bits/stdc++.h>
#define int long long
#define N 1000006
#define M 103
using namespace std;

int a,b;
vector<int>uoc;

int myRes(int n,int m){
    int res=0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            uoc.push_back(i);
            if(i!=sqrt(n)){
                uoc.push_back(n/i);
            }
        }
    }
    for(int x:uoc){
        //cout<<x<<" ";
        if(m%x==0)res++;
    }
    return res;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("phatqua.inp","r",stdin);
    freopen("phatqua.out","w",stdout);

    cin>>a>>b;
    if(a<=b){
        cout<<myRes(a,b);
    }else cout<<myRes(b,a);


}
