#include<bits/stdc++.h>
#define int long long
using namespace std;

main() {
    int n,k;
    cin>>n>>k;
    int a[n+1];
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    set<int>st;
    int res=0;
    for(int i=1;i<=k;i++){
        st.insert(a[i]);

    }
    cout<<*st.begin()<<endl;

    for(int i=k+1;i<=n;i++){
        if(*st.begin() < a[i]){
            st.erase(*st.begin());
            st.insert(a[i]);
        }
        cout<<*st.begin()<<endl;
    }
}
