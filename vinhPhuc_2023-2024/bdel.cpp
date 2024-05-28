#include<bits/stdc++.h>
#define int long long
using namespace std;

main() {
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        unordered_map<int,int>check;
        for(int i=1;i<=n;i++){
            int a;
            cin>>a;
            if(check[a] == 0){
                cout<<a<<" ";
                check[a] = 1;
            }
        }
        cout<<endl;
    }
}
